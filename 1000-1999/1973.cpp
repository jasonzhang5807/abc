#include <cstdio>
int cnt[25];
int main(){
        freopen("mars.in", "r", stdin);
        freopen("mars.out", "w", stdout);
        long long ans=0;
        int n,t;
        scanf("%d",&n);
        for(int i=0;i<n;++i){
                scanf("%d",&t);
                for(int k=0;t>0;++k){
                        if(t%2)++cnt[k];
                        t>>=1;
                }
        }
        for(int k=0;k<20;++k)ans+=1LL*cnt[k]*(n-cnt[k])*(1LL<<k);
        printf("%lld",ans);
        return 0;
}
