#include<iostream> // https://cpprefjp.github.io/reference/ostream/flush.html
#include<thread> // ref https://cpprefjp.github.io/reference/thread/this_thread/sleep_for.html
#include<chrono> // ref https://cpprefjp.github.io/reference/chrono/duration_aliases.html
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;
#define N 2000

int main(void){
    int j;
    for(j = 0;j < N;j=j+1){
        cout << j << " ,";
        sleep_for(milliseconds(5));
    }
}