/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
    
  private:
  Node* reversell(Node* head){
      Node* current = head;
      Node* fwd = NULL;
      Node* prev = NULL;
      
      while(current != NULL){
          fwd = current -> next;
          current -> next = prev;
          prev = current;
          current = fwd;
      }
      
      return prev;
  }
  
  
  void insertattail(Node* &head,Node* &tail, int value){
      
      Node* temp = new Node(value);
      
      //if empty list
      if(head == NULL){
          head = temp;
          tail = temp;
          return ;
      }
      
      //if not empty
      else{
          tail -> next = temp;
          tail = temp;
          
      }
  }
  
  Node* sum(Node* head1, Node* head2){
      
      
      
      int carry = 0;
        
        Node* anshead = NULL;
        Node* anstail = NULL;
        
        while(head1 != NULL || head2 != NULL || carry != 0){
            
            int val1 = 0;
            if(head1 != NULL){
                val1 = head1 -> data;
            }
            
            int val2 = 0;
            if(head2 != NULL){
                val2 = head2 -> data;
            }
            
            int sum = carry + val1 + val2;
            
            int digit = sum % 10;
            
            insertattail(anshead, anstail, digit);
            
            carry = sum / 10;
            
            if(head1 != NULL){
                head1 = head1 -> next;
            }
            
            if(head2 != NULL){
                head2 = head2 -> next;
            }
            
            
        }
        
        return anshead;
  }
  
  
  public:
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        
        //reversing the linked list
        head1 = reversell(head1);
        head2 = reversell(head2);
        
        
        //adding them to find the sum
        Node* ans = sum(head1 , head2);
        
        //reversing the final ans 
        ans = reversell(ans);
        
        //removing the leading zeroes 
        while (ans != NULL && ans->data == 0 && ans->next != NULL) {
         ans = ans->next;
        }
        
        
        
        return ans;
        
    }
};
