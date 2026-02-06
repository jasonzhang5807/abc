#include <cstdio>
#include <algorithm>
long long lcm(long long a,long long b){return a/std::__gcd(a,b)*b;}
int main(){
        freopen("multiple.in","r",stdin);
        freopen("multiple.out","w",stdout);
        long long n,a,b,c;
        scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
        printf("%lld",n/a+n/b+n/c-n/lcm(a,b)-n/lcm(a,c)-n/lcm(b,c)+n/lcm(lcm(a,b),c));
        return 0;
}
