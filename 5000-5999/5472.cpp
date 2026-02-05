#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
pii fa[210][210];
int rnk[210][210];
struct dat{
        int x,y;
        char d;
        inline bool operator<(const dat &nxt)const{
                return (x<<16)+(y<<8)+d<(nxt.x<<16)+(nxt.y<<8)+nxt.d;
        }
        inline bool operator==(const dat &nxt)const{
                return x==nxt.x&&y==nxt.y&&d==nxt.d;
        }
};
set<dat> unq;
pii fnd(pii x){
        if(fa[x.first][x.second]!=x)fa[x.first][x.second]=fnd(fa[x.first][x.second]);
        return fa[x.first][x.second];
}
bool merge(pii x,pii y){
        x=fnd(x);y=fnd(y);
        if(x==y)return true;
        if(rnk[x.first][x.second]<rnk[y.first][y.second])fa[x.first][x.second]=y;
        else fa[y.first][y.second]=x;
        if(rnk[x.first][x.second]==rnk[y.first][y.second])++rnk[y.first][y.second];
        return false;
}
int main(){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)fa[i][j]={i,j};
        for(int ans=1;ans<=m;++ans){
                int x,y;
                char d;
                scanf("%d%d",&x,&y);
                getchar();
                d=getchar();
                if(unq.count({x,y,d}))continue;
                unq.insert({x,y,d});
                //cout<<d<<endl;
                if(d=='D'){
                        if(merge({x,y},{x+1,y})){
                                cout<<ans;
                                return 0;
                        }
                }
                else{
                        if(merge({x,y},{x,y+1})){
                                cout<<ans;
                                return 0;
                        }
                }
        }
        cout<<"draw";
        return 0;
}
