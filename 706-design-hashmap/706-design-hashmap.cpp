class Node{
  public:
    int key;
    int val;
    Node* next;
    
    Node(int key, int val){
        this->key = key;
        this->val = val;
        this->next = NULL;
    }
};
class MyHashMap {
public:
    vector<Node*> buckets;
    MyHashMap() {
        buckets = vector<Node*>(10000, new Node(-1,-1));
    }
    
    void put(int key, int value) {
        Node* prev = find(key);
        if(prev && prev->next){
            prev->next->val = value;
        }else{
            prev->next = new Node(key, value);
        }
    }
    
    int get(int key) {
        Node* prev = find(key);
        if(prev && prev->next){
            return prev->next->val;
        }
        
        return -1;
    }
    
    void remove(int key) {
        Node* prev = find(key);
        if(prev && prev->next){
            Node* next = prev->next;
            prev->next = next->next;
            next->next = NULL;
            delete next;
        }
        
    }
    Node* find(int key){
        int idx = findIndex(key);
        Node* curr = buckets[idx] , *prev = NULL;
        
        while(curr && curr->key != key){
            prev = curr;
            curr = curr->next;
        }
        
        return prev;
    }
    
    int findIndex(int key){
        return key%10000;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */