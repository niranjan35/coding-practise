class Solution {
public:
    
    bool vis[200010];
    int p[200010];
    int r[200010];
    
    int find(int x) {
        if(p[x]==-1) {
            return x;
        }
        return find(p[x]);
    }
    
    void unionset(int x, int y) {
        int p1=find(x);
        int p2=find(y);
        if(p1!=p2) {
            p[p1]=p2;
        }
    }
    
    bool validPath(int n, vector<vector<int>>& e, int s, int d) {
        memset(vis,0,sizeof(vis));
        memset(p,-1,sizeof(p));
        memset(r,1,sizeof(r));
        for(int i=0;i<e.size();i++) {
            unionset(e[i][0],e[i][1]);
        }
        // cout<<p[0]<<" "<<p[1]<<" "<<p[2]<<endl;
        return find(s)==find(d)?true:false;
    }
};