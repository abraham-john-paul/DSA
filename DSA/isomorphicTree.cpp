#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

bool isIsomorphic(Node *root1,Node *root2);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s1,s2;
		getline(cin,s1);
		getline(cin,s2);
		Node* root1 = buildTree(s1);
		Node* root2 = buildTree(s2);
		if(isIsomorphic(root1,root2))
		    cout<<"Yes"<<endl;
		else
		    cout<<"No"<<endl;
    }
    return 0;
}
// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Return True if the given trees are isomotphic. Else return False.
bool isIsomorphic(Node *root1,Node *root2)
{
    if(!root1 || !root2) {
        return (!root1 && !root2);
    }
    queue<Node*> q1;
    q1.push(root1);
    Node* item1 = nullptr;
    vector<int> v1;
    
    queue<Node*> q2;
    q2.push(root2);
    Node* item2 = nullptr;
    vector<int> v2;
    
    int n;
    int i;
    while(!q1.empty() && !q2.empty()) {
        n = q1.size();
        if(n != q2.size()) {
            return false;
        }
        v1.reserve(n);
        v2.reserve(n);
        for(i = 0; i < n; i++) {
            item1 = q1.front();
            q1.pop();
            v1.push_back(item1->data);
            if(item1->left) {
                q1.push(item1->left);
            }
            if(item1->right) {
                q1.push(item1->right);
            }
            
            item2 = q2.front();
            q2.pop();
            v2.push_back(item2->data);
            if(item2->left) {
                q2.push(item2->left);
            }
            if(item2->right) {
                q2.push(item2->right);
            }
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        if(v1 != v2) {
            return false;
        }
        v1.clear();
        v2.clear();
    }
    return !(!q1.empty() || !q2.empty());
}