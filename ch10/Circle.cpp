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
	cout << "원을 삽입, 삭제하는 프로그램" << endl;

	while (true) {
		int no;
		int r;
		string rname;
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >>";
		cin >> no;
		switch (no) {
		case 1:
			cout << "생성하는 원의 반지름과 이름은 >>";
			cin >> r >> rname;
			v.push_back(new Circle(r, rname));
			break;

		case 2:
			cout << "삭제하고자 하는 원의 이름은 >>";
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