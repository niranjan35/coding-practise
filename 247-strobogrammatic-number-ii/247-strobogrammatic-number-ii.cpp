class Solution {
public:
    vector<string> ans;
    vector<pair<string,string>> v;
    
    vector<string> rec(int n, bool firstrec) {
        vector<string> tmp;
        if(n==0) {
            tmp.push_back("");
            return tmp;
        }
        
        if(n==1) {
            tmp.push_back("0");
            tmp.push_back("1");
            tmp.push_back("8");
            return tmp;
        }
        
        vector<string> prev=rec(n-2,false);
        for(int i=0;i<prev.size();i++) {
            string str=prev[i];
            for(int k=0;k<v.size();k++) {
                tmp.push_back(v[k].first+""+str+""+v[k].second);
            }
            if(!firstrec) {
                tmp.push_back("0"+str+"0");
            }
        }
        return tmp;
    }
    vector<string> findStrobogrammatic(int n) {
        v.push_back(make_pair("1","1"));
        v.push_back(make_pair("6","9"));
        v.push_back(make_pair("9","6"));
        v.push_back(make_pair("8","8"));
        return rec(n,true);
    }
};