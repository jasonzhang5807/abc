#include <cstdio>
int main(){
        freopen("rps.in","r",stdin);
        freopen("rps.out","w",stdout);
        char xm,j,xh,ipt[10];
        scanf("%s",ipt);
        xm=ipt[0];
        scanf("%s",ipt);
        j=ipt[0];
        scanf("%s",ipt);
        xh=ipt[0];
        if(xm==j&&xm==xh||xm!=j&&xm!=xh&&j!=xh) printf("?");
        else{
                if(xm==j&&(xm=='r'&&xh=='p'||xm=='p'&&xh=='s'||xm=='s'&&xh=='r')) printf("xiaohong");
                else if(xm==xh&&(xm=='r'&&j=='p'||xm=='p'&&j=='s'||xm=='s'&&j=='r')) printf("jiajia");
                else if(j==xh&&(xm=='r'&&j=='s'||xm=='p'&&j=='r'||xm=='s'&&j=='p')) printf("xiaoming");
                else printf("?");
        }
        return 0;
}
