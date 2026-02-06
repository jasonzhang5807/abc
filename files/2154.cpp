#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
int mod=1000000007;
struct martix{
    int s;
    long long val[110][110];
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
    long long p,q,n;
    cin>>p>>q>>n;
    martix x;
    x.s=2;
    x.val[1][1]=0;
    x.val[1][2]=-q;
    x.val[2][1]=1;
    x.val[2][2]=p;
    martix ans=ksm(x,n-1);
    //cout<<ans.val[1][1]<<" "<<ans.val[1][2]<<"\n"<<ans.val[2][1]<<" "<<ans.val[2][2]<<'\n';
    cout<<(2*ans.val[1][2]%mod+p%mod*ans.val[2][2]%mod+3LL*mod)%mod;
    return 0;
}
