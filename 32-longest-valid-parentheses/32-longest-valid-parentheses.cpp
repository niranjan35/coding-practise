class Solution {
public:
    struct node {
        char c;
        int indx;
    };
    
    int longestValidParentheses(string str) {
        stack<node> s;
        int n=str.length();
        if(n==0) {
            return 0;
        }
        s.push((node){str[0],0});
        for(int i=1;i<n;i++) {
            if(!s.empty() && (str[i]==')' && s.top().c=='(')) {
                s.pop();
            }
            else {
                s.push((node){str[i],i});
            }
        }
        if(s.empty()) {
            return str.length();
        }
        int prev_indx=n;
        int tmp,mx=0;
        while(!s.empty()) {
            node curr=s.top();
            s.pop();
            tmp=prev_indx-curr.indx-1;
            if(tmp>mx) {
                mx=tmp;
            }
            prev_indx=curr.indx;
        }
        if(prev_indx>mx) {
            mx=prev_indx;
        }
        return mx;
    }
};