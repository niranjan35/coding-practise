class Solution {
public:
    string arr[5000];
    
    void rec(int n) {
        if(n==1) {
            return;
        }
        int l=0,r=n-1;
        while(l<r) {
            arr[l]="("+arr[l]+","+arr[r]+")";
            l++;
            r--;
        }
        rec(r+1);
    }
    
    string findContestMatch(int n) {
        for(int i=0;i<n;i++) {
            arr[i]=to_string(i+1);
            // cout<<arr[i]<<endl;
        }
        rec(n);
        return arr[0];
    }
};