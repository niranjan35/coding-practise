class Solution {
public:
    int dp[100];
    int rec(int n) {
        if(n==0 || n==1) {
            return 1;
        }
        if(dp[n]!=-1) {
            return dp[n];
        }
        int tmp=0;
        for(int i=1;i<=n;i++) {
            tmp+=rec(i-1)*rec(n-i);
        }
        return tmp;
    }
    int numTrees(int n) {
        memset(dp,-1,sizeof(dp));
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++) {
            int tmp=0;
            for(int j=0;j<i;j++) {
                tmp+=dp[j]*dp[i-1-j];
            }
            dp[i]=tmp;
        }
        return dp[n];
    }
};