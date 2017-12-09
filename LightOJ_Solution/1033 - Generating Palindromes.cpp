#include<bits/stdc++.h>
using namespace std;
#define MAX 102
string A,B;
int dp [MAX][MAX];
int lenA,lenB;
void intialize(){
    for(int i = 0;i<MAX;i++){
        for(int j = 0;j<MAX;j++){
            dp[i][j] = -1;
        }
    }
}
int LCS(int i ,int j){
    if(i==lenA or j==lenB){
        return 0;
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ans = 0;
    if(A[i]==B[j]){
        ans = 1 + LCS(i+1,j+1);
    }
    else{
        int val1 = LCS(i+1,j);
        int val2 = LCS(i,j+1);
        ans = max(val1,val2);
    }

    dp[i][j] = ans;
    return dp[i][j];

}
int main(){
    int test;
    cin>>test;
    for(int t = 1;t<=test;t++){
        intialize();
        cin>>A;
        B = "";
        for(int i = A.size()-1;i>=0;i--){
            B+=A[i];
        }
        lenA = lenB = A.size();
        printf("Case %d: %d\n",t,lenA-LCS(0,0) ) ;

    }
}
