#include "nickname.h"
#include <iostream>
#include <string>
using namespace std;

string nickname() {
    string name;
    cout << "Ʈ���̳��� �г����� ���ÿ�: ";
    cin >> name;
    cout << "���ϸ� ���� �� ���� ȯ���Ѵ�, " << name << "!" << endl;
    return name;

}
