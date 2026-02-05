#include <cstdio>
int a[1010];
int main(){
	freopen("time17.in", "r", stdin);
	freopen("time17.out", "w", stdout);
    int poi=1;
    while(1){
        char n=getchar();
        if(n!='0'&&n!='1')break;
        a[poi]=n-'0';
        ++poi;
    }
    const int end=poi+4;
    --poi;
    for(int i=poi;i>0;--i)a[i+4]+=a[i];
    for(int i=end-1;i>0;--i)if(a[i]>=2)a[i]-=2,++a[i-1];
    int i=0;
    while(!a[i])i++;
    for(;i<end;++i)printf("%d",a[i]);
    return 0;
}
