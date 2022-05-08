struct compare {
    bool operator()(const string f, const string s) {
        return f.size()<s.size();
    }
};

class Solution {
public:
    map<string,int> mp;
    int rec(vector<string>& arr, set<string> s, string curr) {
        int len=1;
        if(mp[curr]!=-1) {
            return mp[curr];
        }
        for(int i=0;i<curr.size();i++) {
            string tmp=curr.substr(0,i)+curr.substr(i+1);
            if(s.find(tmp)!=s.end()) {
                len=max(len,1+rec(arr,s,tmp));
            }
        }
        mp[curr]=len;
        return len;
    }
    
    int longestStrChain(vector<string>& arr) {
        compare c;
        int n=arr.size();
        sort(arr.begin(),arr.end(),c);
        // for(int i=0;i<n;i++) {
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
        set<string> s;
        for(int i=0;i<n;i++) {
            s.insert(arr[i]);
            mp[arr[i]]=-1;
        }
        int len=1;
        for(string curr:arr) {
            int len_curr=1;
            for(int i=0;i<curr.size();i++) {
                string tmp=curr.substr(0,i)+curr.substr(i+1);
                if(mp.find(tmp)!=mp.end()) {
                    len_curr=max(len_curr,1+mp[tmp]);
                    len=max(len,1+mp[tmp]);
                }
            }
            mp[curr]=len_curr;
        }
        
        // int mx=0;
        // for(int i=0;i<n;i++) {
        //     mx=max(mx,rec(arr,s,arr[i]));
        // }
        // return mx;
        
        return len;
    }
};