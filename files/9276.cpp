#include <bits/stdc++.h>
#define cl(arr) memset(arr,0,sizeof(arr));
using namespace std;
long long a[200010],f[200010],_sum[200010],leq[1000010];//leq[x]=last x's poi
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cl(a);cl(f);cl(_sum);cl(leq);
        int n;
        cin>>n;
        for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
        for(int i=2;i<=n;++i){
            _sum[i]=_sum[i-1];
            if(a[i]==a[i-1])_sum[i]+=a[i];
        }
        for(int i=1;i<=n;++i){
            f[i]=f[i-1];
            if(leq[a[i]])f[i]=max(f[i],f[leq[a[i]]+1]+a[i]+_sum[i]-_sum[leq[a[i]]+1]);
            leq[a[i]]=i;
        }
        cout<<f[n]<<"\n";
    }
    return 0;
}
