#include <bits/stdc++.h>
using namespace std;
int main(){
        freopen("master.in", "r", stdin);
        freopen("master.out", "w", stdout);
        string a,b;
        int n,k,ans=0;
        ios::sync_with_stdio(0);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cin>>n>>k>>a>>b;
        for(int la=0;la<n;++la)
                for(int lb=0;lb<n;++lb){
                        int an=0;
                        int buf=k;
                        for(;;++an){
                                if(la+an>=n||lb+an>=n)break;
                                if(a[la+an]!=b[lb+an])--buf;
                                if(buf<0)break;
                        }
                        ans=max(ans,an);
                }
        cout<<ans;
        return 0;
}
