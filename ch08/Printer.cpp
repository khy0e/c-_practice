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
            cout << "������ �����Ͽ� ����Ʈ �Ұ�" << endl;
        }
    }
    void show() const {
        cout << model << ", " << mf << ", ���� ����: " << aCount;
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
                cout << "����Ʈ ����" << endl;
            }
            else {
                cout << "��ũ�� �����Ͽ� ����Ʈ �Ұ�" << endl;
            }
        }
        else {
            cout << "������ �����Ͽ� ����Ʈ �Ұ�" << endl;
        }
    }

    void showInk() const {
        show();
        cout << ", ���� ��ũ: " << aInk  << endl;
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
                cout << "����Ʈ ����" << endl;
            }
            else {
                cout << "��ʰ� �����Ͽ� ����Ʈ �Ұ�" << endl;
            }
        }
        else {
            cout << "������ �����Ͽ� ����Ʈ �Ұ�" << endl;
        }
    }

    void showLaser() const {
        show();
        cout << ", ���� ���: " << aLaser << endl;
    }
};

int main() {
    InkjetPrinter ink("Officejet V40", "HP", 5, 10);
    LaserPrinter laser("SCX-6x45", "�Ｚ����", 3, 20);

    cout << "���� �۵����� 2���� �����ʹ� �Ʒ��� ����" << endl;
    cout << "��ũ�� : ";
    ink.showInk();
    cout << "������ : ";
    laser.showLaser();

    int printer, paper;
    char ch;
    while (true) {
        cout << endl << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
        cin >> printer >> paper;
        switch (printer) {
        case 1: ink.printInkjet(paper); break;
        case 2: laser.printLaser(paper); break;
        default: cout << "�߸��� �Է��Դϴ�." << endl; break;
        }
        ink.showInk();
        laser.showLaser();

        cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
        cin >> ch;
        if (ch == 'n') break;
    }

    return 0;
}
