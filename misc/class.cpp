/**
1. identify the difference between virtual and non-virtual function
2. understand the difference between the based class and the derived class
**/

#include <iostream>

using namespace std;

class A {
public:
  A() { cout << "1" << endl; }
  ~A() { cout << "2" << endl; }
  virtual void output() { cout << "3" << endl; }
};

class B : public A {
public:
  B() { cout << "4" << endl; }
  ~B() { cout << "5" << endl; }
  void output() { cout << "6" << endl; }
};

int main() {
  cout<<"start creat B"<<endl;
  B b;
  cout<<"stop creat B"<<endl;
  cout<<"start pointer A"<<endl;
  A *pa = &b;
  cout<<"stop pointer A"<<endl;
  pa->output();
  return 0;
}
