class Solution {
public:
    // binary searches for the number just greater than the given number
    // this function is called for the numbers on right of val in the main array
    int bs(vector<int> nums, int val, int s, int e) {
        int mid=s+(e-s)/2;
        if(s==e) {
            return s;
        }
        if(s+1==e) {
            if(nums[e]>val) {
                return e;
            }
            return s;
        }
        if(nums[mid]<=val) {
            return bs(nums,val,s,mid-1);
        }
        return bs(nums,val,mid,e);
    }
    
    void nextPermutation(vector<int>& nums) {
        bool dec=true;
        int n=nums.size();
        for(int i=0;i<n;i++) {
            if(i!=0 && nums[i-1]<nums[i]) {
                dec=false;
            }
        }
        if(dec) {
            sort(nums.begin(),nums.end());
            return;
        }
        int indx=-1,val=-1;
        for(int i=n-2;i>=0;i--) {
            if(nums[i]<nums[i+1]) {
                indx=i;
                val=nums[i];
                break;
            }
        }
        // index of the just greater number to right
        // cout<<indx<<" "<<val<<endl;
        
        int g_indx=bs(nums,val,indx+1,n-1);
        // cout<<g_indx<<" "<<nums[g_indx]<<endl;
        int tmp=nums[g_indx];
        nums[g_indx]=nums[indx];
        nums[indx]=tmp;
        sort(nums.begin()+indx+1,nums.end());
    }
};