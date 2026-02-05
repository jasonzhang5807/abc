
#include <bits/stdc++.h>
using namespace std;
int fa[20000],rnk[20000],c[20];
struct e{
        int u,v,w;
        inline bool operator<(const e &nxt)const{
                return w<nxt.w;
        }
};
e b[1200010];
int fnd(int x){
        if(fa[x]!=x)fa[x]=fnd(fa[x]);
        return fa[x];
}
inline bool merge(int x,int y){
        x=fnd(x),y=fnd(y);
        if(x==y)return false;
        if(rnk[x]<rnk[y])fa[x]=y;
        else{
			fa[y]=x;
        	if(rnk[x]==rnk[y])++rnk[y];
		}
        return true;
}
char buf[1 << 21], *p1 = buf, *p2 = buf;
 inline char gc() {
        if (p1 == p2) {
            p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin);
            if (p1 == p2) return EOF;
        }
        return *p1++;
    }
inline void frd(int &ret){
	char bf;
	while((bf=gc())>='0'){
		if(bf>'9')return;
		ret=ret*10+bf-'0';
	}
}
int main(){
        freopen("road.in","r",stdin);
        freopen("road.out","w",stdout);
        int n=0,m=0,k=0;
        frd(n);frd(m);frd(k);
        for(int i=1;i<=n+k;++i)fa[i]=i;
	int u,v,w;
        for(register int i=1;i<=m;++i){
                u=0,v=0,w=0;
                frd(u);frd(v);frd(w);
                b[i]={u,v,w};
        }
        int bt=m+1;
        for(int i=1;i<=k;++i){
                frd(c[i]);
                for(int j=1;j<=n;++j){
                        w=0;
                        frd(w);
                        b[bt++]={n+i,j,w};
                }
        }
        sort(b+1,b+bt);
        long long ans=0;
        int cnt=0;
        for(register int i=1;i<bt;++i){
                if(cnt>=n-1){
                        bt=i;
                        break;
                }
                if(b[i].u<=n&&merge(b[i].u,b[i].v)){
                        ans+=b[i].w;
                        ++cnt;
                }
        }
        for(int s=1;s<(1<<k);++s){//Kruskal 2^k times -O2 opt O(2^k*n*a)
                cnt=0;
                long long tans=0;
                for(int i=1;i<=k;++i)if((1<<i-1)&s)tans+=c[i];
                for(int i=1;i<=n+k;++i)fa[i]=i,rnk[i]=0;//clear DSU
                for(register int i=1;i<=bt;++i){
                        if(cnt>=n-1+__builtin_popcount(s))break;
                        if(b[i].u>n&&!((1<<b[i].u-n-1)&s))continue;
                        if(merge(b[i].u,b[i].v)){
                                tans+=b[i].w;
                                ++cnt;
                                if(tans>=ans)break;
                        }
                }
                if(cnt>=n-1+__builtin_popcount(s))ans=min(ans,tans);
        }
        printf("%lld",ans);
        return 0;
}
