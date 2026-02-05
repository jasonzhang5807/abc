#include <bits/stdc++.h>
using namespace std;
vector<int> k;
vector<int> s;
const unsigned long long p1=0x9e3779b185ebca87;
const unsigned long long p2=0xc2b2ae3d27d4eb4f;
const unsigned long long bu_yao_ka_wo=0xdeadbeefdeadbeef;
unsigned long long hashh(const vector<int>& arr){
        unsigned long long h1=bu_yao_ka_wo,h2=bu_yao_ka_wo;
        for(int num:arr){
                h1=(h1^(unsigned long long)num)*p1;
                h1=(h1>>32)|(h1<<32);
                h2=((h2+(unsigned long long)num)*p2)^(h2>>23);
        }
        return h1^h2;
}
int main(){
		freopen("music.in", "r", stdin);
		freopen("music.out", "w", stdout);
        int n,c,ans=0;
        vector<int> opt;
        cin>>n;
        int tmp;
        for(int i=0;i<n;++i)scanf("%d",&tmp),k.push_back(tmp);
        cin>>c;
        for(int i=0;i<c;++i)scanf("%d",&tmp),s.push_back(tmp);
        sort(s.begin(),s.end());
        unsigned long long hs=hashh(s);
        unsigned long long hsub;
        for(int i=0;i+c<=n;i++){
                auto sub=vector<int>(k.begin()+i,k.begin()+i+c);
                sort(sub.begin(),sub.end());
                int diff=s[0]-sub[0];
                for(auto j=sub.begin();j<sub.end();j++)*j+=diff;
                if(hashh(sub)==hs)ans++,opt.push_back(i+1);
        }
        cout<<ans<<endl;
        sort(opt.begin(),opt.end());
        while(!opt.empty()){
                printf("%d\n",opt.front());
                opt.erase(opt.begin());
        }
        return 0;
}
