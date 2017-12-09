#include<iostream>
#include<cstdio>
#define ull unsigned long long
#define MOD 10000007

using namespace std;
int a, b, c, d, e, f;
ull dp[10001];
/*ull fn( int n ) {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    if(dp[n-1]!=0)
        return (dp[n-1]%MOD + dp[n-2]%MOD + dp[n-3]%MOD + dp[n-4]%MOD + dp[n-5]%MOD+dp[n-6]%MOD) %MOD;
    return( fn(n-1)%MOD + fn(n-2)%MOD + fn(n-3)%MOD + fn(n-4)%MOD + fn(n-5)%MOD + fn(n-6)%MOD )%MOD;
}*/
int main() {
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    //dp[]
    while( cases-- ) {
        ull temp=0;
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        if(n<6)
        {
            if( n == 0 ) temp=a%MOD;
            else if( n == 1 ) temp=b%MOD;
            else if( n == 2 ) temp=c%MOD;
            else if( n == 3 ) temp=d%MOD;
            else if( n == 4 ) temp=e%MOD;
            else if( n == 5 ) temp=f%MOD;
        }
        else
        {
            for(int i=6;i<=n;i++)
            {
                temp=(a%MOD+b%MOD+c%MOD+d%MOD+e%MOD+f%MOD)%MOD;
                a=b;b=c;c=d;d=e;e=f;f=temp;
            }
        }
        printf("Case %d: %llu\n", ++caseno, temp);
    }
    return 0;
}
