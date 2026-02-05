#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
int n,a,b,sum,v2[500010],mov,ans;
bool judge(int x){
        int mov=x;
        for(int i=0;i<n;i++) if(v2[i]>x*a) (v2[i]-x*a)%b==0 ? mov-=(v2[i]-x*a)/b : mov-=(v2[i]-x*a)/b+1;
        if(mov<0) return false;
        else{
                ans=x;
                return true;
        }
}
int main(){
        scanf("%d %d %d",&n,&a,&b);
        int v[n];
        for(int i=0;i<n;i++) scanf("%d",&v[i]);
        if(n<1000){
                while(1){
                for(int i=0;i<n;i++){
                        if(v[i]!=0) break;
                        if(i==n-1){
                                printf("%d",ans);
                                return 0;
                        }
                }
                for(int i=0;i<n;i++) v[i] = v[i]<a ? 0 : v[i]-a;
                ans++;
                sort(v,v+n,greater<int>());
                v[0] = v[0]<b ? 0 : v[0]-b;
                }
        }
        int l=0,r=n,mid;
        for(int i=0;i<n;i++) v2[i]=v[i];
        sort(v,v+n);
        while(1){
                mid=(l+r)/2;
                if(judge(mid)==false) l=mid+1;
                else r=mid-1;
                if(l>r) break;
        }
        printf("%d",ans);
        return 0;
}
