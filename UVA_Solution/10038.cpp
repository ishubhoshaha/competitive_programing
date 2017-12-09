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
int check[3006];
using namespace std;
int main(){
    freopen("i.txt","r",stdin);
    int n;
    while(scanf("%d",&n)==1){
        memset(check,0,sizeof check);
        int arr[3006],dif;
        bool status  = true;
        cin>>arr[0];
        for(int i=1;i<n;i++){
            cin>>arr[i];

            dif = abs(arr[i-1]-arr[i]);
            //cout<<arr[i-1]<<" "<< arr[i]<<" "<<dif<<endl;
            if(dif<n)
                check[dif]=1;
            if(dif<=0 or dif>=n)
                status = false;
        }
        if(!status){
            cout<<"Not jolly"<<endl;
        }
        else{
            for(int i = 1;i<n;i++){
                if(check[i]==0){
                    status = false;
                    break;
                }
            }
            if(status){
                cout<<"Jolly"<<endl;
            }
            else
                cout<<"Not Jolly"<<endl;
        }
    }
}
