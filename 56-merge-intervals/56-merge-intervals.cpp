class Solution {
    
public:
    static bool cmp(vector<int> &v1,vector<int> &v2) {
        return v1[0]<v2[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),cmp);
        int n=v.size();
        // for(int i=0;i<n;i++) {
        //     cout<<v[i][0]<<" "<<v[i][1]<<endl;
        // }
        vector<vector<int>> ans;
        vector<int> prev;
        prev.push_back(v[0][0]);
        prev.push_back(v[0][1]);
        
        bool flag=false;
        
        for(int i=1;i<n;i++) {
            flag=false;
            if(v[i][0]<=prev[1]) {
                prev[1]=max(v[i][1], prev[1]);
            }
            else {
                ans.push_back(prev);
                flag=true;
                prev=v[i];
            }
        }
        ans.push_back(prev);
        return ans;
    }
};