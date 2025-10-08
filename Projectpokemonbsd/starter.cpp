#include "starter.h"
#include <iostream>
using namespace std;

string starter() {
    string choice;

    while (true) {
        cout << "원하는 스타터 포켓몬을 선택하세요 (이상해꽃,리자몽,거북왕): ";
        cin >> choice;

        if (choice == "리자몽") {
            cout << "리자몽을 선택했습니다!" << endl;
            cout << "           .=-------=:                              " << endl;
            cout << "HP: 39 / 공격력: 52 / 방어력: 43" << endl;
            break;
        }
        else if (choice == "거북왕") {
            cout << "거북왕을 선택했습니다!" << endl;
            cout << "HP: 44 / 공격력: 48 / 방어력: 65" << endl;
            break;
        }
        else if (choice == "이상해꽃") {
            cout << "이상해꽃을 선택했습니다!" << endl;
            cout << "HP: 45 / 공격력: 49 / 방어력: 49" << endl;
            break;
        }
        else {
            cout << "잘못 입력했습니다. 다시 입력하세요." << endl;
        }
    }
    return choice;
}