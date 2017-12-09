#include<bits/stdc++.h>
#define ull unsigned long long
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define msi map<string, int>
#define mem(arrayName,i) memset(arrayName,int (i),sizeof arrayName)
#define pb(number) push_back(number)
#define _VISIT true
#define _UNVISIT false

#define INF 2000000000
#define _INF 127
#define _HALF_INF 63

using namespace std;

int main(){
    int n;
    freopen("r.txt","r",stdin);
    while(cin>>n and n!=0){
        multiset<int> st;
        st.clear();
        ull result = 0;
        for(int i=0;i<n;i++){
            multiset<int> ::iterator st_it1 , st_it2;
            int d;
            cin>>d;
            //cin.ignore();
            for(int i=0;i<d;i++){
                int num;
                cin>>num;
                st.insert(num);
            }
            st_it1=st.begin();
            st_it2=st.end();
            --st_it2;
            //int k=*st_it2;
            result += *st_it2 - *st_it1;
            st.erase(st_it1);
            //st_it1=st.find(k);
            st.erase(st_it2);
//            cout<<endl<<st.size()<<endl;
//            for(set<int> ::iterator st_it=st.begin();st_it!=st.end();st_it++){
//                cout<<*st_it<<" ";
//            }
           //cout<<endl;
        }
        cout<<result<<endl;
    }
}
