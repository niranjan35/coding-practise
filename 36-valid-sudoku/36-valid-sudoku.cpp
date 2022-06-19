class Solution {
public:
    int r[10][10],c[10][10],tmp[10];
    bool isValidSudoku(vector<vector<char>>& arr) {
        for(int i=0;i<10;i++) {
            for(int j=0;j<10;j++) {
                r[i][j]=0;
                c[i][j]=0;
            }
        }
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(arr[i][j]!='.') {
                    r[i][arr[i][j]-'0'-1]++;
                    c[j][arr[i][j]-'0'-1]++;
                    if(r[i][arr[i][j]-'0'-1]>1 || c[j][arr[i][j]-'0'-1]>1) {
                        return false;
                    }
                }
            }
        }
        for(int i=0;i<9;i+=3) {
            for(int j=0;j<9;j+=3) {
                memset(tmp,0,sizeof(tmp));
                for(int x=0;x<3;x++) {
                    for(int y=0;y<3;y++) {
                        if(arr[i+x][j+y]!='.') {
                            tmp[arr[i+x][j+y]-'0'-1]++;
                            if(tmp[arr[i+x][j+y]-'0'-1]>1) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};