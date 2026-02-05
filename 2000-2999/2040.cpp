#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
    long long n;
    cin>>n;
    long long count=0;
    for (long long d=1;d<=n;d++){
        for(long long j=2;true;j+=2){
            long long a=d*j;
            if(a>n)break;
            long long b=a+d;
            if(b>n)break;
            if((a&d)==0)count++;//no bit same
        }
    }
    cout<<count;
    return 0;
}
