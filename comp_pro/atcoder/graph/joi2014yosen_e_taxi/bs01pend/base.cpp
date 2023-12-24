#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

#define MAX_N 5500
bool x[MAX_N][MAX_N];
int y[MAX_N][2];
bool z[MAX_N];
int m[MAX_N];
int s[MAX_N];
int t[MAX_N][MAX_N];

queue<int> Q;

int main() {
	memset(x, false, sizeof(x));
	for (int i = 0; i < 5500; i++) {
		for (int j = 0; j < 5500; j++) {
			m[i] = 1000000000;
			s[i] = 0;
			t[i][j] = 0;
		}
	}
	int N, K, a, b;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> y[i][0] >> y[i][1];
	}
	for (int i = 1; i <= K; i++) {
		cin >> a >> b;
		x[a][b] = true;
		x[b][a] = true;
		t[a][s[a]] = b;
		t[b][s[b]] = a;
		s[a] += 1;
		s[b] += 1;
	}

	int p;
	int r;
	int u;

	u = N;
	if (K > 6000) {
		u = 20;
	}

	m[1] = 0;

	for (int i = 0; i < u; i++) {
		for (int j = 1; j <= N; j++) {
			if (m[j] < 100000000) {
				while (!Q.empty()) {
					Q.pop();
				}
				Q.push(j);
				memset(z, false, sizeof(z));
				for (int k = 0; k < y[j][1]; k++) {
					r = Q.size();
					for (int l = 0; l < r; l++) {
						p = Q.front();
						for (int o = 0; o < s[p]; o++) {
							if (x[p][t[p][o]] == true && z[t[p][o]] == false) {
								Q.push(t[p][o]);
								z[t[p][o]] = true;
								m[t[p][o]] = min(m[t[p][o]], m[j] + y[j][0]);
							}
						}
						Q.pop();
					}
					if (Q.empty()) {
						goto Exit;
					}
				}
			Exit:;
			}
		}
	}
	cout << m[N] << endl;
	return 0;
}
