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
    ull ugly[5850];
    int p1(0),p2(0),p3(0),p4(0);
    ull c1,c2,c3,c4;
    ugly[0]  = 1;
    for(int i = 1;i < 5850 ;i++){
        ull previous = ugly[i-1];
        while(ugly[p1]*2 <= previous)
            ++p1;
        while(ugly[p2]*3 <= previous)
            ++p2;
        while(ugly[p3]*5 <= previous)
            ++p3;
        while(ugly[p4]*7 <= previous)
            ++p4;
        c1 = ugly[p1] * 2;
        c2 = ugly[p2] * 3;
        c3 = ugly[p3] * 5;
        c4 = ugly[p4] * 7;
        ugly[i] = min(c1,min(c2,min(c3,c4)));
    }
    int n;
    while(cin>>n and n!=0){
        int mod = n % 10;
        int mod2 = n%100;
        if(mod ==1 and mod2!=11)
            printf("The %dst humble number is %d.\n",n,ugly[n-1]);
        else if(mod ==2 and mod2!= 12)
            printf("The %dnd humble number is %d.\n",n,ugly[n-1]);
        else if(mod ==3 and mod2!=13)
            printf("The %drd humble number is %d.\n",n,ugly[n-1]);
        else
            printf("The %dth humble number is %d.\n",n,ugly[n-1]);
    }
}
