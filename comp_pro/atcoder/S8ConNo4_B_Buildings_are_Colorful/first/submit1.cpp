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


void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int solver(int &N,vector<int> &H,int &K){
    int result=1<<28;
    // for(int j=0;j<N;j=j+1){
    //     cout << H[j] << " ";
    // }
    cout << "\n" << flush;
    for(int j=1;j<(1<<N);j=j+1){
        vector<int> pos;
        for(int k=0;k<N;k=k+1){
            if((j & (1<<k))!=0){
                pos.push_back(k);
            }
        }
        if(pos.size()!=K){
            continue;
        }
        vector<int> Ht(N);
        copy(H.begin(),H.end(),Ht.begin());
        int now_cost=0;
        for(int k=0;k<pos.size();k=k+1){
            int lpos=pos[k];
            if(lpos==0){
                continue;
            }
            int maxbuild=Ht[0];
            for(int m=1;m<lpos;m=m+1){
                chmax(maxbuild,Ht[m]);
            }
            if(Ht[lpos] < maxbuild ){
                int geta=maxbuild-Ht[lpos]+1;
                now_cost = now_cost + geta;
                // TODO: 問題点 now_costが何故反映できないか。個々の値で反映している
                debug("pos=%d 最高値=%d 下駄=%d 累積=%d \n",lpos,maxbuild,geta,now_cost);
                Ht[lpos]=Ht[lpos]+geta;
            }
        }
        chmin(result,now_cost);
        // debug("----- j = %d の時 に見えていたい 建物-----\n",j);
        // for(int k=0;k<pos.size();k=k+1){
        //     debug("%d ",pos[k]);
        // }
        // debug("\n");

    }
    return result;
}

int main(void){
    initial();
    int N,K;
    cin >> N >> K;
    vector<int> H(N,0);
    for(int j=0;j<N;j=j+1){
        cin >> H[j];
    }
    cout << solver(N,H,K) << "\n" << flush;
    return 0;
}

