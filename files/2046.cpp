#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(){
	freopen("absurdity.in", "r", stdin);
	freopen("absurdity.out", "w", stdout);
    int t;
    string s;
    cin>>t;
    cin>>s;
    int n=s.size();
    long long ans=0;
    for(long long i=1;i<=n;i++){
        ans+=i*i;
        ans%=1000000007;
    }
    cout<<ans;
    return 0;
}
