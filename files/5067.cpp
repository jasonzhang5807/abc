#include <cstdio>
int main(){
        int n,p;
        scanf("%d%d",&n,&p);
        int ans=2*p;
        for(int i=p+1;i<=n;i++) ans+=i;
        printf("%d",ans);
        return 0;
}
