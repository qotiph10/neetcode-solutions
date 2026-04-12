class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    std::unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;
    int capacity;
    
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
public:
    LRUCache(int cap) : capacity(cap) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        
        Node* node = mp[key];
        remove(node);
        addToFront(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            mp[key]->val = value;
            remove(mp[key]);
            addToFront(mp[key]);
            return;
        }
        
        if(mp.size() == capacity) {
            Node* lru = tail->prev;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
        
        Node* newNode = new Node(key, value);
        mp[key] = newNode;
        addToFront(newNode);
    }
};