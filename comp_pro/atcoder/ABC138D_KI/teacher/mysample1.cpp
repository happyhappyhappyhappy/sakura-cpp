#include<bits/stdc++.h>
using namespace std;
int N,Q;
vector<int> E[201010];
int val[201010];

void dfs(int cu,int pa=-1){
    for(auto &to:E[cu]){
        if(to!=pa){
            val[to]=val[cu]+val[to];
            dfs(to,cu);
        }
    }
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> Q;
    for(int j=0;j<N-1;j=j+1)
    {
        int a, b;
        cin >> a >> b;
        a = a-1;
        b = b-1;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    for(int q=0;q<Q;q=q+1){
		int p, x;
        cin >> p >> x;
		p=p-1;
		val[p] = val[p]+x;
        }
    dfs(0);
	for(int j=0;j<N;j=j+1)
    {
		if (j){
            cout << " ";
        }
		cout << val[j] << " ";
	}
	cout << "\n" << flush;
}

