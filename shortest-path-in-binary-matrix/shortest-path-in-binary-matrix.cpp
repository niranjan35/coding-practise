class Solution {
public:
    int xy[8][2]={{1,1},{1,-1},{-1,-1},{-1,1},{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> ans;
    vector<vector<int>> vis;
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        int n=g.size();
        if(g[0][0]!=0) {
            return -1;
        }
        for(int i=0;i<n;i++) {
            vector<int> tmp;
            vector<int> tmp1;
            for(int j=0;j<n;j++) {
                tmp.push_back(INT_MAX);
                tmp1.push_back(0);
            }
            vis.push_back(tmp1);
            ans.push_back(tmp);
        }
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        ans[0][0]=1;
        while(!q.empty()) {
            pair<int,int> p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
            vis[x][y]=1;
            for(int i=0;i<8;i++) {
                int xx=x+xy[i][0];
                int yy=y+xy[i][1];
                if(((xx>=0 && xx<n) && (yy>=0 && yy<n)) && (g[xx][yy]==0) && ans[x][y]+1<ans[xx][yy]) {
                    ans[xx][yy]=ans[x][y]+1;
                    q.push(make_pair(xx,yy));
                }
            }
        }
        if(ans[n-1][n-1]==INT_MAX) {
            return -1;
        }
        return ans[n-1][n-1];
    }
};