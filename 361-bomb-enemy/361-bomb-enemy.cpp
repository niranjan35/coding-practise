class Solution {
public:
    
    int r[550][550],c[550][550];
    
    void pre() {
        for(int i=0;i<550;i++) {
            for(int j=0;j<550;j++) {
                r[i][j]=0;
                c[i][j]=0;
            }
        }
    }
    
    int maxKilledEnemies(vector<vector<char>>& g) {
        pre();
        int m=g.size();
        int n=g[0].size();
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(g[i][j]=='W') {
                    r[i][j]=0;
                    continue;
                }
                if(j>=1) {
                    r[i][j]=r[i][j-1];
                }
                if(g[i][j]=='E') {
                    r[i][j]++;
                }
            }
        }
        
//         for(int i=0;i<m;i++) {
//             for(int j=0;j<n;j++) {
//                 cout<<r[i][j]<<" ";
//             }
//             cout<<""<<endl;
//         }
        
//         cout<<"-----dd----"<<endl;
        
        for(int j=n-1;j>=0;j--) {
            for(int i=0;i<m;i++) {
                if(g[i][j]=='W') {
                    r[i][j]=0;
                    continue;
                }
                if(j<n-1 && g[i][j+1]!='W') {
                    r[i][j]=r[i][j+1];
                }
            }
        }
        
        for(int j=0;j<n;j++) {
            for(int i=0;i<m;i++) {
                if(g[i][j]=='W') {
                    c[i][j]=0;
                    continue;
                }
                if(i>=1) {
                    c[i][j]=c[i-1][j];
                }
                if(g[i][j]=='E') {
                    c[i][j]++;
                }
            }
        }
        
        for(int i=m-1;i>=0;i--) {
            for(int j=0;j<n;j++) {
                if(g[i][j]=='W') {
                    c[i][j]=0;
                    continue;
                }
                if(i<m-1 && g[i+1][j]!='W') {
                    c[i][j]=c[i+1][j];
                }
            }
        }
        
        int ans=0;
        
//         for(int i=0;i<m;i++) {
//             for(int j=0;j<n;j++) {
//                 cout<<r[i][j]<<" ";
//             }
//             cout<<""<<endl;
//         }
        
//         cout<<"---------"<<endl;
        
//         for(int i=0;i<m;i++) {
//             for(int j=0;j<n;j++) {
//                 cout<<c[i][j]<<" ";
//             }
//             cout<<""<<endl;
//         }
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(g[i][j]!='0') {
                    continue;
                }
                ans=max(ans,r[i][j]+c[i][j]);
            }
        }
        
        return ans;
    }
};