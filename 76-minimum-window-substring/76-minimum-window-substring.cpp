class Solution {
public:
    
    int tmp[26][2];
    int smp[26][2];
    
    bool comp() {
//         cout<<" ------------ "<<endl;
//         for(int i=0;i<26;i++) {
//             cout<<tmp[i][0]<<" ";
//         }
//         cout<<""<<endl;
//         for(int i=0;i<26;i++) {
//             cout<<tmp[i][1]<<" ";
//         }
//         cout<<""<<endl;
        
//         for(int i=0;i<26;i++) {
//             cout<<smp[i][0]<<" ";
//         }
//         cout<<""<<endl;
        
//         for(int i=0;i<26;i++) {
//             cout<<smp[i][1]<<" ";
//         }
//         cout<<""<<endl;
        
        
//         cout<<" ------------------------ "<<endl;
        
        for(int i=0;i<26;i++) {
            if((tmp[i][0] > smp[i][0]) || (tmp[i][1] > smp[i][1])) {
                return false;
            }
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        
        for(int i=0;i<26;i++) {
            tmp[i][0]=0;
            tmp[i][1]=0;
            smp[i][0]=0;
            smp[i][1]=0;
        }
        
        for(int i=0;i<t.size();i++) {
            if(t[i]>='a' && t[i]<='z') {
                tmp[t[i]-'a'][0]++;
            }
            else {
                tmp[t[i]-'A'][1]++;
            }
        }
        
        int i=0,j=0;
        
        int l=-1;
        int ii=-1,jj=-1;
        
        int n=s.size();
        
        if(s[i]>='a' && s[i]<='z') {
            smp[s[i]-'a'][0]++;
        }
        else {
            smp[s[i]-'A'][1]++;
        }
        
        while(j<s.size()) {
            
            bool res=comp();
            
            // cout<<"i = "<<i<<" j = "<<j<<" res = "<<res<<endl;
            
            if(res) {
                if((l==-1) || j-i+1<l) {
                    l=j-i+1;
                    ii=i;
                    jj=j;
                }
            }
            
            if(res && i<j) {
                if(s[i]>='a' && s[i]<='z') {
                    smp[s[i]-'a'][0]--;
                }
                else {
                    smp[s[i]-'A'][1]--;
                }
                i++;
            }
            else {
                // cout<<"here"<<endl;
                if(j<n-1) {
                    j++;
                    if(s[j]>='a' && s[j]<='z') {
                        smp[s[j]-'a'][0]++;
                    }
                    else {
                        smp[s[j]-'A'][1]++;
                    }
                }
                else {
                    break;
                }
            }
            
            // if(j==-1) {
            //     i=0;j=0;
            // }
            // if(s[i]>='a' && s[i]<='z') {
            //     smp[s[i]-'a'][0]++;
            // }
            // else {
            //     smp[s[i]-'A'][1]++;
            // }
        }
        
        if(l==-1) {
            return "";
        }
        
        return s.substr(ii,l);
    }
};