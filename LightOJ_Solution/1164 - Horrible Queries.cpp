#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#define MAX 100010
#define ll unsigned long long
using namespace std;
ll Array[3*MAX];
ll segment[3*MAX];
ll propagation[3*MAX];

ll query(ll node,ll start,ll eend,ll i,ll j)
{
    if(i>eend||j<start)
        return 0;
    if(propagation[node]!=0)
    {
        segment[node]+=propagation[node]*(eend-start+1);
        if(start!=eend)
        {
            propagation[2*node]+=propagation[node];
            propagation[2*node+1]+=propagation[node];
        }
        propagation[node]=0;

    }
    if(i <= start && j >= eend)
        return segment[node];
    ll p=query(node*2,start,(start+eend)/2,i,j);
    ll q=query(node*2+1,((start+eend)/2+1),eend,i,j);
    return p+q;
}
void update(ll node,ll start,ll eend,ll i,ll j,ll value)
{
    if(propagation[node]!=0)
    {
        segment[node]+=propagation[node]*(eend-start+1);
        if(start!=eend)
        {
            propagation[2*node]+=propagation[node];
            propagation[2*node+1]+=propagation[node];
        }
        propagation[node]=0;
    }
    if(i>eend || j<start)
        return ;
    if(i<=start && j>=eend)
    {
        segment[node]+=value*(eend-start+1);
        if(start!=eend)
        {
            propagation[2*node]+=value;
            propagation[2*node+1]+=value;
        }
        return ;
    }
    update(2*node,start,(start+eend)/2,i,j,value);
    update(2*node+1,(start+eend)/2+1,eend,i,j,value);
    segment[node]=segment[2*node]+segment[2*node+1];
}
int main()
{
    int t,testCase;
    //freopen("i.txt","r",stdin);
    scanf("%d",&testCase);
    for(t=1;t<=testCase;t++)
    {
        memset(segment,0,sizeof(segment));
        memset(propagation,0,sizeof(propagation));
        int n,query_number;
        scanf("%d %d",&n,&query_number);
        //construct_tree(1,1,n);
        printf("Case %d:\n",t);
        for(int index=0;index<query_number;index++)
        {
            int q;
            scanf("%d",&q);
            if(q==0)
            {
                int index1,index2,value;
                scanf("%d %d %d",&index1,&index2,&value);
                update(1,0,n-1,index1,index2,value);
            }
            else if(q==1)
            {
                int i,j;
                scanf("%d %d",&i,&j);
                printf("%llu\n",query(1,0,n-1,i,j));
            }
        }

    }
    return 0;
}
