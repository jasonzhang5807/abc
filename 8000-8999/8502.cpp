#include <cstdio>
int main(){
	freopen("yogurt.in","r",stdin);
	freopen("yogurt.out","w",stdout);
	int n,a,b;
	scanf("%d %d %d",&n,&a,&b);
	if(a*2<=b){
		printf("%d",n*a);
	}
	else{
		printf("%d",n/2*b+n%2*a);
	}
	return 0;
}
