#include <iostream>
#include <string>
using namespace std;

// TASK_1: Create a Vector template class that implements a vector. The class should have two template parameters. The first parameter (T) is a type parameter that specifies the type of the elements of the Vector, the second parameter is a non-negative integer (unsigned) that specifies the number of elements (N).
template<class T, size_t N>
class Vector {
  T vec[N];
public:
  Vector() = default;
  
  // The class should have a constructor with one parameter (const T*). Initialize the vector with the elements from the array addressed by the paratemer.
  Vector(const T* v) {
    for (size_t i = 0; i < N; i++)
      vec[i] = v[i];
  }
  
  // Extra
  Vector(T (&v)[N]) {
    for (size_t i = 0; i < N; i++)
      vec[i] = v[i];
  }

  // Implement the addition of an N long and an M long vector. The result should be an N+M long vector in which the first N elements are from the left hand side, and the following M elements are from the right hand side of the addition operator.
  template<size_t M>
  Vector<T, N+M> operator+(const Vector<T, M>& v) const {
    Vector<T, N+M> res;
    for (size_t i = 0; i < N; i++)
      res[i] = vec[i];
    for (size_t i = 0; i < M; i++)
      res[N+i] = v[i];
    return res;
  }
  
  // Implement the [] operator such that it gives back the ith elements of the vector if i is less than N. Otherwise, throw an std::exception.
  T& operator[](size_t i) {
    if (i < N)
      return vec[i];
    throw exception();
  }
  
  const T& operator[](size_t i) const {
    if (i < N)
      return vec[i];
    throw exception();
  }

  // Implement the << stream operator such that it prints the elements in one line separated by colons.
  friend ostream& operator<<(ostream& os, const Vector& v) {
    for (size_t i = 0; i < N; i++)
      os << (i ? ", " : "") << v[i];
    return os;
  }
};


// TASK_2: Implement the template function which removes all elements from "array" which are larger than "limit" and returns the number of remaining elements.
template<class T, size_t N /*array size*/>
size_t remove_larger(T* array, const T& limit) {
  size_t j = 0;
  for (size_t i = 0; i < N; i++)
    if (array[i] <= limit)
      array[j++] = array[i];
  return j;
}

// TASK_3: Implement the manipulator which initially sets the countdown to 5. In each usage it decreases the counter and prints "X attempts remaining" or "Boom!!!" if the counter is already 0, and sets the counter back to 5.
ostream& bomb(ostream& os) {
  static int counter = 5;
  if (counter) {
    return os << counter-- << "  attempts remaining";
  } else {
    counter = 5;
    return os << "Boom!!!";
  }
}


// TASK_4: Implement the effector which gets a string and removes the "unnecessary" spaces. If there are several whitespaces after each other then only one space character shoud remain. E.g. cout << remove_space (" apple : peach   orange  ") results "apple : peach orange".
class remove_space {
  string s;
public:
  remove_space(const string& s) : s(s) { }
  friend ostream& operator<<(ostream& os, const remove_space& rs) {
    bool prev_space = true;
    for (auto& c : rs.s)
      if (c == ' ') {
        if (!prev_space)
          os << ' ';
        prev_space = true;
      } else {
        os << c;
        prev_space = false;
      }
    return os;
  }
};

int main() {
  { // 1.
    int array1[] = { 1, 2, 3, 4, 5, 0 };
    int array2[] = { 3, 8, 2, 9, 12, 5, 4, 7, 8, 5, -2, 0 };
    Vector<int, sizeof(array1) / sizeof(int)> v1(array1);
    Vector<int, sizeof(array2) / sizeof(int)> v2(array2);
    Vector<int, (sizeof(array1) + sizeof(array2)) / sizeof(int)> res = v1 + v2;
    cout << "res: " << res << endl;
    
    // extra, -std=c++17 
    Vector v(array1);
    cout << "v: " << v << endl;
  }

  { // 2.
    int array[] = { 3, 8, 2, 9, 12, 5, 4, 7, 8, 5 };
    size_t n = remove_larger<int, sizeof(array) / sizeof(int)>(array, 6);
    for (size_t i = 0; i < n; i++)
      cout << array[i] << ", ";
    cout << endl;
  }

  // 3.
  for (size_t i = 0; i < 15; i++)
    cout << bomb << endl;
  
  // 4.
  cout << remove_space(" apple : peach   orange  ") << endl;
}
