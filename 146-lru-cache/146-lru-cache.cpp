struct Node {
    Node *prev, *next;
    int key, value;
    Node(int k, int v)
    {
        key = k;
        value = v;
        prev = NULL;
        next = NULL;
    }
};
class LRUCache {
public:
    int Cachesize;
    unordered_map<int, Node*> mp;
    Node *head, *tail;
    LRUCache(int capacity) {
        Cachesize = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    void insertNode(Node *node)
    {
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
        node->prev = head;  
    }
    
    void deleteNode(Node *cur)
    {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete(cur);
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        Node *node = new Node(key, mp[key]->value);
        int value = mp[key]->value;
        deleteNode(mp[key]);
        mp[key] = node;
        insertNode(node);
        return value;
    }
    
    void put(int key, int value) {
        Node *node = new Node(key, value);
        if(mp.find(key) != mp.end())
            deleteNode(mp[key]);
        else if(mp.size() == Cachesize)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        mp[key] = node;
        insertNode(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */