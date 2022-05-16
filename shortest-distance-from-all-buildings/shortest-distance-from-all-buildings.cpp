struct blob {
    int x;
    int y;
    int d;
};

class Solution {
public:
    int dist[100][100];
    int vis[100][100];
    int m,n;
    int xx1[4]={1,0,-1,0};
    int yy1[4]={0,1,0,-1};
    
    blob newBlob(int a, int b, int c) {
        blob bl;
        bl.x=a;
        bl.y=b;
        bl.d=c;
        return bl;
    }
    
    void bfs(vector<vector<int>>& g, int x, int y) {
        memset(vis,0,sizeof(vis));
        queue<blob> q;
        q.push(newBlob(x,y,0));
        while(!q.empty()) {
            blob p=q.front();
            // cout<<p.x<<" "<<p.y<<" "<<p.d<<endl;
            vis[p.x][p.y]=1;
            q.pop();
            if(g[p.x][p.y]!=1 || g[p.x][p.y]!=2) {
                dist[p.x][p.y]+=p.d;
            }
            for(int i=0;i<4;i++) {
                int xx=p.x+xx1[i];
                int yy=p.y+yy1[i];
                if((xx>=0 && xx<m) && (yy>=0 && yy<n)) {
                    if(!vis[xx][yy] && g[xx][yy]<=0) {
                        vis[xx][yy]=1;
                        g[xx][yy]-=1;
                        q.push(newBlob(xx,yy,p.d+1));
                    }
                }
            }
        }
    }
    
    int shortestDistance(vector<vector<int>>& g) {
        for(int i=0;i<100;i++) {
            for(int j=0;j<100;j++) {
                dist[i][j]=0;
            }
        }
        m=g.size();
        n=g[0].size();
        int cnt=0;
        // for(int i=0;i<m;i++) {
        //     for(int j=0;j<n;j++) {
        //         cout<<dist[i][j]<<" ";
        //     }
        // }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(g[i][j]==1) {
                    dist[i][j]=0;
                    cnt++;
                    bfs(g,i,j);
                }
            }
        }
        int mn=INT_MAX;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                // cout<<dist[i][j]<<" ";
                if(g[i][j]==-1*cnt) {
                    if(mn>dist[i][j]) {
                        mn=dist[i][j];
                    }
                }
            }
            // cout<<""<<endl;
        }
        if(mn==INT_MAX) {
            return -1;
        }
        return mn;
    }
};