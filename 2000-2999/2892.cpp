#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=40010,MAXE=100010;
const int mod=1000000007;
#define u(i) edge[i].second.first
#define v(i) edge[i].second.second
#define w(i) edge[i].first
int n,m,fa[MAXN];
pair<int,pair<int,int>> edge[MAXE];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
bool merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy)return false;
	fa[fx]=fy;
	return true;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0,u,v,w;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		edge[i]={w,{u,v}};
	}
	sort(edge,edge+m);
	for(int i=1;i<=n;i++)fa[i]=i;
	ll cst=0,cnt=1,mergs=0;
	for(int i=0;i<m;){
		int j,num=0,tot=0;
		set<pair<int,int>> st;
		for(j=i;j<m&&w(i)==w(j);j++){
			int u=find(u(j)),v=find(v(j));
			if(v<u)swap(u,v);
			if(u!=v){
				st.insert({u,v});
				tot++;
			}
		}
		for(;i<j;i++)num+=merge(u(i),v(i));
		mergs+=num;
		cst+=num*w(i-1);
		if(tot==3){
			if(num==1||num==2&&st.size()==3)cnt=(cnt*3)%mod;
			if(num==2&&st.size()==2)cnt=(cnt<<1)%mod;
		}
		if(tot==2&&num==1)cnt=(cnt<<1)%mod;
	}
	printf("%lld %lld",cst,cnt);
}
