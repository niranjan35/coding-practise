class Solution {
public:
    int vis[110];
    bool isBipartite(vector<vector<int>>& g) {
        memset(vis,0,sizeof(vis));
        int n=g.size();
        int v=1;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++) {
            if(g[i].size()>0 && vis[i]==0) {
                vis[i]=v;
                q.push(make_pair(i,v));
            }
            while(!q.empty()) {
                pair<int,int> p=q.front();
                q.pop();
                int x=p.first;
                v=p.second;
                for(int i=0;i<g[x].size();i++) {
                    if(vis[g[x][i]]==v) {
                        return false;
                    }
                    if(vis[g[x][i]]==0) {
                        vis[g[x][i]]=-1*v;
                        q.push(make_pair(g[x][i],-1*v));
                    }
                }
            }
        }
        return true;
    }
};