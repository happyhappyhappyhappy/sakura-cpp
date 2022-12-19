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
const double MAX = (double)1<<28;


void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(10) << setiosflags(ios::fixed);
}

double solver(int &pos,vector<int> &v,
vector<double> &x,vector<double> &y){
    double result=MAX;
    do{
        double now_sum=0;
        vector<double> n_x(pos+1);
        vector<double> n_y(pos+1);
        for(int j=0;j<pos;j=j+1){
            n_x[j] = x[v[j]];
            n_y[j] = y[v[j]];
        }
        // 最後は最初の位置に戻る
        n_x[pos] = x[v[0]];
        n_y[pos] = y[v[0]];
        for(int j=0;j<pos;j=j+1){
            // TODO:: distのコーディングから
            now_sum = now_sum + dist(n_x[j],n_y[j],n_x[j+1],n_y[j+1]);
        }
    }while(next_permutation(v.begin(),v.end()))
    return result;
}

int main(void){
    initial();
    int pos;
    cin >> pos;
    vector<int> v(pos,0);
    for(int j=0;j<pos;j=j+1){
        v[j]=j;
    }
    vector<double> x(pos,0),y(pos,0);
    for(int j=0;j<pos;j=j+1){
        int fst,sec;
        cin >> fst >> sec;
        x[j]=(double)fst;
        y[j]=(double)sed;
    }
    double ans = solver(pos,v,x,y);
    cout << ans << endl;
    return 0;
}

