using namespace std;
#include <iostream>
#include <fstream>
#include <iomanip>
//TEMPLATE_METAPROGRAMMING


template <int n1,int n2>
struct Max{
    static const int val =
    n1>n2 ? n1 :n2;
};



template <int n>
struct  Factorial{
    static const int  val =  n*Factorial <n-1>::val;

};


template <>
struct Factorial <0>{
    static const int val = 1;
};


int main(){
    Max <10,20> obj1;
    cout <<obj1.val<<endl;

   // Factorial<20> fac_obj;

    cout <<Factorial<10> ::val<<endl;

}