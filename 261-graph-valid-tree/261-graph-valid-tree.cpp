class Solution {
public:
    int vis[6000];
    vector<int> arr[6000];
    bool validTree(int n, vector<vector<int>>& e) {
        if(e.empty()) {
            return n>1?false:true;
        }
        memset(vis,0,sizeof(vis));
        for(int i=0;i<5010;i++) {
            arr[i].clear();
        }
        for(int i=0;i<e.size();i++) {
            int x=e[i][0];
            int y=e[i][1];
            arr[x].push_back(y);
            arr[y].push_back(x);
        }
        for(int i=0;i<n;i++) {
            if(arr[i].size()>0 && !vis[i]) {
                queue<pair<int,int>> q;
                q.push(make_pair(i,-1));
                while(!q.empty()) {
                    pair<int,int> pr = q.front();
                    q.pop();
                    int curr=pr.first;
                    int prev=pr.second;
                    vis[curr]++;
                    for(int k=0;k<arr[curr].size();k++) {
                        if(arr[curr][k] != prev) {
                            if(vis[arr[curr][k]]>1) {
                                return false;
                            }
                            q.push(make_pair(arr[curr][k],curr));
                        }
                    }
                }
                break;
            }
        }
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                return false;
            }
        }
        return true;
    }
};