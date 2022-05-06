class Solution {
public:
    int dp[5010][3];
    int maxProfit(vector<int>& p) {
        int n=p.size();
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++) {
            if(i>0) {
                dp[i][0]=max(dp[i-1][0],dp[i-1][2]);
                dp[i][1]=max(dp[i-1][0]-p[i], dp[i-1][1]);
                dp[i][2]=dp[i-1][1]+p[i];
            }
            else {
                dp[0][0]=0;
                dp[0][1]=-1*p[0];
                dp[0][2]=0;
            }
        }
        // for(int i=0;i<n;i++) {
        //     cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
        // }
        return max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
    }
};