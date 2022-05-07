class Solution {
public:
    int dp[1010][230][2];
    int maxProfit(int k, vector<int>& p) {
        int n=p.size();
        for(int i=0;i<=n+2;i++) {
            for(int j=0;j<=k+2;j++) {
                dp[i][j][0]=INT_MIN;
                dp[i][j][1]=INT_MIN;
            }
        }
        if(n==0 || k==0) {
            return 0;
        }
        dp[1][0][0]=0;
        dp[1][0][1]=-1*p[0];
        int mx=INT_MIN;
        for(int i=2;i<=n;i++) {
            for(int j=0;j<=k;j++) {
                dp[i][j][0]=dp[i-1][j][0];
                dp[i][j][1]=dp[i-1][j][1];
                if(j>0) {
                    if(dp[i-1][j-1][1]!=INT_MIN) {
                        dp[i][j][0]=max(dp[i-1][j-1][1]+p[i-1],dp[i][j][0]);
                    }
                }
                if(dp[i-1][j][0]!=INT_MIN) {
                    dp[i][j][1]=max(dp[i][j][1], dp[i-1][j][0]-p[i-1]);
                }
                // cout<<p[i-1]<<endl;
                // cout<<"i = "<<i<<" j = "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
                if(mx<dp[i][j][0]) {
                    mx=dp[i][j][0];
                }
                if(mx<dp[i][j][1]) {
                    mx=dp[i][j][1];
                }
            }
        }
        mx=max(mx,0);
        return mx;
    }
};