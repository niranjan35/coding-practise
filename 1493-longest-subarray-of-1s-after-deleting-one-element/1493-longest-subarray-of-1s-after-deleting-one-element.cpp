class Solution {
public:
    int l[100010],r[100010];
    int longestSubarray(vector<int>& nums) {
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        int n=nums.size();
        int cnt=0;
        bool isOne=false;
        for(int i=0;i<n;i++) {
            if(nums[i]==1) {
                cnt++;
                isOne=true;
            }
            else {
                l[i]=cnt;
                cnt=0;
            }
        }
        cnt=0;
        for(int i=n-1;i>=0;i--) {
            if(nums[i]==1) {
                cnt++;
            }
            else {
                r[i]=cnt;
                cnt=0;
            }
        }
        int mx=0;
        for(int i=0;i<n;i++) {
            if(nums[i]==0) {
                mx=max(mx,l[i]+r[i]);
            }
        }
        if(mx==0 && isOne) {
            return n-1;
        }
        return mx;
    }
};