class Solution {
public:
    vector<int> w;
    int maxBoxesInWarehouse(vector<int>& b, vector<int>& ww) {
        for(int i=0;i<ww.size();i++) {
            w.push_back(ww[i]);
            if(i>0) {
                w[i]=min(w[i],w[i-1]);
            }
        }
        sort(b.begin(),b.end(),greater<int>());
        int i=w.size()-1;
        int j=b.size()-1;
        int ans=0;
        while(true) {
            // cout<<"i = "<<i<<" j = "<<j<<endl;
            if(i<0 || j<0) {
                break;
            }
            if(w[i]>=b[j]) {
                i--;j--;
                ans++;
                continue;
            }
            i--;
        }
        return ans;
    }
};