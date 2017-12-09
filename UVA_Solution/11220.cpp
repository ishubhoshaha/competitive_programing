#include<bits/stdc++.h>
#define pii pair<int,int>
#define msi map<string,int>

#define vpii vector<pii>
#define vmsi vector<msi>


#define _visit true
#define _unvisit false
#define pb(n) push_back(n)
#define INF 2000000000

using namespace std;

int main(){
    int testcase;
    freopen("11120.txt","r",stdin);
    cin>>testcase;
    cin.ignore();
    getchar();
    for(int caseno=1;caseno<=testcase;caseno++){
        cout<<"Case #"<<caseno<<":"<<endl;
        string input;
        int i;
        while(getline(cin,input)){
            if(input.length()==0)
                break;
            stringstream ss(input);
            i = 0;
            string word[35];
            while(ss>>word[i]){
                i++;
            }
            //cout<<i<<endl;
            for(int j=0,k=0;j<i;j++){
                int len = word[j].length()-1;
                if(len<k){
                    //cout<<"s";
                    continue;
                }
                cout<<word[j][k++];
            }
            cout<<endl;
        }
        if(caseno!=testcase)
            cout<<endl;

    }
}
