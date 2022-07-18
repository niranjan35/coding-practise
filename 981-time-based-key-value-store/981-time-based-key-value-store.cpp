class TimeMap {
public:
    
    struct Node {
        int t;
        string val;
    };
    
    Node* newNode(int t, string val) {
        Node* n=new Node();
        n->t=t;
        n->val=val;
        return n;
    }
    
    map<string,vector<Node*>> mp;
    
    TimeMap() {
        
    }
    
    string bs(vector<Node*>v, int t, int s, int e) {
        if(e<s) {
            return "";
        }
        if(s==e) {
            return (v[s]->t<=t) ? v[s]->val : "";
        }
        if(t>=v[e]->t) {
            return v[e]->val;
        }
        if(t<v[s]->t) {
            return "";
        }
        if(s+1==e) {
            return v[s]->val;
        }
        int mid=s+(e-s)/2;
        if(v[mid]->t<=t && v[mid+1]->t>t) {
            return v[mid]->val;
        }
        if(v[mid]->t>t) {
            return bs(v,t,s,mid-1);
        }
        return bs(v,t,mid+1,e);
    }

    
    string bs1(string k, int t, int s, int e) {
        while(s<=e) {
            if(e<s) {
                return "";
            }
            if(s==e) {
                return (mp[k][s]->t<=t) ? mp[k][s]->val : "";
            }
            if(t>=mp[k][e]->t) {
                return mp[k][e]->val;
            }
            if(t<mp[k][s]->t) {
                return "";
            }
            if(s+1==e) {
                return mp[k][s]->val;
            }
            int mid=s+(e-s)/2;
            if(mp[k][mid]->t<=t && mp[k][mid+1]->t>t) {
                return mp[k][mid]->val;
            }
            if(mp[k][mid]->t>t) {
                e=mid-1;
            }
            else {
                s=mid+1;
            }
        }
        return "";
    }
    
    void set(string k, string v, int t) {
        // cout<<"set "<<k<<endl;
        if(mp.find(k)==mp.end()) {
            vector<Node*> vv;
            mp[k]=vv;
        }
        mp[k].push_back(newNode(t,v));
    }
    
    string get(string k, int t) {
        // cout<<"get "<<k<<endl;
        if(mp.find(k)==mp.end()) {
            return "";
        }
        return bs1(k,t,0,mp[k].size()-1);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */