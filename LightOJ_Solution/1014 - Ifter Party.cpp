#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
vector <int> q;
int main()
{
    int t,testCase;
    int leftPiaju,piaju,i;
    scanf("%d",&testCase);
    for(t=1;t<=testCase;t++)
    {
        q.clear();
        scanf("%d %d",&piaju,&leftPiaju);
        int ate=piaju-leftPiaju;
        int sqrtL=sqrt(ate);
        if(ate>leftPiaju)
        {
            for(i=1;i<=sqrtL;i++)
            {
                if(ate%i==0)
                {
                    if(i>leftPiaju)
                    {
                        q.push_back(i);


                    }
                    if(ate/i!=i && ate/i>leftPiaju)
                            q.push_back(ate/i);
                }
            }
        }

        if(q.size()==0)
            printf("Case %d: impossible\n",t);
        else
        {
            sort(q.begin(),q.end());
            printf("Case %d: ",t);
            for(i=0;i<q.size();i++)
            {
                if(i==q.size()-1)
                    printf("%d",q[i]);
                else
                    printf("%d ",q[i]);
            }
            printf("\n");
        }

    }
}
