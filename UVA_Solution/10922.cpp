#include<bits/stdc++.h>

#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define msi map<string, int>

#define visit_ true
#define unvisit_ false
#define ull unsigned long long
#define EPS 1e-9
#define Pi acos(-1.0)
#define INF 20000000
#define _INF 127
#define _HALF_INF 63
#define rep(i,a,b) for(int i = a; i<b ;i++)
#define open(inp) freopen(inp,"r",stdin)
#define Clear(a) memset(a,0,sizeof(a))
#define setfalse(a) memset(a,false,sizeof(a))
#define pb(number) push_back(number)

using namespace std;
int degree = 0;

int digitSum(int sum){
    ++degree;
    int num = 0;
    if(sum<=9){
        return sum;
    }
    while(sum != 0){
        num += (sum%10) ;
        sum/=10;
    }
    sum = num;
    digitSum(sum);
}
int main(){
    string str;
    //open("inp.txt");
    while(cin>>str and str!="0"){
        int sum = 0;
        for(int i = 0;i<str.length();i++){
            sum += str[i] - '0';
        }
        //cout<<sum<<endl;
        int s = digitSum(sum);
        if(s%9==0)
            cout<<str<<" is a multiple of 9 and has 9-degree "<<degree<<"."<<endl;
        else
            cout<<str<<" is not a multiple of 9."<<endl;
        degree = 0;
    }

}
