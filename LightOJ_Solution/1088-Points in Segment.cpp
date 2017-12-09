#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int LowerBound(int item,int len){
    --len;
    int start = 0,mid,index = -1;
    while(start<=len){
        mid = (start+len)/2;
        if(item==v[mid]){
            index = mid;
            len = mid - 1;
        }
        else if(item<v[mid]){
            len = mid-1;
        }
        else if(item>v[mid]){
            start = mid+1;
        }
    }
    return start;
}
int UpperBound(int item,int len){
    --len;
    int start = 0,mid,index = -1;
    while(start<=len){
        mid = (start+len)/2;
        if(item==v[mid]){
            index = mid;
            start = mid + 1;
        }
        else if(item<v[mid]){
            len = mid-1;
        }
        else if(item>v[mid]){
            start = mid+1;
        }
    }
    return len+1;
}
int main(){
    //freopen("inp.txt","r",stdin);
    int test;
    cin>>test;
    for(int cases = 1;cases<=test;cases++){
        printf("Case %d:\n",cases);
        v.clear();
        int n,query;
        scanf("%d %d",&n,&query);
        for(int i = 0;i<n;i++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.len());
        for(int i = 0;i<query;i++){
            int s,e;
            scanf("%d %d",&s,&e);
            //cout<<UpperBound(e,n)<<" " << LowerBound(s,n)<<endl;
            printf("%d\n",(UpperBound(e,n))-LowerBound(s,n));
        }
    }
}
