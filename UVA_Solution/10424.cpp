#include<bits/stdc++.h>

#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define msi map<string, int>

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
#define dy4 {-1,+1,0,0}
#define dx8 {-1,0,+1,-1,+1,-1,0,+1}
#define dy8 {+1,+1,+1,0,0,-1,-1,-1}
using namespace std;
int getSum(string str){
    int sum = 0;
    int l = str.length();
    rep(i,0,l){
        if(isalpha(str[i])){
            sum = sum + (tolower(str[i])-96);
        }
    }
    return sum;
}
int getFinalDigit(int num){
    int sum = num;
    while(sum/10!=0){
        int div = sum,s =0;
        while(div!=0){
            s+=div%10;
            div = div/10;
        }
        sum = s;
    }
    return sum;
}
int main(){
    string name1,name2;
    while(getline(cin,name1)){
        getline(cin,name2);
        int word1 = getSum(name1);
        int word2 = getSum(name2);
        word1 = getFinalDigit(word1);
        word2 = getFinalDigit(word2);
        double w1=word1;
        double w2=word2;
        double result;
        if(word1>word2){
            //result = w2/w1;
            result = (double)word2/(double)word1;
        }
        else{
            result = (double)word1/(double)word2;
            //result = w1/w2;
        }
        result*=100;
        printf("%.2lf %%\n",result);
    }
}
