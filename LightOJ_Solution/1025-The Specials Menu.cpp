#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[61][61];
char str[61];
ll solve(int i,int j){
    if(i>j){
        return 0;
    }
    if(i==j)
        return 1;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(str[i]==str[j]){
        dp[i][j] = 1 + solve(i+1,j) + solve(i,j-1);
    }else{
        dp[i][j] = solve(i+1,j) + solve(i,j-1) - solve(i+1,j-1);
    }
    return dp[i][j];
}
int main(){
    int test;
    scanf("%d",&test);
    for(int t = 1;t<=test;t++){
        memset(dp,-1,sizeof dp);
        scanf("%s",str);
        printf("Case %d: %lld\n",t,solve(0,strlen(str)-1));
    }
}
