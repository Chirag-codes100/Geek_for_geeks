class Solution {
  public:
  
    char getMaxOccuringChar(string& s) {
        //  code here
        int arr[26] = {0}; //fill array to store count with 0s 
        
        for(int i = 0; i<s.length(); i++){ //traverse the string to count each string occurences
            int temp = -1; //this points to the character which have been found acc to number to increment in the array  
            if(s[i] >= 'a' && s[i] <= 'z'){ //in case of lowercase
                temp = s[i] - 'a';
            }
            else{ //in case of uppercase 
                temp = s[i] - 'A';
            }
            arr[temp]++; //count of that character in the array of 0 = a to 25 = z increases
        }
        
        int maxim = INT_MIN; //maximum occurence of the character
        int ans = 0; //index of maximum occuring char
        
        for(int i = 0; i<26; i++){ //incrementing the array of numbers that represent the charcter alphabects from 0 to 25 i.e a to z
            if(maxim < arr[i]){ //if the count of the prev element less than next elemtn 
                ans = i; //store its index in ans
                maxim = arr[i]; //update maxi value to that element for further checking
            }
        }
        return ans + 'a'; //returning index + alphabect in order to return the actual maximum occuring character.
        
        
    }
};
