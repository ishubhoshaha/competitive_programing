#include<bits/stdc++.h>
using namespace std;
string toLower(string str){
    string temp="";
    for(int i = 0;i<str.size();i++){
        temp+=tolower(str[i]);
    }
    return temp;
}
int main(){
    //freopen("in","r",stdin);
    map<string,pair<string,int> > mp;
    string word;
    cin>>word;
    string temp;

    while(word != "#"){
        temp = toLower(word);
        //cout<<temp;
        sort(temp.begin(),temp.end());
        mp[temp].first = word;
        mp[temp].second++;
        cin>>word;
    }
    vector<string>ans;
    for(map<string,pair<string,int> > ::iterator it  = mp.begin();it!=mp.end();it++){
        if(it->second.second==1){
            ans.push_back(it->second.first);
        }
    }
    sort(ans.begin(),ans.end());
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}
