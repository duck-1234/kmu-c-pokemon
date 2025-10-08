#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "title.h"
#include "nickname.h"
#include "starter.h"
#include "map.h"
#include "pokemon.h"
#include "trainer.h"
#include "battle.h"

using namespace std;
int main() {
    srand((unsigned)time(NULL));

    string y = title();
    if (y != "y" && y != "Y") {
        cout << "������ �����մϴ�." << endl;
        return 0;
    }

    cout << "������ �����մϴ�!" << endl;

    string name = nickname();
    cout << "��, " << name << "! ���ϸ� ����� ���!" << endl;

    string myPokemonName = starter();
    Pokemon myPoke = createPokemon(myPokemonName);

#ifdef _WIN32
    system("pause");
    system("cls");
#else
    cout << "����Ϸ��� ���͸� ��������...";
    cin.ignore();
    cin.get();
#endif

    while (true) {
        int townChoice;
        cout << "\n���ø� �����ϼ���.\n1. ����⸶��\n2. �ܸ𷡸���\n3. �����Ƽ\n4. ���Ͻ�Ƽ\n5. ��������\n> ";
        cin >> townChoice;

        if (townChoice == 5) {
            cout << "������ �����մϴ�." << endl;
            break;
        }

        Trainer enemyTrainer = selectTrainer(townChoice);

        cout << "\nƮ���̳� " << enemyTrainer.name << "��(��) " << enemyTrainer.pokemon.name << "��(��) �����´�!" << endl;

#ifdef _WIN32
        system("pause");
#else
        cout << "����Ϸ��� ���͸� ��������...";
        cin.ignore();
        cin.get();
#endif

        battle(myPoke, enemyTrainer.pokemon);

        if (myPoke.hp <= 0) {
            cout << myPoke.name << "�� ���������ϴ�. ���� ����." << endl;
            break;
        }
        else {
            cout << myPoke.name << "�� ���� HP: " << myPoke.hp << endl;         
           myPoke.hp = myPoke.maxHp;
        }
    }

    return 0;
}