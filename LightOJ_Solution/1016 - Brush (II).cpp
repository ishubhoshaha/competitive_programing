#include<bits/stdc++.h>
#define ull  long long
using namespace std;
int main(){
    //freopen("in.txt","r",stdin);
    int test;
    scanf("%d",&test);
    for(int cs = 1;cs<=test;cs++){
        getchar();
        int n,w;
        ull arr[50000+5];
        scanf("%d %d",&n,&w);
        for(int i = 0;i<n;i++){
            ull x,y;
            scanf("%lld %lld",&x,&y);
            arr[i] = y;
        }
        sort(arr,arr+n);
        ull x = arr[0],y = arr[0] + w,sweep = 1;
        for(int i = 1;i<n;i++){
            if(arr[i]>=x and arr[i]<=y){
                continue;
            }
            else{
                sweep++;
                x = arr[i],y = arr[i] + w;
            }
        }
        printf("Case %d: %lld\n",cs,sweep);
    }
}
