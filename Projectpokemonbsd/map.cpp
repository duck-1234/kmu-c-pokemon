#include "map.h"
#include <iostream>
using namespace std;

string map() {
    string direction;
    cout << "���� ������ ���� �ð��Դϴ�! ��� �������� ���ðڽ��ϱ�? (��, ��, ��, ��): ";
    cin >> direction;

    if (direction == "��") {
        cout << "�������� �̵��մϴ�." << endl;
        cout << "����� ������ �����ߴ�!" << endl;
    }
    else if (direction == "��") {
        cout << "�������� �̵��մϴ�." << endl;
        cout << "�ܸ𷡸����� �����ߴ�!" << endl;
    }
    else if (direction == "��") {
        cout << "�������� �̵��մϴ�." << endl;
        cout << "�����Ƽ�� �����ߴ�!" << endl;
    }
    else if (direction == "��") {
        cout << "�������� �̵��մϴ�." << endl;
        cout << "���Ͻ�Ƽ�� �����ߴ�!" << endl;
    }
    else {
        cout << "�߸��� �����Դϴ�. �ٽ� �õ��ϼ���." << endl;
        return map();
    }
    return direction;
}