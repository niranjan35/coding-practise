class Solution {
public:
    long long dp[2][4];
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp,0,sizeof(dp));
        int n=nums.size();
        long long mx=INT_MIN;
        dp[0][0]=INT_MIN;
        dp[0][1]=INT_MIN;
        dp[0][2]=INT_MIN;
        dp[0][3]=nums[0];
        mx=nums[0];
        // dp[0][5]=INT_MIN;
        // cout<<dp[0][0]<<" "<<dp[0][1]<<" "<<dp[0][2]<<" "<<dp[0][3]<<endl;
        int curr=1;
        for(int i=1;i<n;i++) {
            dp[curr][0]=max(dp[1-curr][2],dp[1-curr][3]);
            if(dp[curr][0]!=INT_MIN) {
                dp[curr][0]-=nums[i];
            }
            dp[curr][1]=max(dp[1-curr][0],dp[1-curr][1]);
            dp[curr][2]=max(dp[1-curr][2],dp[1-curr][3]);
            dp[curr][3]=max(dp[1-curr][0],dp[1-curr][1]);
            if(dp[curr][3]!=INT_MIN) {
                dp[curr][3]+=nums[i];
            }
            if(dp[curr][3]<(nums[i])) {
                dp[curr][3]=nums[i];
            }
            
            mx=max(mx,dp[curr][0]);
            mx=max(mx,dp[curr][1]);
            mx=max(mx,dp[curr][2]);
            mx=max(mx,dp[curr][3]);
            // cout<<dp[curr][0]<<" "<<dp[curr][1]<<" "<<dp[curr][2]<<" "<<dp[curr][3]<<endl;
            curr=1-curr;
        }
        return mx;
    }
};