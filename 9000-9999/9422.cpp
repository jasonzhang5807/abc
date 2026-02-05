#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(){
        freopen("haiku.in","r",stdin);
        freopen("haiku.out","w",stdout);
        string ipt1,ipt2,ipt3;
        int l1=0,l2=0,l3=0;
        getline(cin,ipt1);
        getline(cin,ipt2);
        getline(cin,ipt3);
        for(int i=0;i<ipt1.size();i++) if(ipt1[i]=='a'||ipt1[i]=='e'||ipt1[i]=='i'||ipt1[i]=='o'||ipt1[i]=='u') l1++;
        for(int i=0;i<ipt2.size();i++) if(ipt2[i]=='a'||ipt2[i]=='e'||ipt2[i]=='i'||ipt2[i]=='o'||ipt2[i]=='u') l2++;
        for(int i=0;i<ipt3.size();i++) if(ipt3[i]=='a'||ipt3[i]=='e'||ipt3[i]=='i'||ipt3[i]=='o'||ipt3[i]=='u') l3++;
        if(l1==5&&l2==7&&l3==5) cout<<"YES";
        else cout<<"NO";
        return 0;
}
