class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) {
        int n=nums.size();
        vector<int> ans;
        if(n==0){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int s=bs_start(nums,0,n-1,t);
        int e=bs_end(nums,0,n-1,t);
        ans.push_back(s);
        ans.push_back(e);
        return ans;
    }
    
    int bs_start(vector<int> arr, int s, int e, int t) {
        if(s>e) {
            return -1;
        }
        int mid=s+(e-s)/2;
        if(arr[mid]==t) {
            if((mid-1>=s && arr[mid-1]!=t) || mid==s)
                return mid;
            return bs_start(arr,s,mid-1,t);
        }
        if(arr[mid]<t) {
            return bs_start(arr,mid+1,e,t);
        }
        return bs_start(arr,s,mid-1,t);
        
    }
    
    int bs_end(vector<int> arr, int s, int e, int t) {
        if(s>e) {
            return -1;
        }
        int mid=s+(e-s)/2;
        if(arr[mid]==t) {
            if((mid+1<=e && arr[mid+1]!=t) || mid==e)
                return mid;
            return bs_end(arr,mid+1,e,t);
        }
        if(arr[mid]<t) {
            return bs_end(arr,mid+1,e,t);
        }
        return bs_end(arr,s,mid-1,t);
        
    }
};