class Solution {
public:
    
    string w;
    vector<vector<char>> b;
    int m,n;
    int xx[4]={1,0,-1,0};
    int yy[4]={0,1,0,-1};
    
    bool rec(int x, int y, int indx) {
        if(indx>=w.size()) {
            return true;
        }
        if(x<0 || x>=m || y<0 || y>=n || w[indx]!=b[x][y]) {
            return false;
        }
        char c=b[x][y];
        b[x][y]='#';
        for(int i=0;i<4;i++) {
            if(rec(x+xx[i],y+yy[i],indx+1)) {
                return true;
            }
        }
        b[x][y]=c;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        w=word;
        b=board;
        m=b.size();
        n=b[0].size();
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(rec(i,j,0)) {
                    return true;
                }
            }
        }
        return false;
    }
};