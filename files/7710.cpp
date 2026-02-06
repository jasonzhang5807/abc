#include <cstdio>
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
        int n,a;
        scanf("%d",&n);
        a=n;
        for(int i=1;i<=n;i++){
                if(a>0) a%3==0 ? a-=a/3 : a-=a/3+1;
                else{
                        printf("%d ",i-1);
                        break;
                }
        }
        a=n;
        for(int i=1;i<=n;i++){
                if(a>0){
                        if(a%3==1){
                                printf("%d",i);
                                break;
                        }
                        a%3==0 ? a-=a/3 : a-=a/3+1;
                }
        }
        return 0;
}
