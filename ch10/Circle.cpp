#include <iostream>
#include <vector>
using namespace std;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius, string name) {
		this->radius = radius;
		this->name = name;
	}
	double getArea() {
		return 3.14 * radius * radius;
	}
	string getName() {
		return name;
	}
};
int main() {
	vector <Circle*> v;
	vector <Circle*>::iterator it;
	cout << "���� ����, �����ϴ� ���α׷�" << endl;

	while (true) {
		int no;
		int r;
		string rname;
		cout << "����:1, ����:2, ��κ���:3, ����:4 >>";
		cin >> no;
		switch (no) {
		case 1:
			cout << "�����ϴ� ���� �������� �̸��� >>";
			cin >> r >> rname;
			v.push_back(new Circle(r, rname));
			break;

		case 2:
			cout << "�����ϰ��� �ϴ� ���� �̸��� >>";
			cin >> rname;
			for (it = v.begin(); it != v.end(); it++) {
				
				if ((*it)->getName() == rname) {
					it = v.erase(it);
				}
			}
			break;
		case 3:
			for (it = v.begin(); it != v.end(); it++) {
				cout << (*it)->getName() << endl;
			}
			break;
		case 4:
			exit(0);
		}
	}
}