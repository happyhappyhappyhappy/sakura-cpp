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
    map<char,long long> siz;
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
        cout << "L->" << l << "  S->" << S << "\n" << flush;
        cout << "L->" << l << "  T->" << T << "\n" << flush;
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
                        if(siz[st.back()] <= left_ind){
                            cout << "L44行目のエラー感知\n" << flush;
                            return l+1;
                        }
                        if(st.size() == 1){
                            left_char=st[0];
                        }
                        else{
                            if(!ma.count({st.back(),left_ind}))return l+1;
                            left_ind=ma[{st.back(),left_ind}];
                        }
                        st.pop_back();
                    }
                }
                else if(isdigit(c)){
                    left_ind=left_ind*10+(c-'0');
                }
                else{
                    st.push_back(c);
                }
            }
            long long right_val = 0;
            for(auto c:T){
                if(c=='[')continue;
                else if(c == ']'){
                    while(!st.empty()){
                        if(right_val >= siz[st.back()]) return l+1;
                        if(!ma.count({st.back(),right_val}))return l+1;
                        right_val=ma[{st.back(),right_val}];
                        st.pop_back();
                    }
                }
                else if(isdigit(c)){
                    right_val=right_val*10+(c-'0');
                }
                else{
                    st.push_back(c);
                }
            }
            ma[{left_char,left_ind}]=right_val;
        }
    }
    return 0;
}
int main(){
    vector<string> lines;
    while(!(lines=get_input()).empty()){

        cout << solve(lines) << "\n" << flush;
    }
    return 0;
}
