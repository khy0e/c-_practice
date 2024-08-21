#include <iostream>
using namespace std;

class Statistics {

	int* data;      
	int size;          

public:
	
	Statistics() {
		size = 0;
		data = new int[10];  //�迭 ���� �Ҵ�
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
		return *this;  //��ü �ڽ��� ��ȯ���� �ǹ�
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
		cout << "���� ��� ������ ����" << endl;
	int x[5];
	cout << "5�� ���� �Է�>>";

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

