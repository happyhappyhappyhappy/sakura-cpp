#include<iostream>
using namespace std;

class Mul{
    private:
        int j_;
    public:
        Mul(int i):j_(i){}
        int operator()(int k){return k*j_;}
};

int main(void){
    auto doubler = Mul(2);
    cout << "doubler(10)\t" << 
    doubler(10) << "\n" << flush;
    cout << "doubler(123)\t" << 
    doubler(123) << "\n" << flush;
    return 0;
}