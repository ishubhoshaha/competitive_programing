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
    string str;
    bool flag=true;
    freopen("r.txt","r",stdin);
    freopen("o.txt","w",stdout);
    while(getline(cin,str)){
        for(int i=0;i<str.size();i++){
            if(str[i]=='"' && flag==true){
                cout<<"``";
                flag = false;
            }
            else if(str[i]=='"' && flag == false){
                cout<<"''";
                flag = true;
            }
            else
                cout<<str[i];
        }
        cout<<endl;
    }
}
