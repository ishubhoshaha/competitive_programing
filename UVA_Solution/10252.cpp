#include<bits/stdc++.h>
using namespace std;
int check[1005];
int main(){
    string a,b;
    while(getline(cin,a)){
        getline(cin,b);
        memset(check,0,sizeof check);
        multiset<char> st;
        int len = a.length();
        for(int i =0;i<len;i++){
            if(a[i]==' '){
                ++check[1002];
                continue;
            }
            ++check[a[i]-97] ;
        }
        len = b.length();
        for(int i = 0;i<len;i++){
            if(b[i]==' ' and check[1002]!=0){
                st.insert(' ');
                --check[1002];
                continue;
            }
            if(check[b[i]-97] != 0){
                --check[b[i]-97];
                st.insert(b[i]);
            }
        }
        for(multiset<char> ::iterator st_it = st.begin();st_it!=st.end();st_it++){
            cout<<*st_it;
        }
        cout<<endl;
    }
}
