#include <bits/stdc++.h>
using namespace std;
string a,b;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b;
    int n=a.size();
    int i=0,j=1,k=0;
    while(i<n&&j<n&&k<n){
        if(a[(i+k)%n]==a[(j+k)%n])++k;
        else{
            if(a[(i+k)%n]>a[(j+k)%n])i+=k+1;
            else j+=k+1;
            if(i==j)++i;
            k=0;
        }
    }
    if(i>j)i=j;
    string zxbsa=a.substr(i)+a.substr(0,i);
    n=b.size();
    i=0,j=1,k=0;
    while(i<n&&j<n&&k<n){
        if(b[(i+k)%n]==b[(j+k)%n])++k;
        else{
            if(b[(i+k)%n]>b[(j+k)%n])i+=k+1;
            else j+=k+1;
            if(i==j)++i;
            k=0;
        }
    }
    if(i>j)i=j;
    string zxbsb=b.substr(i)+b.substr(0,i);
    if(zxbsa!=zxbsb)cout<<"No";
    else cout<<"Yes\n"<<zxbsa;
    return 0;
}
