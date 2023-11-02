#include<bits/stdc++.h>
using namespace std;

vector<string> get_input(){
    vector<string> lines;
    string S;
    while(cin>>S){
        if(S=="."){
            break;
        }
        lines.push_back(S);
    }
    return lines;
}
int solve(const vector<string> &lines){
    map<char,long long> size;
    map<pair<char,int>,long long> ma;
    for(int l=0;l<lines.size();l=l+1){
        string S="";
        string T="";
        bool uhen=false;
        for(int j=0;j<lines[l].size();j=j+1){
            if(lines[l][j]=='=')uhen=true;
            else if(!uhen) S=S+lines[l][j];
            else T=T+lines[l][j];
        }
        if(T == ""){
            char name=S[0];
            long long val=0;
            for(int j=2;j+1<S.size();j=j+1){
                val=(val*10)+(S[j]-'0');
            }
            siz[name]=val;
        }else{
            vector<char> st;
            char left_char;
            long long left_ind=0;
            for(auto c:S){
                if(c=='[')continue;
                else if(c == ']'){
                    while(!st.empty()){
                        if(siz[st.bach()] <= left_ind){
                            return l+1;
                        }
                        if(st.size() == 1){
                            left_char=st[0];
                        }
                        // TODO:L51
                    }
                }
            }
        }
    }
}
