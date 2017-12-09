#include<iostream>
#include<vector>
#include<cstdio>
#define ull unsigned long long
#define MAX_N 2000001
#define MOD 1000000007
using namespace std;
//vector <ull> fact_save;
ull fact_save[MAX_N];
ull bigmod ( ull a, ull p, ull m )
{
ull res = 1;
ull x = a;
while ( p )
{
if ( p & 1 ) //p is odd
{
res = ( res * x ) % m;
}
x = ( x * x ) % m;
p = p >> 1;
}
return res;
}
void factorial()
{
long long fact=1;
//fact_save.push_back(1);
fact_save[0]=1;
for(int i=1;i<MAX_N;i++)
{
//fact_save.push_back((i%MOD*fact_save[i-1]%MOD)%MOD);
fact_save[i]=(i%MOD*fact_save[i-1]%MOD)%MOD;
}
}
int main()
{
factorial();
int cases,caseno;
scanf("%d",&cases);
//cout<<fact_save[1000000];
for(caseno=1;caseno<=cases;caseno++)
{
int n,k;
ull ans;
scanf("%d %d",&n,&k);
ans= (fact_save[n+k-1]%MOD * bigmod(fact_save[n],MOD-2,MOD) % MOD * bigmod(fact_save[k-1],MOD-2,MOD) %MOD )%MOD;
printf("Case %d: %llu\n",caseno,ans);
}
return 0;
}