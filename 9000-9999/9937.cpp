#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int n,m,x,y;
	freopen("class.in","r",stdin);
	freopen("class.out","w",stdout);
	cin>>n>>m>>x>>y;
	if((x-1)%(2*m)<m)x=(x-1)%m+1;
	else x=m-(x-1)%m;
	if((y-1)%(2*m)<m)y=(y-1)%m+1;
	else y=m-(y-1)%m;
	if(x==y)cout<<"YES";
	else cout<<"NO";
	return 0;
}
