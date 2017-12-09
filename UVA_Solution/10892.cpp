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

#define MAX 46000
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
    primeList.push_back(2);
    for(int i = 3;i<MAX;i+=2){
        if(isPrime[i]){
            //cout<<i<<" ";
            primeList.push_back(i);
        }
    }
}
int get_factorize(int n){
    int result = 1,sn=n;
    for(int i =0;primeList[i]*primeList[i]<=n;i++){

        int c = 0;
        if(sn%primeList[i]==0){
            while(sn%primeList[i]==0){
                sn = sn/primeList[i];
                ++c;
            }
            result*=(2*c+1);
        }
    }
    if(sn>1){
        result*=3;
    }
    return result;
}
int main()
{
    sieve();
    //cout<<primeList.size()<<endl;
    //cout<<get_factorize(12);
    int n;
    while(cin>>n and n){
        int result = get_factorize(n)+1;
        result/=2;
        cout<<n<<" "<<result<<endl;
    }
}
