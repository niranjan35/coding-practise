class Solution {
public:
    vector<int> ar,bl;
    int minimumDeletions(string s) {
        int tmp=0;
        int n=s.size();
        for(int i=0;i<n;i++) {
            ar.push_back(0);
            bl.push_back(0);
        }
        for(int i=0;i<s.size();i++) {
            bl[i]=tmp;
            if(s[i]=='b') {
                bl[i]++;
            }
            tmp=bl[i];
        }
        tmp=0;
        for(int i=n-1;i>=0;i--) {
            ar[i]=tmp;
            if(s[i]=='a') {
                ar[i]++;
            }
            tmp=ar[i];
        }
        tmp=ar[0];
        for(int i=0;i<n;i++) {
            if(i+1<n && (bl[i]+ar[i+1]<tmp)) {
                tmp=bl[i]+ar[i+1];
            }            
        }
        tmp=min(tmp,bl[n-1]);
        return tmp;
    }
};