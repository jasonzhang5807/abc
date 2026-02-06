#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
int main(){
        int n,ipt;
        priority_queue<int> small;
        priority_queue<int,vector<int>,greater<int> > large;
        scanf("%d",&n);
        scanf("%d",&ipt);
        large.push(ipt);
        printf("%d ",ipt);
        for(int i=1;i<n;i++){
                scanf("%d",&ipt);
                if(ipt>=large.top()){
                        if(large.size()>small.size()){
                                large.push(ipt);
                                small.push(large.top());
                                large.pop();
                        }
                        else large.push(ipt);
                }
                else{
                        small.push(ipt);
                        if(large.size()<small.size()) large.push(small.top()),small.pop();
                }
                if(large.size()==small.size()+1) printf("%d ",large.top());
        }
        return 0;
}
