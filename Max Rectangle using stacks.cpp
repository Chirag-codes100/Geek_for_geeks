class Solution {
  public:
  
    vector<int> prev_smallest_element(vector<int> &heights, int n){
        
        stack<int> s;
        vector<int> ans(n);
        s.push(-1);
        
        for(int i = 0; i < n; i++){
            int current = heights[i];
            
            while(s.top() != -1 && heights[s.top()] >= current){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
     vector<int> next_smallest_element(vector<int> &heights, int n){
    
        
        stack<int> s;
        vector<int> ans(n);
        s.push(-1);
        
        for(int i = n-1; i >= 0 ; i--){
            int current = heights[i];
            
            while(s.top() != -1 && heights[s.top()] >= current){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    int largest_rectangle(vector<int> &heights, int n){
        

        
        vector<int> left = prev_smallest_element(heights,n);
        vector<int> right = next_smallest_element(heights,n);
        
        int maxArea = 0;
        
        for(int i = 0; i < n; i++){
            
            if(right[i] == -1) {
                right[i] = n;
            }
            
            int width = right[i] - left[i] - 1;
            
            int length = heights[i];
            
            int area = length * width;
            
            maxArea = max(area, maxArea);
            
        }
        return maxArea;
    }
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int rows = mat.size();
        int col = mat[0].size();
        
        // int maximum = 0;
        int maximum = largest_rectangle(mat[0],col);
        
        // vector<int> heights(col, 0);
        
       
                
        //         if(mat[i][j] == 1){
        //             heights[j]++;
        //         }
        //         else{
        //             heights[j] = 0;
        //         }
        //     }
         for( int i = 1 ;  i < rows; i++){
            
     for(int j = 0 ; j < col ; j++){
         
        if(mat[i][j] != 0)
            mat[i][j] = mat[i][j] + mat[i-1][j];
        else
            mat[i][j] = 0;
    }
            maximum = max(maximum , largest_rectangle(mat[i],col));
        }
        
        return maximum;
        
    }
};
