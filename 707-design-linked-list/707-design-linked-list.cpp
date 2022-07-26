class Node{
public:
    int val ; 
    Node* next;
    
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
class MyLinkedList {
public:
    Node* head;
    int size;
    MyLinkedList() {
      head = NULL;
      size = 0;
    }
    
    int get(int index) {
        if(index >= size)
            return -1;
        
        Node* curr = head;
        for(int i = 0;i<index;i++)
            curr = curr->next;
        
        return curr->val;
    }
    
    void addAtHead(int val) {
        size++;
        if(!head){
            head = new Node(val);
        }
        else{
            Node* temp = head;
            head = new Node(val);
            head->next = temp;
        }
    }
    
    void addAtTail(int val) {
        if(!head)
            return addAtHead(val);
        size++;
        Node* curr = head;
        while(curr->next)
            curr = curr->next;
        
        curr->next = new Node(val);
    }
    
    void addAtIndex(int index, int val) {
        if(index > size)
            return;
        if(index == size)
            return addAtTail(val);
        if(index == 0)
            return addAtHead(val);
        size++;
        Node* curr = head;
        for(int i = 0;i<index - 1;i++)
            curr = curr->next;
        
        Node* newNode = new Node(val);
        newNode->next = curr->next;
        curr->next = newNode;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size)
            return;
        
        size--;
        if(index == 0){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        
        Node* curr = head;
        for(int i = 0;i<index - 1;i++){
            curr = curr->next;
        }
        
        Node* temp = curr->next;
        curr->next = temp->next;
        temp->next = NULL;
        
        delete temp;
    }
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */