#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
vector <int > height,height_save, area,area_save;
stack < pair <int,int> >s;
pair<int,int> p,temp;
int fun()
{
    s.push(make_pair(0,0));
    int index=0;
    area=height;
    while(index!=height.size())
    {
        p=s.top();
        if(p.first<height[index])
        {
            s.push(make_pair(height[index],index+1));
        }
        else if( p.first>=height[index])
        {
                //;
            while(p.first >= height[index])
            {
                s.pop();
                p=s.top();
                    //temp=s.top();
                    //cout<<temp.first<<endl;
            }
            temp=s.top();
            s.push(make_pair(height[index],index+1));
            p=s.top();
            int a=(index-temp.second+1)*p.first;
            area[index]=a;
        }
        index++;
    }
}
int main()
{
    int t,testCase;
    scanf("%d",&testCase);
    for(t=1;t<=testCase;t++)
    {
        int n,item;
        //vector <int > height,height_save, area,area_save;
        //stack < pair <int,int> >s;
        //pair<int,int> p,temp;
        height.clear();
        height_save.clear();
        area.clear();
        area_save.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&item);
            height.push_back(item);
        }
        fun();
        height_save=height;
        area_save=area;
        area.clear();
        reverse(height.begin(),height.end());
        fun();
        //
        int re=0;
        reverse(area.begin(),area.end());
        height.clear();
        for(int i=0;i<height_save.size();i++)
            height.push_back( area_save[i] + area[i] - height_save[i] );
        for(int i=0;i<height.size()-1;i++)
            {re = max(re,height[i]);}
        printf("Case %d: %d\n",t,re);
    }
return 0;

    }
