#include<iostream>
#include<array>
#include<vector>
#include<cstdio>
#include<chrono>
using namespace std;
using namespace std::chrono;
using li = long int;

int main(void){
    system_clock::time_point start,end;
    double elaspd;
    const li MAX=100000;
    array<li,MAX> c;
    cout << "array型を利用する\n";
    start = system_clock::now();
    for(li j=0;j<MAX;j++){
        c[j] = j;
    }
    li sum=0;
    for(li j=0;j<MAX;j++){
        sum = sum + c[j];
    }
    end = system_clock::now();
    elaspd = chrono::duration_cast<microseconds>(end-start).count();
    cout << elaspd << "μs\n";
    return 0;
}