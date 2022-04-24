class Solution {
public:
    int bs(vector<int> arr, int s, int e) {
        if(s>e) {
            return -1;
        }
        int mid=s+((e-s)/2);
        if(((mid-1>=s && arr[mid-1]<arr[mid]) || mid-1<s) && ((mid+1<=e && arr[mid+1]<arr[mid]) || mid+1>e)) {
            return mid;
        }
        else if(((mid-1>=s && arr[mid-1]<arr[mid]) || mid-1<s) && ((mid+1<=e && arr[mid+1]>arr[mid]) || mid+1>e)) {
            return bs(arr,mid,e);
        }
        return bs(arr,s,mid);
    }
    
    int peakIndexInMountainArray(vector<int>& arr) {
        return bs(arr,0,arr.size()-1);
    }
};