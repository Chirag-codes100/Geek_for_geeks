class Solution {
    
    private:
    bool ifSafe(vector<vector<int>>& maze, vector<vector<int>> visited, int x, int y,int n){
        //3 conditions - x is within boundary and y is within boundary and visited array is 0 and maze value at that point is 1
        if((x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y] == 0) && (maze[x][y] == 1)){
            return true;
        }
        else{
            return false;
        }
    }
    
    
    void solve(int x, int y, vector<vector<int>> maze, vector<vector<int>> visited, vector<string>& ans, string path, int n){
        //base case
        if(x == n-1 && y == n-1){ //if the coordinates of destination are achieved 
            ans.push_back(path);
            return ;
        }
        
        visited[x][y] = 1; //mark visited as 1 as we move forward
        
        //up
        int newx = x-1; // the value of new x and y keep chainging depending upon the direction we are choosing
        int newy = y;
        if(ifSafe(maze,visited,newx,newy,n)){ //check each time if satisifes the 3 conditions
        path.push_back('U');
        solve(newx,newy,maze,visited,ans,path,n); //recursion function call
        path.pop_back(); 
        }
        
        //down
        newx = x+1;
        newy = y;
        if(ifSafe(maze,visited,newx,newy,n)){
        path.push_back('D');
        solve(newx,newy,maze,visited,ans,path,n);
        path.pop_back();
        }
        
        //right
        newx = x;
        newy = y+1;
        if(ifSafe(maze,visited,newx,newy,n)){
        path.push_back('R');
        solve(newx,newy,maze,visited,ans,path,n);
        path.pop_back();
            }
        
        //left
        newx = x;
        newy = y-1;
        if(ifSafe(maze,visited,newx,newy,n)){
        path.push_back('L');
        solve(newx,newy,maze,visited,ans,path,n);
        path.pop_back();
           }
        
        //again make the visited array as 0
        visited[x][y] = 0;
    }
    
    
    
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        
        vector<string> ans;
        if(maze[0][0] == 0){ /*to check if the rat is present at the source 
        position and is allowed there otherwise no entry means no movving towards the 
        final destination which will lead tot the possible path as 0
        */
        
        return ans;
        }
        
        int n = maze.size();
        int srcx = 0;
        int srcy = 0; //putting soruce destination as 0,0
        string path = "";
        vector<vector<int>> visited = maze;
        for(int i = 0; i < n; i++){         //creating a visiting 2D array with all element as 0
            for(int j = 0 ; j < n; j++){
                visited[i][j] = 0;
            }
        }
        
        solve(srcx,srcy,maze,visited,ans,path,n);
        sort(ans.begin(),ans.end());
        return ans;
        
        
    }
};
