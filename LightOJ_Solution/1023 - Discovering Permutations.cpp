#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
char char_container[27];
int main()
{
    for(int i=0;i<26;i++)
        char_container[i]=i+65;
    //for(int i=0;i<26;i++)
        //cout<<char_container[i]<<" ";
    int cases,caseno;
    scanf("%d",&cases);
    for(caseno=1;caseno<=cases;caseno++)
    {
        int n,k;
        char tempo[27];
        memset(tempo,0,sizeof tempo);
        scanf("%d %d",&n,&k);
        strncpy(tempo,char_container,n);
        int counter=0;
        printf("Case %d:\n",caseno);
        do
        {
        //   cout<<tempo<<endl;
            puts(tempo);
            ++counter;
            if(counter==k)
                break;
        }while(next_permutation(tempo,tempo+n));
    }

}
