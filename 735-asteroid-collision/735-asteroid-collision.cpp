class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        // int ans=0;
        int n=v.size();
        stack<int> s;
        // s.push(v[0]);
        for(int i=0;i<v.size();i++) {
            bool curr_break=false;
            while(!s.empty() && (s.top()>0 && v[i]<0)) {
                // ans++;
                if(abs(s.top())==abs(v[i])) {
                    s.pop();
                    curr_break=true;
                    break;
                }
                else if(abs(s.top())>abs(v[i])) {
                    curr_break=true;
                    break;
                }
                else {
                    s.pop();
                }
            }
            if(!curr_break) {
                s.push(v[i]);
            }
        }
        vector<int> ans;
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};