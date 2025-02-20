class Solution {
  public:
  void helper(vector<vector<int>> &mat, int r, int c, vector<string> &ans, string path){
      int n=mat.size();
      //base case
      
      if(r<0 || c<0 || r>=n || c>=n || mat[r][c] == 0 || mat[r][c] == -1){
          return;
      }
      if(r==n-1 && c==n-1){
          ans.push_back(path);
          return;
      }
      
      mat[r][c]=-1;                    //VISIT
      
      helper(mat, r,c-1,ans,path + "L");//left
      helper(mat, r,c+1,ans,path + "R");//right
      helper(mat, r-1,c,ans,path + "U");//up
      helper(mat, r+1,c,ans,path + "D");//down
      
      mat[r][c]=1;                    //UNVISIT           //BACKTRACK
  }
  
  
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        vector<string> ans;
        string path="";
        
        
        helper(mat, 0, 0, ans, path);
        return ans;
    }
};
