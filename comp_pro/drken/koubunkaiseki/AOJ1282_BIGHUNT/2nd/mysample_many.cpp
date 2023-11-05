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

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
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
    map<char,ll> siz;
    map<pair<char,int>,long long> ma;
    for(int l=0;l<(int)lines.size();l=l+1){
        string S="";
        string T="";
        bool right_side=false;
        string oneLine=lines[l];
        for(int j=0;j<(int)oneLine.size();j=j+1){
            if(oneLine[j]=='='){
                right_side=true;
            }
            else{
                if(right_side==false){
                    S=S+oneLine[j];
                }
                else{
                    T=T+oneLine[j];
                }
            }
        }
        char* sc=const_cast<char*>(S.c_str());
        char* tc=const_cast<char*>(T.c_str());
        debug("左辺の値 %s,右辺の値 %s\n",sc,tc);
        if(T == ""){
            char name=S[0];
            ll val=0;
            for(int j=2;j+1<(int)S.size();j=j+1){
                val=(val*10)+(S[j]-'0');
            }
            siz[name]=val;
        }

        // TODO: mapの取り出しの仕方を試して見る
        // copy.cpp L36の手前
        /**
        auto siz_begin=siz.begin();
        auto siz_end=siz.end();
        for(auto itr=siz_begin;itr!=siz_end;itr++){
            debug("key = %c -> value = %lld\n",itr->first,itr->second);
        }**/
        else{
            vector<char> st;
            char left_char='a';
            long long left_ind=0;
            char* nowS = const_cast<char*>(S.c_str());
            debug("文 %sを調査\n",nowS);
            for(auto c:S){
                debug("文字 %c を調査\n",c);
                if(c=='['){
                    continue;
                }
                else{
                    if(c  == ']'){
                        while(st.empty()==false){
                            if(siz[st.back()] <= left_ind){
                                // 取った範囲の最終文字の配列要素数が右の文字より小さい
                                debug("L.%d エラー感知\n",__LINE__);
                                return l+1;
                            }
                            if((int)st.size()==1){
                                left_char=st[0];
                            }
                            else{
                                if(!ma.count({st.back(),left_ind})){
                                    debug("L.%d エラー感知\n",__LINE__);
                                    return l+1;
                                }
                                left_ind=ma[{st.back(),left_ind}];
                            }
                            st.pop_back();
                        }
                    }
                    else{
                        if(isdigit(c)){
                            left_ind=left_ind*10+(c-'0');
                        }
                        else{
                            st.push_back(c);
                        }

            }
        }
    }
    return 0;
}
int main(void){
    initial();
    vector<string> lines;
    int no=0;
    while((lines=get_input()).empty()==false){
        no=no+1;
        debug("---%d 問題の右辺左辺解析---\n",no);
        cout << solve(lines) << "\n" << flush;
    /**
        for(int j=0;j<(int)lines.size();j=j+1){
            char* c = const_cast<char*>(lines[j].c_str());
            debug("CaseNo.%d Line.%d -> %s \n",no,j+1,c);
        }**/
    }
    return 0;
}
