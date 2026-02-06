#include <cstdio>
#include <cmath>
int main(){
        freopen("square.in","r",stdin);
        freopen("square.out","w",stdout);
        long long x,y=1;
        scanf("%lld",&x);
        if(x==1){
                printf("1");
                return 0;
        }
        for(int i=2;i<=1000000;i++){
                if(x==1) break;
                int cnt=0;
                while(x%i==0){
                        cnt++;
                        x/=i;
                }
                if(cnt%2==1) y*=i;
        }
        printf("%lld",y*x);
        return 0;
}
