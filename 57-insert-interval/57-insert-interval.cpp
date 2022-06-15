class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& ni) {
        vector<vector<int>> ans;
        vector<int> prev;
        int n=arr.size();
        if(n==0) {
            ans.push_back(ni);
            return ans;
        }
        if(ni[0]>arr[n-1][1]) {
            arr.push_back(ni);
            return arr;
        }
        if(ni[1]<arr[0][0]) {
            ans.push_back(ni);
            for(int i=0;i<n;i++) {
                ans.push_back(arr[i]);
            }
            return ans;
        }
        bool flag=false;
        prev.push_back(ni[0]);
        prev.push_back(ni[1]);
        for(int i=0;i<n;i++) {
            if(((arr[i][0]<=prev[0] && arr[i][1]>=prev[0]) || (arr[i][0]<=prev[1] && arr[i][1]>=prev[1])) || 
               ((arr[i][0]>=prev[0] && arr[i][0]<=prev[1])) || (arr[i][1]>=prev[0] && arr[i][1]<=prev[1])) {
                flag=true;
                prev[0]=min(prev[0],arr[i][0]);
                prev[1]=max(prev[1],arr[i][1]);
            }
            else {
                if(flag) {
                    flag=false;
                    ans.push_back(prev);
                }
                ans.push_back(arr[i]);
            }
            if(i!=n-1) {
                if(arr[i][1]<ni[0] && ni[1]<arr[i+1][0]) {
                    ans.push_back(ni);
                }
            }
        }
        if(flag) {
            ans.push_back(prev);
        }
        return ans;
    }
};