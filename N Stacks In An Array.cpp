#include <bits/stdc++.h> 
class NStack
{
    int *arr; //actual array
    int *top; //aray with index of top elemnt of stack
    int *next;

    int n,s; // n = no of stack , s = no of element in the stack or array size

    int freespot;
    
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        //intialising the top

        for(int i = 0;  i < n ; i++){
            top[i] = -1;
        }


        //initialsing the next array 

        for(int i = 0; i < s; i++){
            next[i] = i+1;
        }

        //upating last value of the next array to -1
        next[s-1] = -1;

        //intiitalizing the freespot variable
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //check for overflow

        if(freespot == -1){
            return false;
        }
        
        //initialize index
        int index = freespot;


        //update freespot
        freespot = next[index];

        //push the element in the array
        arr[index] = x;

        //update next element with the index of the top element
        next[index] = top[m-1];

        //update top value with the index which will be equivalent to the stack the element is operated
        top[m-1] = index;

        //top[m-1] is due to indexing where m is the stack number on which the operation is performed and we do -1 to make it accoringly the exact number

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        //check for underflow

        if(top[m-1] == -1){
            return -1;
        }

        //note the index of the top element so that we know which element is to be removed or released
        int index = top[m-1];

        //stepping down the position of the top element one step down towards the next index
        top[m-1] = next[index];

        //connnect the removed position to free list
        next[index] = freespot;

        //making the released position first free position
        freespot = index;

        //return the pooppped element
        return arr[index];


    }
};
