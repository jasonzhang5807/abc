#include <bits/stdc++.h>
#define maxn 210
using namespace std;
int a[maxn],b[maxn];
int ans;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)scanf("%d%d",&a[i],&b[i]);
    for(int i=1;i<=n;++i)
        ans+=a[i]*b[i%n+1]-a[i%n+1]*b[i];
    ans=abs(ans)>>1;
    cout<<ans;
    return 0;
}
