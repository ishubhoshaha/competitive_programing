#include<bits/stdc++.h>
using namespace std;
int a[1000];
bool isOptimal(int n,int m,int currentOptimal){
    int sum = 0,k = 1;
    for(int i = 0;i<n;i++){
        sum = sum + a[i];
        if(sum>currentOptimal){
            sum = a[i];
            k++;
        }
    }
    return k<=m;
}
int main(){
    //freopen("inp.txt","r",stdin);
    int test;
    scanf("%d",&test);
    for(int cs = 0;cs<test;cs++){
        memset(a,0,1000);
        int n,m,low = 0,high = 0,mid;
        scanf("%d %d",&n,&m);
        for(int i =0;i<n;i++){
            scanf("%d",&a[i]);
            //low = min(low,a[i]);
            if(low<a[i])
                low = a[i];
            high+=a[i];
        }
        while(low<high){
            mid = (low+high)/2;
            isOptimal(n,m,mid) ? high = mid : low = mid+1;
        }
        printf("Case %d: %d\n",cs+1,high);
    }
}
