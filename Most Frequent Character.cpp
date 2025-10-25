class Solution {
public:
    char getMaxOccuringChar(string& s) {
        int arr[26] = {0};

        // Count frequency of each character
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i]; // making character ch for each character 
            int index = ch - 'a';   // convert char to index (0-25) as array is not from 1 to 26 its from 0 to 25
            arr[index]++;  // at each index count increases to display overall frequency of each char in the array
        }

        //maxi is the max frequency and ans is the max frequency index
        int maxi = -1, ans = 0;

        // Find index of max frequency character
        for (int i = 0; i < 26; i++) {
            if (arr[i] > maxi) {
                maxi = arr[i];  //uodates to put new maxi value of char azrray to see further if any char is greater than it or not
                ans = i;   //stores the index of the max char occurred
            }
        }

        return ans + 'a';  // convert index back to character
    }
};
