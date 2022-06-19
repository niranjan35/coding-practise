class Solution {
public:
    int dp[110][110];
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        for(int i=0;i<110;i++) {
            for(int j=0;j<110;j++) {
                dp[i][j]=0;
            }
        }
        dp[0][0]=1;
        if(arr[0][0]==1) {
            return 0;
        }
        int m=arr.size();
        int n=arr[0].size();
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(!arr[i][j]) {
                    if(i-1>=0) {
                        dp[i][j]+=dp[i-1][j];
                    }
                    if(j-1>=0) {
                        dp[i][j]+=dp[i][j-1];
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
};