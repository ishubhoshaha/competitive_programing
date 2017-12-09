#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int cases = 1;cases<=t;cases++){
        int n,ans=0;
        bool check[50]={false},mineCheck[50]={false};
        cin>>n;
        vector<int>mine,opp;
        for(int i = 0;i<n;i++){
            int a;
            scanf("%d",&a);
            mine.push_back(a);
        }
        for(int i = 0;i<n;i++){
            int a;
            scanf("%d",&a);
            opp.push_back(a);
        }
        sort(mine.begin(),mine.end());
        sort(opp.begin(),opp.end());
        for(int i = 0;i<n;i++){
            for(int j = n-1;j>=0;j--){
                if(mine[i]>opp[j]and !check[j]){
                    ans+=2;
                    check[j] = true;
                    mineCheck[i]=true;
                    break;
                }
            }
        }
        //cout<<ans<<endl;
        for(int i = 0;i<n;i++){
            for(int j = n-1;j>=0;j--){
                if(mine[i]==opp[j] and !check[j]and !mineCheck[i]){
                    ans++;
                    check[j]=true;
                    break;
                }
            }
        }
        printf("Case %d: %d\n",cases,ans);
    }
}
