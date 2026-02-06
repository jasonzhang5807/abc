#include <cstdio>
int main(){
        freopen("game.in","r",stdin);
        freopen("game.out","w",stdout);
        int n,d,tt=0;
        scanf("%d %d",&n,&d);
        int t[n];
        for(int i=0;i<n;i++) scanf("%d",&t[i]);
        for(int i=0;i<n;i++) tt+=t[i];
        if(5*n+tt>d||10*n-5>d){
               printf("-1");
               return 0;
        }
        int ans=2*n-1;
        d-=ans*5+tt;
        if(d<0){
                printf("-1");
                return 0;
        }
        printf("%d",ans+d/5);
        return 0;
}
