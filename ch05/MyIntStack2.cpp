#include <iostream>
using namespace std;


class MyIntStack {
	int* p;
	int tos;
	int size;
public:
	MyIntStack();
	MyIntStack(int size) {
		this->size = size;
		p = new int[size];
		tos = 0;
	}
	MyIntStack(const MyIntStack& s) {
		this->size = s.size;
		this->p = new int [s.size];
		this->tos = s.tos;
		for (int i = 0; i < s.size; i++) {
			p[i] = s.p[i];
		}
	}
	~MyIntStack() {
		delete[] p;
		p = NULL;
	};
	bool push(int n) {
		if (tos == size) {
			return false;
		}
		else {
			p[tos] = n;
			tos++;
			return true;
		}
	}
	bool pop(int& n) {
		if (tos == 0) return false;
		else {
			n = p[--tos];
			return true;
		}
	}
};
int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a;
	b.push(30);

	int n;
	a.pop(n);
	cout << "스택a에서 pop한 값" << n << endl;
	b.pop(n);
	cout << "스택b에서 pop한 값" << n << endl;

}