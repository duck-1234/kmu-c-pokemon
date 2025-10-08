#include "battle.h"
#include "pokemon.h"
#include <iostream>
#include <cstdlib>

using namespace std;

struct Move {
    std::string name;
    int power;
};

Move getMove(std::string name) {
	if (name == "�����ġ��")     return { name, 30 };
    if (name == "���Ѹ���")       return { name, 20 };
    if (name == "����ä��")       return { name, 45 };
    if (name == "�����ġ��")     return { name, 40 };
    if (name == "ȸ����")         return { name, 40 };
    if (name == "�Ҳɼ���")       return { name, 40 };
    if (name == "������")         return { name, 35 };
    if (name == "ȭ�����")       return { name, 90 };
    if (name == "������")         return { name, 40 };
    if (name == "��ǰ")           return { name, 20 };
    if (name == "���̵������")   return { name, 80 };
    if (name == "�ż�")           return { name, 60 };
    if (name == "ȭ���ڵ���")     return { name, 70 };
    if (name == "��������")       return { name, 65 };
    if (name == "���")           return { name, 50 };
    if (name == "�����ĵ�")       return { name, 85 };
    if (name == "�Ҳɾ���")       return { name, 75 };
    if (name == "�����ĵ�")       return { name, 80 };
    if (name == "����")           return { name, 60 };
    if (name == "������μ���")   return { name, 80 };
    if (name == "�����ڸ���")     return { name, 35 };
    if (name == "Ǯ����")         return { name, 55 };
    if (name == "��������")       return { name, 60 };
    if (name == "��¦����")       return { name, 40 };
    if (name == "������Ű�׽ý�") return { name, 90 };
    if (name == "ī����")         return { name, 70 };
    if (name == "���̾��ص�")     return { name, 80 };
    if (name == "�߰�")           return { name, 60 };
    if (name == "����")           return { name, 70 };
    if (name == "�õ���")         return { name, 90 };
    if (name == "��ħ")           return { name, 40 };
    if (name == "�����")       return { name, 70 };
    if (name == "��������")       return { name, 50 };
    if (name == "���濡��")       return { name, 70 };
    if (name == "��������")       return { name, 50 };
    if (name == "�ĵ�ź")         return { name, 80 };
    if (name == "������")         return { name, 75 };
    if (name == "����ű")         return { name, 85 };
    if (name == "������")         return { name, 60 };
    if (name == "���Ҽ�")       return { name, 80 };
    if (name == "Ʈ���̾���")     return { name, 90 };
    if (name == "����")           return { name, 80 };
    if (name == "���̹ޱ�")       return { name, 85 };
    if (name == "���������")     return { name, 90 };
    if (name == "�ĵ�Ÿ��")       return { name, 90 };
    if (name == "����")           return { name, 80 };
    if (name == "����ũ")         return { name, 65 };
    if (name == "���ϵ庼Ʈ")     return { name, 90 };
    if (name == "���̵��ĳ��")   return { name, 90 };
    if (name == "���Ǻг�")       return { name, 85 };
    if (name == "�����ĵ�")       return { name, 85 };
    if (name == "����������")     return { name, 80 };
    if (name == "����")           return { name, 80 };
    if (name == "Ǯ����")         return { name, 60 };
    if (name == "�Ҹ���ġ")       return { name, 40 };
    if (name == "�ڸ���ġ")       return { name, 90 };
    if (name == "����ǹ�ġ��")   return { name, 80 };

    return { name, 50 };
}

int calcDamage(Pokemon attacker, Pokemon defender, string moveName) {
    Move move = getMove(moveName);
    int damage = (attacker.attack * move.power / 100) - (defender.defense/5);
    if (damage < 1) damage = 1;
    return damage;
}
void battle(Pokemon& myPoke, Pokemon& enemy) {
    myPoke.hp = myPoke.maxHp;
    enemy.hp = enemy.maxHp;

    cout << "\n=============================\n";
    cout << myPoke.name << " VS " << enemy.name << "!" << endl;
    cout << "=============================\n";

    while (myPoke.hp > 0 && enemy.hp > 0) {
        cout << "\n[" << myPoke.name << " HP: " << myPoke.hp << " / " << enemy.name << " HP: " << enemy.hp << "]\n";

        cout << "\n����� ����� �����ϼ���:\n";
        cout << "1. " << myPoke.skill1 << "\n2. " << myPoke.skill2 << "\n3. " << myPoke.skill3 << "\n4. " << myPoke.skill4 << "\n> ";

        int choice;
        cin >> choice;
        string myMove;
        switch (choice) {
        case 1: myMove = myPoke.skill1; break;
        case 2: myMove = myPoke.skill2; break;
        case 3: myMove = myPoke.skill3; break;
        case 4: myMove = myPoke.skill4; break;
        default: myMove = myPoke.skill1; break;
        }

        string enemyMoves[4] = { enemy.skill1, enemy.skill2, enemy.skill3, enemy.skill4 };
        string enemyMove = enemyMoves[rand() % 4];

        bool playerFirst = true;

        if (playerFirst) {
            int dmg = calcDamage(myPoke, enemy, myMove);
            cout << myPoke.name << "�� " << myMove << "!" << endl;
            enemy.hp -= dmg;
            cout << enemy.name << "���� " << dmg << "�� ������!" << endl;

            if (enemy.hp > 0) {
                dmg = calcDamage(enemy, myPoke, enemyMove);
                cout << enemy.name << "�� " << enemyMove << "!" << endl;
                myPoke.hp -= dmg;
                cout << myPoke.name << "���� " << dmg << "�� ������!" << endl;
            }
        }
        else {
            int dmg = calcDamage(enemy, myPoke, enemyMove);
            cout << enemy.name << "�� " << enemyMove << "!" << endl;
            myPoke.hp -= dmg;
            cout << myPoke.name << "���� " << dmg << "�� ������!" << endl;

            if (myPoke.hp > 0) {
                dmg = calcDamage(myPoke, enemy, myMove);
                cout << myPoke.name << "�� " << myMove << "!" << endl;
                enemy.hp -= dmg;
                cout << enemy.name << "���� " << dmg << "�� ������!" << endl;
            }
        }

        if (myPoke.hp <= 0 || enemy.hp <= 0) {
            break;
        }
    }

    cout << "\n=============================\n";
    if (myPoke.hp > 0)
        cout << myPoke.name << "�� �¸�!\n";
    else
        cout << enemy.name << "�� �¸�...\n";
    cout << "=============================\n";
}