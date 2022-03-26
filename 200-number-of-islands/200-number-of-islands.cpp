class Solution {
public:
    bool vis[400][400];
    
    bool inRange(int xx, int yy, int x, int y) {
        if((xx>=0 && yy>=0) && (xx<x && yy<y)) {
            return true;
        }
        return false;
    }
    
    int numIslands(vector<vector<char>>& g) {
        memset(vis,0,sizeof(vis));
        int ans=0;
        int m=g.size();
        int n=g[0].size();
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(g[i][j]=='1' && !vis[i][j]) {
                    fill(g,i,j);
                    ans++;
                }
            }
        }
        
        return ans;
    }   
    
    void fill(vector<vector<char>>& g, int i, int j) {
        int x[4]={1,0,-1,0};
        int y[4]={0,1,0,-1};
        queue<pair<int,int>> q;
        q.push(make_pair(i,j));
        vis[i][j]=1;
        int m=g.size();
        int n=g[0].size();
        while(!q.empty()) {
            pair<int,int> f=q.front();
            q.pop();
            for(int k=0;k<4;k++) {
                int xx=f.first+x[k];
                int yy=f.second+y[k];
                if(inRange(xx,yy,m,n) && (g[xx][yy]=='1' && !vis[xx][yy])) {
                    vis[xx][yy]=1;
                    q.push(make_pair(xx,yy));
                }
            }
        }
    }
};