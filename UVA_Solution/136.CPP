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
int main(){
    ull ugly[1501];
    int p1(0),p2(0),p3(0);
    ull c1,c2,c3;
    ugly[0]  = 1;
    for(int i = 1;i <= 1500 ;i++){
        ull previous = ugly[i-1];
        while(ugly[p1]*2 <= previous)
            ++p1;
        while(ugly[p2]*3 <= previous)
            ++p2;
        while(ugly[p3]*5 <= previous)
            ++p3;
        c1 = ugly[p1] * 2;
        c2 = ugly[p2] * 3;
        c3 = ugly[p3] * 5;
        ugly[i] = min(c1,min(c2,c3));
    }
    //859963392
    cout<<"The 1500'th ugly number is "<<ugly[1499]<<"."<<endl;
}
