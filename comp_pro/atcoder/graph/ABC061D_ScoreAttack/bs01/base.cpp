// OCRにかけてみたが難しいので適当に読み直すこと
using ll = long long;
const ll INF = 1LL << 50;
int main(void) て

6     int N, M;

7     cin >> N >> M;

8

9     const int NMAX = 1000;

10     const int MMAX = 2000;

11     int a[MMAX], b[MMAX] :

12     11 c[MMAX] :

13

14     for (int i = 0; 1 <く Mi +i) f

15         cin >> a[i] >> bli] >> cli];
16               e[i] = -cLil;

17        }

18

19     11 dist [NMAX] :

20

21     for (int i = 0; i<N; #i) f

22         dist[i] = INF;

23           }

24

25     dist[0] = 0;

26

27

28     for (int loop = 0; loop < N - 1; ++ loop) {
29         for (int i = 0; i<M; ++i) {
if (dist[a[1] - 1] == INF) continue;

if (dist[b[i] - 1] > dist[a[i] - 1] + chi]) て
dist[b[i] - 1] = dist[a[i] - 1] + c[il;

11 ans = dist[N - 1];

bool negative [NMAX] ;

for (int i = 0; i<N; #i) f

negative[i] = false;

for (int loop = 0; loop < N ; ++ loop) {
for (int i = 0; i <M; ++i) {
if (dist[a[i] - 1] == INF) continue;

if (dist [b[i]   1] > dist[a[i] - 1] + cli]) f
dist[b[i] - 1] = dist[a[i] - 1] + ci]:

negative[b[i] - 1] = true;

}

if (negative[a[i] - 1] == true) {
negative[b[i] - 1] = true;

}

if (megative[N - 1])

cout << "inf" << endl;
else

cout << -ans << endl;

return 0;
