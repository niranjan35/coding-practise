class Solution {
public:
    int arr[1000];
    int lengthOfLongestSubstring(string str) {
        memset(arr,0,sizeof(arr));
        int n=str.length();
        int s=0,e=0,len=0,mx_len=0;
        bool rep=false;
        while(e<n) {
            if(rep) {
                if(arr[str[s]]==2) {
                    arr[str[s]]=1;
                    rep=false;
                }
                else {
                    arr[str[s]]--;
                }
                s++;
            }
            else {
                arr[str[e]]++;
                if(arr[str[e]]>=2) {
                    rep=true;
                }
                if(!rep && e-s+1>mx_len) {
                    mx_len=e-s+1;
                }
                e++;
            }
        }
        return mx_len;
    }
};