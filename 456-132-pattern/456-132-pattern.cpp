class Solution {
public:
    int mn[200010];
    bool find132pattern(vector<int>& arr) {
        int n=arr.size();
        memset(mn,INT_MAX,sizeof(mn));
        for(int i=0;i<n;i++) {
            if(i==0) {
                mn[i]=arr[i];
            }
            else {
                mn[i]=min(mn[i-1],arr[i]);
            }
        }
        stack<int> s;
        for(int i=n-1;i>0;i--) {
            while(!s.empty() && s.top()<=mn[i-1]) {
                s.pop();
            }
            if(!s.empty() && (s.top()>mn[i-1] && s.top()<arr[i])) {
                return true;
            }
            else {
                s.push(arr[i]);
            }
        }
        return false;
    }
};