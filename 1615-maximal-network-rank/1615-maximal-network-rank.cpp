class Solution {
public:
    vector<vector<int>> g;
    vector<int> v;
    int maximalNetworkRank(int n, vector<vector<int>>& r) {
        for(int i=0;i<n;i++) {
            v.push_back(0);
        }
        for(int i=0;i<n;i++) {
            vector<int> xx;
            g.push_back(xx);
            for(int j=0;j<n;j++) {
                g[i].push_back(0);
            }
        }
        for(int i=0;i<r.size();i++) {
            g[r[i][0]][r[i][1]]=1;
            g[r[i][1]][r[i][0]]=1;
            v[r[i][0]]++;
            v[r[i][1]]++;
        }
        int mx=0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int tmp=v[i]+v[j];
                tmp-=g[i][j];
                if(tmp>mx) {
                    mx=tmp;
                }
            }
        }
        return mx;
    }
};