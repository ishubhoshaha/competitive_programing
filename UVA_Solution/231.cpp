#include<bits/stdc++.h>
using namespace std;
vector<int>arr;

int LIS(int n){
    vector<int>lis;
    for(int i = 0;i<n;i++){
        int x = lower_bound(lis.begin(),lis.end(),arr[i])-lis.begin();
        if(x==lis.size()){
            lis.push_back(arr[i]);
        }
        else{
            lis[x] = arr[i];
        }
    }
    return lis.size();

}
int main(){
    int test = 1;

    while(test){
        int n;
        bool notend = false;
        arr.clear();
        //lis.clear();
        while(scanf("%d",&n)==1 and n!=-1){
            notend = true;
            arr.push_back(n);
        }
        reverse(arr.begin(),arr.end());

        if(!notend)
            break;
        if(test!=1)
            printf("\n");
        printf("Test #%d:\n",test++);
        printf("  maximum possible interceptions: %d\n",LIS(arr.size()));
    }
}
