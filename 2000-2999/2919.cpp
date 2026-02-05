#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
int mp[110][110];
int n,m,t,q;
pair<int,int> nxt(int x,int y){
	switch(mp[x][y]){
		case 1:
			return make_pair(x-1,y);
		case 2:
			return make_pair(x+1,y);
		case 3:
			return make_pair(x,y-1);
		case 4:
			return make_pair(x,y+1);
		default:
			exit(0);
	}
}
int main(){
	freopen("snake.in", "r", stdin);
	freopen("snake.out", "w", stdout);
	cin>>n>>m>>t>>q;
	//1up2down3left4right
	//3f3f3f3f=block
	//3f3f3f3f=border
	memset(mp,0x3f,sizeof(mp));
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			mp[i][j]=0;
	while(t--){
		int x,y;
		scanf("%d%d",&x,&y);
		mp[x][y]=0x3f3f3f3f;
	}
	int hx,hy,tx,ty;
	cin>>hx>>hy;
	tx=hx;ty=hy;
	for(int ans=1;ans<=q;++ans){
		int opt;
		scanf("%d",&opt);
		if(opt==1){
			getchar();
			char ve=getchar();
			switch(ve){
				case 'U':
					mp[hx][hy]=1;
					break;
				case 'D':
					mp[hx][hy]=2;
					break;
				case 'L':
					mp[hx][hy]=3;
					break;
				case 'R':
					mp[hx][hy]=4;
					break;
				default:
					break;
			}
			auto v=nxt(hx,hy);
			if(mp[v.first][v.second]){
				printf("%d",ans);
				return 0;
			}
			hx=v.first;
			hy=v.second; 
		}
		else{
			auto v=nxt(tx,ty);
			mp[tx][ty]=0;
			tx=v.first,ty=v.second;
		}
	}
	printf("-1");
	return 0;
}
