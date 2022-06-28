class Solution {
public:
    vector<int> g[10100];
    int vis[10100];
    
    bool dfs(int s, int d) {
        vis[s]=1;
        if(g[s].size()==0) {
            vis[s]=2;
            if(s==d) {
                return true;
            }
            return false;
        }
        for(int i=0;i<g[s].size();i++) {
            if(vis[g[s][i]]==1) {
                return false;
            }
            if(vis[g[s][i]]==2) {
                vis[s]=2;
                return true;
            }
            if(!dfs(g[s][i],d)) {
                return false;
            }
        }
        vis[s]=2;
        return true;
    }
    
    bool leadsToDestination(int n, vector<vector<int>>& e, int s, int d) {
        for(int i=0;i<10100;i++) {
            g[i].clear();
        }
        memset(vis,0,sizeof(vis));
        for(int i=0;i<e.size();i++) {
            g[e[i][0]].push_back(e[i][1]);
        }
        return dfs(s,d);
    }
};