#include <iostream>
#include <string>
using namespace std;
int main(){
	int len;
	string s[100010];
	for(int i=0;i<=100000;i++){
		getline(cin,s[i]);
		if(s[i]=="end"){
			len=i;
			break;
		}
	}
	for(int i=len-1;i>=0;i--) cout<<s[i]<<endl;
	return 0;
}
