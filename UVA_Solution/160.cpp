#include<bits/stdc++.h>

#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define msi map<string, int>
#define mem(arrayName,i) memset(arrayName,int (i),sizeof arrayName)
#define pb(number) push_back(number)
#define _VISIT true
#define _UNVISIT false
#define ull unsigned long long

#define INF 2000000000
#define _INF 127
#define _HALF_INF 63

using namespace std;
int primeList[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
vector<int> factor[100];
void Factorize(){
    for(int i=2;i<=100;i++){
        //cout<<i<<endl;
        int j(0);
        while(i>=primeList[j]){
            //cout<<j<<endl;
            int div=i,r(0);
            while(div!=1 and div!=0){

                div = floor(div/primeList[j]);
                r+=div;
                //cout<<r<<endl;
            }
            factor[i].pb(r);
            j++;
        }
    }
}
int main(){

    Factorize();
    int n;
    while(scanf("%d",&n)&&n!=0){
        printf("%3d! =",n);
        for(int i=0;i<factor[n].size();i++){

            if(i==15){
                printf("\n%9d",factor[n][i]);
            }
            else
                printf("%3d",factor[n][i]);
        }
        printf("\n");
    }

}
