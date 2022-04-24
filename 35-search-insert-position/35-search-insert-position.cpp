class Solution {
public:
    
    int bs(vector<int> nums, int s, int e, int x) {
        if(s>e) {
            return -1;
        }
        int mid=s+((e-s)/2);
        if(x<nums[s]) {
            return s;
        }
        if(nums[mid]==x) {
            return mid;
        }
        if(nums[e]<x) {
            return e+1;
        }
        if(nums[mid]<x) {
            if((mid+1<=e && nums[mid+1]>x) || (mid+1>e)) {
                return mid+1;
            }
            return bs(nums,mid+1,e,x);
        }
        return bs(nums,s,mid,x);
    }
    
    int searchInsert(vector<int>& nums, int target) {
        return bs(nums,0,nums.size()-1,target);
    }
};