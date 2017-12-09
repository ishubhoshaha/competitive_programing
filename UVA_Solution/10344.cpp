#include<bits/stdc++.h>
using namespace std;
int a[5];
bool solve(int total,int index){
    if(index==5){
        return total==23;
    }
    return solve(total+a[index],index+1) or solve(total-a[index],index+1) or solve(total*a[index],index+1);
}
int main(){
    while(scanf("%d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4])){
        if(a[0]==0 and a[1]==0 and a[2]==0 and a[3]==0 and a[4]==0){
            break;
        }
        sort(a,a+5);
        bool gotit = false;
        do{
            if(solve(a[0],1))
                gotit = true;
        }while(next_permutation(a,a+5));
        if(gotit){
            printf("Possible\n");
        }
        else{
            printf("Impossible\n");
        }
    }
}
