#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n and n!=0){
        vector<int> v;
        for(int i = 0;i<n;i++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        int maxsofar = 0, maxend = 0;
        for(int i = 0;i<n;i++){
            maxend += v[i];
            if(maxsofar<maxend){
                maxsofar=maxend;
            }
            if(maxend<0){
                maxend = 0;
            }
        }
        //cout<<maxsofar;
        if(maxsofar==0){
            cout<<"Losing streak."<<endl;
        }else{
            cout<<"The maximum winning streak is "<<maxsofar<<"."<<endl;
        }
    }
}
