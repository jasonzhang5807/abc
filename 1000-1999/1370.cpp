#include <bits/stdc++.h>
using namespace std;
int a[1010],lsh[1010];
int main(){
	freopen("tqueue.in", "r", stdin);
	freopen("tqueue.out", "w", stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)scanf("%d",&a[i]),lsh[i]=a[i];
    sort(lsh,lsh+n);
    int m=unique(lsh,lsh+n)-lsh;
    for(int i=0;i<n;i++)a[i]=lower_bound(lsh,lsh+m,a[i])-lsh+1;
    //for(int i=0;i<n;i++)printf("%d ",a[i]);
    //puts("");
    int ans=0;
    for(int i=1;i<=m;i++){
        int tmp=0,now=-1;
        for(int j=0;j<n;j++){
            if(a[j]==i)continue;
            if(now==-1)++tmp,now=a[j];
            else if(now==a[j])++tmp;
            else ans=max(ans,tmp),tmp=1,now=a[j];
        }
        ans=max(ans,tmp);
    }
    cout<<ans;
    return 0;
}
