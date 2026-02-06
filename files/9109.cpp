#include <bits/stdc++.h>
using namespace std;
int main(){
        ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        int t;long long n,m;
        cin>>t;
        while(t--){
                cin>>n>>m;
                cout<<(((n/m)*(m-1)+((n%m)?(n%m-1):0)&1)^1)<<endl;
        }
        return 0;
}
