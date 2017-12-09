#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#define MAX 2002
using namespace std;
vector<int> land[MAX],area,tempLand[MAX],tempLand_save,area_save,maxV;
stack<pair <int, int> > s;
pair<int ,int >p,temp;
int Histogram(int row)
{

    temp.first=0;
    temp.second=0;
    s.push(make_pair(-1,0));
    int index=0;
    area=tempLand[row];
    while(index!=tempLand[row].size())
    {
        bool flag=true;
        p=s.top();
        if(p.first<tempLand[row][index])
        {
            s.push(make_pair(tempLand[row][index],index+1));
        }
        else if( p.first>=tempLand[row][index])
        {
            while(p.first >= tempLand[row][index])
            {

                s.pop();
                p=s.top();
            }
            temp=s.top();
                s.push(make_pair(tempLand[row][index],index+1));
            //temp=s.top();
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
    //freopen("i.txt","r",stdin);
    scanf("%d ",&testCase);
    for(t=1;t<=testCase;t++)
    {
        //land.clear();
        tempLand_save.clear();area_save.clear();maxV.clear();
        //land.clear();
        int m,n;
        char ch[MAX];
        scanf("%d %d",&m,&n);
        getchar();
        for(int i=0;i<m;i++)
        {
            gets(ch);
            int j=0;
            while(ch[j]!='\0')
            {
                if(ch[j]=='0')
                land[i].push_back(1);
                else
                    land[i].push_back(0);
                j++;
            }
        }//input cloase

        tempLand[0]=land[0];//assing 1st row of land in templand
        for(int i=0;i<m-1;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(land[i+1][j]==0)
                    tempLand[i+1].push_back(0);
                else
                    tempLand[i+1].push_back(tempLand[i][j]+land[i+1][j]);
            }
        }
        for(int i=0;i<m;i++)
        {
            int re=0;
            Histogram(i);
            tempLand_save=tempLand[i];
            area_save=area;
            reverse(tempLand[i].begin(),tempLand[i].end());
            Histogram(i);
            reverse(area.begin(),area.end());
            tempLand[i].clear();

            //cout<<endl;
            for(int j=0;j<tempLand_save.size();j++)
                tempLand[i].push_back( area_save[j] + area[j] - tempLand_save[j] );
            for(int j=0;j<tempLand[i].size();j++)
            {
                re = max(re,tempLand[i][j]);
                maxV.push_back(re);
            }
        }
        int re=0;
        for(int i=0;i<maxV.size();i++)
        {
            re = max(re,maxV[i]);
        }
        for(int i=0;i<m;i++)
        {land[i].clear();tempLand[i].clear();}
        //cout<<"Case "<<t<<": "<<re<<endl;
        printf("Case %d: %d\n",t,re);


    }//testCase cloase
    return 0;
}
