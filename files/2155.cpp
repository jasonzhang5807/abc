#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
int mod=1000000007;
struct martix{
    int s;
    long long val[200][200];
    martix operator*(const martix &nxt)const{
        martix ret;
        ret.s=s;
        memset(ret.val,0,sizeof(ret.val));
        if(s!=nxt.s)exit(1);
        for(int i=1;i<=s;++i){
            for(int j=1;j<=s;++j){
                for(int k=1;k<=s;++k){
                    ret.val[i][j]+=val[i][k]*nxt.val[k][j];
                    ret.val[i][j]%=mod;
                }
            }
        }
        return ret;
    }
};
martix ksm(martix a,long long b){
    martix ret;
    ret.s=a.s;
    memset(ret.val,0,sizeof(ret.val));
    for(int k=1;k<=a.s;++k)ret.val[k][k]=1;
    while(b>0){
        if(b&1)ret=ret*a;
        a=a*a;
        b>>=1;
    }
    return ret;
}
int main(){
    int n,m,s;
    cin>>n>>m>>s;
    int top=n;
    martix x;
    memset(x.val,0,sizeof(x.val));
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        if(w==1){
            ++x.val[u][v];
            continue;
        }
        ++x.val[u][++top];
        for(int i=0;i<w-2;++i)++x.val[top][top+1],++top;
        ++x.val[top][v];
    }
    x.s=top;
    martix ans=ksm(x,s);
    cout<<ans.val[1][n];
    return 0;
}
