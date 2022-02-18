class Solution {
public:
    int dp[500];
    int rob(vector<int>& nums) {
        memset(dp,0,sizeof(dp));
        int n=nums.size();
        for(int i=0;i<n;i++) {
            dp[i]=nums[i];
            if(i-2>=0) {
                dp[i]=nums[i]+dp[i-2];
            }
            if(i-1>=0) {
                dp[i]=max(dp[i],dp[i-1]);
            }
        }
        return dp[n-1];
    }
};