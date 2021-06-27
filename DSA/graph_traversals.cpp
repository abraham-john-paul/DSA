#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <array>
#include <climits>
#include <algorithm>

using namespace std;

void addEdges(vector<int> a[], vector<int> edges, int source) {
    a[source] = move(edges);
}

void addUndirectesEdges(vector<int> a[], int src, int des) {
    a[src].push_back(des);
    a[des].push_back(src);
}

void addDirectesEdges(vector<int> a[], int src, int des) {
    a[src].push_back(des);
}

void dfsTraversalRecursive(vector<int> const a[], const int source, vector<bool> &visited) {
    if(!visited[source]) {
        cout << source << " ";
        visited[source] = true;
        for(const auto node : a[source]) {
            dfsTraversalRecursive(a, node, visited);
        }
    }
}

void dfsTraversal(vector<int> const a[], int source, int n_v) {
    vector<bool> visited(n_v, false);

    dfsTraversalRecursive(a, source, visited);

    for(int i = 0; i < n_v; i++) {
        if(!visited[i]) {
            dfsTraversalRecursive(a, i, visited);
        }
    }
}

void bfsTraversal(vector<int> const a[], int source, int n_v) {
    vector<bool> visited(n_v, false);
    queue<int> q;
    q.push(source);
    int node;
    int n_nodes;
    int i;
    while(!q.empty()) {
        n_nodes = q.size();
        for(int i = 0; i < n_nodes; i++) {
            node = q.front();
            q.pop();
            if(!visited[node]) {
                cout << node << " ";
                for(const auto elem : a[node]) {
                    q.push(elem);
                }
                visited[node] = true;
            }
        }
        cout << "\n";
    }
}

void printAdjList(vector<int> const (a)[], int n_v) {
    for(int i = 0; i < n_v; i++) {
        cout << i << " >> ";
        for(const auto node : a[i]) {
            cout << node << " ";
        }
        cout << "\n";
    }
}

void shortestPathInUnidirectedGraph(vector<int> const adj[], int source, int n_vertices) {
    vector<bool> visited(n_vertices, false);
    queue<int> q;
    q.push(source);
    vector<int> distances(n_vertices, INT_MAX);
    distances[source] = 0;
    visited[source] = true;
    int node;
    int i;
    int n;
    while(!q.empty()) {
        n = q.size();
        for(int i = 0; i < n; i++) {
            node = q.front();
            q.pop();
            for(const auto& destn : adj[node]) {
                if(!visited[destn]) {
                    visited[destn] = true;
                    distances[destn] = distances[node] + 1;
                    q.push(destn);
                }
            }
        }
    }

    cout << "\nShortest Distances from Source " << source << "\n";
    for(const auto d : distances) {
        cout << d << " ";
    } 
}

bool dfsTraversalRecursive(vector<int> adj[], vector<bool>& recStk, vector<bool>& visited, int src) {
    recStk[src] = true;
    visited[src] = true;
    for(const auto dest : adj[src]) {
        if(!visited[dest]) {
            if(dfsTraversalRecursive(adj, recStk, visited, dest)) {
                return true;
            }
        }
        if(recStk[dest]) {
            return true;
        }

    }
    recStk[src] = false;
    return false;
}

bool detectCycleInDirectedGraph(vector<int> adj[], int src, int n_vertices) {
    vector<bool> recStk(n_vertices, false);
    vector<bool> visited(n_vertices, false);

    if(dfsTraversalRecursive(adj, recStk, visited, src)) {
        return true;
    } else {
        for(int i = 0; i < n_vertices; i++) {
            if(!visited[i]) {
                if(dfsTraversalRecursive(adj, recStk, visited, i)) {
                    return true;
                }
            }
        }
    return false;
    }
}

// bool detectCycleInUndirectedGraph_dfs(const vector<int> adj[], int src, int n_vertices) {

// }


bool detectCycleInUndirectedGraph(const vector<int> adj[], int src, int n_vertices) {
    vector<bool> visited(n_vertices, false);
    vector<bool> parentOf(n_vertices, -1);
    
    queue<int> q;
    q.push(src);
    int n;
    int i;
    int node;

    while(!q.empty()) {
        n = q.size();
        for(i = 0; i < n; i++) {
            node = q.front();
            visited[node] = true;
            q.pop();
            for(const auto dest : adj[node]) {
                if(!visited[dest]) {
                    visited[dest] = true;
                    parentOf[dest] = node;
                    q.push(dest);
                } else if(parentOf[node] != dest) {
                    return true;
                }
            }
        }
    }

    return false;
}

void toplogical_sorting_bfs(const vector<int> adj[], int n_vertices) {
    vector<int> vertex_indegrees(n_vertices, 0);
    vector<bool> visited(n_vertices, false);
    queue<int> q;
    for(int i = 0; i < n_vertices; i++) {
        for(const auto dest : adj[i]) {
            vertex_indegrees[dest]++;
        }
    }
    cout << "\nindegree of vertices : ";
    for(const auto node : vertex_indegrees) {
        cout << node << " ";
    }
    auto start = find(vertex_indegrees.begin(), vertex_indegrees.end(), 0);
    while(start != vertex_indegrees.end()) {
        q.push(start - vertex_indegrees.begin());
        start = find(start + 1, vertex_indegrees.end(), 0);
    }
    int node;
    cout << "\ntopological sort of the graph : ";
    while(!q.empty()) {
        node = q.front();
        q.pop();
        cout << node << " ";
        visited[node] = true;
        for(const auto dest : adj[node]) {
            vertex_indegrees[dest]--;
            if(!visited[dest]) {
                if(!vertex_indegrees[dest]) {
                    q.push(dest);
                }
            }
        }
    }
    cout << "\n";
}

void addUndirectedWgtEdge(vector<pair<int, int>> adj_wt[], int src, int des, int wt) {
    adj_wt[src].push_back({des, wt});
    adj_wt[des].push_back({src, wt});
}

//non-optimal
int prims_algorithm(vector<pair<int, int>> adj_wt[], int n_v) {
    vector<bool> mst_set(n_v, false);
    vector<int> key(n_v, INT_MAX);
    // Always start MST at 1st vertex
    key[0] = 0;
    int src;
    int res = 0;
    for(int count = 0; count < n_v; count++) {
        src = -1;
        f
        has the index of  of the minimum value of all the non mst vertices
        res += key[src];
        mst_set[src] = true;
        for(const auto dest : adj_wt[src]) {
            if(!mst_set[dest.first]) {
                key[dest.first] = min(key[dest.first], dest.second);
            }
        }
    }
    return res;
}

int main() {
    int n; 
    // cout << "enter no. of vertices : ";
    // cin >> n;
    // vector<int> adj[n];

    // graph 1
    // addEdges(adj, {1, 2}, 0);
    // addEdges(adj, {0, 3, 4}, 1);
    // addEdges(adj, {0, 3}, 2);
    // addEdges(adj, {1, 2, 4}, 3);
    // addEdges(adj, {1, 3}, 4);
    
    // graph 2
    // n = 6;
    // addEdges(adj, {1, 2}, 0);
    // addEdges(adj, {0, 3, 4}, 1);
    // addEdges(adj, {0, 3}, 2);
    // addEdges(adj, {1, 2}, 3);
    // addEdges(adj, {1, 5}, 4);
    // addEdges(adj, {4}, 5);

    // graph 3
    // n = 5;
    // addEdges(adj, {1, 2}, 0);
    // addEdges(adj, {0, 2}, 1);
    // addEdges(adj, {0, 1}, 2);
    // addEdges(adj, {4}, 3);
    // addEdges(adj, {3}, 4);

    //graph 4
    // n = 4;
    // addEdges(adj, {1, 2}, 0);
    // addEdges(adj, {0, 2, 3}, 1);
    // addEdges(adj, {0, 1, 3}, 2);
    // addEdges(adj, {1, 2}, 3);
    // shortestPathInUnidirectedGraph(adj, 0, n);

    //graph 5
    // n = 6;
    // addEdges(adj, {1}, 0);
    // addEdges(adj, {}, 1);
    // addEdges(adj, {1, 3}, 2);
    // addEdges(adj, {4}, 3);
    // addEdges(adj, {5}, 4);
    // addEdges(adj, {3}, 5);
    // cout << (detectCycleInDirectedGraph(adj, 0, n) ? "true" : "false") << endl;

    //graph 6
    // n = 6;
    // vector<int> adj[n];
    // addUndirectesEdges(adj, 0, 1);
    // addUndirectesEdges(adj, 2, 1);
    // addUndirectesEdges(adj, 3, 2);
    // addUndirectesEdges(adj, 4, 3);
    // addUndirectesEdges(adj, 5, 4);
    // // addUndirectesEdges(adj, 3, 5);
    // cout << (detectCycleInUndirectedGraph(adj, 0, n) ? "true" : "false") << endl;

    //graph 7 - topological sort
    // n = 5;
    // vector<int> adj[n];
    // addDirectesEdges(adj, 0, 2);
    // addDirectesEdges(adj, 0, 3);
    // addDirectesEdges(adj, 1, 3);
    // addDirectesEdges(adj, 1, 4);
    // addDirectesEdges(adj, 2, 3);
    // toplogical_sorting_bfs(adj, n);

    // bfsTraversal(adj, 0, n);
    // dfsTraversal(adj, 0, n);
    // printAdjList(adj, n);

    n = 4;
    vector<pair<int, int>> adj_wt[n];
    addUndirectedWgtEdge(adj_wt, 0, 1, 5); // 0-1
    addUndirectedWgtEdge(adj_wt, 0, 2, 8); // 0-2
    addUndirectedWgtEdge(adj_wt, 1, 2, 10); // 1-2
    addUndirectedWgtEdge(adj_wt, 1, 3, 15); // 1-3
    addUndirectedWgtEdge(adj_wt, 2, 3, 20); // 2-3
    cout << prims_algorithm(adj_wt, n) << "\n";
    return 0;
}