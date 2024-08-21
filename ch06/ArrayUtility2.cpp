#include <iostream>
using namespace std;

class ArrayUtility2 {
	static int* s;
	static int retsize;
public:

	static int* concat(int s1[], int s2[], int size1, int size2) {
		int size = size1 + size2;
		s = new int[size];

		for (int i = 0; i < size1; i++) {
			s[i] = s1[i];
		}
		for (int i = 0; i < size2; i++) {
			s[size1+i] = s2[i];
		}
		return s;
	}
	static int* remove(int s1[], int s2[], int size1,int size2, int& retsize) {
		for (int i = 0; i < size1; i++) {
			for (int j = 0; j < size2; j++) {
				if (s1[i] == s2[j]) 
					s1[i] = NULL;
			}
		}
		for (int i = 0; i < size1; i++)
			if (s1[i] != NULL) 
				retsize++;

		s = new int[retsize];
		int n = 0;
		for (int i = 0; i < size1; i++)
			if (s1[i] != NULL) {
				s[n] = s1[i];
				n++;
			}
		return s;
	
	}
};

int* ArrayUtility2::s = nullptr;
int ArrayUtility2::retsize = 0;
int main() {

	ArrayUtility2 au;
	int size1, size2, retsize = 0;
	int x[5], y[5];
	int* tmp;

	cout << "정수 5개를 입력. 배열 x에 삽입>>";
	for (int i = 0; i < 5; i++) {
		cin >> x[i];
	}
	cout << "정수 5개를 입력. 배열 y에 삽입>>";
	for (int i = 0; i < 5; i++) {
		cin >> y[i];
	}

	size1 = sizeof(x) / sizeof(int);
	size2 = sizeof(y) / sizeof(int);
	cout << "합친 정수 배열: " << endl;
	tmp = au.concat(x, y, size1, size2);
	for (int i = 0; i < size1+size2; i++) {
		cout << tmp[i] << " ";
	}
	cout << endl;

	cout << "배열x에서 배열y를 뺀 배열: " << endl;
	tmp = au.remove(x, y, size1,size2, retsize);
	for (int i = 0; i < retsize; i++) {
		cout << tmp[i] << " ";
	}
	cout << endl;
}