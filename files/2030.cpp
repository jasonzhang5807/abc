#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int pr[100010],o[100010];
double f[100010];
double k,c,w;
int main(){
	freopen("mine.in", "r", stdin);
	freopen("mine.out", "w", stdout);
	scanf("%d %lf %lf %lf",&n,&k,&c,&w);
	for(int i=1;i<=n;++i)scanf("%d%d",&o[i],&pr[i]);
	for(int i=n;i>=1;--i){
		if(o[i]==1)f[i]=max(f[i+1],f[i+1]*(1-0.01*k)+pr[i]);
		else f[i]=max(f[i+1],f[i+1]*(1+0.01*c)-pr[i]);
	}
	printf("%.2lf",f[1]*w);
	return 0;
}
