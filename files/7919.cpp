#include <cstdio>
int main(){
	freopen("letter.in","r",stdin);
	freopen("letter.out","w",stdout);
	int n;
	scanf("%d",&n);
	char a[n];
	char b[n];
	scanf("%s\n%s",a,b);
	int ans=0;
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]){
			ans++;
		}
	}
	printf("%d",ans);
}
