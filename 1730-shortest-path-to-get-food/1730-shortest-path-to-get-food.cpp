class Solution {
public:
    struct Node {
        int x;
        int y;
        int d;
    };
    
    Node* newNode(int x, int y, int d) {
        Node* n=new Node();
        n->x=x;
        n->y=y;
        n->d=d;
        return n;
    }
    
    bool vis[210][210];
    int xx[4]={1,0,-1,0};
    int yy[4]={0,1,0,-1};
    
    int getFood(vector<vector<char>>& g) {
        int m=g.size();
        int nn=g[0].size();
        int sx=-1,sy=-1;
        for(int i=0;i<m;i++) {
            for(int j=0;j<nn;j++) {
                vis[i][j]=0;
                if(g[i][j]=='*') {
                    sx=i;
                    sy=j;
                }
            }
        }
        queue<Node*> q;
        q.push(newNode(sx,sy,0));
        
        while(!q.empty()) {
            Node* n=q.front();
            q.pop();
            int fx=n->x;
            int fy=n->y;
            vis[fx][fy]=1;
            // cout<<fx<<" "<<fy<<endl;
            if(g[fx][fy]=='#') {
                return n->d;
            }
            for(int i=0;i<4;i++) {
                int nx=fx+xx[i];
                int ny=fy+yy[i];
                if((nx>=0 && nx<m) && (ny>=0 && ny<nn)) {
                    if(vis[nx][ny]==0 && g[nx][ny]!='X') {
                        vis[nx][ny]=1;
                        q.push(newNode(nx,ny,n->d+1));
                    }
                }
            }
        }
        return -1;
    }
};