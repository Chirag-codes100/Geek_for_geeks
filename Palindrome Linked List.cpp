/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = nullptr;
    }
};*/


class Solution {
    
private: 

Node* getMid(Node* head){ //getting middle element via fast and slow pointer
    Node* slow = head;
    Node* fast = head -> next; //fast is head next to find correct middle in even ll too
    
    while(fast != NULL && fast -> next != NULL){
    
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    return slow;
}

Node* reverse(Node* head){ //getting reversed linked list head element which will be prev
    Node* curr = head;
    Node* prev = NULL;
    Node* fwd = NULL;
    
    while(curr != NULL){
        fwd = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = fwd;
    }
    
    return prev;
}

 
  public:
    bool isPalindrome(Node *head) {

      //in case the list is empty or has only one element 
        if(head == NULL || head -> next == NULL){
            return true;
        }


      //step 1 - getting the middle element
        Node* middle = getMid(head);

      //step 2 - reversing the list from the point we found middle next
        Node* temp = middle -> next;
        middle -> next  = reverse(temp);

      //step 3 comparing both of the ll
        Node* head2 = middle -> next;
        Node* head1 = head;
        
        while(head2 != NULL){
            if(head1 -> data != head2 -> data){
                return false;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }


      //step 4 - to repeat step 2 to make it the original ll
        temp = middle -> next;
        middle -> next = reverse(temp);
        return true;
        
    }
};


// #include <vector>

// class Solution {
    
//   private:
//   bool checkPalindrome(vector<int> arr){
//       int n = arr.size();
//       int s = 0;
//       int e = n-1;
//       while(s <= e){
//           if(arr[s] != arr[e]){
//               return false;
//           }
//           s++;
//           e--;
//       }
      
//       return true;
//   }
  
//   public:
//     bool isPalindrome(Node *head) {
        
//         //approachh 1

//     vector<int> arr;
//     Node* temp = head;
    
//     while(temp != NULL){
//         arr.push_back(temp -> data);
//         temp = temp -> next;
//     }
    
//     return checkPalindrome(arr);
        
//     }
// };
