class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod=1000000007;
        int n=arr.size();
        vector<int> sum;
        sum.push_back(0);
        int e=1;
        int o=0;
        for(int i=0;i<n;i++) {
            int tmp=sum[i]+arr[i];
            tmp%2==0?e++:o++;
            sum.push_back(tmp);
        }
        // cout<<e<<" "<<o<<endl;
        long long t=o;
        // t*=(o-1);
        // if(t>=mod) {
        //     t%=mod;
        // }
        long long ans=0;
        // t=e;
        // t*=(e-1);
        // if(t>=mod) {
        //     t%=mod;
        // }
        // ans+=t;
        // if(ans>=mod) {
        //     ans%=mod;
        // }
        t=o;
        t*=e;
        ans+=t;
        if(ans>=mod) {
            ans%=mod;
        }
        return ans;
    }
};