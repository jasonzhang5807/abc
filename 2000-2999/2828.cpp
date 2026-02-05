#include <bits/stdc++.h>
#define syc ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int ch[500010][26],rbp,fail[500010],bo[500010];
int main(){syc;
        int t,n;
        cin>>t;
        while(t--){
                memset(bo,0,sizeof(bo));
                memset(ch,0,sizeof(ch));
                memset(fail,0,sizeof(fail));
                rbp=1;
                int ans=0;

                cin>>n;
                for(int i=1;i<=n;++i){
                        string s;
                        cin>>s;
                        int j=1;
                        for(char x:s){
                                if(!ch[j][x-'a'])ch[j][x-'a']=++rbp;
                                j=ch[j][x-'a'];
                        }
                        ++bo[j];
                }
                queue<int> q;
                for(int i=0;i<26;++i)ch[0][i]=1;
                fail[0]=1;
                q.push(1);
                while(!q.empty()){
                        int u=q.front();q.pop();
                        for(int i=0;i<26;++i){
                                if(!ch[u][i])ch[u][i]=ch[fail[u]][i];
                                else{
                                        q.push(ch[u][i]);
                                        fail[ch[u][i]]=ch[fail[u]][i];
                                }
                        }
                }
                string s;
                cin>>s;
                int j=1;
                for(char x:s){
                        int k=j;
                        while(k>1){
                                ans+=bo[k];
                                bo[k]=0;
                                k=fail[k];
                        }
                        j=ch[j][x-'a'];
                }
			    while(j>1){
					ans+=bo[j];
					bo[j]=0;
					j=fail[j];
				}
                cout<<ans<<'\n';
        }
        return 0;
}
