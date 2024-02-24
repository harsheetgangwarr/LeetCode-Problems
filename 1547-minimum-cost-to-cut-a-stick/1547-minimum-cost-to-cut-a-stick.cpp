
class Solution {
public: 
     int f(int i, int j, vector<int>& cuts,vector<vector<int>> &dp) {
          if(j-i<=1)
              return 0;

              if(dp[i][j]!=-1)
              return dp[i][j];

          int mini = 1e9;
          
          for(int k = i+1; k < j; k++){
             int ans = cuts[j]-cuts[i] + f(i, k, cuts,dp) + 
                       f(k , j, cuts,dp);
             mini = min(ans, mini);
          }
          return dp[i][j]= mini;
    }
    int minCost(int n, vector<int>& cuts) {

        cuts.push_back(0); // Add 0 and n to cuts
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end()); // Sort cuts
        
         int m = cuts.size();
        
        // Initialize a memoization table with -1
        vector<vector<int>> dp(m, vector<int>(m, -1));
        
        return f(0, m - 1, cuts, dp);
    }
};
