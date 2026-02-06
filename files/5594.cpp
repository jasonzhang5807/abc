#include <cstdio>
#include <algorithm>
using namespace std;
int ans[20],cnt;
void f(int n){
        if(n==1) return;
        for(int i=2;i<=n;i++){
                if(n%i==0){
                        ans[cnt]=i;
                        cnt++;
                        f(n/i);
                        break;
                }
        }
}
int main(){
        int n;
        scanf("%d",&n);
        f(n);
        sort(ans,ans+20);
        for(int i=0;i<20;i++) if(ans[i]!=0&&ans[i]!=1) printf("%d ",ans[i]);
        return 0;
}
