class Solution {
public:
    int dp[20010][2];
    int deleteAndEarn(vector<int>& nums) {
        memset(dp,0,sizeof(dp));
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int prev=-10;
        for(int i=0;i<n;i++) {
            if(i>0 && nums[i]!=nums[i-1]) {
                prev=nums[i-1];
            }
            if(i>0) {
                if(nums[i]==prev+1) {
                    if(nums[i]==nums[i-1]) {
                        dp[i][0]=dp[i-1][0];
                        dp[i][1]=max(dp[i-1][0],dp[i-1][1]) + nums[i];
                    }
                    else {
                        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
                        dp[i][1]=dp[i-1][0]+nums[i];
                    }
                }
                else {
                    dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
                    dp[i][1]=max(dp[i-1][0],dp[i-1][1]) + nums[i];
                }
                if(nums[i]==nums[i-1]) {
                    dp[i][0]=dp[i-1][0];
                    dp[i][1]=dp[i-1][1]+nums[i];
                }
            }
            else {
                dp[i][0]=0;
                dp[i][1]=nums[i];
            }
        }
        // for(int i=0;i<n;i++) {
        //     cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
        // }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};