#include <bits/stdc++.h>
using namespace std;
struct tp{
        int a,b,c,r,m,l;
        bool operator<(const tp &nxt){
                if(r-m!=nxt.r-nxt.m)return r-m>nxt.r-nxt.m;
                return m-l>nxt.m-nxt.l;
        }
};
tp a[100010];
int main(){
        freopen("club.in","r",stdin);
        freopen("club.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    int t,n;
    int ba,bb,bc;
    long long ans;
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        ba=bb=bc=n>>1;
        for(int i=1;i<=n;++i){
                cin>>a[i].a>>a[i].b>>a[i].c;
                int x,y,z;
                x=a[i].a;y=a[i].b;z=a[i].c;
                if(y<z)swap(y,z);
                if(x<y)swap(x,y);
                if(y<z)swap(y,z);
                a[i].r=x;a[i].m=y;a[i].l=z;
                }
                sort(a+1,a+n+1);
                for(int i=1;i<=n;++i){
                        if(a[i].r==a[i].a&&ba>0){
                                --ba;
                                ans+=a[i].a;
                        }
                        else if(a[i].r==a[i].b&&bb>0){
                                --bb;
                                ans+=a[i].b;
                        }
                        else if(a[i].r==a[i].c&&bc>0){
                                --bc;
                                ans+=a[i].c;
                        }
                        else if(a[i].m==a[i].a&&ba>0){
                                --ba;
                                ans+=a[i].a;
                        }
                        else if(a[i].m==a[i].b&&bb>0){
                                --bb;
                                ans+=a[i].b;
                        }
                        else if(a[i].m==a[i].c&&bc>0){
                                --bc;
                                ans+=a[i].c;
                        }
                        else if(a[i].l==a[i].a&&ba>0){
                                --ba;
                                ans+=a[i].a;
                        }
                        else if(a[i].l==a[i].b&&bb>0){
                                --bb;
                                ans+=a[i].b;
                        }
                        else if(a[i].l==a[i].c&&bc>0){
                                --bc;
                                ans+=a[i].c;
                        }
                        else cout<<"err\n";
                }
                cout<<ans<<'\n';
    }
    return 0;
}
