#include <cstdio>
#include <cmath>
#include <algorithm>
int main(){
	freopen("triangle.in","r",stdin);
        freopen("triangle.out","w",stdout);
        int a,b;
        scanf("%d%d",&a,&b);
        if(a==b){
                printf("%.3lf",1.414214*a);
                return 0;
        }
        else{
                if(a>b) std::swap(a,b);
                printf("%.3lf",sqrt(b*b-a*a));
        }
        return 0;
}
