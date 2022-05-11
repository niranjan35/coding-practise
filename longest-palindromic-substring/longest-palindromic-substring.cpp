class Solution {
public:
    int dp[1010][1010];
    // string rec(string str, int s, int e) {
    //     if(str[s]==str[e]) {
    //         return 
    //     }
    // }
    
    string longestPalindrome(string str) {
        int n=str.length();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<1010;i++) {
            for(int j=0;j<1010;j++) {
                dp[i][j]=-1;
            }
        }
        for(int s=0;s<n;s++) {
            for(int x=0;s+x<n;x++) {
                int y=s+x;
                if(x==y) {
                    dp[x][y]=1;
                    continue;
                }
                if(str[x]==str[y]) {
                    if(x+1==y) {
                        dp[x][y]=2;
                    }
                    if((x+1<n && y-1>=0) && (x+1<=y-1 && dp[x+1][y-1]!=-1)) {
                        dp[x][y]=max(dp[x][y],dp[x+1][y-1]+2);
                    }
                    // if((x+1<n) && (x+1<=y && dp[x+1][y]!=-1)) {
                    //     dp[x][y]=max(dp[x][y],dp[x+1][y]);
                    // }
                    // if((y-1>=0) && (x<=y-1 && dp[x][y-1]!=-1)) {
                    //     dp[x][y]=max(dp[x][y],dp[x][y-1]);
                    // }
                }
            }
        }
        
        int mx=-1,x,y;
        
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<n;j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<""<<endl;
        // }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(dp[i][j]>mx) {
                    mx=dp[i][j];
                    x=i;y=j;
                }
            }
        }
        
        return str.substr(x,y-x+1);
    }
};