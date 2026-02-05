#include <cstdio>
int n[100][100];
int nn;
int r=-1,c=-1;
bool odd(bool row,int a){
	int add=0;
	if(row){
		for(int i=0;i<nn;i++){
			add+=n[a][i];
		}
	}
	else{
		for(int i=0;i<nn;i++){
			add+=n[i][a];
		}
	}
	if(add%2==0){
		return false;
	}
	else{
		return true;
	}
}
int main(){
	scanf("%d",&nn);
	for(int i=0;i<nn;i++){
		for(int j=0;j<nn;j++){
			scanf("%d",&n[i][j]);
		}
	}
	for(int i=0;i<nn;i++){
		if(odd(true,i)&&r==-1){
			r=i;
		}
		else if(odd(true,i)&&r!=-1){
			printf("Corrupt");
			return 0;
		}
		if(odd(false,i)&&c==-1){
			c=i;
		}
		else if(odd(false,i)&&c!=-1){
			printf("Corrupt");
			return 0;
		}
	}
	//printf("%d %d",r,c);
	if(r+c==-2){
		printf("OK");
	}
	else{
		printf("%d %d",r+1,c+1);
	}
	return 0;
}
