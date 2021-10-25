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
typedef vector< int > vint;
typedef vector<ll> vll;
typedef pair< int , int > pint;
typedef pair<ll,ll> pll;

#define REP(i, n) for ( int (i) = 0; (i) < ( int )(n); ++(i))
#define ALL(s) (s).begin(),(s).end()
#define EACH(i,s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<endl

template < class T1, class T2> ostream& operator <<(ostream &s, pair<T1,T2> P){ return s<<'<' <<P.first<< ", " <<P.second<< '>' ;}
template < class T> ostream& operator <<(ostream &s, vector<T> P) {s<< "{ " ; for ( int i=0;i<P.size();++i){if (i>0)s<< ", " ;s<<P[i];} return s<< " }" <<endl;}
template < class T> ostream& operator <<(ostream &s, set<T> P) {s<< "{ "; for (__typeof__(P.begin()) it=P.begin();it!=P.end();++it){ if (it!=P.begin())s<< ", ";s<<*it;} return s<< " }" <<endl;}
template < class T1, class T2> ostream& operator <<(ostream &s, map<T1,T2> P) {s<< "{ "; for (__typeof__(P.begin()) it=P.begin();it!=P.end();++it){ if (it!=P.begin())s<< ", ";s<< '<' <<it->first<< "->" <<it->second<< '>' ;} return s<< " }" <<endl;}

template < class T> bool chmax(T& a, T b) { if (a < b) {a = b; return 1;} return 0; }
template < class T> bool chmin(T& a, T b) { if (a > b) {a = b; return 1;} return 0; }



map< long long , long long > prime_factor( long long n) {
    map< long long , long long > res;
    for ( long long i = 2LL; i*i <= n; ++i) {
        while (n%i == 0LL) {
            ++res[i];
            n /= i;
        }
    }
    if (n != 1LL) res[n] = 1LL;
    return res;
}


int N;
long long D;
double dp[2][100][50][50];


int main() {
        while (cin >> N >> D) {
              map<ll,ll> ma = prime_factor(D);
               int a = ma[2], b = ma[3], c = ma[5];
               bool ok = true ;
               for (map<ll,ll>::iterator it = ma.begin(); it != ma.end(); ++it)
                      if (it->first != 2 && it->first != 3 && it->first != 5) {
                           ok = false ; puts( "0.00000000000" );
                     }
               if (!ok) continue ;

               //cout << a << ", " << b << ", " << c << endl;

              REP(i,2) REP(j,100) REP(k,50) REP(l,50) dp[i][j][k][l] = 0.0;
              dp[0][0][0][0] = 1.0;
               for ( int i = 0; i < N; ++i) {
                     REP(j,100) REP(k,50) REP(l,50) dp[(i+1)%2][j][k][l] = 0.0;
                      for ( int j = 0; j <= a; ++j) {
                            for ( int k = 0; k <= b; ++k) {
                                   for ( int l = 0; l <= c; ++l) {
                                         dp[(i+1)%2][j][k][l] += dp[i%2][j][k][l]/6;
                                         dp[(i+1)%2][min(a,j+1)][k][l] += dp[i%2][j][k][l]/6;
                                         dp[(i+1)%2][j][min(b,k+1)][l] += dp[i%2][j][k][l]/6;
                                         dp[(i+1)%2][min(a,j+2)][k][l] += dp[i%2][j][k][l]/6;
                                         dp[(i+1)%2][j][k][min(c,l+1)] += dp[i%2][j][k][l]/6;
                                         dp[(i+1)%2][min(a,j+1)][min(b,k+1)][l] += dp[i%2][j][k][l]/6;
                                  }
                           }
                     }
              }
              cout << fixed << setprecision(9) << dp[N%2][a][b][c] << endl;
       }
   
    return 0;
}