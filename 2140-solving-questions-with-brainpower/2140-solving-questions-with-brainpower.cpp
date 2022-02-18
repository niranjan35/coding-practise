class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        vector<long long> v;
        int n=q.size();
        for(int i=0;i<n;i++) {
            v.push_back(0);
        }
        for(int i=n-1;i>=0;i--) {
            v[i]=q[i][0];
            if(i!=n-1) {
                v[i]=max(v[i],v[i+1]);
            }
            if(q[i][1]+i+1<n) {
                long long tmp=v[q[i][1]+i+1];
                tmp+=q[i][0];
                v[i]=max(tmp,v[i]);
            }
        }
        return v[0];
    }
};