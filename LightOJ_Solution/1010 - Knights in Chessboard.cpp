#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    cin>>test;
    for(int t = 1;t<=test;t++){
        int a,b,m;
        scanf("%d %d",&a,&b);
        printf("Case %d: ",t);
        if(a == 1 or b==1){
            a==1?printf("%d\n",b):printf("%d\n",a);
            continue;
        }
        if(a==2){
            if(b%2==1)
                printf("%d\n",a+b-1);
            else if(b%4==0){
                printf("%d\n",b);
            }else printf("%d\n",a+b);
            continue;
        }else if(b==2){
            if(a%2==1)
                printf("%d\n",a+b-1);
            else if(a%4==0){
                printf("%d\n",a);
            }else printf("%d\n",a+b);
            continue;
        }
        m = a*b;
        if(m%2==1){
            printf("%d\n",(m+1)/2);
        }
        else printf("%d\n",m/2);
    }
    return 0;
}
