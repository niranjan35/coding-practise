class Solution {
public:
    int dp[1020];
    int mod=1000000007;
    int numFactoredBinaryTrees(vector<int>& arr) {
        memset(dp,0,sizeof(dp));
        sort(arr.begin(),arr.end());
        map<int,int> mp;
        int n=arr.size();
        for(int i=0;i<n;i++) {
            mp[arr[i]]=i+1;
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<i;j++) {
                // cout<<arr[i-1]<<" "<<arr[j-1]<<endl;
                if(arr[i-1]%arr[j-1]==0) {
                    // cout<<"entered"<<endl;
                    int k=mp[arr[i-1]/arr[j-1]];
                    // cout<<"k = "<<k<<endl;
                    if(k>0) {
                        long long int tmp=dp[j];
                        tmp*=dp[k];
                        if(tmp>=mod) {
                            tmp%=mod;
                        }
                        dp[i]+=tmp;
                    }
                }
                if(dp[i]>=mod) {
                    dp[i]%=mod;
                }
            }
            dp[i]+=1;
            // cout<<dp[i]<<endl;
        }
        int ans=0;
        for(int i=1;i<=n;i++) {
            ans+=dp[i];
            if(ans>=mod) {
                ans%=mod;
            }
        }
        return ans;
    }
};