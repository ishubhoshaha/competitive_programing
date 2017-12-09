#include<bits/stdc++.h>
using namespace std;
int arr[10005];
int visit[10005];
void init(){
    for(int i = 0;i<10005;i++){
        arr[i] = 0;
        visit[i] = 0;
    }
}
int main(){
    int test;
    scanf("%d",&test);
    for(int t = 1;t<=test;t++){
        int n;
        cin>>n;
        for(int i = 0;i<n;i++){
            scanf("%d",&arr[i]);

        }
        sort(arr,arr+n);
        int x ;
        bool flag = false;
        for(int i = 0;i<n;i++){
            if(arr[i]>=n){
                flag = true;
                break;
            }
            x = arr[i];
            if(visit[x]==0){
                visit[x] = 1;
            }
            else if(visit[n-1-x]==0){
                visit[n-1-x] = 1;
            }
            else{
                flag = true;
                break;
            }

        }
        if(flag){
            printf("Case %d: no\n",t);
        }
        else{
            printf("Case %d: yes\n",t);
        }
        init();
    }
}
