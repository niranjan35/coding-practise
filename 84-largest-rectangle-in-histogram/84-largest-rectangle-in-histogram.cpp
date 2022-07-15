class Solution {
public:
    
    int r[100010],l[100010];
    
    int largestRectangleArea(vector<int>& h) {
        memset(l,-1,sizeof(l));
        memset(r,-1,sizeof(r));
        
        int n=h.size();
        
        stack<pair<int,int>> s;
        for(int i=0;i<n;i++) {
            while(!s.empty() && s.top().first>h[i]) {
                r[s.top().second]=i;
                s.pop();
            }
            s.push(make_pair(h[i],i));
        }
        
        s=stack<pair<int,int>>();
        
        for(int i=n-1;i>=0;i--) {
            while(!s.empty() && s.top().first>h[i]) {
                l[s.top().second]=i;
                s.pop();
            }
            s.push(make_pair(h[i],i));
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++) {
            
            int lw=i,rw=n-i-1;
            if(lw<0) {
                lw=0;
            }
            if(rw<0) {
                rw=0;
            }
            if(l[i]!=-1) {
                lw=i-l[i]-1;
            }
            if(r[i]!=-1) {
                rw=r[i]-i-1;
            }
            // cout<<h[i]<<" "<<lw<<" "<<rw<<" "<<l[i]<<" "<<r[i]<<endl;
            int tw=lw+rw+1;
            int tmp=tw*h[i];
            if(tmp>ans) {
                ans=tmp;
            }
        }
        
        return ans;
    }
};