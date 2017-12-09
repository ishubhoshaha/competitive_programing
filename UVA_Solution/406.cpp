#include<bits/stdc++.h>

#define ull unsigned long long
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define msi map<string, int>
#define mem(arrayName,i) memset(arrayName,int (i),sizeof arrayName)
#define pb(number) push_back(number)
#define _VISIT true
#define _UNVISIT false

#define INF 2000000000
#define _INF 127
#define _HALF_INF 63

using namespace std;


#define MAX 1500
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
    primeList.pb(1);
    primeList.pb(2);
    for(int i = 3;i<MAX;i+=2){
        if(isPrime[i]){
            //cout<<i<<" ";
            primeList.push_back(i);
        }
    }
    //cout<<primeList.size()<<endl;
}
int main(){
    sieve();
    int n,c;
   // freopen("406.txt","r",stdin);
    while(scanf("%d %d",&n,&c)!=EOF){
        int start,end;
        cout<<n<<" "<<c<<":";
        int number_of_prime=0;
        for(int i= 0;primeList[i]<=n;i++){
                ++number_of_prime;
        }
        //cout<<number_of_prime<<endl;
        if(number_of_prime%2==0){
            if(c*2>=number_of_prime){
                //cout<<"S";
                for(int i = 0;i<number_of_prime;i++)
                    printf(" %d",primeList[i]);//primeList[i]);
                    //cout<<primeList[i]<<" ";
            }
            else{
                start = (number_of_prime-1)/2 - c +1;
                end = (number_of_prime-1)/2 + c;
                for(int i = start;i<=end;i++)
                    printf(" %d",primeList[i]);
            }
        }
        else{
            if((c*2-1)>=number_of_prime){
                for(int i = 0;i<number_of_prime;i++)
                    printf(" %d",primeList[i]);
            }
            else{
                start = (number_of_prime-1)/2 - c +1;
                end = (number_of_prime-1)/2 + c -1;
                for(int i = start;i<=end;i++){
                    printf(" %d",primeList[i]);
                }
            }
        }
        printf("\n\n");
    }
}
