#include <cstdio>
#define maxn 110
int a[maxn][maxn];
int dx[]={-1,0,1,-1,1,-1,0,1};
int dy[]={-1,-1,-1,0,0,1,1,1};
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(a[i][j]!=1)continue;
			for(int k=0;k<8;k++)if(a[i+dx[k]][j+dy[k]]==0)a[i+dx[k]][j+dy[k]]=2;
		}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]==2)ans++;
	printf("%d",ans);
	return 0;
}
