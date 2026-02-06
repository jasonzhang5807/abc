#include <cstdio>
#include <queue>
#include <stack>
#include <climits>
int main(){
        int n,m,t,maxa=INT_MAX,maxb=INT_MAX;
        scanf("%d%d",&n,&m);
        int a[n+5],b[n+5];
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<n;i++) scanf("%d",&b[i]);
        std::priority_queue<int> pq;
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        if(i>=maxa&&j>=maxb) break;
                        if(pq.size()<m) pq.push(a[i]+b[j]);
                        else if(pq.top()>a[i]+b[j]){
                                pq.pop();
                                pq.push(a[i]+b[j]);
                        }
                        else maxa=i,maxb=j;
                }
        }
        std::stack<int> prt;
        int p=m;
        while(m--){
                prt.push(pq.top());
                pq.pop();
        }
        while(p--){
                printf("%d\n",prt.top());
                prt.pop();
        }
        return 0;
}
