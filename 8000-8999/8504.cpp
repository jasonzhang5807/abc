#include <cstdio>
int min(int a,int b){
	if(a<b) return a;
	else return b;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int a,b;
	scanf("%d %d",&a,&b);
	if(min(a,b)%2==0) printf("xiaoming");
	else printf("jiajia");
	return 0;
}
