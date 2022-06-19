class Solution {
public:
    
    vector<vector<int>> ans;
    
    void rec(vector<int> arr, int val, int indx, vector<int> tmp, int sum) {
        // cout<<"here "<<indx<<" "<<sum<<endl;
        int n=arr.size();
        if(sum==val) {
            ans.push_back(tmp);
            return;
        }
        if(indx>=n) {
            return;
        }
        rec(arr,val,indx+1,tmp,sum);
        if(sum+arr[indx]<=val) {
            // cout<<"pushing "<<arr[indx]<<endl;
            tmp.push_back(arr[indx]);
            rec(arr,val,indx,tmp,sum+arr[indx]);
            // cout<<"popping "<<arr[indx]<<endl;
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& arr, int val) {
        vector<int> tmp;
        rec(arr,val,0,tmp,0);
        return ans;
    }
};