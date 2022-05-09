class Solution {
public:
    int l[100100],r[100100];
    map<char, int> mp;
    int numSplits(string s) {
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        int cnt=0;
        int n=s.size();
        mp.clear();
        for(int i=0;i<n;i++) {
            if(mp[s[i]]==0) {
                cnt++;
            }
            mp[s[i]]++;
            l[i+1]=cnt;
        }
        int cnt1=0;
        mp.clear();
        for(int i=n-1;i>=0;i--) {
            if(mp[s[i]]==0) {
                cnt1++;
            }
            mp[s[i]]++;
            r[i]=cnt1;
        }
        int ans=0;
        if(cnt%2==1) {
            cnt++;
        }
        // for(int i=0;i<=n;i++) {
        //     cout<<l[i]<<" "<<r[i]<<endl;
        // }
        cnt/=2;
        for(int i=0;i<=n;i++) {
            // cout<<l[i]<<" "<<r[i]<<endl;
            if(l[i]==r[i]) {
                ans++;
            }
        }
        return ans;
    }
};