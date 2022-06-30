class Solution {
public:
    
    int n;
    int indx;
    
    void rec(vector<int> arr, int min, int max) {
        if(indx>=n) {
            return;
        }
        // cout<<"val = "<<arr[indx]<<" min = "<<min<<" max = "<<max<<endl;
        if(indx<n && (arr[indx]>min && arr[indx]<max)) {
            int root_val=arr[indx];
            indx++;
            rec(arr,min,root_val);
            rec(arr,root_val,max);
        }
    }
    
    bool verifyPreorder(vector<int>& arr) {
        n=arr.size();
        indx=0;
        rec(arr,INT_MIN,INT_MAX);
        return indx==n?true:false;
    }
};