#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int main(){
        freopen("number.in","r",stdin);
        freopen("number.out","w",stdout);
        char ipt[20],ans[20];
        scanf("%s%s",ipt,ans);
        sort(ipt,ipt+strlen(ipt));
        for(int i=0;i<strlen(ipt);i++){
                if(ipt[i]!='0'){
                        swap(ipt[i],ipt[0]);
                        break;
                }
        }
        for(int i=0;i<max(strlen(ans),strlen(ipt));i++){
                if(ipt[i]!=ans[i]){
                        printf("WRONG_ANSWER");
                        return 0;
                }
        }
        printf("OK");
        return 0;
}
