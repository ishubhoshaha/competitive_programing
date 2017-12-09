#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("inp.txt","r",stdin);
    int cases;
    cin>>cases;
    for(int test = 1;test<=cases;test++){
        printf("Case %d:\n",test);
        int n,m;
        cin>>n>>m;
        cin.ignore();
        deque<int> dq;
        for(int i = 0;i<m;i++){
            string str,word;
            int number;
            getline(cin,str);
            //cin.ignore();
            stringstream ss(str);
            if(str.length()<=8){
                ss>>word;
            }else{
                ss>>word>>number;
            }
            if(word == "pushLeft"){
                if(dq.size()<n){
                    dq.push_back(number);
                    cout<<"Pushed in left: "<<number<<endl;
                }
                else{
                    cout<<"The queue is full"<<endl;
                }
            }
            else if(word == "pushRight"){
                if(dq.size()<n){
                    dq.push_front(number);
                    cout<<"Pushed in right: "<<number<<endl;
                }
                else{
                    cout<<"The queue is full"<<endl;
                }
            }
            else if(word == "popLeft"){
                if(!dq.empty()){
                    cout<<"Popped from left: "<<dq.back()<<endl;
                    dq.pop_back();
                }else{
                    cout<<"The queue is empty"<<endl;
                }
            }
            else if(word == "popRight"){
                if(!dq.empty()){
                    cout<<"Popped from right: "<<dq.front()<<endl;
                    dq.pop_front();
                }else{
                    cout<<"The queue is empty"<<endl;
                }
            }
        }

    }
}
