#include <iostream>
#include <sstream>
#include <string>
using namespace std;


template <class T>
class Stack{
    public:
    struct Elem{
        T data;
        Elem *next;
    };
    Elem *head;
    int size;
    
    public:
     class iterator {   
        public:
        Elem *_p;
        iterator () : _p(nullptr){

        }
        T& operator * (){
            return _p->data;

        }

        T& operator ->(){
            return & (_p->data);
        }
     
        iterator & operator ++(){
            _p=_p->next;
            return *this;

        }

     
        bool operator ==( const iterator &it){
            return (_p==it._p);

        }
        bool operator != ( const iterator &it){
            return !(_p==it._p);
        }

      iterator (Elem *p):_p(p){
      }

     };
      iterator begin(){
        return iterator(head);
      }

      iterator end(){
        return iterator (nullptr);
      }

     void push( const T &data){
        head = new Elem{data,head};
        ++size;
     }

     T & pop (){
        Elem * tmp =head;
        head=head->next;
        ++size;
        auto  tmp_data = new Elem{tmp->data,nullptr};
        delete tmp;
        return tmp_data->data;

     }

     T & pop_end(){
      
       
        Elem *node =  head;
        while (node->next!=nullptr)
        {
          
            node=node->next;
        }
        
        return node->data;        
     }

};




ostream & operator <<(ostream& out,Stack<int> & obj){
    for (auto it=obj.begin();it !=obj.end();++it){
        out <<*it<<endl;
    }
    return out;
}

int main(){
    Stack <int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(6);
  // cout<<s1.pop()<<endl;
    //cout<<s1.pop()<<endl;
   // cout <<s1.pop_end()<<endl;


    //cout <<s1.pop_end()<<endl;
   // cout <<s1<<endl;

     

}