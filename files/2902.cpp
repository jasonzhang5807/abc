#include <bits/stdc++.h>
#define maxn 25010
using namespace std;
struct tx{
	int c,g;
	bool operator<(const tx& nxt){
		if(g<=c&&nxt.g<=nxt.c)return g<nxt.g;
		else if(g<=c&&nxt.g>nxt.c)return true;
		else if(g>c&&nxt.g<=nxt.c)return false;
		else return c>nxt.c;
	}
}; 
int main(){
	int n;
	tx a[maxn];
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].g,&a[i].c);
	sort(a+1,a+n+1);
	int hc=0,ans=0;
	for(int i=1;i<=n;i++){
		hc=(hc<a[i].g)?0:hc-a[i].g;
		ans+=a[i].g;
		hc+=a[i].c;
	}
	ans+=hc;
	cout<<ans;
	return 0;
}
