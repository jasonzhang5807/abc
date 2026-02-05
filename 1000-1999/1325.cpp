#include <cstdio>
#include <algorithm>
using namespace std;
long long n[5][5];
bool andian(int x,int y){
	long long s0[5],s1[5];
	for(int i=0;i<5;i++){
		s0[i]=n[x][i];
		s1[i]=n[i][y];
	}
	sort(s0,s0+5);
	sort(s1,s1+5);
	if(s0[4]==n[x][y]&&s1[0]==n[x][y]){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			scanf("%lld",&n[i][j]);
		}
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(andian(i,j)){
				printf("%lld %lld %lld",i+1,j+1,n[i][j]);
				return 0;
			}
		}
	}
	printf("not found");
	return 0;
}
