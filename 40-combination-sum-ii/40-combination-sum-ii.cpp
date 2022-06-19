class Solution {
public:
    
    vector<vector<int>> ans;
    
    void rec(vector<int> arr, int val, int indx, vector<int> tmp, int sum, int prev) {
        // cout<<"indx = "<<indx<<" sum = "<<sum<<" prev = "<<prev<<endl;
        int n=arr.size();
        if(sum==val) {
            if(indx<n && (indx-1>=0 && arr[indx]==arr[indx-1])) {
                return;
            }
            ans.push_back(tmp);
            return;
        }
        if(sum>val || indx>=n) {
            return;
        }
        if(prev!=arr[indx]) {
            rec(arr,val,indx+1,tmp,sum, prev);
        }
        if(arr[indx]+sum<=val) {
            tmp.push_back(arr[indx]);
            rec(arr,val,indx+1,tmp,sum+arr[indx], arr[indx]);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& arr, int val) {
        sort(arr.begin(),arr.end());
        vector<int> tmp;
        rec(arr,val,0,tmp,0,-1);
        return ans;
    }
};