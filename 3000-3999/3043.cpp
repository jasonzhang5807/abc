#include <bits/stdc++.h>
using namespace std;
int n,r,l[]={-1,6,8,9,10,11,12,12,13,14,14};
int main(){
	freopen("wall.in", "r", stdin);
	freopen("wall.out", "w", stdout);
        cin>>n;
        if(n<=10)cout<<l[n];
        else{r=int(sqrtl(((long double)12)*n-3)/6+0.5);
                cout<<6*r+(n-3*r*r+3*r-1)/r+((n-3*r*r+3*r-1)?1:0);}
        return 0;
}
