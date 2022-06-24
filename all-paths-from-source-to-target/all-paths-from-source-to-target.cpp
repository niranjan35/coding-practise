class Solution {
public:
    
    bool vis[20];
    vector<vector<int>> ans;
    
    void dfs(vector<vector<int>>& g, int s, int d, vector<int> path) {
        path.push_back(s);
        if(s==d) {
            ans.push_back(path);
            path.pop_back();
            return;
        }
        for(int i=0;i<g[s].size();i++) {
            dfs(g,g[s][i],d,path);
        }
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        memset(vis,0,sizeof(vis));
        int n=g.size();
        if(n==0) {
            return ans;
        }
        vector<int> v;
        dfs(g,0,n-1,v);
        return ans;
    }
};