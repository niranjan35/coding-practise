class Solution {
public:
    int vis[120];
    bool isBipartite(vector<vector<int>>& g) {
        memset(vis,0,sizeof(vis));
        queue<int> q;
        int n=g.size();
        bool rock=true;
        bool toc=false;
        while(true) {
            for(int i=0;i<n;i++) {
                if(g[i].size()!=0 && vis[i]==0) {
                    vis[i]=1;
                    q.push(i);
                    toc=true;
                    break;
                }
            }
            if(!toc) {
                break;
            }
            while(!q.empty()) {
                int curr=q.front();
                q.pop();
                for(int i=0;i<g[curr].size();i++) {
                    int next=g[curr][i];
                    if(vis[next]==vis[curr]) {
                        return false;
                    }
                    if(vis[next]==0) {
                        q.push(next);
                        vis[next]=-1*vis[curr];
                    }
                }
            }
            toc=false;
        }
        return true;
    }
};