class Solution {
public:
    
    bool vis[300][300];
    int xx[4]={1,0,-1,0};
    int yy[4]={0,1,0,-1};
    int m,n;
    
    vector<pair<int,int>> get_edge_zero(vector<vector<char>>& arr) {
        vector<pair<int,int>> v;
        for(int i=0;i<m;i++) {
            if(arr[i][0]=='O') {
                v.push_back(make_pair(i,0));
            }
        }
        for(int i=0;i<m;i++) {
            if(arr[i][n-1]=='O') {
                v.push_back(make_pair(i,n-1));
            }
        }
        for(int i=0;i<n;i++) {
            if(arr[0][i]=='O') {
                v.push_back(make_pair(0,i));
            }
        }
        for(int i=0;i<n;i++) {
            if(arr[m-1][i]=='O') {
                v.push_back(make_pair(m-1,i));
            }
        }
        return v;
    }
    
    void bfs(vector<vector<char>>& arr) {
        queue<pair<int,int>> q;
        vector<pair<int,int>> edge_zeros = get_edge_zero(arr);
        for(int i=0;i<edge_zeros.size();i++) {
            q.push(edge_zeros[i]);
        }
        while(!q.empty()) {
            pair<int,int> p = q.front();
            int x=p.first;
            int y=p.second;
            vis[x][y]=1;
            q.pop();
            for(int i=0;i<4;i++) {
                int xn=x+xx[i];
                int yn=y+yy[i];
                if(((xn>=0 && xn<m) && (yn>=0 && yn<n)) && (!vis[xn][yn] && arr[xn][yn]=='O')) {
                    q.push(make_pair(x+xx[i],y+yy[i]));
                }
            }
        }
    }
    
    void solve(vector<vector<char>>& arr) {
        memset(vis,0,sizeof(vis));
        m=arr.size();
        n=arr[0].size();
        bfs(arr);
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(arr[i][j]=='O' && !vis[i][j]) {
                    arr[i][j]='X';
                }
            }
        }
    }
};