#include <cmath>
#include <cstdio>
bool judge(int p,int q,int u,int v,int x,int y){
        int a=(p-u)*(p-u)+(q-v)*(q-v);
        int b=(p-x)*(p-x)+(q-y)*(q-y);
        int c=(u-x)*(u-x)+(v-y)*(v-y);
        if(a!=0&&b!=0&&c!=0&&(a+b==c||a+c==b||b+c==a)) return true;
        else return false;
}
int main(){
        int p,q,u,v,x,y;
        scanf("%d %d %d %d %d %d",&p,&q,&u,&v,&x,&y);
        if(judge(p,q,u,v,x,y)){
                printf("RIGHT");
                return 0;
        }
        if(judge(p+1,q,u,v,x,y)||judge(p,q+1,u,v,x,y)||judge(p,q,u+1,v,x,y)||judge(p,q,u,v+1,x,y)||judge(p,q,u,v,x+1,y)||judge(p,q,u,v,x,y+1)||judge(p-1,q,u,v,x,y)||judge(p,q-1,u,v,x,y)||judge(p,q,u-1,v,x,y)||judge(p,q,u,v-1,x,y)||judge(p,q,u,v,x-1,y)||judge(p,q,u,v,x,y-1)) printf("ALMOST");
        else printf("NEITHER");
        return 0;
}
