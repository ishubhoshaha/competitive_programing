#include<bits/stdc++.h>
using namespace std;
bool flag;
struct compare {
    bool operator()(const std::string& first, const std::string& second) {
        return first.size() < second.size();
    }
};
struct node{
    bool isEnd;
    node *next[11];
    node(){
        isEnd = false;
        for(int i = 0;i<11;i++){
            next[i] = NULL;
        }
    }
};
void Insert(node *root,string inp){
    node *temp = root;
    int n = inp.size();

    for(int i = 0;i<n;i++){
        int id = inp[i]-'0';
        if(temp->next[id] ==NULL){
            temp->next[id] = new node();
        }
        temp = temp->next[id];
    }
    temp->isEnd = true;
}
bool check(node *temp, string inp){
    int n = inp.size();
    for(int i = 0;i<n;i++){
        if(temp->isEnd){
            flag = true;
            return true;
        }
        temp= temp->next[inp[i]-'0'];
    }
    return false;
}
void del(node *cur)
{
      for(int i=0;i<11;i++)
             if(cur->next[i])
                  del(cur->next[i]) ;
          delete(cur) ;
}
int main(){
    //freopen("in.txt","r",stdin);
    int test;
    cin>>test;
    for(int t = 1;t<=test;t++){
        flag  = false;
        node *root = new node();
        int n;
        cin>>n;
        string str[10005];
        for(int i = 0;i<n;i++){
            cin>>str[i];
            Insert(root,str[i]);
        }
        sort(str,str+n,compare());
//        for(int i= 0;i<n;i++){
//            cout<<str[i]<<endl;
//        }
        for(int i = 0;i<n;i++){
            if(check(root,str[i])){
                cout<<"NO\n";
                break;
            }
        }
        if(!flag){
            cout<<"YES\n";
        }
        del(root);
    }
    return 0;
}
