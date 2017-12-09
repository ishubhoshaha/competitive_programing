#include<bits/stdc++.h>

#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define msi map<string, int>

#define visited_ true
#define unvisited_ false
#define ull unsigned long long
#define EPS 1e-9
#define Pi acos(-1.0)
#define INF 2000000000
#define _INF 127
#define _HALF_INF 63
#define rep(i,from,to) for(int i = from; i<to ;i++)
#define open(inp) freopen(inp,"r",stdin)
#define Clear(a) memset(a,0,sizeof(a))
#define setfalse(a) memset(a,false,sizeof(a))
#define pb(number) push_back(number)
#define dx4 {-1,+1,0,0}
#define dy4 {0,0,-1,+1}
#define dx8 {-1,0,+1,-1,+1,-1,0,+1}
#define dy8 {+1,+1,+1,0,0,-1,-1,-1}

using namespace std;
#define MAXC 1000
//char A[MAXC],B[MAXC];
string A,B;
int lenA,lenB;
int dp[MAXC][MAXC];
bool visited[MAXC][MAXC];
int calcLCS(int i,int j)
{
    //if(A[i]=='\0' or B[j]=='\0')
    if(lenA==i or lenB==j)
        return 0;
    if(visited[i][j])
        return dp[i][j];

    int ans=0;
    if(A[i]==B[j])
        ans=1+calcLCS(i+1,j+1);
    else{
        int val1=calcLCS(i+1,j);
        int val2=calcLCS(i,j+1);
        ans=max(val1,val2);
    }
    visited[i][j]=1;
    dp[i][j]=ans;
    return dp[i][j];
}
int main() {
    open("lcs.txt");
    while(getline(cin,A) and getline(cin,B)){
        //;
        Clear(dp);
        setfalse(visited);
        lenA=A.length();
        lenB=B.length();
        printf("%d\n",calcLCS(0,0));
        A.clear();
        B.clear();
    }
    return 0;

}
