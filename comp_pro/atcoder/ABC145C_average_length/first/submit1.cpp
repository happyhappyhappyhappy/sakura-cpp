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
// const double MAX = (double)1<<28;


void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(10) << setiosflags(ios::fixed);
}
double dist(double x1,double y1,double x2,double y2){
    double answer=0.0;
    double step1;
    step1 = pow((x2-x1),2.0)+pow((y2-y1),2.0);
    return pow(step1,0.5);
}
double solver(int &pos,vector<int> &v,
vector<double> &x,vector<double> &y){
    double all_sum=0.0;
    double pattern=0.0;
    do{
        pattern = pattern+1.0;
        double now_sum=0;
        vector<double> n_x(pos+1);
        vector<double> n_y(pos+1);
        for(int j=0;j<pos;j=j+1){
            n_x[j] = x[v[j]];
            n_y[j] = y[v[j]];
        }
        // 最後は最初の位置に戻る
        // ↑戻りません
        // n_x[pos] = x[v[0]];
        // n_y[pos] = y[v[0]];
        for(int j=0;j<pos-1;j=j+1){

            now_sum = now_sum + dist(n_x[j],n_y[j],n_x[j+1],n_y[j+1]);
        }
        all_sum = all_sum + now_sum;
    }while(next_permutation(v.begin(),v.end()));
    return all_sum/pattern;
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
        double fst,sec;
        cin >> fst >> sec;
        x[j]=fst;
        y[j]=sec;
    }
    double ans = solver(pos,v,x,y);
    cout << ans << endl;
    return 0;
}

