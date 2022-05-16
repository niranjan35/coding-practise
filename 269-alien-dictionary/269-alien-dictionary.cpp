class Solution {
public:
    map<char,vector<char>> g;
    int vis[1010];
    string ans;
    string alienOrder(vector<string>& w) {
        memset(vis,0,sizeof(vis));
        int n=w.size();
        ans="";
        for(int i=0;i<n-1;i++) {
            string w1=w[i];
            string w2=w[i+1];
            if(w1.size()<=w2.size() && w2.substr(0,w1.size())==w1) {
                // cout<<"match"<<endl;
                // cout<<w1<<" "<<w2<<endl;
                continue;
            }
            bool flag=true;
            for(int j=0;j<min(w1.size(),w2.size());j++) {
                if(w1[j]!=w2[j]) {
                    flag=false;
                    // cout<<w1[j]<<" "<<w2[j]<<endl;
                    g[w2[j]].push_back(w1[j]);
                    break;
                }
            }
            if(flag) {
                return "";
            }
        }
        map<char,vector<char>>::iterator it;
        for(it=g.begin();it!=g.end();it++) {
            // cout<<"calling dfs for "<<it->first<<endl;
            bool cycle=dfs(it->first);
            if(cycle) {
                return "";
            }
        }
        if(g.size()==0) {
            return reduce(w[w.size()-1]);
        }
        for(int i=0;i<w.size();i++) {
            for(int j=0;j<w[i].size();j++) {
                if(g[w[i][j]].size()==0 && vis[w[i][j]]==0) {
                    ans+=w[i][j];
                    vis[w[i][j]]=1;
                }
            }
        }
        return ans;
    }
    
    string reduce(string s) {
        string tmp="";
        memset(vis,0,sizeof(vis));
        for(int i=0;i<s.size();i++) {
            if(vis[s[i]]==0) {
                vis[s[i]]=1;
                tmp+=s[i];
            }
        }
        return tmp;
    }
    
    bool dfs(char root) {
        // cout<<"root = "<<root<<endl;
        if(vis[root]==1) {
            // cout<<"return true 1"<<endl;
            return true;
        }
        if(vis[root]==2) {
            // cout<<"return false 2"<<endl;
            return false;
        }
        vis[root]=1;
        for(int i=0;i<g[root].size();i++) {
            bool cycle=dfs(g[root][i]);
            if(cycle) {
                // cout<<"return true 2"<<endl;
                return true;
            }
        }
        vis[root]=2;
        ans+=root;
        // cout<<"return false 3"<<endl;
        return false;
    }
};