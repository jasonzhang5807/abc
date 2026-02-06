#include <cstdio>
#include <algorithm>
int main(){
        freopen("2025.in","r",stdin);
        freopen("2025.out","w",stdout);
        int ans=1,m;
        scanf("%d",&m);
        for(int i=0;i<4050;i++){
                ans*=2025;
                ans%=m;
        }
        ans=(ans+2025)%m;
        printf("%d",ans);
        return 0;
}
