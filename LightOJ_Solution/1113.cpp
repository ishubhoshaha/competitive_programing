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
    freopen("1113.txt","r",stdin);
    cin>>cases;
    cin.ignore();
    for(int caseno=1;caseno<=cases;caseno++){
        cout<<"Case "<<caseno<<":"<<endl;
        string line;
        stack<string> back_stack,for_stack;
        string currentPage= "http://www.lightoj.com/";
        while(getline(cin,line)){
            if(line == "QUIT"){
                break;
            }
            else if(line[0]=='V'){
                string cmd,content;
                stringstream ss(line);
                while(ss>>cmd>>content){
                    back_stack.push(currentPage);
                    currentPage=content;
                    cout<<currentPage<<endl;//<<back_stack.size()<<back_stack.top()<<endl;
                    while(!for_stack.empty()){
                        for_stack.pop();
                    }
                }
            }
            else if(line == "BACK"){
                if(back_stack.empty()){
                    cout<<"Ignored"<<endl;
                }
                else{
                    for_stack.push(currentPage);
                    currentPage = back_stack.top();
                    back_stack.pop();
                    cout<<currentPage <<endl;
                }
            }
            else if(line == "FORWARD"){
                if(for_stack.empty()){
                    cout<<"Ignored"<<endl;
                }
                else{
                    back_stack.push(currentPage);
                    currentPage = for_stack.top();
                    for_stack.pop();
                    cout<<currentPage<<endl;
                }
            }
        }
    }
}
