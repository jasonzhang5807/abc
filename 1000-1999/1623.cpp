#include <cstdio>
int main(){
	int n,x,y;
	scanf("%d",&n);
	int a[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=0;
		}
	}
	a[0][n/2]=1;
	x=0;
	y=n/2;
	for(int k=2;k<=n*n;k++){
		if(x==0&&y!=n-1){
			a[n-1][y+1]=k;
			x=n-1;
			y++;
		}
		else if(y==n-1&&x!=0){
			a[x-1][0]=k;
			x--;
			y=0;
		}
		else if(x==0&&y==n-1){
			a[x+1][y]=k;
			x++;
		}
		else{
			if(a[x-1][y+1]==0){
				a[x-1][y+1]=k;
				x--;
				y++;
			}
			else{
				a[x+1][y]=k;
				x++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
