class Solution {
public:
    int dp[110][110];
    vector<string> v;
    int numDecodings(string s) {
        v.push_back("0");
        v.push_back("1");
        v.push_back("2");
        v.push_back("3");
        v.push_back("4");
        v.push_back("5");
        v.push_back("6");
        
        for(int i=0;i<110;i++) {
            for(int j=0;j<110;j++) {
                dp[i][j]=0;
            }
        }
        int n=s.size();
        for(int l=1;l<=n;l++) {
            for(int i=0;i+l<=n;i++) {
                int e=i+l-1;
                if(s.substr(i,1)=="0") {
                    dp[i][e]=0;
                    continue;
                }
                // cout<<"s = "<<i<<" e = "<<e<<endl;
                if(l==1) {
                    dp[i][e]=1;
                    continue;
                }
                if(e-1>=i && s.substr(e,1)!="0") {
                    // cout<<"hello1"<<endl;
                    dp[i][e]+=dp[i][e-1];
                }
                if(s.substr(e-1,1)=="1" || (s.substr(e-1,1)=="2" && find(v.begin(), v.end(), s.substr(e,1)) != v.end())) {
                    if(e-2>=i) {
                        // cout<<"hello2"<<endl;
                        dp[i][e]+=dp[i][e-2];
                    }
                    else if(e-2==i-1) {
                        // cout<<"hello3"<<endl;
                        dp[i][e]+=1;
                    }
                }
            }
        }
        // for(int i=0;i<110;i++) {
        //     for(int j=0;j<110;j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<""<<endl;
        // }
        return dp[0][n-1];
    }
};