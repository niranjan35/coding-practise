class Solution {
public:
    
    int cnt[20];
    vector<pair<string,string>> v;
    
    vector<string> ll,hh;
    
    vector<string> rec(int n, bool firstrec, string low, string high) {
        vector<string> tmp;
        if(n==0) {
            tmp.push_back("");
            
            if(n==low.size()) {
                for(string s:tmp) {
                    ll.push_back(s);
                }
            }

            if(n==high.size()) {
                for(string s:tmp) {
                    hh.push_back(s);
                }
            }
            
            
            return tmp;
        }
        
        if(n==1) {
            tmp.push_back("0");
            tmp.push_back("1");
            tmp.push_back("8");
            
            if(n==low.size()) {
                for(string s:tmp) {
                    ll.push_back(s);
                }
            }

            if(n==high.size()) {
                for(string s:tmp) {
                    hh.push_back(s);
                }
            }
            
            return tmp;
        }
        
        vector<string> prev=rec(n-2,false,low,high);
        for(int i=0;i<prev.size();i++) {
            string str=prev[i];
            for(int k=0;k<v.size();k++) {
                tmp.push_back(v[k].first+""+str+""+v[k].second);
            }
            
        }
        
        cnt[n]=tmp.size();
        
        // cout<<"n = "<<n<<" lows = "<<low.size()<<" highs "<<high.size()<<endl;
        
        if(n==low.size()) {
            for(string s:tmp) {
                ll.push_back(s);
            }
        }
        
        if(n==high.size()) {
            for(string s:tmp) {
                hh.push_back(s);
            }
        }
        
        for(int i=0;i<prev.size();i++) {
            string str=prev[i];
            if(!firstrec) {
                tmp.push_back("0"+str+"0");
            }
        }
        
        return tmp;
    }
    
    int strobogrammaticInRange(string low, string high) {
        
        v.push_back(make_pair("1","1"));
        v.push_back(make_pair("6","9"));
        v.push_back(make_pair("9","6"));
        v.push_back(make_pair("8","8"));
        
        memset(cnt,-1,sizeof(cnt));
        
        cnt[0]=0;
        cnt[1]=2;
        
        rec(high.size(),true,low,high);
        
        if(high.size()>1) {
            rec(high.size()-1,true,low,high);
        }
        
        // if((high.size()%2==0 && low.size()%2!=0) || (high.size()%2!=0 && low.size()%2==0)) {
        //     rec(low.size(),true,low,high);
        // }
        
        int ans=0;
        
        if(low.size()==high.size()) {
            for(string s:hh) {
                if(s>=low && s<=high) {
                    // cout<<s<<endl;
                    ans++;
                }
            }
            return ans;
        }
        
        for(int x=low.size()+1;x<high.size();x++) {
            ans+=cnt[x];
        }
        
        for(string s:ll) {
            if(s>=low) {
                ans++;
            }
        }
        for(string s:hh) {
            if(s<=high) {
                ans++;
            }
        }
        return ans;
    }
};