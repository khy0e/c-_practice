#include <iostream>
using namespace std;

class Statistics {

	int* data;      
	int size;          

public:
	
	Statistics() {
		size = 0;
		data = new int[10];  //배열 동적 할당
	}
	~Statistics() {
		delete[] data;
	}

	// ! operator
	bool operator ! () {
		if (size == 0)
			return true;
		else
			return false;
	}
	// ~ operator
	void operator ~ () {
		for (int i = 0; i < size; i++) {
			cout << data[i] << ' ';
		}
		cout << endl;
	}

	// << operator
	Statistics& operator<<(int num) {
		data[size] = num;
		size++;
		return *this;  //객체 자신을 반환함을 의미
	}

	// >> operator
	Statistics& operator>>(int& avg) {
		if (size > 0) {
			int sum = 0;
			for (int i = 0; i < size; i++) {
				sum += data[i];
			}
			avg = sum / size;
		}
		else {
			avg = 0;
		}
		return *this;
	}
};
int main() {
	Statistics stat;
	if (!stat)
		cout << "현재 통계 데이터 없음" << endl;
	int x[5];
	cout << "5개 정수 입력>>";

	for (int i = 0; i < 5; i++)
		cin >> x[i];
	for (int i = 0; i < 5; i++)
		stat << x[i];

	stat << 100 << 200;
	~stat; 

	int avg;
	stat >> avg;
	cout << "avg=" << avg << endl;
}

