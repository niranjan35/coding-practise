class Solution {
public:
    
    int p[7];
    int sum1,sum2;
    
    int find(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(sum2>sum1) {
            int tmp=sum2;
            sum2=sum1;
            sum1=tmp;
        }
        // cout<<sum1<<" "<<sum2<<endl;
        int i=0;
        int j=n2-1;
        int ans=0;
        while(i<n1 && j>=0) {
            // cout<<"i = "<<i<<" j = "<<j<<endl;
            if(nums1[i]-1>=6-nums2[j]) {
                int tmp=nums1[i]-1;
                ans++;
                if(tmp>=sum1-sum2) {
                    return ans;
                }
                sum1-=tmp;
                i++;
            }
            else {
               int tmp=6-nums2[j];
                // cout<<"tmp = "<<tmp<<" diff = "<<sum1-sum2<<endl;
                ans++;
                if(tmp>=sum1-sum2) {
                    return ans;
                }
                sum2+=tmp;
                j--;
            }
        }
        while(i<n1) {
            int tmp=nums1[i]-1;
            ans++;
            if(tmp>=sum1-sum2) {
                return ans;
            }
            sum1-=tmp;
            i++;
        }
        
        while(j>=0) {
            int tmp=6-nums2[j];
            ans++;
            if(tmp>=sum1-sum2) {
                return ans;
            }
            sum2+=tmp;
            j--;
        }
        return -1;
    }
    
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        p[1]=3;
        p[2]=2;
        p[3]=1;
        p[4]=1;
        p[5]=2;
        p[6]=3;
        sort(nums1.begin(),nums1.end(),greater<int>());
        sort(nums2.begin(),nums2.end(),greater<int>());
        int n1=nums1.size();
        int n2=nums2.size();
        for(int i=0;i<n1;i++) {
            sum1+=nums1[i];
        }
        for(int i=0;i<n2;i++) {
            sum2+=nums2[i];
        }
        
        if(sum1==sum2) {
            return 0;
        }
        
        return sum1>sum2?find(nums1,nums2):find(nums2,nums1);
    }
};