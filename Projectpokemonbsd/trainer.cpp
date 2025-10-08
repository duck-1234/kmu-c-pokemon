#include "trainer.h"
#include <string>

// static index ���� ���� (����)
static int indexTown1 = 0;
static int indexTown2 = 0;
static int indexTown3 = 0;
static int indexTown4 = 0;

Trainer selectTrainer(int town) {
    Trainer t;
    switch (town) {
    case 1: {
        std::string names[] = { "��ü", "����", "����", "ī��", "���̸���" };
        std::string pokes[] = { "�̻��ؾ�", "���̸�", "����", "�ﰡ", "���󵵽�" };
        int i = indexTown1 % 5;
        indexTown1++;
        t.name = names[i];
        t.pokemon = createPokemon(pokes[i]);  // ���� ���ϸ� �Ҵ�
        break;
    }
    case 2: {
        std::string names[] = { "ȣ��", "�̽�", "ö��", "�ʷ�", "����" };
        std::string pokes[] = { "����ũ", "�����縮", "������", "����Ÿ", "�Ƹ��Ƶ���" };
        int i = indexTown2 % 5;
        indexTown2++;
        t.name = names[i];
        t.pokemon = createPokemon(pokes[i]);
        break;
    }
    case 3: {
        std::string names[] = { "��", "����", "�Ը�", "��ũ�θ�", "����" };
        std::string pokes[] = { "�����Ľ�", "��ī����", "����Ÿ", "����", "��ճ�����" };
        int i = indexTown3 % 5;
        indexTown3++;
        t.name = names[i];
        t.pokemon = createPokemon(pokes[i]);
        break;
    }
    case 4: {
        std::string names[] = { "�ƽ���", "����", "����", "����", "��ȣ" };
        std::string pokes[] = { "�÷���", "��Ʈ��", "ŷ���", "�з�ƽ", "��Ÿ�׷ν�" };
        int i = indexTown4 % 5;
        indexTown4++;
        t.name = names[i];
        t.pokemon = createPokemon(pokes[i]);
        break;
    }
    default:
        t.name = "����";
        t.pokemon = createPokemon("missing.no");
        break;
    }
    return t;
}