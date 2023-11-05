#include<bits/stdc++.h>
#ifdef LOCAL
#include"/wrk/sakura-cpp/comp_pro/debug.h"
#include"/wrk/sakura-cpp/comp_pro/t_debug.h"
#include"/wrk/sakura-cpp/lib/dump.hpp"
#else
#define debug(...) 42
#define debug2(...) 42
#define debugt(...) 42
#define to_string(...) 42
#define debug_out(...) 42
#endif
using namespace std;
using ll=long long;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 60;

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
    for(int l=0;l<(int)lines.size();l=l+1){
        string S="";
        string T="";
        bool right_side=false;
        for(int j=0;j<(int)lines[l].size();j=j+1){
            if(lines[l][j]=='='){
                right_side=true;
            }
            else if(right_side == false){
                S=S+lines[l][j];
            }
            else{
                T=T+lines[l][j];
            }
        }
        char* cS = const_cast<char*>(S.c_str());
        char* cT = const_cast<char*>(T.c_str());
        debug("S=%s,T=%s\n",cS,cT);
        if(T == ""){
            char name=S[0];
            long long val=0;
            for(int j=2;j+1<(int)S.size();j=j+1){
                val=(val*10)+(S[j]-'0');
            }
            siz[name]=val;
        }else{
            vector<char> st;
            char left_char;
            long long left_ind=0;
            for(auto c:S){
                if(c=='[')continue;
                else if(c==']'){
                    while(st.empty()==false){
                        if(siz[st.back()]<= left_ind){
                            debug("宣言時の範囲外に値を入れた\n");
                            debug("Error ON %d\n",__LINE__);
                            return l+1;
                        }
                        if((int)st.size()==1){
                            left_char=st[0];
                        }
                        else{
                            if(!ma.count({st.back(),left_ind})){
                                debug("Error ON %d\n",__LINE__);
                                return l+1;
                            }
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
            long long right_val=0;
            for(auto c:T){
                if(c=='[')continue;
                else if(c == ']'){
                    while(st.empty()==false){
                        if(siz[st.back()] <= right_val){
                            debug("右要素実は範囲外\n");
                            debug("Error ON %d\n",__LINE__);
                            return l+1;
                        }
                        if(!ma.count({st.back(),right_val})){
                            debug("初期化してないのに値を入れた!!\n");
                            debug("Error ON %d\n",__LINE__);
                            return l+1;
                        }
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

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    vector<string> lines;
    while((lines=get_input()).empty()==false){
        cout << solve(lines) << "\n" << flush;
    }
    return 0;
}
