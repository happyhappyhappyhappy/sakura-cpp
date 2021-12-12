#include<iostream>
using namespace std;

class Mul{
    private :
        int i_ ;
    public :
        Mul(int i): i_(i){}
        int operator()(int j){return j*i_;}
};
int main(void){
    auto doubler=Mul(2);
    cout << "doubler(2)\t" << doubler(2) << "\n" << flush;
    cout << "doubler(3)\t" << doubler(3) << "\n" << flush;
    cout << "doubler(100)\t" << doubler(100) << "\n" << flush;    
    return 0;
}