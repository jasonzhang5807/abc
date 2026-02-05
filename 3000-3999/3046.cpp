#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
int n;
double l[maxn],r[maxn];
int main(){
	freopen("coin.in", "r", stdin);
	freopen("coin.out", "w", stdout);
        cin>>n;
        for(int i=0;i<n;++i)scanf("%lf",&l[i]);
        for(int i=0;i<n;++i)scanf("%lf",&r[i]);
        sort(l,l+n,greater<double>());
        sort(r,r+n,greater<double>());
        int pl=0,pr=0;
        double sl=0,sr=0;
        double ans=0;
        while(1){
                if(sl-sr>0&&pr<n)sr+=r[pr],++pr;
                else if(pl<n)sl+=l[pl],++pl;
                else break;
                ans=max(ans,min(sl,sr)-pl-pr);
        }
        printf("%.4lf",ans);
        return 0;
}
