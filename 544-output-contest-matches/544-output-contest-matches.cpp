class Solution {
public:
    string arr[5000];
    string findContestMatch(int n) {
        for(int i=0;i<n;i++) {
            arr[i]=to_string(i+1);
            // cout<<arr[i]<<endl;
        }
        int l=0,r=n-1;
        while(l<r) {
            while(l<r) {
                arr[l]="("+arr[l]+","+arr[r]+")";
                l++;
                r--;
            }
            l=0;
        }
        return arr[0];
    }
};