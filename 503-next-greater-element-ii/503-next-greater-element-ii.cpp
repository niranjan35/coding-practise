class Solution {
public:
    vector<int> ans;
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++) {
            ans.push_back(-1);
        }
        if(n==1) {
            return ans;
        }
        stack<pair<int,int>> s;
        for(int i=0;i<n;i++) {
            while(!s.empty() && s.top().first<nums[i]) {
                pair<int,int> p=s.top();
                s.pop();
                ans[p.second]=nums[i];
            }
            s.push(make_pair(nums[i],i));
        }
        for(int i=0;i<n;i++) {
            while(!s.empty() && s.top().first<nums[i]) {
                pair<int,int> p=s.top();
                s.pop();
                ans[p.second]=nums[i];
            }
            s.push(make_pair(nums[i],i));
        }
        return ans;
    }
};