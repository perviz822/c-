#include <iostream>

#include <iomanip>

#include <string>

#include <sstream>

#include <vector>

using namespace std;

//backwards

class backwards {
  public: string text;
  backwards(string s): text(s) {}
};

ostream & operator << (ostream & out,
  const backwards & obj) {
  for (int i = obj.text.length() - 1; i > 0; i--) {
    out << obj.text[i];
  }
  return out;
}

//putting the word in quotes with the help of manipulators

stringstream s;
streambuf * sb;

ostream & backwardsbegin(ostream & out) {
  sb = out.rdbuf(s.rdbuf());
  return out;

}

ostream & backwardsend(ostream & out) {
  out.rdbuf(sb);
  string str = s.str();
  out << "\"" << str << "\"";

  return out;

}

//space - doubler

class double_space {
  public: string str;
  double_space(string arg): str(arg) {}
  friend ostream & operator << (ostream & out, double_space obj) {

    for (auto c: obj.str) {
      out << (c == ' ' ? " " : "") << c;
    }

    // out <<obj.str<<endl;

    return out;
  }
};


int main() {
  //warm  up

  istringstream iss("47 1.345 This is a test");
  int i;
  double f;
  iss >> i >> f; //read from iss stream into variable i and f;

  //cout << "integer value is"<<i<<endl;
  //cout << "double value is"<<f<<endl;

  stringstream s("hilala");
  stringstream s2;
  streambuf * sb;

  sb = s.rdbuf();
  // iss >>s;
  //cout <<s <<endl;
  //out <<iss.rdbuf()<<endl;

  //cout <<s.rdbuf()<<endl;

  //cout << sb<<endl;

  stringstream s1("hello I am string stream");
  streambuf * s1_bfr = s1.rdbuf();
  ostream my_stream(s1_bfr);

  my_stream << "hey" << endl;

  cout << s1.rdbuf() << endl;

  string my_str = "back to black";

  //cout <<"\"" << my_str <<"\"";

  //cout <<backwardsbegin <<"you know I am no good" <<backwardsend ;

  cout << double_space("I am  the string for double   space") << endl;

}