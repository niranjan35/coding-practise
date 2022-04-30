class Solution {
public:
    int dp[310];
    
    int rec(vector<int> nums, int s, int e) {
        memset(dp,0,sizeof(dp));
        int n=nums.size();
        for(int i=s;i<=e;i++) {
            dp[i]=nums[i];
            if(i-2>=s) {
                dp[i]=nums[i]+dp[i-2];
            }
            if(i-1>=s) {
                dp[i]=max(dp[i],dp[i-1]);
            }
        }
        return dp[e];
    }
    
    int rob(vector<int>& arr) {
        int n=arr.size();
        if(arr.size()==1) {
            return arr[0]>=0?arr[0]:0;
        }
        if(arr.size()==2) {
            return max(arr[0],arr[1]);
        }
        memset(dp,-1,sizeof(dp));
        return max(rec(arr,0,arr.size()-2), rec(arr,1,arr.size()-1));
    }
};