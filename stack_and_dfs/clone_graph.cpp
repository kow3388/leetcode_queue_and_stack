#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int val;
        vector<Node*> neighbors;
        Node()
        {
            val = 0;
            neighbors = vector<Node*>();
        }
        Node(int _val)
        {
            val = _val;
            neighbors = vector<Node*>();
        }
        Node(int _val, vector<Node*> _neighbors)
        {
            val = _val;
            neighbors = _neighbors;
        }
};

//dfs的做法
Node* dfs(Node *node, unordered_map<Node*, Node*> &G)
{
    if(G.count(node))
        return G[node];
    
    Node *new_n = new Node(node->val);
    G.emplace(node, new_n);

    for(auto &n : node->neighbors)
        new_n->neighbors.push_back(dfs(n, G));

    return new_n;
}

Node* cloneGraph(Node *node)
{
    unordered_map<Node*, Node*> G;

    return (node == NULL)? node : dfs(node, G);
}

//bfs的做法
Node* cloneGraph1(Node *node)
{
    if(node == NULL)
        return node;
    
    Node *new_node = new Node(node->val);

    unordered_map<Node*, Node*> G;
    queue<Node*> bfs;
    G.emplace(node, new_node);
    bfs.push(node);

    while(!bfs.empty())
    {
        Node *tmp = bfs.front();
        bfs.pop();
        for(auto &n : tmp->neighbors)
        {
            if(!G.count(n))
            {
                G.emplace(n, new Node(n->val));
                bfs.push(n);
            }
            G[tmp]->neighbors.push_back(G[n]);
        }
    }

    return new_node;
}