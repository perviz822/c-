#include <iostream>

#include <iomanip>

#include <string>

#include <sstream>

#include <vector>

using namespace std;

struct  Water {
    friend ostream & operator <<(ostream &out, Water & obj){
        out <<"water"<<endl;
        return out;
    }
};
struct  Milk {
    friend ostream & operator <<(ostream &out, Water & obj){
        out <<"milk"<<endl;
        return out;
    }
};
struct  Honey {
    friend ostream & operator <<(ostream &out, Water & obj){
        out <<"honey"<<endl;
        return out;
    }
};
struct  Cookie{
    friend ostream & operator <<(ostream &out, Water & obj){
        out <<"cookie"<<endl;
        return out;
    }
};



struct  Bear{
    friend ostream & operator <<(ostream &out, Water & obj){
        out <<"Winnie -the-pooh"<<endl;
        return out;
    }
};


struct  Boy{
    friend ostream & operator <<(ostream &out, Boy & obj){
        out <<"Christopher Robin"<<endl;
        return out;
    }
};



template <class Actor>
class ActorTraits;


template  <>
class ActorTraits <Bear> {
    typedef Water beverage_type;
    typedef Honey snack_type;
};

class ActorTraits <Boy> {
    typedef Milk beverage_type;
    typedef Cookie snack_type;
}
;


template <class Actor,Traits= ActorTraits<Actor>>
class Cartoon{
    typedef typename Traits::beverage_type beverage_type;
    typedef typename Traits::snack_type snack_type;
    beverage_type beverage;
    snack_type snack;
    Actor actor;

    public:
    void acts(){
        cout <<actor <<endl;
        cout <<beverage<<endl;
        cout <<actor <<endl;

    }

};





class Android {
  string op_system;
public:
  Android(unsigned version) : op_system("Android v" + to_string(version)) {
  }
  const string& get_op_system() const {
    return op_system;
  }
};

class iOS {
  string op_system;
public:
  iOS(unsigned version) : op_system("iOS v" + to_string(version)) {
  }
  const string& get_op_system() const {
    return op_system;
  }
};

class Hun {
  string lang = "Hungarian";
public:
  const string& get_lang() const {
    return lang;
  }
};

class Eng {
  string lang = "English";
public:
  const string& get_lang() const {
    return lang;
  }
};

class Samsung {
public:
  string get_brand() const {
    return "Samsung";
  }
};

class iPhone {
public:
  string get_brand() const {
    return "iPhone";
  }
};

template<class BRAND>
class mobile_config;

template<>
class mobile_config<Samsung> {
public:
  typedef Android op_system_type;
  typedef Hun lang_type;
};

template<>
class mobile_config<iPhone> {
public:
  typedef iOS op_system_type;
  typedef Eng lang_type;
};

template<class BRAND, class CONFIG = mobile_config<BRAND>, unsigned VER = 10>
class mobile {
  typedef typename CONFIG::op_system_type op_system_type;
  typedef typename CONFIG::lang_type lang_type;
  
  string name;
  BRAND brand;
  op_system_type op_s;
  lang_type lang;
public:
  mobile(const string& name, unsigned op_version = VER) : name(name), op_s(op_version) {
  }
  
  friend ostream& operator<<(ostream& os, const mobile& m) {
    return os << m.name << " (" << m.brand.get_brand() << ", "
              << m.op_s.get_op_system() << ", "
              << m.lang.get_lang() << ")";
  }
  
  const op_system_type& get_os() const {
    return op_s;
  }
};

// ----- test -----

void test_mombile() {
  cout << endl << "test mobile" << endl;

  mobile<Samsung> ma("Samsung X", 11);
  cout << ma << endl;
  cout << ma.get_os().get_op_system() << endl;
  /* Samsung X (Samsung, Android v11, Hungarian)
     Android v11
  */

  mobile<iPhone, mobile_config<iPhone>, 13> mi("iPhone 13");
  cout << mi << endl;
  cout << mi.get_os().get_op_system() << endl;
  /* iPhone 13 (iPhone, iOS v13, English)
     iOS v13
  */
}







int main(){

}