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
vi pset(100005);
vi frnd_counter(100005);
int rV ;
void initSet(int f){
    pset.resize(f);
    for(int i=0;i<=f;i++){
        pset[i]=i;
        frnd_counter[i]=1;
    }
}
int findSet(int i){
    return (pset[i]==i) ? i : (pset[i]=findSet(pset[i]));
}
bool isSameSet(int i,int j){
    return (findSet(i) == findSet(j)) ? true : false;
}
int frndSearch(int i){
    return (pset[i]==i) ? frnd_counter[i] : ( frnd_counter[i] = frnd_counter[findSet(pset[i])] ) ;
}
int unionSet(int i,int j){
    rV=frnd_counter[i];
    if(!isSameSet(i,j)){
        int x,y;
        x = findSet(i);
        y = findSet(j);
        frnd_counter[y] += frnd_counter[x];
        frnd_counter[x] = frnd_counter[y];
        return frnd_counter[y];
    }
    return frndSearch(i);
}
int main(){
    int testCase;
    //freopen("11503.txt","r",stdin);
    cin>>testCase;
    cin.ignore();
    for(int caseno=1;caseno<=testCase;caseno++){
        pset.clear();
        frnd_counter.clear();
        msi frndIndex;
        frndIndex.clear();
        int f,l=1;
        cin>>f;
        cin.ignore();
        initSet(f);
        for(int j=1;j<=f;j++){
            string frnd1,frnd2;
            cin>>frnd1>>frnd2;
            if(frndIndex.find(frnd1)==frndIndex.end()){
                frndIndex[frnd1]=l;
                ++l;
            }
            if(frndIndex.find(frnd2)==frndIndex.end()){
                frndIndex[frnd2]=l;
                ++l;
            }
            cout<<unionSet(frndIndex[frnd1],frndIndex[frnd2])<<endl;
        }
    }
}
