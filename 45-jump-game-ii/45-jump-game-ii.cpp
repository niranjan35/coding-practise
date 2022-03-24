class Solution {
public:
    int dp[100030];
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        dp[0]=0;
        for(int i=0;i<n;i++) {
            for(int r=1;r<=nums[i];r++) {
                // cout<<"i = "<<i<<" r = "<<r<<endl;
                if(i+r<n && (dp[i+r]==-1 || dp[i+r]>dp[i]+1)) {
                    // cout<<"enter "<<dp[i]+1<<endl;
                    dp[i+r]=dp[i]+1;
                }
            }
        }
        return dp[n-1];
    }
};