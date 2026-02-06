#include <cstdio>
int main(){
        freopen("ctime.in","r",stdin);
        freopen("ctime.out","w",stdout);
        int d,h,m;
        scanf("%d%d%d",&d,&h,&m);
        d-=11;h-=11;m-=11;
        int ans=d*1440+h*60+m;
        printf("%d",ans>=0?ans:-1);
        return 0;
}
