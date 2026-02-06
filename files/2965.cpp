#include <bits/stdc++.h>
#define maxn 1000010
#define mod 1000000007
using namespace std;
int inv[maxn>>1];
int main(){
        freopen("ball.in", "r", stdin);
        freopen("ball.out", "w", stdout);
        int n,m,k;
        cin>>n>>m>>k;
        int a=n-k,b=m-1;
        if(a<b){cout<<0;return 0;}
        if(a==0){cout<<1;return 0;}
        inv[1]=1;
        b=min(b,a-b);
        for(int i=2;i<=b;++i)inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
        long long ans=1;
        for(int i=a;i>a-b;--i)ans*=i,ans%=mod;
        for(int i=1;i<=b;++i)ans*=inv[i],ans%=mod;
        cout<<ans;
        return 0;
}
