class DoublyLinkedList{
    int key, val;
    DoublyLinkedList next;
    DoublyLinkedList prev;

    DoublyLinkedList(int key, int val){
        this.key = key;
        this.val = val;
    }
}
public class LRUCache {
    DoublyLinkedList head;
    DoublyLinkedList tail;
    int capacity;
    HashMap<Integer, DoublyLinkedList> hashMap;
    public LRUCache(int capacity) {
        head = new DoublyLinkedList(-1 , -1);
        tail = new DoublyLinkedList(-1, -1);
        this.capacity = capacity;
        head.next = tail;
        tail.prev = head;

        hashMap = new HashMap<>();

    }

    public int get(int key) {
        if(hashMap.containsKey(key)){
            DoublyLinkedList node = hashMap.get(key);
            remove(node);
            insert(node);

            return node.val;
        }
            return -1;
    }

    public void remove(DoublyLinkedList node){
        node.prev.next = node.next;
        node.next.prev = node.prev;
        hashMap.remove(node.key);
    }

    public void insert(DoublyLinkedList node){
        hashMap.put(node.key , node);
        head.next.prev = node;
        node.next = head.next;

        head.next = node;
        node.prev = head;
    }

    public void put(int key, int value) {
        if(hashMap.containsKey(key)){
            remove(hashMap.get(key));
        }

        if(hashMap.size() == capacity){
            remove(tail.prev);
        }

        insert(new DoublyLinkedList(key, value));
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */