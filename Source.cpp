#include <iostream>
using namespace std;
template < class T>
class unique
{
public:
	unique() : t(_t) {}
	unique(const T& t) : unique() { *this = t; }
	unique& operator=(const T& other) {
		t = other;
		return *this;
	}
	operator T&() { return t; }
	T& value() { return t; }
 private:
	 T& t;
	 static T _t;
};

 template < class T>
 T unique<T>::_t;

 int main()
 {
	 unique<int> u1(5);
	 int& x = u1;
	 x = 7;
	 cout << u1.value() << endl;
	 unique<float> u2(5);
	 u2 = static_cast<int>(10);
	 u1 = u2;
	 u2 = 11;
	 cout << unique<int>() << endl;
	 unique<int> u3(u1);
	 u3 = 9;
	 u1 -= 3;
	 //u3 = u1;
	 cout << u3 << endl;
 }