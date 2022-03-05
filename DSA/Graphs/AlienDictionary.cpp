#include "header.h"

struct TrieNode
{
    unordered_map<char, TrieNode *> children;
    bool isEnd = false;
};

class Trie
{
    TrieNode *root = nullptr;

public:
    Trie()
    {
        root = new TrieNode();
    }

    TrieNode *getRoot() const
    {
        return root;
    }

    void addWord(const string &word)
    {
        auto *itr = root;

        for (char c : word)
        {
            if (itr->children.find(c) == itr->children.end())
            {
                itr->children[c] = new TrieNode();
            }
            itr = itr->children[c];
        }

        itr->isEnd = true;
    }

    void searchWord(const string &word, unordered_map<char, vector<char>> &adjList)
    {
        auto *itr = root;

        for (char c : word)
        {
            if (itr->children.find(c) == itr->children.end())
            {
                for (const auto &p : itr->children)
                {
                    adjList[p.first].push_back(c);
                }
                break;
            }
            itr = itr->children[c];
        }
    }
};

enum class NodeStatus
{
    IN_PROGRESS,
    VISITED
};

class Solution
{

    bool dfs(unordered_map<char, vector<char>> &adjList, unordered_map<char, NodeStatus> &visited,
             char node, string &ans)
    {
        visited[node] = NodeStatus::IN_PROGRESS;
        for (const auto &neigh : adjList[node])
        {
            if (visited.find(neigh) == visited.end())
            {
                if (!dfs(adjList, visited, neigh, ans))
                {
                    return false;
                }
            }
            else if (visited[neigh] == NodeStatus::IN_PROGRESS)
            {
                return false;
            }
        }

        visited[node] = NodeStatus::VISITED;
        ans.push_back(node);
        return true;
    }

public:
    string findOrder(string dict[], int N, int K)
    {
        unordered_map<char, vector<char>> adjList;
        adjList.reserve(K);
        for (int i = 0; i < N - 1; i++)
        {
            const string &s1 = dict[i];
            const string &s2 = dict[i + 1];
            int x = min(s1.size(), s2.size());
            for (int j = 0; j < x; j++)
            {
                if (s1[j] != s2[j])
                {

                    adjList[s1[j]].push_back(s2[j]);
                    break;
                }
            }
        }

        string ans;
        ans.reserve(K);

        unordered_map<char, NodeStatus> visited;
        visited.reserve(K);

        for (const auto &node : adjList)
        {
            if (visited.find(node.first) == visited.end())
            {
                if (!dfs(adjList, visited, node.first, ans))
                {
                    return "";
                }
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};