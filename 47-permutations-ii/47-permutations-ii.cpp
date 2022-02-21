class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        rec(nums,0,n);
        return ans;
    }
    
    void rec(vector<int> nums,int indx, int n) {
        if(indx==n-1) {
            ans.push_back(nums);
            return;
        }
        for(int i=indx;i<n;i++) {
            if(indx!=i && nums[indx]==nums[i]) {
                continue;
            }
            int tmp=nums[indx];
            nums[indx]=nums[i];
            nums[i]=tmp;
            rec(nums,indx+1,n);
        }
        return;
    }
};