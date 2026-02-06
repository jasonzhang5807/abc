#include <cstdio>
int main(){
        freopen("w.in","r",stdin);
        freopen("w.out","w",stdout);
        int n,m,fyw=0,ans=0;
        scanf("%d%d",&m,&n);
        while(m>0){
                fyw+=m;
                ans+=m;
                m=fyw/n;
                fyw-=m*n;
        }
        printf("%d",ans);
        return 0;
}
