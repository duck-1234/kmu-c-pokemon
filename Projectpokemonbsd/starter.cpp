#include "starter.h"
#include <iostream>
using namespace std;

string starter() {
    string choice;

    while (true) {
        cout << "���ϴ� ��Ÿ�� ���ϸ��� �����ϼ��� (�̻��ز�,���ڸ�,�źϿ�): ";
        cin >> choice;

        if (choice == "���ڸ�") {
            cout << "���ڸ��� �����߽��ϴ�!" << endl;
            cout << "           .=-------=:                              " << endl;
            cout << "HP: 39 / ���ݷ�: 52 / ����: 43" << endl;
            break;
        }
        else if (choice == "�źϿ�") {
            cout << "�źϿ��� �����߽��ϴ�!" << endl;
            cout << "HP: 44 / ���ݷ�: 48 / ����: 65" << endl;
            break;
        }
        else if (choice == "�̻��ز�") {
            cout << "�̻��ز��� �����߽��ϴ�!" << endl;
            cout << "HP: 45 / ���ݷ�: 49 / ����: 49" << endl;
            break;
        }
        else {
            cout << "�߸� �Է��߽��ϴ�. �ٽ� �Է��ϼ���." << endl;
        }
    }
    return choice;
}