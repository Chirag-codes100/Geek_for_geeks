class Solution {
  private:
  
  bool knows(vector<vector<int>>& mat, int a, int b, int n){
      if(mat[a][b] == 1){
          return true;
      }
      else{
          return false;
      }
  }
  public:
    int celebrity(vector<vector<int>>& mat) {
        
        //step 1: push all elements in the stack
        
        stack<int> s;
        int n = mat.size();
        
        for(int i = 0; i < n; i++){
            s.push(i);
        }
        
        //step 2: take two element out to check
        
        while(s.size() > 1){
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(mat,a,b,n)){
                s.push(b);
            }
            else{
                s.push(a);
            }
            
        }
        
        //step 3 : verify the potential found is celeb or not
        
        int zeros_count = 0;
        
        int potential_celeb = s.top();
        
        //if i != celeb is imp for 0 and 1 both 
        
        for(int i = 0; i < n; i++){
            if(i != potential_celeb && mat[potential_celeb][i] == 0){
                zeros_count++;
            }
        }
        
        if(zeros_count != n-1){
            return -1;
        }
        
        int one_count = 0;
        
        for(int i = 0; i < n; i++){
            if(i != potential_celeb && mat[i][potential_celeb] == 1){
                one_count++;
            }
        }
        
        if(one_count != n-1){
            return -1;
        }
        
        return potential_celeb;
        
    }
};
