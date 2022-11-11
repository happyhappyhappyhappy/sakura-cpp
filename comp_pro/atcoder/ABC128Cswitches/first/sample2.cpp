#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
int N, M;
vector<int> S[10];
int P[10];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;
	for(int i=0;i<M;i=i+1) {
		int k; cin >> k;
		for(int j=0;j<k;j=j+1){
			int s; 
            cin >> s; 
            s=s-1;
			S[i].push_back(s);
		}
	}
	for(int i=0;i<M;i=i+1)
    {
        cin >> P[i];
    }
	int ans = 0;
	for(int msk=0; msk < (1 << N);msk=msk+1) {
		debug("---フィルターコード %d 検索開始---\n",msk);
        debug("==== ただいまのスイッチ操作状況 ====\n");
        for(int switchc=0;switchc < N;switchc=switchc+1){
            if((msk & (1<<switchc))!=0){
                debug("%d 番目のスイッチON\n",switchc);
            }
            else{
                debug("%d 番目のスイッチOFF\n",switchc);
            }
        }
        debug("==== 状況をお伝えしました ====\n");
        int ok = 0;
		for(int m=0;m<M;m=m+1) {
			int cnt = 0;
			for(auto &s:S[m])
                {
                debug("%d番目の電球,%d番目のスイッチについて\n",m,s);  
                     if (msk & (1 << s))
                        { 
                            debug("フィルター%dの組み合わせは %dで条件満たす\n",msk,s);
                            cnt=cnt+1;
                        }
                    else{
                        debug("フィルター%dの組み合わせは %dでは条件満たさず\n",msk,s);
                    }
                 }
			if (cnt % 2 == P[m]) {
                debug("%d番目点灯しました\n",m);
                ok=ok+1;
                }
                else{
                    debug("%d番目:奇数、偶数が合わず点灯しない\n",m);
                }
		}
        debug("フィルター %d について、点灯した合計 %d / %d \n",msk,ok,M);
		if (ok == M) 
        {
            ans=ans+1;
        }
	}
	cout << ans << endl;
}
