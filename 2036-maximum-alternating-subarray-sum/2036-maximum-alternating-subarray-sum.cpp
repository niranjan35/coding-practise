class Solution {
public:
    long long dp[3][2];
    long long maximumAlternatingSubarraySum(vector<int>& nums) {
        memset(dp,0,sizeof(dp));
        int n=nums.size();
        long long mx=INT_MIN;
        int curr=0;
        for(int i=0;i<n;i++) {
            if(i==0) {
                dp[curr][0]=INT_MIN;
                dp[curr][1]=nums[i];
            }
            else if(i>0) {
                if(dp[1-curr][1]!=INT_MIN) {
                    dp[curr][0]=dp[1-curr][1]-nums[i];
                }
                else {
                    dp[curr][0]=INT_MIN;
                }
                
                if(dp[1-curr][0]!=INT_MIN) {
                    dp[curr][1]=max(dp[1-curr][0]+nums[i],nums[i]);
                }
                else {
                    dp[curr][1]=max(INT_MIN,nums[i]);
                }
            }
            // cout<<dp[curr][0]<<" "<<dp[curr][1]<<endl;
            mx=max(mx,dp[curr][0]);
            mx=max(mx,dp[curr][1]);
            curr=1-curr;
        }
        return mx;
    }
    
    long long max(long long x, long long y) {
        return x>y?x:y;
    }
};