#include<bits/stdc++.h>
using namespace std;
string DecimalToBinary(int decimal){
    string binary ="00000000";
    for(int i = 7 ;i>=0;i--){
        if(decimal%2==1){
            binary[i] = '1';
        }
        decimal/=2;
    }
    return binary;
}
int main(){
    //freopen("inp.txt","r",stdin);
    int test;
    cin>>test;
    //cout<<DecimalToBinary(254)<<endl;
    for(int cs = 1;cs<=test;cs++){
        int a,b,c,d;
        scanf("%d.%d.%d.%d",&a,&b,&c,&d);
        getchar();
        //cout<<a<<b<<c<<d<<endl;
        string binaryVal;
        getline(cin,binaryVal);
        string temp = DecimalToBinary(a)+"."+DecimalToBinary(b)+"."+DecimalToBinary(c)+"."+DecimalToBinary(d);
        //cout<<binaryVal<<endl;
        if(binaryVal==temp){
            printf("Case %d: Yes\n",cs);
        }
        else{
            printf("Case %d: No\n",cs);
        }
    }
}
