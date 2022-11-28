using namespace std;
#include <iostream>
#include <fstream>
#include <iomanip>

template <class T,int N>
class Vector {
    public:
    T data [N];
    class reverse_iterator{
    public:
    T *_p;
    reverse_iterator():_p(nullptr){
    }

    reverse_iterator  operator ++(){
        --_p;
        return  reverse_iterator (_p);

    }

    T & operator *(){
        return *_p;
    }


    bool operator !=(  const reverse_iterator &it)
    {
      return !(_p ==it._p);
    }
   



    reverse_iterator (T *p) :_p(p){  
    }

    };

    reverse_iterator   r_end() {
        return   reverse_iterator (data+1);
    };
    reverse_iterator  r_begin(){
        return reverse_iterator(data+N-1);
    };



    

};


template <class T, int N>
void init(Vector <T,N> & v){
    for (auto it = v.r_begin(); it!=v.r_end();++it){
          *it =  10;
    }

     for (auto it = v.r_begin(); it!=v.r_end();++it){
          cout <<*it<<endl;
    }

}

int main(){
    Vector <int,10> v1;
    init(v1);
    return 0;
}