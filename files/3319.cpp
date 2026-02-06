#include <cstdio>
int s[300010];
int main(){
    int n;
    scanf("%d",&n);
    for(int a=0;a<n;++a)scanf("%d",&s[a]);
    int i=0,j=1,k=0;
    while(i<n&&j<n&&k<n){
        if(s[(i+k)%n]==s[(j+k)%n])++k;
        else{
            if(s[(i+k)%n]>s[(j+k)%n])i+=k+1;
            else j+=k+1;
            if(i==j)++i;
            k=0;
        }
    }
    if(i>j)i=j;
    int ei=i-1;
    if(ei==-1)ei+=n;
    for(;i!=ei;i=(i+1)%n)
            printf("%d ",s[i]);
    printf("%d",s[ei]);
    return 0;
}
