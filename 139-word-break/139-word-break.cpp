class Solution {
public:
    bool dp[400];
    bool wordBreak(string s, vector<string>& dict) {
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        int n=s.size();
        if(n==1 && dict.size()==1) {
            if(dict[0]==s) {
                return true;
            }
            return false;
        }
        for(int i=0;i<n;i++) {
            for(int l=0;l<dict.size();l++) {
                if(dp[i] && (i-1+dict[l].size()<n && s.substr(i,dict[l].size())==dict[l])) {
                    if(i+dict[l].size()<=n) {
                        dp[i+dict[l].size()]=1;
                    }
                }
            }
        }
        return dp[n];
    }
};