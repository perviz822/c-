using namespace std;
#include <iostream>
#include <fstream>
#include <iomanip>



//istream ,ostream,iostream

class Person{
public:
 int age;
 Person(int arg_age):age(arg_age){

}

};
class Animal {
    public:
    string type;

    Animal (string arg_type):type(arg_type){
    }
};
ostream& operator <<(ostream & out,Person per){
        out<<per.age<<endl;
        return out;
}

ostream & operator <<(ostream &out ,Animal anm){
    cout <<anm.type<<endl;
    return out;
}




class my_string {
    public:
    string str;
    my_string(string s,int width): str(s,0,width){

    }

   
};

 ostream & operator <<(ostream &out,my_string  &Str){
        out <<Str.str<<endl;
        return out;
    }




int main(){
    Person p1(26);
    cout<<p1<<endl;
    Animal anm1 ("cat");
    cout <<anm1 <<endl;

    //FILE_STREAM  FSTREAM

   
  

//OSTREAM
ofstream out("output.cpp");
ifstream in("practice06.cpp");

string s1;

while (in >> s1){
    out <<s1<<" ";
}



const int size = 256;

ifstream in2("practice06.cpp");

char buff [256];

while(in2.getline(buff,size)){
   // cout <<buff<<endl;
}


//if we do not know the size



string s2;
ifstream in3("07.cpp");
while (getline(in3,s2)){
    cout <<s2<<endl;
}





//pointing to different parts of stream


const int NUM=5,LEN=10;



char data [ NUM ] [ LEN ] ={
    "first",
    "second",
    "third",
    "fourth",
    "fifth"
};

ofstream out3 ("data.bin",ofstream::binary);
for (int i=0;i<NUM;i++){
    out3.write(data[i],LEN);

}
out3.close();




ifstream in4 ("data.bin",ifstream :: binary);

in4.read(data[0],LEN);


//cout <<data[0] <<endl;



in4.seekg(-10,ios::end);

in4.read(data[1],10);





in4.seekg(30,ios::beg);
in4.read(data[2],10);
cout<<data[2]<<endl;

in4.seekg(40);
in4.read(data[3],10);
cout <<data[3]<<endl;


//output_stream_formatting/manipulators

cout <<(float) 10 <<endl;

cout <<fixed <<showpos <<showpoint<<setprecision(5);

cout <<(float) 10 <<endl;


cout <<0x10<<endl;

cout <<hex <<0x10<<endl;


//EFFECTORS ARE MANIPULATORS WITH PARAMETER LIKE SET PRECISION




string  s5= "Asasdasdasd";

//cout <<s6(s5,0,4)<<endl;

my_string s6(s5,2);

cout <<s6<<endl;



}






