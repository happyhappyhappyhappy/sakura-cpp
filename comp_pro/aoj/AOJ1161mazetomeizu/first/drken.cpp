#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef pair<int,int> pint;

#define DE 1
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define ALL(s) (s).begin(),(s).end()
#define REP(i,n) for (int i = 0; i < (int)(n); ++i)
#define EACH(i,s) for (typeof((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define COUT(x) cout<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<<endl

template<class T1, class T2> ostream& operator<<(ostream &s, pair<T1,T2> P){return s<<'<'<<P.first<<", "<<P.second<<'>';}
template<class T> ostream& operator<<(ostream &s, vector<T> P) {s<<"{ ";for(int i=0;i<P.size();++i){if(i>0)s<<", ";s<<P[i];}return s<<" }"<<endl;}
template<class T1, class T2> ostream& operator<<(ostream &s, map<T1,T2> P) {s<<"{ ";for(typeof(P.begin()) it=P.begin();it!=P.end();++it){if(it!=P.begin())s<<", ";s<<'<'<<it->first<<"->"<<it->second<<'>';}return s<<" }"<<endl;}


bool canmove[50][50][4];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int seen[50][50];

int main() {
    //freopen( "/Users/macuser/Documents/Programming/Contest/input.in", "r", stdin );

    int W, H;
    while (cin >> W >> H) {
        if (W == 0) break;

        for (int i = 0; i < 50; ++i) for (int j = 0; j < 50; ++j) for (int k = 0; k < 4; ++k) canmove[i][j][k] = true;
        for (int i = 0; i < H; ++i) {
            canmove[i][0][3] = false;
            canmove[i][W-1][1] = false;
        }
        for (int i = 0; i < W; ++i) {
            canmove[0][i][2] = false;
            canmove[H-1][i][0] = false;
        }

        for (int i = 0; i < 2*H-1; ++i) {
            if (i & 1) {
                int x = i/2;
                for (int j = 0; j < W; ++j) {
                    int num; cin >> num;
                    if (num == 1) {
                        canmove[x][j][0] = false;
                        canmove[x+1][j][2] = false;
                    }
                }
            }
            else {
                int x = i/2;
                for (int j = 0; j < W-1; ++j) {
                    int num; cin >> num;
                    if (num == 1) {
                        canmove[x][j][1] = false;
                        canmove[x][j+1][3] = false;
                    }
                }
            }
        }

//        for (int i = 0; i < H; ++i) {
//            for (int j = 0; j < W; ++j) {
//                cout << MP(i,j) << " : ";
//                for (int k = 0; k < 4; ++k) cout << canmove[i][j][k] << ", ";
//                cout << endl;
//            }
//        }
        memset(seen, 0, sizeof(seen));
        queue<pint> que;

        que.push(MP(0,0));
        seen[0][0] = 1;

        while (!que.empty()) {
            pint now = que.front();
            que.pop();

            for (int i = 0; i < 4; ++i) {
                if (canmove[now.FI][now.SE][i]) {
                    int nx = now.FI + dx[i];
                    int ny = now.SE + dy[i];

                    if (seen[nx][ny] == 0) {
                        que.push(MP(nx,ny));
                        seen[nx][ny] = seen[now.FI][now.SE] + 1;
                    }
                }
            }
        }

        cout << seen[H-1][W-1] << endl;
    }

    return 0;
}
