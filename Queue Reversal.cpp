class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        int n = q.size();
        stack<int> s;
        
        while(!q.empty()){
           int ans = q.front();
            q.pop();
            s.push(ans);
        }
        
        while(!s.empty()){
           int ans = s.top();
            s.pop();
            q.push(ans);
        }
    }
};
