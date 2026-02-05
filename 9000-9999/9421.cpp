#include <cstdio>
#include <iostream>
int main(){
	freopen("game.in","r",stdin);
        freopen("game.out","w",stdout);
        int n;
        char p;
        std::cin>>n>>p;
        if(n==1||n>22){
                printf("0");
                return 0;
        }
        if(p=='A'){
                if(n==12||n==2||n==22) printf("3");
                else if(n==11||n==21) printf("16");
                else printf("4");
        }
        else if(p>='2'&&p<='9'){
                if(n<=p-'0'||n>p-'0'+11) printf("0");
                else if(n==2*(p-'0')) printf("3");
                else if(n-(p-'0')==10) printf("16");
                else printf("4");
        }
        else{
                if(n<=10||n==22) printf("0");
                else if(n==20) printf("15");
                else printf("4");
        }
        return 0;
}
