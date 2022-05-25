#include <iostream>

using namespace std;

class Class {
public:
	int a;
	int* b;

public:
	Class(const int& arg1, int* arg2) : a(arg1), b(arg2) {
		cout << "기본 생성자 : " << a << ' ' << *b << endl;
	}

	Class(const Class& arg) {
		this->a = arg.a;
		this->b = arg.b;
		cout << "복사 생성자 : " << a << ' ' << *b << endl;
	}

	int solution(int arg) {

	}
};



int main() {
	int b = 10;

	Class class1(5, &b);
	Class class2(class1);

	cout << "class1 : " << class1.a << ' ' << *class1.b << endl;
	cout << "class2 : " << class2.a << ' ' << *class2.b << endl;

	return 0;
}