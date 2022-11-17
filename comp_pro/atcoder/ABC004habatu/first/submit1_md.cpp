#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
template<class XXX> void chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
    }
}
template<class XXX> void chmax(XXX &x,XXX y){
    if(x < y){
        x = y;
    }
}
// デバッグの山
typedef pair<int,int> PAIR;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void nowSearch(int &bit,int N){
    debug("=====bit番号 %d について調べていること=====\n",bit);
    for(int pos=0;pos<N;pos=pos+1){
        if((bit & (1<<pos))!=0){
            debug("Mr. %d さん,",pos);
        }
    }
    debug("との関係性を探索します\n");
}

int solver(vector<PAIR> &R,int N,int M){
    int result=0;
    // 関連表
    vector<vector<bool>> RG(N,vector<bool>(N,false));
    // 関連表にセット
    // 個人対個人
    for(int j=0;j<M;j=j+1){
        int x,y;
        x = R[j].first-1;
        y = R[j].second-1;
        RG[x][y]=true;
        RG[y][x]=true;
    }
    // 自分は自分と関連している
    for(int j=0;j<N;j=j+1){
        RG[j][j]=true;
    }
    // ビット全探索
    for(int bit=1;bit<(1<<N);bit=bit+1){
        // nowSearch(bit,N);
        // この時調査したいメンバーをチェック
        vector<int> chain;
        for(int pos=0;pos<N;pos=pos+1){
            if((bit & (1<<pos))!=0){
                chain.push_back(pos);
            }
        }
        int intsize = (int)chain.size();
        // debug chainの中身は?
        
        debug("いま見ようとしているのは ");
        for(int k=0;k<(int)chain.size();k=k+1){
            debug("Mr. %d ",chain[k]);
        }
        debug("との関係性です\n");
        bool ok=true;
        for(int j=0;j<intsize;j=j+1){
            for(int k=0;k<intsize;k=k+1){
                if(!RG[chain[j]][chain[k]]){
                    debug("なんと！ %d 氏と %d 氏の関係がありません。調査断念。\n",chain[j],chain[k]);
                    ok=false;
                    break;
                }
            }
       }
       if(ok){
        debug("最終的に ");
        for(int k=0;k<(int)chain.size();k=k+1){
            debug("Mr. %d ",chain[k]);
        }
        debug("とはお互いに認識していました\n");
        chmax(result,intsize);
       }
       else{
        debug("最終的に ");
        for(int k=0;k<(int)chain.size();k=k+1){
            debug("Mr. %d ",chain[k]);
        }
        debug("とはお互いに認識していません…\n");

       }
    }
    return result;
}
int main(void){
    initial();
    int N,M;
    cin >> N >> M;
    vector<PAIR> R(M);
    for(int j=0;j<M;j=j+1){
        cin >> R[j].first >> R[j].second;
    }
    /**
    for(int j=0;j<M;j=j+1){
        debug("%d と %d は関係があります\n",R[j].first,R[j].second);
    }
    **/
    cout << solver(R,N,M) << "\n" << flush;
    return 0;
}
