#include <cstdio>
#include <cmath>
#include <stack>
int main(){
        freopen("number.in","r",stdin);
        freopen("number.out","w",stdout);
        int k;
        scanf("%d",&k);
        if(k==1){
                printf("4");
                return 0;
        }
        if(k==2){
                printf("7");
                return 0;
        }
        int d=int(std::log2(k+1));
        k-=(1<<d)-2;
        k--;
        std::stack<int> prt;
        while(d--){
                if(k%2) prt.push(7);
                else prt.push(4);
                k/=2;
        }
        while(!prt.empty()){
                printf("%d",prt.top());
                prt.pop();
        }
        return 0;
}
