#include <cstdio>
int main(){
	freopen("bank.in","r",stdin);
	freopen("bank.out","w",stdout);
	int n;
	scanf("%d",&n);
	if(n<0){
		n*=-1;
		if(n%10>(n%100)/10) printf("%d",-1*(n/10));
		else printf("%d",-1*(n/100*10+n%10));
	}
	else printf("%d",n);
	return 0;
}
