#include <cstdio>
int hig(int a,int b){
	if(a<b) return b-a;
	if(a>=b) return a-b;
}
int main(){
	freopen("war.in","r",stdin);
	freopen("war.out","w",stdout);
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int dth=hig(a[0],a[1]);
	int poi=0;
	for(int i=0;i<n;i++){
		if(hig(a[i],a[(i+1)%n])<dth){
			dth=hig(a[i],a[(i+1)%n]);
			poi=i;
		}
	}
	printf("%d %d",poi+1,(poi+1)%n+1);
	return 0;
}
