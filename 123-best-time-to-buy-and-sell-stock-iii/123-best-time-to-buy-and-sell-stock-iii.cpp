class Solution {
public:
    int dp[100100][5];
    int maxProfit(vector<int>& p) {
        for(int i=0;i<100100;i++) {
            for(int j=0;j<5;j++) {
                dp[i][j]=INT_MIN;
            }
        }
        int n=p.size();
        dp[1][0]=0;
        dp[1][1]=-1*p[0];
        for(int i=2;i<=n;i++) {
            dp[i][0]=0;
            for(int j=1;j<5;j++) {
                dp[i][j]=dp[i-1][j];
                if(dp[i-1][j-1]!=INT_MIN) {
                    if(j==1 || j==3) {
                        dp[i][j]=max(dp[i][j], dp[i-1][j-1]-p[i-1]);
                    }
                    else {
                        dp[i][j]=max(dp[i][j], dp[i-1][j-1]+p[i-1]);
                    }
                }
            }
            // dp[i][1]=max(dp[i-1][0]-p[i-1],dp[i-1][1]);
            // dp[i][2]=max(dp[i-1][1]+p[i-1],dp[i-1][2]);
            // dp[i][3]=max(dp[i-1][2]-p[i-1],dp[i-1][3]);
            // dp[i][4]=max(dp[i-1][3]+p[i-1],dp[i-1][4]);
        }
        int mx=0;
        // for(int x=1;x<=n;x++) {
        //     for(int i=0;i<5;i++) {
        //         cout<<dp[x][i]<<" ";
        //     }
        //     cout<<""<<endl;
        // }
        for(int i=0;i<5;i++) {
            mx=max(mx,dp[n][i]);
        }
        return mx;
    }
};