#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<stack>
using namespace std;
int Array[100050];
int segment[300050];
void constructTree(int node,int start,int eend)
{
    if(start==eend)
    {
        segment[node]=Array[start];
        return ;
    }
    constructTree(2*node,start,(start+eend)/2);
    constructTree(2*node+1,((start+eend)/2)+1,eend);
    if(segment[2*node]<segment[2*node+1])
        segment[node]=segment[2*node];
    else
        segment[node]=segment[2*node+1];
}
int quaries(int node, int start, int eend, int i,int j)
{
    if(i>eend||j<start)
        return 20000000;
    if(i <= start && j >= eend)
        return segment[node];
    int p=quaries(node*2,start,(start+eend)/2,i,j);
    int q=quaries(node*2+1,((start+eend)/2+1),eend,i,j);
    if(p<q)
        return p;
    else
        return q;
}

int main()
{
    int t,testCase;
    //freopen("ab.txt","r",stdin);
    scanf("%d",&testCase);
    for(t=1;t<=testCase;t++)
    {
        //printf("\n");
        int N,q;
        scanf("\n%d %d",&N,&q);
        for(int index= 1;index<=N;index++)
        {
            scanf("%d",&Array[index]);
        }
        constructTree(1,1,N);
        //for(int index=0;index<N;index++)
            //cout<<Array[index];
        printf("Case %d:\n",t);
        for(int index=0;index<q;index++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            printf("%d\n",quaries(1,1,N,a,b));
        }

    }
    return 0;
}
