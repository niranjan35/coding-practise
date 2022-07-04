class Solution {
public:
    string nextPalindrome(string num) {
        int n=num.size();
        // n/=2;
        string s="";
        int tmp=-1;
        for(int i=(n-2)/2;i>=0;i--) {
            cout<<i<<endl;
            if(i-1>=0 && num[i]>num[i-1]) {
                tmp=i-1;
                break;
            }
        }
        if(tmp==-1) {
            return "";
        }
        // cout<<"tmp = "<<tmp<<endl;
        s=num.substr(0,(n)/2);
        int tmp1=tmp+1;
        for(int i=tmp+1;i<=(n-1)/2;i++) {
            if(s[i]>s[tmp] && s[tmp1]>s[i]) {
                tmp1=i;
            }
        }
        // cout<<"tmp1 = "<<tmp1<<endl;
        char c=s[tmp];
        s[tmp]=s[tmp1];
        s[tmp1]=c;
        // cout<<"s = "<<s<<endl;
        sort(s.begin()+tmp+1,s.end());
        string rev_s=s;
        reverse(rev_s.begin(),rev_s.end());
        if(n%2!=0) {
            cout<<num<<endl;
            // cout<<"n = "<<n/2<<" "<<num[n/2]<<endl;
            s+=(string(1,num[n/2])+rev_s);
        }
        else {
            s+=rev_s;
        }
        return s;
    }
};