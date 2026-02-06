#include <bits/stdc++.h>
using namespace std;
const int N=21,M=1e5+5;
int m,n,l[N*N],st[N],lst[N],ans;
struct{int id,c;}a[N][N];
int mac[N][M];
int main(){
	freopen("jsp.in", "r", stdin);
	freopen("jsp.out", "w", stdout);
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n*m;i++)scanf("%d",l+i);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j].id);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j].c);
    for(int i=1;i<=n*m;i++){
        int x=l[i]; st[x]++;
        int id=a[x][st[x]].id,c=a[x][st[x]].c,s=0;
        for(int j=lst[x]+1;;j++){
            s=mac[id][j]?0:s+1;
            if(s==c){
                for(int k=j-c+1;k<=j;k++)mac[id][k]=1;
                ans=max(ans,j); lst[x]=j;
                break;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
