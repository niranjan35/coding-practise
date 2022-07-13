class Solution {
public:
    string reverseWords(string s) {
        string w="";
        vector<string> v;
        
        // string str=s;
        
        for(int i=0;i<s.size();i++) {
            if(s[i]==' ') {
                if(!((w.size()==1 && w[0]==' ') || w.size()==0)) {
                    v.push_back(w);
                }
                w="";
            }
            else {
                w+=s[i];
            }
        }
        
        if(!((w.size()==1 && w[0]==' ') || w.size()==0)) {
            v.push_back(w);
        }
        
        // for(int i=0;i<v.size();i++) {
        //     cout<<v[i]<<" "<<endl;
        // }
        // cout<<" ------- "<<endl;
        
        int i=v.size()-1;
        bool first=true;
        string ans="";
        while(i>=0) {
            if(!first) {
                ans+=" ";
            }
            ans+=v[i];
            first=false;
            i--;
        }
        return ans;
    }
};