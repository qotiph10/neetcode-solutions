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
    map<int , bool> visted;
    map<int, Node*> memory;
    Node* dfs(Node* node){

        Node *newNode = new Node(node->val);
        visted[node->val] = true;
        memory[node->val] = newNode;
        if(node->neighbors.size()){
            for(auto i: node->neighbors){
                if(!visted[i->val]){
                    newNode->neighbors.push_back(dfs(i));
                }
                else{
                    newNode->neighbors.push_back(memory[i->val]);
                }
            }
        }

        return newNode;
    }
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        if(!node->neighbors.size()){
            Node *temp = new Node(node->val);
            return temp;
        }

        Node *newNode = dfs(node);

        return newNode;
    }
};
