#include <iostream>
using namespace std;

//(((N/Base)/Base)/Base)/BASE ...
template<unsigned N, unsigned BASE, bool FIRST = true>
struct count {
  static const unsigned val = count<N/BASE, BASE, false>::val + 1;
};

template<unsigned BASE> // stop cond.
struct count<0, BASE, false> {
  static const unsigned val = 0;
};

template<unsigned BASE> // first
struct count<0, BASE, true> {
  static const unsigned val = 1;
};


int main() {
  cout << 5 << " " << 10 << " " << count<5, 10>::val << endl;
  cout << 5 << " " << 2 << " " << count<5, 2>::val << endl;
  cout << 999 << " " << 1000 << " " << count<999, 1000>::val << endl;
  cout << 1000 << " " << 1000 << " " << count<1000, 1000>::val << endl;
  cout << 0 << " " << 10 << " " << count<0, 10>::val << endl;
}
