#include <bits/stdc++.h>
#define dt 505
using namespace std;
const int dx[]={0,0,-1,1};
const int dy[]={-1,1,0,0};
int mp[1010][1010];
int main(){
        int bx,by,n;
        cin>>bx>>by>>n;
        memset(mp,0x3f,sizeof(mp));
        for(int i=0;i<n;++i){
                int x,y;
                scanf("%d%d",&x,&y);
                mp[x+dt][y+dt]=0xdeadbeef;
        }
        mp[dt][dt]=0;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
                int x=q.front().first,y=q.front().second;
                q.pop();
                if(x==bx&&y==by)break;
                for(int i=0;i<4;++i){
                        if(x+dx[i]<-502||x+dx[i]>502||y+dy[i]>502||y+dy[i]<-502)continue;
                        if(mp[x+dt][y+dt]+1>=mp[x+dx[i]+dt][y+dy[i]+dt])continue;
                        if(mp[x+dx[i]+dt][y+dy[i]+dt]==0xdeadbeef)continue;
                        mp[x+dx[i]+dt][y+dy[i]+dt]=mp[x+dt][y+dt]+1;
                        q.push({x+dx[i],y+dy[i]});
                }
        }
        cout<<mp[bx+dt][by+dt];
        return 0;
}

