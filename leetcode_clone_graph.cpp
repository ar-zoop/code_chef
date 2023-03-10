/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node *node,  vector<Node*>&nodeList){
        for(auto adjNode:  node->neighbors){
            if(nodeList[adjNode->val]==NULL){
                Node *newNode= new Node (adjNode->val);
                nodeList[adjNode->val]=newNode;
                ((nodeList[node->val])->neighbors).push_back(newNode);
                dfs(adjNode, nodeList);
            }
            else{
                (nodeList[node->val]->neighbors).push_back(nodeList[adjNode->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {        
        if (node==NULL) return NULL;
        vector<Node*> nodeList(101, NULL);
        // Node head(node->val);
        Node *head = new Node(node->val);
        nodeList[node->val]=head;
        for(auto adjNode: node->neighbors){
            int val= adjNode->val;
            if(nodeList[val]==NULL){
                Node *newNode= new Node(val);
                nodeList[val]= newNode;
               ( head->neighbors).push_back(newNode);
                dfs(adjNode, nodeList);
            }
            else{
                (head->neighbors).push_back(nodeList[val]);
            }
            
        }
        return head;
        
    }
};