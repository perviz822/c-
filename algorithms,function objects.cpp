using namespace std;
#include <iostream>

#include <iomanip>

#include <algorithm>

#include <vector>

#include <iterator>


class jump_n {
  public:
    int jump;
  int begin = 0;
  jump_n(int i): jump(i) {

  }

  int operator()() {
    int a = begin;
    begin += jump;
    return a;

  }
};

struct gen_random {
  string source;

  gen_random(): source("QWERTYUIOPASDFGHJKLZXCVBNM") {
    srand(time(NULL));
  }

  char operator()() {
    return source[rand() % source.length()];

  }
};
struct gen_int_random {
  int random;

  gen_int_random(): random(rand() % 100) {
    srand(time(NULL));
  }

  int operator()() {
    return random;

  }
};

template < typename Iterator >
  void print(Iterator first, Iterator last, string prefix) {
    cout << prefix << ":";
    while (first != last) {
      cout << * first << " ";
      first++;
    }
    cout << endl;
  }

  class obj{
    string st;
    int occurence=0;

    obj(string str):st(str){
    
    }

    void  operator ++(){
        occurence+=1;
    }

  };



  vector <string>  delete_copies( vector <string> string_vector){
    vector <string> v;
    for ( auto it=string_vector.begin();it<string_vector.end();it++){   
        bool is_duplicate = false;
        for(auto it2 = string_vector.begin();it2<string_vector.end();it2++){
            if (*it ==*it2){
                is_duplicate==true;
            }
        }

        if(is_duplicate==false) {
            v.push_back(*it);

        }    

    }

    return v;

  }

int main() {

  vector < string > v1(5);
  //fill
  fill(v1.begin(), v1.end(), "ha");
  print(v1.begin(), v1.end(), "v1");

  vector < string > v2;
  //fill_n
  fill_n(back_inserter(v2), 7, "string");
  print(v2.begin(), v2.end(), "v2");

  //generate and generate_n

  vector < int > v3(10);

  vector < int > v4;

  generate(v3.begin(), v3.end(), jump_n(2));
  generate_n(back_inserter(v4), 12, jump_n(78));

  std::vector < int > ::iterator it = v4.begin();

  print(v3.begin(), v3.end(), "v3");
  print(v4.begin(), v4.end(), "v4");

  //counting functions  COUNT AND COUNT_IF

  vector < char > v5;

  generate_n(back_inserter(v5), 12, gen_random());

  print(v5.begin(), v5.end(), "v5");

  for (auto it = v5.begin(); it != v5.end(); it++) {
    cout << * it << count(v5.begin(), v5.end(), * it) << endl;
    //cout <<count_if(v5.begin(),v5.end(),bind2nd(greater_equal<char>(),"a"))<<endl;
    // cout<<k<<endl;

  }

  struct is_greater_than {
    int value;
    is_greater_than(int v): value(v) {};
    bool operator()(int x) {
      return x > value;

    }

  };

  vector < int > v6;

  generate_n(back_inserter(v6), 12, gen_int_random());

  //print(v6.begin(),v6.end(),"v6");

  int k = count_if(v6.begin(), v6.end(), is_greater_than(15));

  //cout <<k <<endl;

  vector < int > v7;
  vector < int > v8(15);

  generate_n(back_inserter(v7), 10, jump_n(3));

  //print(v7.begin(),v7.end(),"v7");

  //copy (v7.begin(),v7.end(),back_inserter(v8));

  //print(v8.begin(),v8.end(),"v8");

  //COPY_BACKWARD

  copy_backward(v7.begin(), v7.end(), v8.end()); //here it does not copy the last element to last element it copies last element to last element
  //rather than first to first as it is in copy algorithm.

  //reverse(v8.begin(),v8.end());

  //print(v8.begin(),v8.end(),"v8");

  //SWAP_RANGES

  vector < int > v9;
  vector < int > v10;

  generate_n(back_inserter(v9), 10, jump_n(2));
  print(v9.begin(), v9.end(), "v9");
  swap_ranges(v9.begin(), v9.begin() + 4, v9.begin() + 6);
  print(v9.begin(), v9.end(), "v9");

  //COPY_BACKWARD
  vector < string > v11 = {
    "one",
    "two",
    "three"
  };
  vector < string > v12(3);

  copy_backward(v11.begin(), v11.end(), v12.end());
  print(v12.begin(), v12.end(), "v12");

  //ROTATE
  rotate(v12.begin(), v12.begin() + 1, v12.end());
  cout << "rotated" << endl;
  print(v12.begin(), v12.end(), "v12");

  //REVERSE

  vector < int > v13 = {
    1,
    2,
    3,
    4,
    5,
    6,
    7
  };
  print(v13.begin(), v13.end(), "v13");
  reverse(v13.begin(), v13.end());
  cout << "Reversed" << endl;
  print(v13.begin(), v13.end(), "v13");

  //REVERSE_COPY
  vector < int > v14 = {
    7,
    6,
    5,
    4,
    3,
    12
  };
  vector < int > v15;
  reverse_copy(v14.begin(), v14.end(), back_inserter(v15));
  cout << "reverse_copied into v15" << endl;
  print(v15.begin(), v15.end(), "v15");

  //FIND, FIND_IF 

  vector < string > v16 = {
    "zoltan",
    "ferenc",
    "ivan",
    "katalin",
    "zoltan"
  };
  auto it2 = find(v16.begin(), v16.end(), "zoltan");
  cout << * it2 << endl;
  //FIND_IF
  vector < int > v17 = {
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    10
  };
  auto it3 = find_if(v17.begin(), v17.end(), is_greater_than(9));
  cout << * it3 << endl;
  //FIND_FIRST_OF

  vector < string > v18 = {
    "one",
    "two",
    "three"
  };
  vector < string > v19 = {
    "five",
    "six",
    "seven",
    "one",
    "one"
  };

  auto result = find_first_of(v18.begin(), v18.end(), v19.begin(), v19.end());
  cout << * result << endl;

  //SEARCH

  vector < int > v20 = {
    1,
    2,
    3,
    4,
    5,
    6
  };
  vector < int > v21 = {
    1,
    2,
    3
  };
  auto it4 = search(v20.begin(), v20.end(), v21.begin(), v21.end());
  print(it4, it4 + 3, "found");

  //UNIQUE

  vector <string> v22 = {"gio","usama","zahra","zahra","parviz"};


  auto it5 =  unique(v22.begin(),v22.end());

  print(v22.begin(),it5,"v22");





  vector <string> v23 = {"one","two","one"};


  vector <string> v24 =  delete_copies(v23);



  print(v24.begin(),v24.end(),"v24");







}