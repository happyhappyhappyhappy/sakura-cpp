#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
template<class XXX> void chmin(XXX &x,XXX y){
    if(x < y){
        x = y;
    }
}
// ソート後すべての組み合わせについて、正方形を作る座標を出す
typedef pair<int,int> P;

void sphereMaker(P A,P B,P &C,P &D,int &xdiff,int &ydiff){
    int x1,y1,x2,y2;
    x1 = A.first;
    y1 = A.second;
    x2 = B.first;
    y2 = B.second;
    xdiff = x2-x1;
    ydiff = y2-y1;
    C.first = x2 - (y2-y1);
    C.second= y2 + (x2-x1);
    D.first = x1 - ( y2-y1);
    D.second = y1 + (x2-x1);
}

int main(void){
    int coord_point;
    cin >> coord_point;
    vector<P> Point(coord_point);
    for(int j=0;j<coord_point;j=j+1){
        cin >> Point[j].first >> Point[j].second ;
    }
    sort(Point.begin(),Point.end());
    cout << "ソート結果\n" << flush;
    for(int j=0;j<coord_point;j=j+1){
        printf("%d: (%d,%d)\n",j+1,Point[j].first,Point[j].second);
    }
    cout << "正方形を作ると\n" << flush;
    for(int j=0;j<coord_point;j=j+1){
        for(int k=j+1;k<coord_point;k=k+1){
            P A,B,C,D;
            int xdiff,ydiff;
            A.first = Point[j].first;
            A.second = Point[j].second;
            B.first = Point[k].first;
            B.second = Point[k].second;
            sphereMaker(A,B,C,D,xdiff,ydiff);
            printf("A:(%d,%d)\n",A.first,A.second);
            printf("B:(%d,%d)\n",B.first,B.second);
            cout << "    ↓   \n" << flush;
            printf("C:(%d,%d)\n",C.first,C.second);
            printf("D:(%d,%d)\n",D.first,D.second);
            printf("xdiff=%d,ydiff=%d\n",xdiff,ydiff);
            printf("面積は%d(あれば)\n",xdiff*xdiff+ydiff*ydiff);
            cout << "---------\n" << flush;
        }
    }
    return 0;
}