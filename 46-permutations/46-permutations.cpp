class Solution {
public:
    vector<vector<int>> ans;
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        rec(nums,0,n);
        return ans;
    }
    
    void rec(vector<int>nums, int indx, int n) {
        if(indx==n-1) {
            ans.push_back(nums);
            return;
        }
        for(int i=indx;i<n;i++) {
            int tmp=nums[i];
            nums[i]=nums[indx];
            nums[indx]=tmp;
            rec(nums,indx+1,n);
        }
        return;
    }
    
};