#include<bits/stdc++.h>
using namespace std;
#define MAX 20001
vector<int>graph[MAX],xx[MAX];
int visit[MAX];
int color[MAX];
int arr[MAX];
int n,mx = -1;
void initialize(){
    for(int i = 0;i<MAX;i++){
        graph[i].clear();
        visit[i] = false;
        color[i] = 0;
        xx[i].clear();
        arr[i] = i;
    }
}
int Find(int x){
    if(arr[x]==x){
        return x;
    }
    return arr[x] = Find(arr[x]);
}
void Union(int a,int b){
    arr[Find(b)] = Find(a);
}
void bfs(int sx){
    queue<int> q;
    q.push(sx);
    visit[sx] = true;
    int counter = 1;
    color[sx] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0;i<graph[u].size();i++){
            int v = graph[u][i];
            if(!visit[v]){
                color[v] = color[u]+1;
                q.push(v);
                visit[v] = true;
            }
         }
    }

}

int main(){
    int test;
    scanf("%d",&test);
    for(int t=1;t<=test;t++){
        initialize();

        scanf("%d",&n);
        set<int>st;
        for(int i = 0;i<n;i++){
            int u,v;
            scanf("%d %d",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
            Union(u,v);
            mx = max(mx,max(u,v));
            st.insert(u);
            st.insert(v);
        }
        int ans = 0;
        set<int>st1;
        for(set<int>::iterator it = st.begin();it!=st.end();it++){
            int i = *it;
            int x = Find(i);
            st1.insert(x);
            //cout<<i<<" "<<x<<" "<<endl;
            xx[x].push_back(i);

        }

        for(set<int>::iterator it = st1.begin();it!=st1.end();it++){
            int x = *it;
            int r = 0,z = 0;

            if(!visit[x]){
                bfs(x);
            }
            for(int i = 0;i<xx[x].size();i++){
                //cout<<color[xx[x][i]]<<" ";
                if(color[xx[x][i]]%2==1){
                    r++;
                }
                else{
                    z++;
                }
            }
            //cout<<endl<<max(r,z)<<endl;
            ans=ans+max(r,z);
        }
        printf("Case %d: %d\n",t,ans);

    }
}
