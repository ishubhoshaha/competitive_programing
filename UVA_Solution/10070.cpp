#include<bits/stdc++.h>
using namespace std;

int main(){
    string year;
    freopen("r.txt","r",stdin);
    int bl = 0;
    while(cin>>year){
        if(bl!=0)
            cout<<endl;
        bl=1;
        //cin.ignore();
        int mod4 = 0,mod100 = 0,mod400 = 0,mod15 = 0,mod55 = 0,len;
        len = year.length();
        for(int i =0;i<len;i++){
            mod4 = ( (mod4*10) + (year[i]-'0') )%4;
            mod100 = ( (mod100*10) + (year[i]-'0') )%100;
            mod400 = ( (mod400*10) + (year[i]-'0') )%400;
            mod15 = ( (mod15*10) + (year[i]-'0') )%15;
            mod55 = ( (mod55*10) + (year[i]-'0') )%55;
        }
        //cout<<mod4<<" "<<mod100<<" "<<mod400<<" "<<mod15<<" "<<mod55<<endl;
        bool isLY = false,flag=true;
        if((mod4 == 0 and mod100!=0) or mod400==0){
            cout<<"This is leap year."<<endl;
            isLY=true;
            flag = false;
        }
        if(mod15==0){
            cout<<"This is huluculu festival year."<<endl;
            flag = false;
        }
        if(mod55==0 and isLY){
                cout<<"This is bulukulu festival year."<<endl;
                flag = false;
        }
        if(flag)
            cout<<"This is an ordinary year."<<endl;

       // cout<<endl;
    }
}
