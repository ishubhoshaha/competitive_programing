// Type: Prime Factorization of factorial number

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
#define INF 2000000000
#define _INF 127
#define _HALF_INF 63
#define rep(i,a,b) for(int i = a; i<b ;i++)
#define open(inp) freopen(inp,"r",stdin)
#define Clear(a) memset(a,0,sizeof(a))
#define setfalse(a) memset(a,false,sizeof(a))
#define pb(number) push_back(number)

using namespace std;
#define MAX 50000
vector<bool> isPrime(MAX,true);
vector<int> primeList;
void sieve(){
    int sqrtN = sqrt(MAX);
    for(int i=4;i<MAX;i+=2)
        isPrime[i] = false;
    for(int i = 3;i<=sqrtN;i++){
        if(isPrime[i])
            for(int j = i*i;j <= MAX;j+=i){
                isPrime[j] = false;
            }
    }
    isPrime[0] = false;
    isPrime[1] = false;
    primeList.pb(2);
    for(int i = 3;i<MAX;i+=2){
        if(isPrime[i]){
            primeList.push_back(i);
        }
    }
}
bool get_decision(int fact,int div){
    map<int,int>f;
    int save_div = div, save_fact = fact;
    for(int i = 0;primeList[i]*primeList[i] <= div;i++){
        if(div%primeList[i] == 0){
            while (div%primeList[i] == 0){
                div/=primeList[i];
                f[primeList[i]]++;
            }
        }
    }
    if(div>1){
        f[div]++;
    }
    //cout<<div;
//    for(map<int,int> ::iterator it = f.begin();it!=f.end();it++){
//            cout<<it->first<<" "<<it->second<<endl;
//    }
    for(map<int,int> ::iterator it = f.begin();it!=f.end();it++){
        int c = 0;
        while(fact!=0 and fact!=1){
            fact = fact/it->first;
            c += fact;
        }
        fact = save_fact;
        //cout<<c<<" "<<it->first<<endl;
        if(c<it->second)
            return false;
    }
    return true;
}
int main(){
    sieve();
    //open("inp.txt");
    int fact,div;
    while(cin>>fact>>div){


        if(get_decision(fact,div) and div != 0){
            printf("%d divides %d!\n",div,fact);
        }
        else
            printf("%d does not divide %d!\n",div,fact);

    }
}
