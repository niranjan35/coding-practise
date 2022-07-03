class Solution {
public:
    vector<int> v;
    int nextGreaterElement(int n) {
        int x=n;
        while(x>0) {
            int tmp=x%10;
            x/=10;
            v.push_back(tmp);
        }
        int tmp=-1;
        for(int i=1;i<v.size();i++) {
            if(i-1>=0 && v[i]<v[i-1]) {
                tmp=i;
                break;
            }
        }
        if(tmp==-1) {
            return -1;
        } 
        int target=tmp-1;
        for(int i=tmp-1;i>=0;i--) {
            if(v[i]>v[tmp] && v[i]<v[target]) {
                target=i;
            }
        }
       int tmp1=v[target];
        v[target]=v[tmp];
        v[tmp]=tmp1;
        
        sort(v.begin(),v.begin()+tmp,greater<int>());
        long long int ans=0;
        for(int i=v.size()-1;i>=0;i--) {
            ans*=10;
            ans+=v[i];
        }
        if(ans>INT_MAX) {
            return -1;
        }
        return ans;
    }
};