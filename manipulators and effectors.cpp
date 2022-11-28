#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

ostream& abcitem(ostream &os) {
  static char cnt = 'a';
  return os << cnt++;
}

class backwards {
  string text;
public:
  backwards(string s) : text(s) {}
  friend ostream& operator<<(ostream &os, const backwards &b){
  	for (int i = b.text.length()-1; i >= 0; --i)
  	    os << b.text[i];
    return os;
  }
};

template<int N, int M>
class matrix {
  int m[N][M];
public:
  matrix(int mp[N][M]) {
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j)
        m[i][j] = mp[i][j];
  }
  friend ostream& operator<<(ostream &os, const matrix &m){
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        os << setw(4) << m.m[i][j];
	  }
      os << endl;
	}
    return os;
  }
};

stringstream s;
streambuf *sb;

ostream& backwardsBegin(ostream &os) {
  sb = os.rdbuf(s.rdbuf());
  return os;
}

ostream& backwardsEnd(ostream &os) {
  os.rdbuf(sb);
  string str = s.str();
  for (int i = str.length()-1; i >= 0; --i)
    os << str[i];
  return os;
}

int main() {
  // We use the manipulator here: we "write" the function to the stream.
  // For calling the function, there is an overloaded << operator in the STL.
  cout << abcitem << ". element" << endl;
  cout << abcitem << ". element" << endl;
  cout << abcitem << ". element" << endl;
  cout << backwards("something") << endl;  // -> gnihtemos  
  cout << backwardsBegin << "something" << backwardsEnd <<endl;  // -> gnihtemos  
  const int N=3;
  const int M=4;
  int m[N][M] = {
    1, 2, 3, 4,
    5, 6, 7, 8,
    9,10,11,12
  };
  cout << matrix<N,M>(m) << endl;
  return 0;
}

