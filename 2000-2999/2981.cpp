#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("rank.in","r",stdin);
	freopen("rank.out","w",stdout);
        int n,a,s;
        cin>>n>>a>>s;
        if(a==100||n==1){
                cout<<"1 1";
                return 0;
        }
        if(n*a>=s)cout<<"1 ";
        else cout<<ceil(1.0*(s-n*a)/(100-a))+1<<" ";
        cout<<min(n,(s-a)/(a+1)+1);
        return 0;
}
