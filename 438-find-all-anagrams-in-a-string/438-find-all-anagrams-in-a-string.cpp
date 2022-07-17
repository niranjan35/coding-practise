class Solution {
public:
    int mp1[26],mp2[26];
    
    bool compare() {
        for(int i=0;i<26;i++) {
            if(mp1[i]!=mp2[i]) {
                return false;
            }
        }
        return true;
    }
    
    vector<int> findAnagrams(string str, string p) {
        memset(mp1,0,sizeof(mp1));
        memset(mp2,0,sizeof(mp2));
        
        int s=0,e=0;
        int ss=str.size();
        int ps=p.size();
        
        vector<int> ans;
        
        for(int i=0;i<ps;i++) {
            mp1[p[i]-'a']++;
        }
        
        if(ss<ps) {
            return ans;
        }
        
        while(e<ps) {
            mp2[str[e]-'a']++;
            e++;
        }
        
        e=ps-1;
        
        while(e<ss) {
            // cout<<"s = "<<s<<" e = "<<e<<endl;
            if(compare()) {
                ans.push_back(s);
            }
            e++;
            if(e<ss) {
                mp2[str[s]-'a']--;
                mp2[str[e]-'a']++;
            }
            s++;
        }
        
        return ans;
    }
};