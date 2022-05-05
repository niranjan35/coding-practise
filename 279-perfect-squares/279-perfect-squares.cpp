class Solution {
public:
    int dp[11000];
    int numSquares(int n) {
        vector<int> arr;
        for(int i=0;i<11000;i++) {
            dp[i]=INT_MAX;
        }
        for(int i=1;i*i<=n;i++) {
            arr.push_back(i*i);
        }
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++) {
            for(int j=0;j<arr.size() && arr[j]<=i;j++) {
                int x=i/arr[j];
                int y=i%arr[j];
                // cout<<"dp[i] = "<<dp[i]<<endl;
                if(dp[i]>dp[y]+(x)) {
                    // cout<<"ent"<<endl;
                    dp[i]=dp[y]+x;
                }
                // cout<<"x = "<<x<<" y = "<<y<<endl;
                // cout<<"i = "<<i<<" j = "<<arr[j]<<" "<<dp[i]<<endl;
            }
        }
        return dp[n];
    }
};