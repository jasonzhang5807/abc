#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
int nxt[maxn];
string s,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(1){
		int ans=0;
		cin>>s>>m;
		if(s[0]=='#')return 0;
		nxt[0]=0;
		for(int i=1,j=1;i<m.size();){
			if(j==1||j==0){
				nxt[i]=0;
				++i;j=i;
				continue;
			}
			j=nxt[j-1]+1;
			if(m[i]==m[j]){
				nxt[i]=j;
				++i;j=i;
			}
		}
		int i=0,j=0;
		while(i<s.size()){
			if(j==m.size())++ans,j=0;
			if(s[i]==m[j])++i,++j;
			else if(j==0)++i;
			else j=nxt[j-1];
		}
		if(j==m.size())++ans;
		cout<<ans<<'\n';
	}
}
