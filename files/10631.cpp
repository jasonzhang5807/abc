#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("abc.in","r",stdin);
	freopen("abc.out","w",stdout);
	string s;
	cin>>s;
	if(s=="abc")cout<<0;
	else if(s=="bac"||s=="acb"||s=="cba")cout<<1;
	else cout<<2;
	return 0;
}
