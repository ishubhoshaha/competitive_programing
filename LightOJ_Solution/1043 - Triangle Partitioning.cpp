#include<bits/stdc++.h>
using namespace std;
#define PI 2*acos(0)
#define EPS 1e-7
int main(){
    int test;
    scanf("%d",&test);
    for(int t = 1;t<=test;t++){
        double ab,ac,bc,rat;
        scanf("%lf %lf %lf %lf",&ab,&ac,&bc,&rat);
        rat = rat/(rat+1);
        ac = ab*sqrt(rat);
        printf("Case %d: %.7lf\n",t,ac);
    }
}
