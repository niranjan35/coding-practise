class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n/2;j++) {
                int tmp=arr[i][j];
                arr[i][j]=arr[i][n-1-j];
                arr[i][n-1-j]=tmp;
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n-1-i;j++) {
                int tmp=arr[i][j];
                arr[i][j]=arr[n-1-j][n-1-i];
                arr[n-1-j][n-1-i]=tmp;
            }
        }
    }
};