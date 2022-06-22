class Solution {
public:
    double dp[110][110];
    int sum[110];
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<k;j++) {
                dp[i][j]=0;
            }
        }
        for(int i=0;i<n;i++) {
            if(i==0) {
                sum[i]=nums[i];
            }
            else {
                sum[i]=sum[i-1]+nums[i];
            }
        }
        for(int i=0;i<n;i++) {
            dp[i][0]=sum[i];
            dp[i][0]/=(i+1);
        }
        for(int x=1;x<k;x++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<i;j++) {
                    double tmp=sum[i]-sum[j];
                    tmp/=(i-j);
                    dp[i][x]=max(dp[i][x],dp[j][x-1]+tmp);
                }
            }
        }
        // for(int i=0;i<k;i++) {
        //     for(int j=0;j<n;j++) {
        //         cout<<dp[j][i]<<" ";
        //     }
        //     cout<<""<<endl;
        // }
        return dp[n-1][k-1];
    }
};