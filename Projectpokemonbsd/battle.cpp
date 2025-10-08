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
	if (name == "몸통박치기")     return { name, 30 };
    if (name == "씨뿌리기")       return { name, 20 };
    if (name == "덩굴채찍")       return { name, 45 };
    if (name == "몸통박치기")     return { name, 40 };
    if (name == "회오리")         return { name, 40 };
    if (name == "불꽃세례")       return { name, 40 };
    if (name == "할퀴기")         return { name, 35 };
    if (name == "화염방사")       return { name, 90 };
    if (name == "물대포")         return { name, 40 };
    if (name == "거품")           return { name, 20 };
    if (name == "하이드로펌프")   return { name, 80 };
    if (name == "신속")           return { name, 60 };
    if (name == "화염자동차")     return { name, 70 };
    if (name == "번개엄니")       return { name, 65 };
    if (name == "기습")           return { name, 50 };
    if (name == "악의파동")       return { name, 85 };
    if (name == "불꽃엄니")       return { name, 75 };
    if (name == "물의파동")       return { name, 80 };
    if (name == "물기")           return { name, 60 };
    if (name == "깨물어부수기")   return { name, 80 };
    if (name == "연속자르기")     return { name, 35 };
    if (name == "풀베기")         return { name, 55 };
    if (name == "벌레먹음")       return { name, 60 };
    if (name == "깜짝베기")       return { name, 40 };
    if (name == "사이코키네시스") return { name, 90 };
    if (name == "카운터")         return { name, 70 };
    if (name == "아이언해드")     return { name, 80 };
    if (name == "발경")           return { name, 60 };
    if (name == "번개")           return { name, 70 };
    if (name == "냉동빔")         return { name, 90 };
    if (name == "독침")           return { name, 40 };
    if (name == "독찌르기")       return { name, 70 };
    if (name == "돌던지기")       return { name, 50 };
    if (name == "스톤에지")       return { name, 70 };
    if (name == "바위깨기")       return { name, 50 };
    if (name == "파동탄")         return { name, 80 };
    if (name == "본러쉬")         return { name, 75 };
    if (name == "점프킥")         return { name, 85 };
    if (name == "차지빔")         return { name, 60 };
    if (name == "기어소서")       return { name, 80 };
    if (name == "트라이어택")     return { name, 90 };
    if (name == "지진")           return { name, 80 };
    if (name == "들이받기")       return { name, 85 };
    if (name == "아쿠아테일")     return { name, 90 };
    if (name == "파도타기")       return { name, 90 };
    if (name == "괴력")           return { name, 80 };
    if (name == "스파크")         return { name, 65 };
    if (name == "와일드볼트")     return { name, 90 };
    if (name == "하이드로캐논")   return { name, 90 };
    if (name == "용의분노")       return { name, 85 };
    if (name == "용의파동")       return { name, 85 };
    if (name == "폭포오르기")     return { name, 80 };
    if (name == "열탕")           return { name, 80 };
    if (name == "풀묶기")         return { name, 60 };
    if (name == "불릿펀치")       return { name, 40 };
    if (name == "코멧펀치")       return { name, 90 };
    if (name == "사념의박치기")   return { name, 80 };

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

        cout << "\n사용할 기술을 선택하세요:\n";
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
            cout << myPoke.name << "의 " << myMove << "!" << endl;
            enemy.hp -= dmg;
            cout << enemy.name << "에게 " << dmg << "의 데미지!" << endl;

            if (enemy.hp > 0) {
                dmg = calcDamage(enemy, myPoke, enemyMove);
                cout << enemy.name << "의 " << enemyMove << "!" << endl;
                myPoke.hp -= dmg;
                cout << myPoke.name << "에게 " << dmg << "의 데미지!" << endl;
            }
        }
        else {
            int dmg = calcDamage(enemy, myPoke, enemyMove);
            cout << enemy.name << "의 " << enemyMove << "!" << endl;
            myPoke.hp -= dmg;
            cout << myPoke.name << "에게 " << dmg << "의 데미지!" << endl;

            if (myPoke.hp > 0) {
                dmg = calcDamage(myPoke, enemy, myMove);
                cout << myPoke.name << "의 " << myMove << "!" << endl;
                enemy.hp -= dmg;
                cout << enemy.name << "에게 " << dmg << "의 데미지!" << endl;
            }
        }

        if (myPoke.hp <= 0 || enemy.hp <= 0) {
            break;
        }
    }

    cout << "\n=============================\n";
    if (myPoke.hp > 0)
        cout << myPoke.name << "의 승리!\n";
    else
        cout << enemy.name << "의 승리...\n";
    cout << "=============================\n";
}