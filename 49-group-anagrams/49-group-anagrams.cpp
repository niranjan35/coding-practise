bool cmp(pair<string,int> p1, pair<string,int> p2) {
    return p1.first<p2.first? true:false;
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& w) {
        map<int,string> mp;
        for(int i=0;i<w.size();i++) {
            mp[i]=w[i];
        }
        vector<pair<string,int>> v;
        for(int i=0;i<w.size();i++) {
            string s=w[i];
            sort(s.begin(),s.end());
            v.push_back(make_pair(s,i));
        }
        sort(v.begin(),v.end(),cmp);
        vector<vector<string>> ans;
        vector<string> tmp;
        for(int i=0;i<v.size();i++) {
            // cout<<v[i].first<<" "<<v[i].second<<endl;
            if(i==0 || v[i].first == v[i-1].first) {
                // cout<<"pushing"<<endl;
                tmp.push_back(mp[v[i].second]);
            }
            else {
                // cout<<"cut"<<endl;
                ans.push_back(tmp);
                tmp.clear();
                tmp.push_back(mp[v[i].second]);
            }
        }
        if(tmp.size()!=0) {
            ans.push_back(tmp);
        }
        return ans;
    }
};