#include <bits/stdc++.h>
#define maxn 55
#define mv 2500
using namespace std;
long long n,a,x[maxn],f[maxn][5010];
int main(){
    cin>>n>>a;
    for(int i=1;i<=n;++i)scanf("%lld",&x[i]),x[i]-=a;
    f[0][mv]=1;
    for(int i=1;i<=n;++i){
        for(int j=-mv;j<=mv;++j){
            f[i][j+mv]+=f[i-1][j+mv];
            if(-mv<=j-x[i]&&j-x[i]<=mv)f[i][j+mv]+=f[i-1][j-x[i]+mv];
        }
    }
    printf("%lld",max(1LL*0,f[n][mv]-1));
    return 0;
}
