#include <cstdio>
#include <algorithm>
int main(){
        freopen("cost.in","r",stdin);
        freopen("cost.out","w",stdout);
        int n,a[100010];
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        printf("%d %d\n",a[1]-a[0],a[n-1]-a[0]);
        for(int i=1;i<n-1;i++) printf("%d %d\n",std::min(a[i]-a[i-1],a[i+1]-a[i]),std::max(a[i]-a[0],a[n-1]-a[i]));
        printf("%d %d\n",a[n-1]-a[n-2],a[n-1]-a[0]);
        return 0;
}
