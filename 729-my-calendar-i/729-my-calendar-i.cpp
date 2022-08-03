class LinkedList{
  public:
    int start;
    int end;
    LinkedList* next;
    // LinkedList* prev;
    LinkedList(int start, int end){
        this->start = start;
        this->end = end;
        this->next = nullptr;
    }
};
class MyCalendar {
public:
    LinkedList* head;
    int size = 0;
    MyCalendar() {
        head = new LinkedList(-1, -1);
    }
    
    bool book(int start, int end) {
      if(size == 0){
          LinkedList* newBook = new LinkedList(start, end);
          head->next = newBook;
          size++;
          return true;          
      }else{
          LinkedList* curr = head->next, *prev = head;
          while(curr && curr->start <= start){
              prev = curr;
              curr = curr->next;
          }
          
          if(!curr){
              if(prev->end > start)
                  return false;
              else{
                  prev->next = new LinkedList(start, end);
                  size++;
                  return true;
              }
          }
          else{
              if(start >= prev->end  && end <= curr->start){
                  LinkedList* newBook = new LinkedList(start, end);
                  newBook->next = prev->next;
                  prev->next = newBook;
                  size++;
                  return true;
              }else{
                  return false;
              }
          }
      }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */