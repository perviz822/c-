#include <iostream>

#include <iomanip>

#include <string>

#include <sstream>

#include <vector>

using namespace std;

template < class T, unsigned n >
  class voting {
    public: T candidates[n];
    bool closed = false;
    int votes[n] = {};
    voting() {

    };
    voting(T( & arg)[n]) {
      for (int i = 0; i < n; i++) {
        candidates[i] = arg[i];
      }

    }

    voting & operator += (T vote) {
      bool is_in_the_list = false;

      if (!closed) {
        for (int i = 0; i < n; i++) {
          if (candidates[i] == vote) {
            votes[i] += 1;
            is_in_the_list = true;
          }
        }
      } else {
        throw exception();
      }

      if (!is_in_the_list) {
        throw exception();

      }
      return * this;

    }

    friend T operator!(voting & obj) {
      int max_index = -1;
      obj.closed = true;
      for (int i = 0; i < n; i++) {
        if (obj.votes[i] > max_index) {
          max_index = i;
        }
      }

      return obj.candidates[max_index];
    }

    friend ostream & operator << (ostream & out, voting & obj) {
      for (int i = 0; i < n; i++) {
        cout << obj.candidates[i] << ":" << obj.votes[i] << endl;
      }
      return out;

    }

  };

int main() {

  char arr[5] = {
    'a',
    'b',
    'c',
    'd',
    'e'
  };
  voting < char, 5 > vc(arr);

  vc += 'a';
  vc += 'a';
  vc += 'b';
  vc += 'c';
  vc += 'c';
  vc += 'c';
  vc += 'd';
  vc += 'e';
  //vc+='t';

  for (int i = 0; i < 5; i++) {
    // cout << vc.votes[i]<<endl;
  }

  cout << !vc << endl;

}