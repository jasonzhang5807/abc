#include <bits/stdc++.h>
int main(){
	char n[1000];
	scanf("%s",n);
	int ans=0;
	for(int i=0;i<strlen(n);i++){
		if(n[i]!='0'){
			ans++;
		}
	}
	printf("%d\n",ans);
	for(int i=0;i<strlen(n);i++){
		if(n[i]!='0'){
			printf("%c",n[i]);
			for(int j=0;j<strlen(n)-i-1;j++){
				printf("0");
			}
			printf(" ");
		}
	}
	return 0;
}
