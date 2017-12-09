#include<iostream>
#include<cstdio>
#include<vector>
#define MAX 100003
using namespace std;
int Array[MAX];
int segment[3*MAX];
int value;

void construct_tree(int node, int start, int eend)
{
    if (start==eend)
    {
        segment[node]=Array[start];
        return ;
    }
    construct_tree(2*node,start,(start+eend)/2);
    construct_tree(2*node+1,(start+eend)/2+1,eend);
    segment[node]=segment[2*node]+segment[2*node+1];
}
int query(int node, int start, int eend, int i,int j)
{
    if(i>eend||j<start)
        return 0;
    if(i <= start && j >= eend)
        return segment[node];
    int p=query(node*2,start,(start+eend)/2,i,j);
    int q=query(node*2+1,((start+eend)/2+1),eend,i,j);
    return p+q;
}
void update(int node,int start,int eend,int value,int location)
{

    if(location>eend || location<start)
        return ;
    if(start==eend)
    {
        segment[node]+=value;
        return ;
    }
    update(2*node,start,(start+eend)/2,value,location);
    update(2*node+1,(start+eend)/2+1,eend,value,location);
    segment[node]=segment[2*node]+segment[2*node+1];


}
int main()
{
    int t,testCase;
    scanf("%d ",&testCase);
    for(int t=1;t<=testCase;t++)
    {
        int n,query_number;
        scanf("%d %d",&n,&query_number);
        for(int index=1;index<=n;index++)
            scanf("%d",&Array[index]);
        construct_tree(1,1,n);
                        //for(int index=1;index<=9;index++)
//printf("%d ",segment[index]);
        printf("Case %d:\n",t);
        for(int index=0;index<query_number;index++)
        {
            int q;
            scanf("%d",&q);
            if(q==1)
            {
                int i;
                scanf("%d",&i);
                printf("%d\n",Array[i+1]);

                update(1,1,n,-Array[i+1],i+1);
                Array[i+1]=0;
                //for(int index=1;index<=9;index++)
                    //printf("%d ",segment[index]);
            }
            else if(q==2)
            {
                int i,v;
                scanf("%d %d",&i,&v);
                update(1,1,n,v,i+1);
                Array[i+1]+=v;
                //for(int index=1;index<=9;index++)
                    //printf("%d ",segment[index]);

            }
            else if(q==3)
            {
                int i,j;
                scanf("%d %d",&i,&j);
                printf("%d\n",query(1,1,n,i+1,j+1));
                //for(int index=1;index<=9;index++)
                    //printf("%d ",segment[index]);
            }
        }
    }
    return 0;
}N
