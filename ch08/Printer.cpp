#include <iostream>
using namespace std;

class Printer {
    string model;
    string mf;
    int pCount;
    int aCount;
public:
    Printer(string model, string mf, int pCount, int a=0) {
        this->model = model;
        this->mf = mf;
        this->pCount = 10;
        this->aCount = a;
    }
    void print(int pages) {
        if (aCount >= pages) {
            pCount += pages;
            aCount -= pages;
        }
        else {
            cout << "용지가 부족하여 프린트 불가" << endl;
        }
    }
    void show() const {
        cout << model << ", " << mf << ", 남은 종이: " << aCount;
    }

    int getAvailablePaper() const {
        return aCount;
    }
};

class InkjetPrinter : public Printer {
    int aInk;
public:
    InkjetPrinter(string model = "", string mf = "", int a = 0, int ink = 0)
        : Printer(model, mf, a) {
        this->aInk = ink;
    }

    void printInkjet(int pages) {
        if (getAvailablePaper() >= pages) {
            if (aInk >= pages) {
                print(pages);
                aInk -= pages;
                cout << "프린트 성공" << endl;
            }
            else {
                cout << "잉크가 부족하여 프린트 불가" << endl;
            }
        }
        else {
            cout << "용지가 부족하여 프린트 불가" << endl;
        }
    }

    void showInk() const {
        show();
        cout << ", 남은 잉크: " << aInk  << endl;
    }
};

class LaserPrinter : public Printer {
    int aLaser;
public:
    LaserPrinter(string model = "", string mf = "", int a = 0, int toner = 0)
        : Printer(model, mf, a) { this->aLaser = toner; }

    void printLaser(int pages) {
        if (getAvailablePaper() >= pages) {
            if (aLaser >= pages) {
                print(pages);
                aLaser -= pages;
                cout << "프린트 성공" << endl;
            }
            else {
                cout << "토너가 부족하여 프린트 불가" << endl;
            }
        }
        else {
            cout << "용지가 부족하여 프린트 불가" << endl;
        }
    }

    void showLaser() const {
        show();
        cout << ", 남은 토너: " << aLaser << endl;
    }
};

int main() {
    InkjetPrinter ink("Officejet V40", "HP", 5, 10);
    LaserPrinter laser("SCX-6x45", "삼성전자", 3, 20);

    cout << "현재 작동중인 2대의 프린터는 아래와 같다" << endl;
    cout << "잉크젯 : ";
    ink.showInk();
    cout << "레이저 : ";
    laser.showLaser();

    int printer, paper;
    char ch;
    while (true) {
        cout << endl << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
        cin >> printer >> paper;
        switch (printer) {
        case 1: ink.printInkjet(paper); break;
        case 2: laser.printLaser(paper); break;
        default: cout << "잘못된 입력입니다." << endl; break;
        }
        ink.showInk();
        laser.showLaser();

        cout << "계속 프린트 하시겠습니까(y/n)>>";
        cin >> ch;
        if (ch == 'n') break;
    }

    return 0;
}
