#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int bin(string &n){
        int ret=0;
        for(char x:n){
                ret<<=1;
                ret+=x-'0';
        }
        return ret;
}
int tri(string &n){
        int ret=0;
        for(char x:n){
                ret*=3;
                ret+=x-'0';
        }
        return ret;
}
int main(){
		freopen("digit.in","r",stdin);
	    freopen("digit.out","w",stdout);
        string a,b;
        cin>>a>>b;
        for(int i=0;i<a.length();i++)
                for(int j=0;j<b.length();j++)
                        for(int k=1;k<3;k++){
                                a[i]=((a[i]=='0')?'1':'0');
                                b[j]=(b[j]-'0'+k)%3+'0';
                                if(bin(a)==tri(b)){
                                        cout<<bin(a);
                                        return 0;
                                }
                                a[i]=((a[i]=='0')?'1':'0');
                                b[j]=(b[j]-'0'-k+3)%3+'0';
                        }
        return 0;
}
