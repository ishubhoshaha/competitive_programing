#include<bits/stdc++.h>

#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define msi map<string, int>
#define mem(arrayName,i) memset(arrayName,int (i),sizeof arrayName)
#define pb(number) push_back(number)
#define _VISIT true
#define _UNVISIT false

#define INF 2000000000
#define _INF 127
#define _HALF_INF 63

using namespace std;
bool compare(pair <int,int> a,pair <int,int> b){
    if(a.second==b.second)
        return a.first>b.first;
    else
        return a.second<b.second;
}
int main(){
    string inp;
    int n=0;
    freopen("r.txt","r",stdin);
    while(getline(cin,inp)){
        if(n!=0)
            cout<<endl;
        n++;
        map<char,int> mp;
        int len = inp.length();
        for(int i = 0;i<len;i++){
            mp[inp[i]]++;
        }
        vpii vec(mp.begin(),mp.end());

        sort(vec.begin(),vec.end(),compare);
        for(int i=0;i<vec.size();i++){
            cout<<vec[i].first<<" "<<vec[i].second<<endl;
        }
        //cout<<endl;
    }
}
