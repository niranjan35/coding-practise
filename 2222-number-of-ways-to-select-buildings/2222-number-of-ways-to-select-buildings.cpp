class Solution {
public:
    long long r[100010][2];
    long long l[100010][2];
    long long numberOfWays(string s) {
        for(int i=0;i<100010;i++) {
            r[i][0]=0;
            r[i][1]=0;
        }
        int n=s.length();
        for(int i=0;i<n;i++) {
            if(i>0) {
                l[i][0]=l[i-1][0];
                l[i][1]=l[i-1][1];
            }
            s[i]=='1'?l[i][1]++:l[i][0]++;
        }
        for(int i=n-1;i>=0;i--) {
            if(i<n-1) {
                r[i][0]=r[i+1][0];
                r[i][1]=r[i+1][1];
            }
            s[i]=='1'?r[i][1]++:r[i][0]++;
        }
        long long ans=0;
        for(int i=0;i<n;i++) {
            int v=s[i]=='0'?1:0;
            if(i+1<n && i-1>=0) {
                long long ll=r[i+1][v];
                long long rr=l[i-1][v];
                if(ll!=0 && rr!=0) {
                    ans+=(ll*rr);
                }
            }
        }
        return ans;
    }
};