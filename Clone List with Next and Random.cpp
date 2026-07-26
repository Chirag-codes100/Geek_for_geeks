/*
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    
  private:
  
  void iat(Node* &head, Node* &tail, int data){
      
      Node* temp = new Node(data);
      
      if(head == NULL){
          head = temp;
          tail = temp;
      }
      else{
          tail -> next = temp;
          tail = temp;
      }
      
      
  }
  
  
   public:
  
  //appoach 3: By changing the links so space complexity big of 1 o(1)
  
    Node* cloneLinkedList(Node* head) {
       
        //step1 1: clone list 
        Node* clonehead = NULL;
        Node* clonetail = NULL;
        
        Node* temp = head;
        while(temp != NULL){
            iat(clonehead,clonetail,temp->data);
            temp = temp -> next;
        }
        
        //step 2: inserting clone nodes btw the original nodes
        
        temp = head;
        Node* temp2 = clonehead;
        
        
        /*
        Node* fwd = temp;
        Node* clfwd = temp2;
        
        while(temp != NULL){
            fwd = temp -> next;
            clfwd = temp2 -> next;
            temp -> next = temp2;
            temp2 -> next = fwd;
            
            temp = fwd;
            temp2 = clfwd;
            
        }
        
        OR 
        
        */
        
        while(temp != NULL && temp2 != NULL){
            Node* fwd = temp -> next;
            temp -> next = temp2;
            temp = fwd;
            
            fwd = temp2 -> next;
            temp2 -> next = temp;
            temp2 = fwd;
        }
        
        temp = head;
        
        while(temp != NULL){
           
            temp -> next -> random = temp -> random ?  temp -> random -> next : temp -> random;
                temp = temp -> next -> next;
            
        }
        
        //step 4: reversting the original changes
        
        
        temp = head;
        temp2 = clonehead;
     
        
        while(temp != NULL && temp2 != NULL){
            
            temp -> next = temp2 -> next;
            temp = temp -> next;
            
            if(temp != NULL){
            temp2 -> next = temp -> next;
            }
            else{
                temp2 -> next = NULL;
            }
            temp2 = temp2 -> next;
            
            
        }
        
        //step 5  : returning the answer list
         
        return clonehead;
     
        
    }
};

  
//   public:
  
  /*approach 2: uses hashmap so n space complexity
  
  
  
    Node* cloneLinkedList(Node* head) {
        // code here
        
        
        //step 1: creating the clone linkedlist with original list
        
        Node* clonehead = NULL;
        Node* clonetail = NULL;
        
        Node* temp = head;
        while(temp != NULL){
            iat(clonehead, clonetail, temp -> data);
            temp = temp -> next;
        }
        
        
        unordered_map<Node*,Node*> oldtonew;
        
        Node* OriginalNode = head;
        Node* CloneNode = clonehead;
        
        while(OriginalNode != NULL && CloneNode != NULL){
            oldtonew[OriginalNode] = CloneNode;
            OriginalNode = OriginalNode -> next;
            CloneNode = CloneNode -> next;
        }
        
        OriginalNode = head;
        CloneNode = clonehead;
        while(OriginalNode != NULL){
            CloneNode -> random = oldtonew[OriginalNode -> random];
            OriginalNode = OriginalNode -> next;
            CloneNode = CloneNode -> next;
        }
        
        
        return clonehead;
    }
};

  
  
  //approach 2: uses hashmap so big of n space complexity 
//   public:
  
  
//     Node* cloneLinkedList(Node* head) {
//         // code here
        
        
//         //step 1: creating the clone linkedlist with original list
        
//         Node* clonehead = NULL;
//         Node* clonetail = NULL;
        
//         Node* temp = head;
//         while(temp != NULL){
//             iat(clonehead, clonetail, temp -> data);
//             temp = temp -> next;
//         }
        
        
//         unordered_map<Node*,Node*> oldtonew;
        
//         Node* OriginalNode = head;
//         Node* CloneNode = clonehead;
        
//         while(OriginalNode != NULL && CloneNode != NULL){
//             oldtonew[OriginalNode] = CloneNode;
//             OriginalNode = OriginalNode -> next;
//             CloneNode = CloneNode -> next;
//         }
        
//         OriginalNode = head;
//         CloneNode = clonehead;
//         while(OriginalNode != NULL){
//             CloneNode -> random = oldtonew[OriginalNode -> random];
//             OriginalNode = OriginalNode -> next;
//             CloneNode = CloneNode -> next;
//         }
        
        
//         return clonehead;
//     }
// };



//BRUTE FORCE
// class Solution {
    
//     private:
    
//     void insertattail(Node* &head, Node* &tail, int data){
//         Node* temp = new Node(data);
//         if(head == NULL){
//             head = temp;
//             tail = temp;
//         }
//         else{
//             tail -> next = temp;
//             tail = temp;
//         }
        
//     }
    
    
//   public:
//     Node* cloneLinkedList(Node* head) {
//         // code here
//         Node* clonehead = NULL;
//         Node* clonetail = NULL;
        
//         Node* temp = head;
//         while(temp != NULL){
//             insertattail(clonehead, clonetail, temp -> data);
//             temp = temp -> next;
//         }
        
//         temp = head;
//         Node* temp2 = clonehead;
        
        
//         while(temp != NULL){
            
             
//         if(temp -> random == NULL){
//             temp2 -> random = NULL;
//         }
//         else{
            
//             Node* ptr1 = head;
//             Node* ptr2 = clonehead;
            
//             while(temp -> random != ptr1 ){
//                 ptr1 = ptr1 -> next;
//                 ptr2 = ptr2 -> next;
//             }
            
//             temp2 -> random = ptr2;
//         }
//           temp = temp -> next;
//           temp2 = temp2 -> next;
//         }
//         return clonehead;
//     }
// };
*/
