struct Node{
    int x;
    int y;
    int t;
};

class Solution {
public:
    int time[15][15];
    int xx[4]={1,0,-1,0};
    int yy[4]={0,1,0,-1};
    int ans=0;
    
    int orangesRotting(vector<vector<int>>& g) {
        int m=g.size();
        int n=g[0].size();
        queue<Node*> q;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                time[i][j]=INT_MAX;
                if(g[i][j]==2) {
                    time[i][j]=0;
                    ans=0;
                    q.push(make_node(i,j,0));
                }
            }
        }
        while(!q.empty()) {
            Node* f=q.front();
            q.pop();
            for(int i=0;i<4;i++) {
                int x=f->x+xx[i];
                int y=f->y+yy[i];
                if(((x>=0 && x<m) && (y>=0 && y<n)) && (g[x][y]==1 && time[x][y]>f->t+1)) {
                    time[x][y]=f->t+1;
                    ans=max(ans,time[x][y]);
                    q.push(make_node(x,y,f->t+1));
                }
            }
        }
        bool flag=true;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                // cout<<i<<" "<<j<<" "<<g[i][j]<<" "<<time[i][j]<<endl;
                if(g[i][j]==1 && time[i][j]==INT_MAX) {
                    // cout<<"here"<<endl;
                    return -1;
                }
                if(g[i][j]==1) {
                    flag=false;
                }
            }
        }
        // cout<<"here1"<<endl;
        // if(!flag && )
        return ans;
    }
    
    Node* make_node(int x, int y, int t) {
        Node* n=new Node();
        n->x=x;
        n->y=y;
        n->t=t;
        return n;
    }
};