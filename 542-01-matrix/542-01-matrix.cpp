class Solution {
public:
    struct node {
        int x;
        int y;
        int val;
    };
    int xx[4] = {1,0,0,-1};
    int yy[4] = {0,-1,1,0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& arr) {
        int m=arr.size();
        int n=arr[0].size();
        vector<vector<int>> ans;
        vector<int> tmp;
        for(int i=0;i<n;i++) {
            tmp.push_back(-1);
        }
        for(int i=0;i<m;i++) {
            ans.push_back(tmp);
        }
        queue<node> q;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(arr[i][j]==0) {
                    q.push((node){i,j,0});
                    ans[i][j]=0;
                }
            }
        }
        while(!q.empty()) {
            node p=q.front();
            q.pop();
            for(int i=0;i<4;i++) {
                if((p.x+xx[i]<m && p.x+xx[i]>=0) && (p.y+yy[i]<n && p.y+yy[i]>=0)) {
                    if(ans[p.x+xx[i]][p.y+yy[i]]==-1) {
                        ans[p.x+xx[i]][p.y+yy[i]]=p.val+1;
                        q.push({p.x+xx[i],p.y+yy[i],p.val+1});
                    }
                }
            }
        }
        return ans;
    }
};