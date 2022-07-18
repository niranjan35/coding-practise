class Solution {
public:
    
    int p[1010];
    
    int findp(int x) {
        if(p[x]==x) {
            return x;
        }
        return findp(p[x]);
    }
    
    void unionset(int x, int y) {
        int px=findp(x);
        int py=findp(y);
        if(px==py) {
            return;
        }
        p[px]=py;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& arr) {
        memset(p,0,sizeof(p));
        unordered_map<int,vector<string>> mp;
        unordered_map<string,int> group;
        vector<vector<string>> ans;
        for(int i=0;i<arr.size();i++) {
            p[i]=i;
            // vector<string> vv;
            // v.push_back(vv);
        }
        for(int i=0;i<arr.size();i++) {
            string first_email="";
            for(int j=1;j<arr[i].size();j++) {
                string name=arr[i][0];
                string email=arr[i][j];
                if(j==1) {
                    first_email=arr[i][1];
                }
                if(group.find(email)==group.end()) {
                    group[email]=i;
                }
                else {
                    unionset(i,group[email]);
                }
            }
        }
        
        for(auto e: group) {
            string email=e.first;
            int group=e.second;
            mp[findp(group)].push_back(email);
        }
        
        for(auto entry:mp) {
            int g=entry.first;
            vector<string> emails=entry.second;
            string name=arr[g][0];
            vector<string> vv;
            vv.push_back(name);
            sort(emails.begin(),emails.end());
            for(int i=0;i<emails.size();i++) {
                vv.push_back(emails[i]);
            }
            ans.push_back(vv);
        }
        return ans;
    }
};