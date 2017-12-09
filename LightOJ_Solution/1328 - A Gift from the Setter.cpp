#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull a[100005];
const int M = 1000007 ;
int main(){
    int test;
    cin>>test;
    for(int t = 1;t<=test;t++){
        memset(a,0,sizeof a);
        ull c,k,n,sum;
        scanf("%lld %lld %lld %lld",&k,&c,&n,&a[0]);
        sum = a[0];
        for(int i = 1;i<n;i++){
            a[i] = (((k %M * a[i-1]%M)%M)%M + c%M)%M;
            sum +=a[i];
            //cout<<a[i]<<" ";
        }
        sort(a,a+n);
        ull x , y = 0,ans = 0,j = n;
        for(int i = 0;i<n;i++){
            x = sum - (a[i]*j--);
            ans = ans + x -y;
            y+=a[i];
            //cout<<ans<<endl;
        }
        printf("Case %d: %lld\n",t,ans);
    }
}
