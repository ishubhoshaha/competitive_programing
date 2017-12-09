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
int main(){
    int cases;
    //freopen("sp.txt","r",stdin);
    cin>>cases;
    cin.ignore();
    getchar();
    for(int caseno =1;caseno<=cases;caseno++){
        msi treeList;
        treeList.clear();
        int total_tree=0;
        string input;
        while(getline(cin,input)){
            if(input.size()==0)
                break;
            ++total_tree;
            if(treeList.find(input)==treeList.end()){
                treeList[input]=0;
            }
            ++treeList[input];
        }
        for(msi ::iterator mp_it = treeList.begin();mp_it!=treeList.end();mp_it++){
            double a=(double)mp_it->second;
            double res;
            res=a/(double)total_tree;
            printf("%s %.4lf\n",mp_it->first.c_str(),res*100);
            //cout<<mp_it->first<<" "<<<endl;
        }
        if(cases!=caseno)
            cout<<endl;
        //getchar();
    }
}
