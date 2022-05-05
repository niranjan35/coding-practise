class Solution {
public:
    int dp[30010][2];
    int maxProfit(vector<int>& p) {
        memset(dp,0,sizeof(dp));
        int n=p.size();
        for(int i=0;i<n;i++) {
            if(i>0) {
                dp[i][0]=max(dp[i-1][0],dp[i-1][1]+p[i]);
                dp[i][1]=max(dp[i-1][0]-p[i],dp[i-1][1]);
            }
            else {
                dp[i][0]=0;
                dp[i][1]=-1*p[i];
            }
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};