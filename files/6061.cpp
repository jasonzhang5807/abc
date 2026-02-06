#include <bits/stdc++.h>
#define maxn 50010
using namespace std;
struct lr{
        int l,r;
        inline bool operator<(const lr &nxt)const{return r>nxt.r||r==nxt.r&&l<nxt.l;}
        inline bool operator==(const lr &nxt)const{return l==nxt.l&&r==nxt.r;}
} a[maxn];
int main(){
	freopen("cover.in", "r", stdin);
	freopen("cover.out", "w", stdout);
        int n;
        cin>>n;
        for(int i=0;i<n;++i)scanf("%d%d",&a[i].l,&a[i].r);
        sort(a,a+n);
        n=unique(a,a+n)-a;
        int cnt=1,sta=a[0].l,nd=a[0].r;
        for(int i=1;i<n;++i){
                if(a[i].l>=sta)sta=a[i].l,nd=a[i].r;
                else if(sta>=a[i].r)++cnt,sta=min(a[i].l,sta);
        }
        cout<<cnt;
        return 0;
}
