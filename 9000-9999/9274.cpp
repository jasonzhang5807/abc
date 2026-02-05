#include <bits/stdc++.h>
using namespace std;
int mp[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,t,ans=0;
	cin>>n;
	for(int i=0;i<n;++i){
		scanf("%d",&t);
		++mp[t];
		ans=max(mp[t],ans);
	}
	cout<<ans;
	return 0;
} 
