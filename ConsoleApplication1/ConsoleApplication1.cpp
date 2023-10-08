#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include "windows.h"
using namespace std;

struct monstr {
    int HP;
    int UR;
} slizn, zlog, slizen, toxic, lol;

class Wolf
{

private:
    int Rand, CritMonstr = 0, P_crit, MinYr, MaxYr;

public:
    int Zd, Adk;
    string Nick;

    Wolf(int h, string name, int P, int Mini, int Maxi)
    {
        P_crit = P;
        Zd = h;
        Nick = name;
        MinYr = Mini;
        MaxYr = Maxi;
    }

    void Attack(int x);

    void Dis();
};

void Wolf::Dis()
{
    if (Zd > 0)
    {
        Attack(P_crit);
        cout << "Здоровья: " << Zd << endl << endl;
    }
    else
    {
        Adk = 0;
        cout << Nick << " повержен." << endl << endl;
    }
}

void Wolf::Attack(int x)
{
    Rand = 1 + rand() % x;
    switch (Rand) {
    case 1: {Adk = MinYr + rand() % MaxYr + CritMonstr * P_crit; CritMonstr = 0; cout << Nick << " сейчас нанесёт урона: " << Adk << endl; break; }
    case 2: {Adk = MinYr + rand() % MaxYr + CritMonstr * P_crit; CritMonstr = 0; cout << Nick << " сейчас нанесёт урона: " << Adk << endl; break; }
    case 3: {Adk = 0; CritMonstr++; cout << Nick << " достаёт новую кирку.." << endl; break; }
    default: {Adk = 0; CritMonstr++; cout << Nick << " натягивает лук.." << endl; break; }
    }
}
//бык
void BIK(monstr A, int& a, int s) {
    int AttakMonstr, ViborOne, ViborTwo, AttakUserA, AttakUserS, Command, hod = 0, CritMonstr = 0, CritUser = 0;
    string CommandProtection;
    A.HP = 10 + rand() % (21);
    cout << "Тебе встретилось животное.. Это же кабан!" << endl << endl << "Здоровье: " << A.HP << endl << "У тебя здоровья: " << a << endl << endl;
    while (A.HP > 0 and a > 0) {
        hod++;
        AttakMonstr = 1 + rand() % 3;
        switch (AttakMonstr) {
        case 1: {A.UR = 5 + rand() % 11 + CritMonstr * 30; CritMonstr = 0;  cout << "Кабан сейчас нанесёт урона: " << A.UR << endl << endl; break; }
        case 2: {A.UR = 5 + rand() % 11 + CritMonstr * 30; CritMonstr = 0;  cout << "Кабан сейчас нанесёт урона: " << A.UR << endl << endl; break; }
        case 3: {A.UR = 0; CritMonstr++; cout << "Кабан готовит атаку.." << endl << endl; break; }
        }
        ViborOne = 1 + rand() % 3;
        switch (ViborOne) {
        case 1: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserA = 5 + rand() % 11 + 3 * s; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
        case 2: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserA = 5 + rand() % 11 + 3 * s; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
        case 3: {AttakUserA = 0; cout << "1 - Отдохнуть" << endl; break; }
        }
        ViborTwo = 1 + rand() % 3;
        switch (ViborTwo) {
        case 1: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserS = 5 + rand() % 11 + 3 * s; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
        case 2: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserS = 5 + rand() % 11 + 3 * s; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
        case 3: {AttakUserS = 0; cout << "2 - Отдохнуть" << endl; break; }
        }
        cout << "Выбери действие : ";
        do {
            cin >> CommandProtection;
            if (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "666778" and CommandProtection != "2010") cout << "Такой команды нет, попробуй ещё раз: ";
        } while (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "666778" and CommandProtection != "2010");
        Command = stoi(CommandProtection);
        switch (Command) {
        case 1: { if (AttakUserA != 0) {
            CritUser = 0;
            A.HP = A.HP - AttakUserA;
            cout << "Ты нанёс урон" << endl;
        }
              else { cout << "Ты отдохнул" << endl; CritUser++; }
              break; }
        case 2: { if (AttakUserS != 0) {
            CritUser = 0;
            A.HP = A.HP - AttakUserS;
            cout << "Ты нанёс урон" << endl;
        }
              else { cout << "Ты отдохнул" << endl; CritUser++; }
              break; }
        case 666778: {A.HP = 0;  break; }
        case 2010: {a = 0; }
        }
        if (A.HP > 0 and a > 0) {
            if (A.UR > 0) {
                a = a - A.UR;
            }
            cout << "Ход#" << hod << " закончился. ..  ." << endl;
            system("pause");
            system("cls");
            cout << "У свиньи осталось здоровья: " << A.HP << endl;
            cout << "У тебя осталось здоровья: " << a << endl << endl;
        }
    }
    system("cls");
    if (A.HP <= 0) {
        cout << "Бык повержен!" << endl << "Ходов сделано: " << hod << endl;
        system("pause");
    }
}

//олень
void olen (monstr A, int& a, int s) {
    int AttakMonstr, ViborOne, ViborTwo, AttakUserA, AttakUserS, Command, hod = 0, CritMonstr = 0, CritUser = 0, ykon=0, win=0;
    string CommandProtection;
    A.HP = 30 + rand() % (21);
    cout << "Тебе встретилось животное.. Это же ненецкий олень!" << endl << endl << "Здоровье: " << A.HP << endl << "У тебя здоровья: " << a << endl << endl;
    while (A.HP > 0 and a > 0 and win!=3) {
        hod++;
        AttakMonstr = 1 + rand() % 3;
        switch (AttakMonstr) {
        case 1: {A.UR = 20 + rand() % 61 + CritMonstr * 1; CritMonstr = 0;  cout << "Олень сейчас нанесёт урона: " << A.UR << endl << endl; break; }
        case 2: {A.UR = 0; CritMonstr++; cout << "Олень готовит атаку.." << endl << endl; break; }
        case 3: {A.UR = 0; CritMonstr++; cout << "Олень готовит атаку.." << endl << endl; break; }
        }
        ViborOne = 1 + rand() % 3;
        switch (ViborOne) {
        case 1: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserA = 5 + rand() % 11 + 3 * s; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
        case 2: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserA = 5 + rand() % 11 + 3 * s; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
        case 3: {AttakUserA = 0; cout << "1 - Отдохнуть" << endl; ykon = 1; break; }
        }
        ViborTwo = 1 + rand() % 3;
        switch (ViborTwo) {
        case 1: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserS = 5 + rand() % 11 + 3 * s; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
        case 2: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserS = 5 + rand() % 11 + 3 * s; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
        case 3: {AttakUserS = 0; cout << "2 - Отдохнуть" << endl; ykon = 1; break; }
        }
        cout << "Выбери действие : ";
        do {
            cin >> CommandProtection;
            if (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "666778" and CommandProtection != "2010") cout << "Такой команды нет, попробуй ещё раз: ";
        } while (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "666778" and CommandProtection != "2010");
        Command = stoi(CommandProtection);
        switch (Command) {
        case 1: { if (AttakUserA != 0) {
            CritUser = 0;
            A.HP = A.HP - AttakUserA;
            cout << "Ты нанёс урон" << endl;
            win = 0;
        }
              else { cout << "Ты отдохнул" << endl; CritUser++; win = win + 1;}
              break; }
        case 2: { if (AttakUserS != 0) {
            CritUser = 0;
            A.HP = A.HP - AttakUserS;
            cout << "Ты нанёс урон" << endl;
            win = 0;
        }
              else { cout << "Ты отдохнул" << endl; CritUser++; win = win + 1;}
              break; }
        case 666778: {A.HP = 0;  break; }
        case 2010: {a = 0; }
        }
        if (A.HP > 0 and a > 0) {
            if (A.UR > 0 and ykon == 0) {
                a = a - A.UR;
            }
            else if (A.UR > 0 and ykon == 1) {
                cout <<endl<< "Олень не решился атаковать?" << endl<<endl;
            }
            ykon = 0;
            cout << "Ход#" << hod << " закончился. ..  ." << endl;
            system("pause");
            system("cls");
            cout << "У оленя осталось здоровья: " << A.HP << endl;
            cout << "У тебя осталось здоровья: " << a << endl << endl;
        }
    }
    system("cls");
    if (win == 3) {
        cout << "Неницкий олень не видит в тебя врага и уходит, как благородный!" << endl << "Ходов сделано: " << hod << endl;
        system("pause");
    }
    else if (A.HP <= 0) {
        cout << "Ненецкий олень повержен!" << endl << "Ходов сделано: " << hod << endl;
        system("pause");
    }
}

//курица
void CHICK(monstr A, int& a, int s) {
    int AttakMonstr, ViborOne, ViborTwo, AttakUserA, AttakUserS, Command, hod = 0, CritMonstr = 0, CritUser = 0;
    string CommandProtection;
    A.HP = 10 + rand() % (21);
    cout << "Тебе встретилось животное.. Это же курочка!" << endl << endl << "Здоровье: " << A.HP << endl << "У тебя здоровья: " << a << endl << endl;
    while (A.HP > 0 and a > 0) {
        hod++;
        AttakMonstr = 1 + rand() % 15;
        switch (AttakMonstr) {
        case 1: {A.UR = 0; cout << "Курочка снесла яичко.." << endl << endl; break; }
        case 2: {A.UR = 0; cout << "Курочка бегает.." << endl << endl; break; }
        case 3: {A.UR = 0; cout << "Курочка поймала червячка.." << endl << endl; break; }
        case 4: {A.UR = 0; cout << "Курочка клюёт зёрнышко.." << endl << endl; break; }
        case 5: {A.UR = 0; cout << "Курочка играет в fortnite.." << endl << endl; break; }
        case 6: {A.UR = 0; cout << "Курочка посмотрела в небо.." << endl << endl; break; }
        case 7: {A.UR = 0; cout << "Курочка села на травку.." << endl << endl; break; }
        case 9: {A.UR = 0; cout << "Курочка кудахтнула.." << endl << endl; break; }
        case 10: {A.UR = 0; cout << "Курочка крадётся.." << endl << endl; break; }
        case 11: {A.UR = 0; cout << "Курочка поцеловала петушка.." << endl << endl; break; }
        case 12: {A.UR = 0; cout << "Курочка попила из лужи.." << endl << endl; break; }
        case 13: {A.UR = 0; cout << "Курочка заснула на сене.." << endl << endl; break; }
        case 14: {A.UR = 0; cout << "Курочка зашла в курятник.." << endl << endl; break; }
        case 15: {A.UR = 0; cout << "Курочка посмотрела на тебя.." << endl << endl; break; }
        }
        ViborOne = 1 + rand() % 3;
        switch (ViborOne) {
        case 1: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserA = 5 + rand() % 11 + 3 * s; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
        case 2: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserA = 5 + rand() % 11 + 3 * s; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
        case 3: {AttakUserA = 0; cout << "1 - Отдохнуть" << endl; break; }
        }
        ViborTwo = 1 + rand() % 3;
        switch (ViborTwo) {
        case 1: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserS = 5 + rand() % 11 + 3 * s; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
        case 2: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserS = 5 + rand() % 11 + 3 * s; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
        case 3: {AttakUserS = 0; cout << "2 - Отдохнуть" << endl; break; }
        }
        cout << "Выбери действие : ";
        do {
            cin >> CommandProtection;
            if (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "666778" and CommandProtection != "2010") cout << "Такой команды нет, попробуй ещё раз: ";
        } while (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "666778" and CommandProtection != "2010");
        Command = stoi(CommandProtection);
        switch (Command) {
        case 1: { if (AttakUserA != 0) {
            CritUser = 0;
            A.HP = A.HP - AttakUserA;
            cout << "Ты нанёс урон" << endl;
        }
              else { cout << "Ты отдохнул" << endl; CritUser++; }
              break; }
        case 2: { if (AttakUserS != 0) {
            CritUser = 0;
            A.HP = A.HP - AttakUserS;
            cout << "Ты нанёс урон" << endl;
        }
              else { cout << "Ты отдохнул" << endl; CritUser++; }
              break; }
        case 666778: {A.HP = 0;  break; }
        case 2010: {a = 0; }
        }
        if (A.HP > 0 and a > 0) {
            if (A.UR > 0) {
                a = a - A.UR;
            }
            cout << "Ход#" << hod << " закончился. ..  ." << endl;
            system("pause");
            system("cls");
            cout << "У курочки осталось здоровья: " << A.HP << endl;
            cout << "У тебя осталось здоровья: " << a << endl << endl;
        }
    }
    system("cls");
    if (A.HP <= 0) {
        cout << "Ты убил курочку." << endl << "Ходов сделано: " << hod << endl;
        system("pause");
    }
}

//слизень
void SLIZ(monstr A, int& a, int s){
    int AttakMonstr, ViborOne, ViborTwo, AttakUserA, AttakUserS, Command, hod=0, CritMonstr=0, CritUser = 0;
    string CommandProtection;
    A.HP = 40 + rand() % (81);
    cout << "Тебе встретилось странное существо.. Это кислотный слизнь!" << endl << endl << "Здоровье: " << A.HP << endl << "У тебя здоровья: " << a << endl << endl;
    while (A.HP > 0 and a > 0) {
        hod++;
        AttakMonstr = 1 + rand() % 3;
        switch (AttakMonstr) {
        case 1: {A.UR = 5 + rand() % 11 + CritMonstr * 5; CritMonstr = 0;  cout << "Слизнь сейчас нанесёт урона: " << A.UR << endl << endl; break; }
        case 2: {A.UR = 0; cout << "Слизнь готовит атаку.." << endl << endl; break; }
        case 3: {A.UR = 0; CritMonstr++; cout << "Слизнь готовит атаку.." << endl << endl; break; }
        }
        ViborOne = 1 + rand() % 3;
        switch (ViborOne) {
        case 1: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserA = 5 + rand() % 11 + 3 * s; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
        case 2: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserA = 5 + rand() % 11 + 3 * s; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
        case 3: {AttakUserA = 0; cout << "1 - Отдохнуть" << endl; break; }
        }
        ViborTwo = 1 + rand() % 3;
        switch (ViborTwo) {
        case 1: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserS = 5 + rand() % 11 + 3 * s; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
        case 2: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserS = 5 + rand() % 11 + 3 * s; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
        case 3: {AttakUserS = 0; cout << "2 - Отдохнуть" << endl; break; }
        }
        cout << "Выбери действие : ";
        do {
            cin >> CommandProtection;
            if (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "666778" and CommandProtection != "2010") cout << "Такой команды нет, попробуй ещё раз: ";
        } while (CommandProtection!="1" and CommandProtection!="2" and CommandProtection!="666778" and CommandProtection!="2010");
        Command = stoi(CommandProtection);
        switch (Command) {
        case 1: { if (AttakUserA != 0) {
            CritUser = 0;
            A.HP = A.HP - AttakUserA;
            cout << "Ты нанёс урон" << endl;
        }
              else { cout << "Ты отдохнул" << endl; CritUser++;}
              break; }
        case 2: { if (AttakUserS != 0) {
            CritUser = 0;
            A.HP = A.HP - AttakUserS;
            cout << "Ты нанёс урон" << endl;
        }
              else { cout << "Ты отдохнул" << endl; CritUser++;}
              break; }
        case 666778: {A.HP = 0;  break; }
        case 2010: {a = 0; }
        }
        if (A.HP > 0 and a > 0) {
            if (A.UR > 0) {
                a = a - A.UR;
            }
            cout << "Ход#" << hod << " закончился. ..  ." << endl;
            system("pause");
            system("cls");
            cout << "У слизня осталось здоровья: " << A.HP << endl;
            cout << "У тебя осталось здоровья: " << a << endl<<endl;
        }
    }
    system("cls");
    if (A.HP <= 0) {
        cout << "Кислотный слизнь повержен!"<<endl<<"Ходов сделано: "<<hod<<endl;
        system("pause");
    }
}

//злогер
void SLOG(monstr A, int& a, int s) {
    int AttakMonstr, ViborOne, ViborTwo, AttakUserA, AttakUserS, Command, hod = 0, CritMonstr = 0, CritUser = 0;
    string CommandProtection;
    A.HP = 10 + rand() % (41);
    cout << "Тебе встретилось странное существо.. Это злогер!" <<endl << endl << "Здоровье: " << A.HP << endl << "У тебя здоровья: " << a << endl << endl;
    while (A.HP > 0 and a > 0) {
        hod++;
        AttakMonstr = 1 + rand() % 3;
        switch (AttakMonstr) {
        case 1: {A.UR = 15 + rand() % 26 + CritMonstr * 10; CritMonstr = 0; cout << "Злог сейчас нанесёт урона: " << A.UR << endl << endl; break; }
        case 2: {A.UR = 15 + rand() % 26 + CritMonstr * 10; CritMonstr = 0; cout << "Злог сейчас нанесёт урона: " << A.UR << endl << endl; break; }
        case 3: {A.UR = 0; CritMonstr++; cout << "Злог готовит атаку.." << endl << endl; break; }
        }
        ViborOne = 1 + rand() % 3;
        switch (ViborOne) {
        case 1: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserA = 5 + rand() % 11 + 3 * s; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
        case 2: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserA = 5 + rand() % 11 + 3 * s; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
        case 3: {AttakUserA = 0; cout << "1 - Отдохнуть" << endl; break; }
        }
        ViborTwo = 1 + rand() % 3;
        switch (ViborTwo) {
        case 1: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserS = 5 + rand() % 11 + 3 * s; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
        case 2: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserS = 5 + rand() % 11 + 3 * s; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
        case 3: {AttakUserS = 0; cout << "2 - Отдохнуть" << endl; break; }
        }
        cout << "Выбери действие : ";
        do {
            cin >> CommandProtection;
            if (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "666778" and CommandProtection != "2010") cout << "Такой команды нет, попробуй ещё раз: ";
        } while (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "666778" and CommandProtection != "2010");
        Command = stoi(CommandProtection);
        switch (Command) {
        case 1: { if (AttakUserA != 0) {
            CritUser = 0;
            A.HP = A.HP - AttakUserA;
            cout << "Ты нанёс урон" << endl;
        }
              else { cout << "Ты отдохнул" << endl; CritUser++; }
              break; }
        case 2: { if (AttakUserS != 0) {
            CritUser = 0;
            A.HP = A.HP - AttakUserS;
            cout << "Ты нанёс урон" << endl;
        }
              else { cout << "Ты отдохнул" << endl; CritUser++; }
              break; }
        case 666778: {A.HP = 0;  break; }
        case 2010: {a = 0; }
        }
        if (A.HP > 0 and a > 0) {
            if (A.UR > 0) {
                a = a - A.UR;
            }
            cout << "Ход#" << hod << " закончился. ..  ." << endl;
            system("pause");
            system("cls");
            cout << "У злога осталось здоровья: " << A.HP << endl;
            cout << "У тебя осталось здоровья: " << a << endl << endl;
        }
    }
    system("cls");
    if (A.HP <= 0) {
        cout << "Злогер повержен!" << endl << "Ходов сделано: " << hod << endl;
        system("pause");
    }
}

//ёжик
void EZ(monstr A, int& a, int s) {
    int AttakMonstr, ViborOne, ViborTwo, AttakUserA, AttakUserS, Command, hod = 0, CritMonstr = 0, CritUser = 0;
    string CommandProtection;
    A.HP = 10 + rand() % (21);
    cout << "Тебе встретилось животное.. Это королевский ёжик!" << endl << endl << "Здоровье: " << A.HP << endl << "У тебя здоровья: " << a << endl << endl;
    while (A.HP > 0 and a > 0) {
        hod++;
        AttakMonstr = 1 + rand() % 6;
        switch (AttakMonstr) {
        case 1: {A.UR = 3 + rand() % 5 + CritMonstr * 1; CritMonstr = 0; cout << "Ёжик сейчас нанесёт урона: " << A.UR << endl << endl; break; }
        case 2: {A.UR = 3 + rand() % 5 + CritMonstr * 1; CritMonstr = 0; cout << "Ёжик сейчас нанесёт урона: " << A.UR << endl << endl; break; }
        case 3: {A.UR = 3 + rand() % 5 + CritMonstr * 1; CritMonstr = 0; cout << "Ёжик сейчас нанесёт урона: " << A.UR << endl << endl; break; }
        case 4: {A.UR = 3 + rand() % 5 + CritMonstr * 1; CritMonstr = 0; cout << "Ёжик сейчас нанесёт урона: " << A.UR << endl << endl; break; }
        case 5: {A.UR = 3 + rand() % 5 + CritMonstr * 1; CritMonstr = 0; cout << "Ёжик сейчас нанесёт урона: " << A.UR << endl << endl; break; }
        case 6: {A.UR = 0; CritMonstr++; cout << "Ёжик свернулся в клубок.." << endl << endl; break; }
        }
        ViborOne = 1 + rand() % 3;
        switch (ViborOne) {
        case 1: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserA = 5 + rand() % 11 + 3 * s; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
        case 2: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserA = 5 + rand() % 11 + 3 * s; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
        case 3: {AttakUserA = 0; cout << "1 - Отдохнуть" << endl; break; }
        }
        ViborTwo = 1 + rand() % 3;
        switch (ViborTwo) {
        case 1: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserS = 5 + rand() % 11 + 3 * s; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
        case 2: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserS = 5 + rand() % 11 + 3 * s; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
        case 3: {AttakUserS = 0; cout << "2 - Отдохнуть" << endl; break; }
        }
        cout << "Выбери действие : ";
        do {
            cin >> CommandProtection;
            if (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "666778" and CommandProtection != "2010") cout << "Такой команды нет, попробуй ещё раз: ";
        } while (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "666778" and CommandProtection != "2010");
        Command = stoi(CommandProtection);
        switch (Command) {
        case 1: { if (AttakUserA != 0) {
            CritUser = 0;
            A.HP = A.HP - AttakUserA;
            cout << "Ты нанёс урон" << endl;
        }
              else { cout << "Ты отдохнул" << endl; CritUser++; }
              break; }
        case 2: { if (AttakUserS != 0) {
            CritUser = 0;
            A.HP = A.HP - AttakUserS;
            cout << "Ты нанёс урон" << endl;
        }
              else { cout << "Ты отдохнул" << endl; CritUser++; }
              break; }
        case 666778: {A.HP = 0;  break; }
        case 2010: {a = 0; }
        }
        if (A.HP > 0 and a > 0) {
            if (A.UR > 0) {
                a = a - A.UR;
            }
            cout << "Ход#" << hod << " закончился. ..  ." << endl;
            system("pause");
            system("cls");
            cout << "У ежа осталось здоровья: " << A.HP << endl;
            cout << "У тебя осталось здоровья: " << a << endl << endl;
        }
    }
    system("cls");
    if (A.HP <= 0) {
        cout << "Ёжик повержен!" << endl << "Ходов сделано: " << hod << endl << endl;
        system("pause");
        AttakMonstr = 10 + rand() % 6;
        cout <<  endl << endl << "Ёжика разорвало на " << AttakMonstr << " иголок!" << endl;
        a = a - AttakMonstr;
        cout << "Осталось здоровья: " << a << endl;
        system("pause");
    }
}

//мимикрылька
int Mimicril(monstr A, int& a, int s) {
    int AttakMonstr, ViborOne, ViborTwo, AttakUserA, AttakUserS, Command, hod = 0, CritMonstr = 0, CritUser = 0;
    string CommandProtection;
    A.HP = 30 + rand() % (21);
    AttakMonstr = 1 + rand() % (5);
    switch (AttakMonstr)
    {
    case 1: {cout << "Тебе встретилось странное существо.. Оно порит! Это летающая капуста!" << endl << endl << "Здоровье: " << A.HP << endl << "У тебя здоровья: " << a << endl << endl; break; }
    case 2: {cout << "Тебе встретилось странное существо.. Оно порит! Это левитирующее яблоко!" << endl << endl << "Здоровье: " << A.HP << endl << "У тебя здоровья: " << a << endl << endl; break; }
    case 3: {cout << "Тебе встретилось странное существо.. Оно порит! Это летающий кабан!" << endl << endl << "Здоровье: " << A.HP << endl << "У тебя здоровья: " << a << endl << endl; break; }
    case 4: {cout << "Тебе встретилось странное существо.. Оно порит! Это мячик!" << endl << endl << "Здоровье: " << A.HP << endl << "У тебя здоровья: " << a << endl << endl; break; }
    case 5: {cout << "Тебе встретилось странное существо.. Оно порит! Это заяц с крыльями!" << endl << endl << "Здоровье: " << A.HP << endl << "У тебя здоровья: " << a << endl << endl; break; }
    }
    while (A.HP > 0 and a > 0) {
        hod++;
        AttakMonstr = 1 + rand() % 3;
        switch (AttakMonstr) {
        case 1: {A.UR = 5 + rand() % 16 + CritMonstr * 2; CritMonstr = 0; cout << "Мимикрылька сейчас нанесёт урона: " << A.UR << endl << endl; break; }
        case 2: {A.UR = 10 + rand() % 11; CritMonstr = 0; cout << "Мимикрылька сейчас нанесёт урона: " << A.UR << endl << endl; break; }
        case 3: {A.UR = 0; CritMonstr++; cout << "Мимикрылька подлетает наверх.." << endl << endl; break; }
        }
        ViborOne = 1 + rand() % 3;
        switch (ViborOne) {
        case 1: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserA = 5 + rand() % 11 + 3 * s; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
        case 2: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserA = 5 + rand() % 11 + 3 * s; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
        case 3: {AttakUserA = 0; cout << "1 - Отдохнуть" << endl; break; }
        }
        ViborTwo = 1 + rand() % 3;
        switch (ViborTwo) {
        case 1: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserS = 5 + rand() % 11 + 3 * s; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
        case 2: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserS = 5 + rand() % 11 + 3 * s; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
        case 3: {AttakUserS = 0; cout << "2 - Отдохнуть" << endl; break; }
        }
        cout << "Выбери действие : ";
        do {
            cin >> CommandProtection;
            if (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "666778" and CommandProtection != "2010") cout << "Такой команды нет, попробуй ещё раз: ";
        } while (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "666778" and CommandProtection != "2010");
        Command = stoi(CommandProtection);
        switch (Command) {
        case 1: { if (AttakUserA != 0) {
            CritUser = 0;
            A.HP = A.HP - AttakUserA;
            cout << "Ты нанёс урон" << endl;
        }
              else { cout << "Ты отдохнул" << endl; CritUser++; }
              break; }
        case 2: { if (AttakUserS != 0) {
            CritUser = 0;
            A.HP = A.HP - AttakUserS;
            cout << "Ты нанёс урон" << endl;
        }
              else { cout << "Ты отдохнул" << endl; CritUser++; }
              break; }
        case 666778: {A.HP = 0;  return 1; }
        case 2010: {a = 0; }
        }
        if (A.HP > 0 and a > 0) {
            if (A.UR > 0) {
                a = a - A.UR;
            }
            if (A.HP < 15)
            {
                system("pause");
                cout << endl << endl << "Мимикрыл улетел. Ты проиграл." << endl << endl;
                system("pause");
                system("cls");
                return 0;
            }
            cout << "Ход#" << hod << " закончился. ..  ." << endl;
            system("pause");
            system("cls");
            cout << "У мимикрыльки осталось здоровья: " << A.HP << endl;
            cout << "У тебя осталось здоровья: " << a << endl << endl;
        }
    }
    system("cls");
    if (A.HP <= 0) {
        cout << "Мимикрыл повержен!" << endl << "Ходов сделано: " << hod << endl;
        system("pause");
        return 1;
    }
}


//добрый слизень
void SLIZEN(monstr A, int& a) {
    int plus, wop, lol;
    cout << "Тебе встретилось странное существо.. Это водный слизнь!" << endl << endl << "Оно покрыло тебя слизью. ..  ." << endl << "Места, где тебя обсосал слизнь, начали заживать. ..  ." << endl << "Здоровье восстановлено c " << a;
    if (a >= 100) { wop = 0; lol = 6;}
    if (a <= 99 and a>=70) { wop = 5; lol = 11; }
    if (a <= 69 and a >= 50) { wop = 10; lol = 8; }
    if (a <= 49) { wop = 15; lol = 6; }
    plus = wop + rand() % lol;
    a = a + plus;
    cout << " до " << a <<"!"<< endl << endl;
    system("pause");
}

//босс вокс
void ToxicSlizn(monstr A, int& a, int s) {
    int AttakMonstr, ViborOne, ViborTwo, AttakUserA, AttakUserS, Command, hod = 0, CritUser=0, AntiCrit=0;
    string CommandProtection;
    A.HP = 100 + rand() % (161);
    cout << "Тебе встретилось странное существо.. Это радиактивный дух!" << endl << endl << "Здоровье: " << A.HP << endl << "У тебя здоровья: " << a << endl << endl;
    while (A.HP > 0 and a > 0) {
        hod++;
        AttakMonstr = 1 + rand() % 3;
        switch (AttakMonstr) {
        case 1: {A.UR = 1 + rand() % 10; cout << "Вокс сейчас нанесёт урона: " << A.UR << endl << endl; break; }
        case 2: {A.UR = 1 + rand() % 10; cout << "Вокс сейчас нанесёт урона: " << A.UR << endl << endl; break; }
        case 3: {A.UR = 0; cout << "Вокс внезапно замер." << endl << "Ты ощущаешь, что замер также, как и вокс. ..  ." << endl << endl; AntiCrit+=3; break; }
        }
        ViborOne = 1 + rand() % 3;
        switch (ViborOne) {
        case 1: { if (AntiCrit != 0) { AttakUserA = 5 + rand() % 11; cout << "1 - Нанести " << AttakUserA << " урона" << endl; } else { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserA = 5 + rand() % 11 + 3 * s; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; } break; }
        case 2: { if (AntiCrit != 0) { AttakUserA = 5 + rand() % 11; cout << "2 - Нанести " << AttakUserA << " урона" << endl; } else { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * s + 7; } else { AttakUserA = 5 + rand() % 11 + 3 * s; } cout << "2 - Нанести " << AttakUserA << " урона" << endl; } break; }
        case 3: {AttakUserA = 0; cout << "1 - Отдохнуть" << endl; break; }
        }
        ViborTwo = 1 + rand() % 3;
        switch (ViborTwo) {
        case 1: { if (AntiCrit != 0) { AttakUserS = 5 + rand() % 11; cout << "1 - Нанести " << AttakUserS << " урона" << endl; } else { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserS = 5 + rand() % 11 + 3 * s; } cout << "1 - Нанести " << AttakUserS << " урона" << endl; } break; }
        case 2: { if (AntiCrit != 0) { AttakUserS = 5 + rand() % 11; cout << "2 - Нанести " << AttakUserS << " урона" << endl; } else { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserS = 5 + rand() % 11 + 3 * s; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; } break; }
        case 3: {AttakUserS = 0; cout << "2 - Отдохнуть" << endl; break; }
        }
        cout << "Выбери действие : ";
        do {
            cin >> CommandProtection;
            if (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "666778" and CommandProtection != "2010") cout << "Такой команды нет, попробуй ещё раз: ";
        } while (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "666778" and CommandProtection != "2010");
        Command = stoi(CommandProtection);
        switch (Command) {
        case 1: { if (AttakUserA != 0) {
            CritUser = 0;
            A.HP = A.HP - AttakUserA;
            if (AntiCrit > 0) {
                AntiCrit--;
            }
            cout << "Ты нанёс урон" << endl;
        }
              else { cout << "Ты отдохнул" << endl; CritUser++;}
              break; }
        case 2: { if (AttakUserS != 0) {
            CritUser = 0;
            if (AntiCrit>0) {
                AntiCrit--;
            }
            A.HP = A.HP - AttakUserS;
            cout << "Ты нанёс урон" << endl;
        }
              else {
            cout << "Ты отдохнул" << endl; CritUser++;}
              break; }
        case 666778: {A.HP = 0;  break; }
        case 2010: {a = 0; }
        }
        if (A.HP > 0 and a > 0) {
            if (A.UR > 0) {
                a = a - A.UR;
            }
            cout << "Ход#" << hod << " закончился. ..  ." << endl;
            system("pause");
            system("cls");
            cout << "У вокса осталось здоровья: " << A.HP << endl;
            cout << "У тебя осталось здоровья: " << a << endl << endl;
        }
    }
    system("cls");
    if (A.HP <= 0) {
        cout << "Вокс повержен!" << endl << "Ходов сделано: " << hod << endl;
        system("pause");
    }
}

//золотая овечка
int GOLD(monstr A, int& a, int s) {
    int AttakMonstr, ViborOne, ViborTwo, AttakUserA, AttakUserS, Command, hod = 0, CritMonstr = 0, CritUser = 0, beg = 0, hp;
    string CommandProtection;
    hp = 5 + rand() % (12);
    cout << "Тебе встретилось странное существо животное.. Это же золотая овца!" << endl << endl << "Здоровье: " << hp << endl << "У тебя здоровья: " << a << endl << endl;
    cout << "Что будешь делать?" << endl << "1 - сражаться" << endl << "2 - сбежать" << endl << "Выбери действие : ";
    do {
        getline(cin, CommandProtection);
        if (CommandProtection != "1" and CommandProtection != "2") cout << "Такой команды нет, попробуй ещё раз: ";
    } while (CommandProtection != "1" and CommandProtection != "2");
    Command = stoi(CommandProtection);
    switch (Command) {
    case 1: {A.HP = hp; break; }
    case 2: {beg = 1; break; }
    }
          while (A.HP > 0 and a > 0) {
              hod++;
              cout << endl<<"Овечка спит. ..  . "<< endl << endl;
              ViborOne = 1 + rand() % 3;
              switch (ViborOne) {
              case 1: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserA = 5 + rand() % 11 + 3 * s; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
              case 2: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserA = 5 + rand() % 11 + 3 * s; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
              case 3: {AttakUserA = 0; cout << "1 - Отдохнуть" << endl; break; }
              }
              ViborTwo = 1 + rand() % 3;
              switch (ViborTwo) {
              case 1: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserS = 5 + rand() % 11 + 3 * s; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
              case 2: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserS = 5 + rand() % 11 + 3 * s; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
              case 3: {AttakUserS = 0; cout << "2 - Отдохнуть" << endl; break; }
              }
              cout << "Выбери действие : ";
              do {
                  cin >> CommandProtection;
                  if (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "666778" and CommandProtection != "2010") cout << "Такой команды нет, попробуй ещё раз: ";
              } while (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "666778" and CommandProtection != "2010");
              Command = stoi(CommandProtection);  
              switch (Command) {
              case 1: { if (AttakUserA != 0) {
                  CritUser = 0;
                  A.HP = A.HP - AttakUserA;
                  cout << "Ты нанёс урон" << endl;
              }
                    else { cout << "Ты отдохнул" << endl; CritUser++; }
                    break; }
              case 2: { if (AttakUserS != 0) {
                  CritUser = 0;
                  A.HP = A.HP - AttakUserS;
                  cout << "Ты нанёс урон" << endl;
              }
                    else { cout << "Ты отдохнул" << endl; CritUser++; }
                    break; }
              case 666778: {A.HP = 0;  break; }
              case 2010: {a = 0; }
              }
              if (A.HP > 0) {
                  if (A.HP > 0) {
                      a = 0;
                      cout << endl<<"Овечка проснулась и лягнула тебя" << endl;
                      system("pause");
                  }
                  else {
                      cout << "Ход#" << hod << " закончился. ..  ." << endl;
                      system("pause");
                      system("cls");
                      cout << "У овцы осталось здоровья: " << A.HP << endl;
                      cout << "У тебя осталось здоровья: " << a << endl << endl;
                  }
              }
          }
          system("cls");
          if (beg == 1) { cout << "Ты сбежал."<<endl; 
          system("pause");
          }
           else if(A.HP <= 0) {
              cout << "Овца повержена!" << endl << "Ходов сделано: " << hod << endl;
              system("pause");
          }
          return beg;
    }

//разбойник - мушкет
int Taika(monstr A, int& a, int s)
{
    int AttakMonstr, ViborOne, ViborTwo, AttakUserA, AttakUserS, Command, hod = 0, CritMonstr = 0, CritUser = 0, beg = 0, hp, fraza, yv = 0, pop, mysh = 0, V = 0;
    string CommandProtection;
    hp = 115 + rand() % (26);
    cout << "Кто-то крикнул тебе в след: 'Мой сладенький, к моим ножкам!' " << endl << "Тебе встретилась разбойница Тайка.. " << endl;
    cout << endl << "Здоровье : " << hp << endl << "У тебя здоровья : " << a << endl << endl;
    cout << "Что будешь делать?" << endl << "1 - вступить в поединок" << endl << "2 - покинуть поле боя" << endl << "Выбери действие : ";
    do {
        cin >> CommandProtection; //cin >> CommandProtection;
        if (CommandProtection != "1" and CommandProtection != "2") cout << "Такой команды нет, попробуй ещё раз: ";
    } while (CommandProtection != "1" and CommandProtection != "2");
    Command = stoi(CommandProtection);
    switch (Command) {
    case 1: {
        A.HP = hp;
        cout << endl << "Разбойница чистит мушкет!" << endl << endl;
        break; }
    case 2: {beg = 1; break; }
    }
    while (A.HP > 0 and a > 0) {
        hod++;
        if (mysh == 0) {
            AttakMonstr = 1 + rand() % (3 - CritMonstr);
            switch (AttakMonstr) {
            case 1: {A.UR = 5 + rand() % (6 + CritMonstr * 90); CritMonstr = 0;  cout << "Разбойница сейчас нанесёт урона: " << A.UR << endl << endl; break; }
            case 2: {A.UR = 5 + rand() % (6 + CritMonstr * 90); CritMonstr = 0;  cout << "Разбойница сейчас нанесёт урона: " << A.UR << endl << endl; break; }
            case 3: {A.UR = 0; mysh++; cout << "Разбойница заряжает мушкет.." << endl << endl; break; }
            }
        }
        else if (V == 1)
        {
            cout << "Разбойница целится.." << endl << endl;
            CritMonstr++;
            mysh = 0;
        }
        else 
        {
            cout << "Разбойница сбилась.." << endl << endl;
            mysh = 0;
        }
        
        ViborOne = 1 + rand() % 3;
        switch (ViborOne) {
        case 1: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserA = 5 + rand() % 11 + 3 * s; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
        case 2: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserA = 5 + rand() % 11 + 3 * s; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
        case 3: {AttakUserA = 0; cout << "1 - Отдохнуть" << endl; break; }
        }
        ViborTwo = 1 + rand() % 3;
        switch (ViborTwo) {
        case 1: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserS = 5 + rand() % 11 + 3 * s; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
        case 2: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserS = 5 + rand() % 11 + 3 * s; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
        case 3: {AttakUserS = 0; cout << "2 - Отдохнуть" << endl; break; }
        }
        cout << "Выбери действие : ";
        do {
            cin >> CommandProtection;
            if (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "666778" and CommandProtection != "2010") cout << "Такой команды нет, попробуй ещё раз: ";
        } while (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "666778" and CommandProtection != "2010");
        Command = stoi(CommandProtection);
        switch (Command) {
        case 1: { if (AttakUserA != 0) {
            CritUser = 0;
            A.HP = A.HP - AttakUserA;
            cout << "Ты нанёс урон" << endl;
            V = 0;
        }
              else { cout << "Ты отдохнул" << endl; CritUser++; V = 1; }
              break; }
        case 2: { if (AttakUserS != 0) {
            CritUser = 0;
            A.HP = A.HP - AttakUserS + 4;
            cout << "Ты нанёс урон" << endl;
            V = 0;
        }
              else { cout << "Ты отдохнул" << endl; CritUser++; V = 1;}
              break; }
        case 666778: {A.HP = 0;  break; }
        case 2010: {a = 0; }
        }
        if (A.HP > 0 and a > 0) {
            if (A.UR > 0) {
                a = a - A.UR;
            }
            cout << "Ход#" << hod << " закончился. ..  ." << endl;
            system("pause");
            system("cls");
            cout << "У разбойницы осталось здоровья: " << A.HP << endl;
            cout << "У тебя осталось здоровья: " << a << endl << endl;
        }
    }
    system("cls");
    if (beg == 1) {
        cout << "Ты сбежал." << endl;
        system("pause");
    }
    else if (A.HP <= 0) {
        cout << "Разбойница повержена!" << endl << "Ходов сделано: " << hod << endl;
        system("pause");
    }
    return beg;
}

//разбойник - уворот
int gnuk(monstr A, int& a, int s) {
    int AttakMonstr, ViborOne, ViborTwo, AttakUserA, AttakUserS, Command, hod = 0, CritMonstr = 0, CritUser = 0, beg = 0, hp, fraza, yv=0, pop;
    string CommandProtection;
    hp = 120 + rand() % (76);
    cout << "Кто-то крикнул тебе в след: 'Из тебя выйдет отличный пледик, кисонька!' " << endl << "Тебе встретился разбойник Гнок.. " << endl; 
    cout  << endl << "Здоровье : " << hp << endl << "У тебя здоровья : " << a << endl << endl;
    cout << "Что будешь делать?" << endl << "1 - вступить в поединок" << endl << "2 - покинуть поле боя" << endl << "Выбери действие : ";
    do {
        cin >> CommandProtection; //cin >> CommandProtection;
        if (CommandProtection != "1" and CommandProtection != "2") cout << "Такой команды нет, попробуй ещё раз: ";
    } while (CommandProtection != "1" and CommandProtection != "2");
    Command = stoi(CommandProtection);
    switch (Command) {
    case 1: {A.HP = hp;
        cout << endl << "Разбойник заряжает арболёт!" << endl << endl;
        break; }
    case 2: {beg = 1; break; }
    }
    while (A.HP > 0 and a > 0) {
        hod++;
        AttakMonstr = 1 + rand() % 3;
        switch (AttakMonstr) {
        case 1: {A.UR = 0; cout << "Разбойник натягивает тетиву.." << endl << endl; CritMonstr = CritMonstr+1; break; }
        case 2: {A.UR = 8 + rand() % 3 + CritMonstr * 3; CritMonstr = 0;  cout << "В тебя летит стрела со скоростью: " << A.UR << endl << endl; break; }
        case 3: {A.UR = 0; CritMonstr++; cout << "Разбойник отступает на безопасное расстояние." << endl << endl; yv = yv + 1; break; }
        }
        ViborOne = 1 + rand() % 3;
        switch (ViborOne) {
        case 1: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserA = 5 + rand() % 11 + 3 * s; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
        case 2: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserA = 5 + rand() % 11 + 3 * s; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
        case 3: {AttakUserA = 0; cout << "1 - Отдохнуть" << endl; break; }
        }
        ViborTwo = 1 + rand() % 3;
        switch (ViborTwo) {
        case 1: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserS = 5 + rand() % 11 + 3 * s; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
        case 2: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserS = 5 + rand() % 11 + 3 * s; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
        case 3: {AttakUserS = 0; cout << "2 - Отдохнуть" << endl; break; }
        }
        cout << "Выбери действие: ";
        do {
            cin >> CommandProtection;
            if (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "666778" and CommandProtection != "2010") cout << "Такой команды нет, попробуй ещё раз: ";
        } while (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "666778" and CommandProtection != "2010");
        Command = stoi(CommandProtection);
        switch (Command) {
        case 1: { if (AttakUserA != 0) {
            pop= 1+rand() % 1 + yv;
            switch (pop)
            {
            case 1: {
                A.HP = A.HP - AttakUserA;
                cout << "Ты нанёс урон" << endl;
                break; }
            default: {cout << "Разбойник увернулся." << endl; yv = 0; break; }
            }
            CritUser = 0;
        }
              else { cout << "Ты отдохнул" << endl; CritUser++; }
              break; }
        case 2: { if (AttakUserS != 0) {
            pop = 1 + rand() % 1 + yv;
            switch (pop)
            {
            case 1: {
                A.HP = A.HP - AttakUserS;
                cout << "Ты нанёс урон" << endl; 
                break;
            }
            default: {cout << "Разбойник увернулся." << endl; yv = 0;  break; }
            }
            CritUser = 0;
        }
              else { cout << "Ты отдохнул" << endl; CritUser++; }
              break; }
        case 666778: {A.HP = 0;  break; }
        case 2010: {a = 0; }
        }
        if (A.HP > 0 and a > 0) {
            if (A.UR > 0) {
                a = a - A.UR;
            }
            cout << "Ход#" << hod << " закончился. ..  ." << endl;
            system("pause");
            system("cls");
            cout << "У разбойника осталось здоровья: " << A.HP << endl;
            cout << "У тебя осталось здоровья: " << a << endl << endl;
        }
    }
    system("cls");
    if (beg == 1) {
        cout << "Ты сбежал." << endl;
        system("pause");
    }
    else if (A.HP <= 0) {
        cout << "Разбойник повержена!" << endl << "Ходов сделано: " << hod << endl;
        system("pause");
    }
    return beg;
}

//разбойник - маска
int Zeld(monstr A, int& a, int s)
{
    int AttakMonstr, ViborOne, ViborTwo, AttakUserA, AttakUserS, Command, hod = 0, CritMonstr = 0, CritUser = 0, beg = 0, hp, fraza, yv = 0, pop;
    string CommandProtection;
    hp = 100 + rand() % (41);
    cout << "Кто-то крикнул тебе в след: 'Эй, мешок костей, ну-к, бырь сюда!' " << endl << "Тебе встретился разбойник в таинственной маске.." << endl;
    cout << endl << "Здоровье : 150" << endl << "У тебя здоровья : " << a << endl << endl;
    cout << "Что будешь делать?" << endl << "1 - вступить в поединок" << endl << "2 - покинуть поле боя" << endl << "Выбери действие : ";
    do {
        cin >> CommandProtection; //cin >> CommandProtection;
        if (CommandProtection != "1" and CommandProtection != "2") cout << "Такой команды нет, попробуй ещё раз: ";
    } while (CommandProtection != "1" and CommandProtection != "2");
    Command = stoi(CommandProtection);
    switch (Command) {
    case 1: {
        A.HP = hp;
        cout << endl << "Разбойник достаёт ножик!" << endl << endl;
        break; }
    case 2: {beg = 1; break; }
    }
    while (A.HP > 0 and a > 0) {
        hod++;
            AttakMonstr = 1 + rand() % 4;
            switch (AttakMonstr) {
            case 1: {A.UR = 5 + rand() % (6 + CritMonstr * 2); CritMonstr = 0;  cout << "Разбойник быстро бежит на тебя." << endl << endl; break; }
            case 2: {A.UR = 5 + rand() % (6 + CritMonstr * 2); CritMonstr = 0;  cout << "Ты не поспеваешь за движениями разбойника." << endl << endl; break; }
            case 3: {A.UR = 5 + rand() % (6 + CritMonstr * 2); CritMonstr = 0;  cout << "Разбойник скрылся в тени." << endl << endl; break; }
            case 4: {A.UR = 0; CritMonstr++; cout << "Разбойник точит ножик.." << endl << endl; break; }
            }
        ViborOne = 1 + rand() % 3;
        switch (ViborOne) {
        case 1: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserA = 5 + rand() % 11 + 3 * s; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
        case 2: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserA = 5 + rand() % 11 + 3 * s; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
        case 3: {AttakUserA = 0; cout << "1 - Отдохнуть" << endl; break; }
        }
        ViborTwo = 1 + rand() % 3;
        switch (ViborTwo) {
        case 1: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserS = 5 + rand() % 11 + 3 * s; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
        case 2: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserS = 5 + rand() % 11 + 3 * s; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
        case 3: {AttakUserS = 0; cout << "2 - Отдохнуть" << endl; break; }
        }
        cout << "Выбери действие : ";
        do {
            cin >> CommandProtection;
            if (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "666778" and CommandProtection != "2010") cout << "Такой команды нет, попробуй ещё раз: ";
        } while (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "666778" and CommandProtection != "2010");
        Command = stoi(CommandProtection);
        switch (Command) {
        case 1: { if (AttakUserA != 0) {
            CritUser = 0;
            A.HP = A.HP - AttakUserA;
            cout << "Ты нанёс урон" << endl;
        }
              else { cout << "Ты отдохнул" << endl; CritUser++; }
              break; }
        case 2: { if (AttakUserS != 0) {
            CritUser = 0;
            A.HP = A.HP - AttakUserS + 4;
            cout << "Ты нанёс урон" << endl;
        }
              else { cout << "Ты отдохнул" << endl; CritUser++; }
              break; }
        case 666778: {A.HP = 0;  break; }
        case 2010: {a = 0; }
        }
        if (A.HP > 0 and a > 0) {
            if (A.UR > 0) {
                a = a - A.UR;
            }
            cout << "Ход#" << hod << " закончился. ..  ." << endl;
            system("pause");
            system("cls");
            cout << "У разбойника осталось здоровья: 150" << endl;
            cout << "У тебя осталось здоровья: " << a << endl << endl;
        }
    }
    system("cls");
    if (beg == 1) {
        cout << "Ты сбежал." << endl;
        system("pause");
    }
    else if (A.HP <= 0) {
        cout << "Зельд повержена!" << endl << "Ходов сделано: " << hod << endl;
        system("pause");
    }
    return beg;
}

void Zomb(monstr A, int& a, int s) {
    int AttakMonstr, ViborOne, ViborTwo, AttakUserA, AttakUserS, Command, hod = 0, CritMonstr = 0, CritUser = 0, kill = 0, V = 0;
    string CommandProtection;
    A.HP = 100 + rand() % (1000);
    cout << "Тебе встретилось странное существо.. Это зомбu!" << endl << endl << "Здоровье: " << A.HP << endl << "У тебя здоровья: " << a << endl << endl;
    while (A.HP > 0 and a > 0) {
        hod++;
        AttakMonstr = 1 + rand() % 5;
        switch (AttakMonstr) {
        case 1: {CritMonstr = 1; cout << "Зомбu сейчас укусит тебя!" << endl << endl; kill = 1; break; }
        case 2: {CritMonstr = 1; cout << "Зомбu сейчас укусит тебя!"  << endl << endl; kill = 1; break; }
        case 3: { cout << "Зомбu ползёт до тебя.." << endl << endl; break; }
        case 4: { cout << "Зомбu плюнул в тебя кислотой.." << endl << endl; a = a - 10; break; }
        case 5: { cout << "Зомбu ползёт до тебя.." << endl << endl; break; }
        }
        ViborOne = 1 + rand() % 3;
        switch (ViborOne) {
        case 1: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserA = 5 + rand() % 11 + 3 * s; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
        case 2: { AttakUserA = -1; cout << "1 - Увернуться " << endl; break; }
        case 3: {AttakUserA = 0; cout << "1 - Отдохнуть" << endl; break; }
        }
        ViborTwo = 1 + rand() % 3;
        switch (ViborTwo) {
        case 1: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * s + 5; } else { AttakUserS = 5 + rand() % 11 + 3 * s; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
        case 2: { AttakUserS = -1; cout << "2 - Увернуться " << endl; break; }
        case 3: {AttakUserS = 0; cout << "2 - Отдохнуть" << endl; break; }
        }
        cout << "Выбери действие : ";
        do {
            cin >> CommandProtection;
            if (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "666778" and CommandProtection != "2010") cout << "Такой команды нет, попробуй ещё раз: ";
        } while (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "666778" and CommandProtection != "2010");
        Command = stoi(CommandProtection);
        switch (Command) {
        case 1: { 
            if (AttakUserA == -1)
            {
                cout << "Ты увернулся" << endl;
                V = 1;
            }
            else if (AttakUserA != 0) {
            CritUser = 0;
            A.HP = A.HP - AttakUserA;
            cout << "Ты нанёс урон" << endl;
        }
              else { cout << "Ты отдохнул" << endl; CritUser++; }
              break; }
        case 2: {  if (AttakUserA == -1)
        {
            cout << "Ты увернулся" << endl;
            V = 1;
        }
              else if (AttakUserS != 0) {
            CritUser = 0;
            A.HP = A.HP - AttakUserS;
            cout << "Ты нанёс урон" << endl;
        }
              else { cout << "Ты отдохнул" << endl; CritUser++; }
              break; }
        case 666778: {A.HP = 0;  break; }
        case 2010: {a = 0; }
        }
        if (A.HP > 0 and a > 0) {
            if (kill == 1 and V == 0) {
                cout << endl << "Тебя укусил зомбu.. Ты чувствуешь как теряешь сознание.." << endl;
                system("pause");
                a = 0;
            }
            kill = 0;
            V = 0;
            cout << "Ход#" << hod << " закончился. ..  ." << endl;
            system("pause");
            system("cls");
            cout << "У зомбu осталось здоровья: " << A.HP << endl;
            cout << "У тебя осталось здоровья: " << a << endl << endl;
        }
    }
    system("cls");
    if (A.HP <= 0) {
        cout << "Зомбu повержен!" << endl << "Ходов сделано: " << hod << endl;
        system("pause");
    }
}

int main() {
    srand(time(NULL));
    //SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    int CommandZiclGame = 4, masha, RandomMonstr, Stupid = 0, Command, wop, pobeg, AttakMonstr, ViborOne, ViborTwo, ViborTree,
        AttakUserA, AttakUserS, AttakUserD, Pr, tren = 20, Tips;
    string CommandProtection, otvet, ComPr, WolfPr;
    cout << "Привет" << endl << "1) Привет" << endl << "2) Кто я?" << endl << "Выбери: ";
        cin >> CommandProtection; //cin >> CommandProtection;
        if (CommandProtection == "1" or CommandProtection == "2")
        {
            cout << endl << "Отлично, ты умственно развит." << endl;
            system("pause");
            system("cls");
        }
        else
        {
            system("pause");
            system("cls");
            cout << "Так. Давай проведём небольшой тренер-клас по нажатию кнопок.." << endl << "Выбери вариант 'Кошечка'." << endl << "1) Кошечка" << endl << "2) Яблочко" << endl;
            do {
                cin >> CommandProtection; //cin >> CommandProtection;
                if (CommandProtection != "1" and CommandProtection != "2") cout << "Такой команды нет, попробуй ещё раз: ";
                if (CommandProtection == "2") cout << "Нет, это 'Яблочко', попробуй ещё раз: ";
            } while (CommandProtection != "1");
            system("pause");
            system("cls");
        }
        cout << "Ударь чучело." << endl << endl;
        cout << "Здоровье у чучела: 20" << endl << "У тебя здоровья: 110" << endl << endl;
        cout << "1 - Нанести 5 урона" << endl;
        cout << "2 - Нанести 10 урона" << endl;
        cout << "Выбери: ";
        do {
            cin >> CommandProtection; //cin >> CommandProtection;
            if (CommandProtection != "1" and CommandProtection != "2") cout << "Такой команды нет, попробуй ещё раз: ";
        } while (CommandProtection != "1" and CommandProtection != "2");
        system("pause");
        system("cls");
        cout << "Как видишь у чучела стало меньше здоровья." << endl << "Но, естественно, и чучело может тебя атаковать." << endl << "Кроме атаки ты также можешь отдохнуть." << endl << endl;
        cout << "Чучело сейчас нанесёт урона: 10" << endl << endl;
        if (CommandProtection == "1")
            tren = tren - 5;
        else
            tren = tren - 10;
        cout << "Здоровье у чучела: " << tren << endl << "У тебя здоровья: 110" << endl << endl;
        cout << "1 - Отдохнуть" << endl;
        cout << "2 - Отдохнуть" << endl;
        cout << "Выбери: ";
        do {
            cin >> CommandProtection; //cin >> CommandProtection;
            if (CommandProtection != "1" and CommandProtection != "2") cout << "Такой команды нет, попробуй ещё раз: ";
        } while (CommandProtection != "1" and CommandProtection != "2");
        system("pause");
        system("cls");
        cout << "Если ты отдохнёшь два раза подряд, то ты сможешь нанести усиленный удар." << endl << "Чучело тоже готовит критический удар, поторопись добить его." << endl << endl;
        cout << "Чучело смотрит на тебя мёртвым взглядом.." << endl << endl;
        cout << "Здоровье у чучела: " << tren << endl << "У тебя здоровья: 100" << endl << endl;
        cout << "1 - Отдохнуть" << endl;
        cout << "2 - Отдохнуть" << endl;
        cout << "Выбери: ";
        do {
            cin >> CommandProtection; //cin >> CommandProtection;
            if (CommandProtection != "1" and CommandProtection != "2") cout << "Такой команды нет, попробуй ещё раз: ";
        } while (CommandProtection != "1" and CommandProtection != "2");
        system("pause");
        system("cls");
        cout << "Как видишь, не всегда везёт на хороший удар." << endl << "Добей чучело." << endl << endl;
        cout << "Чучело сейчас нанесёт критический урон: 19" << endl << endl;
        cout << "Здоровье у чучела: " << tren << endl << "У тебя здоровья: 100" << endl << endl;
        cout << "1 - Нанести 16 урона" << endl;
        cout << "2 - Нанести 6 урона" << endl;
        cout << "Выбери: ";
        do {
            cin >> CommandProtection; //cin >> CommandProtection;
            if (CommandProtection != "1" and CommandProtection != "2") cout << "Такой команды нет, попробуй ещё раз: ";
            if (CommandProtection == "2") cout << "Добей чучело: ";
        } while (CommandProtection != "1");
        system("pause");
        system("cls");
        cout << "Ты победил чучело, поздравляю." << endl << "Через каждые пять убитых монстров твои навыки будут улучшаться." << endl << "Прощай." << endl << endl;
        cout << "Чучело повержено!" << endl << "Ходов сделано: 4" << endl << endl;
        system("pause");
        system("cls");

    while (CommandZiclGame != 7) {
        system("cls");
        Tips = 1 + rand() % 23;
        switch (Tips)
        {
        case 1: {cout << "За убийство курочки даётся половина опыта."; break; }
        case 2: {cout << "В игре есть специальная команда '2010'."; break; }
        case 3: {cout << "В первой главе есть несколько редких противников."; break; }
        case 4: {cout << "В игре три главы."; break; }
        case 5: {cout << "Ку-ку."; break; }
        case 6: {cout << "Не все слизни злые."; break; }
        case 7: {cout << "Во второй главе нужно убивать, лучше слизней."; break; }
        case 8: {cout << "Во второй главе есть секретный и очень редкий босс."; break; }
        case 9: {cout << "Главная цель игры - дойти и убить виверну."; break; }
        case 10: {cout << "Игра называется 'Долина дисбаланса.'"; break; }
        case 11: {cout << "Курочка - единственный агрессивный противник, который не наносит урона."; break; }
        case 12: {cout << "В 'Долину дисбаланса' не была добавлена бабочка."; break; }
        case 13: {cout << "В 'Долину дисбаланса' не был добавлен ГлючЛаг" << endl << "Часть его функционала перешла другому врагу."; break; }
        case 14: {cout << "Главного героя готовили к битве с самого рождения."; break; }
        case 15: {cout << "В 'Долину дисбаланса' не были добавлены события: феи и река."; break; }
        case 16: {cout << "У главного героя нет имени. В деревне его все зовут 'Героем'."; break; }
        case 17: {cout << "Главный герой - не единственный герой, которого готовят с самого детства." << endl << "Всех таких людей называют героями."; break; }
        case 18: {cout << "В 'Долину дисбаланса' не был добавлен HardMod."; break; }
        case 19: {cout << "Изначально рыбак должен был быть противником."; break; }
        case 20: {cout << "В 'Долине дисбаланса' всего две отсылки на другие игры."; break; }
        case 21: {cout << "Подсказка: солнце светит."; break; }
        case 22: {cout << "В первой версии игры были только злогер и слизень."; break; }
        case 23: {cout << "В игре одна концовка."; break; }
        }
        Sleep(3000);
        system("cls");
        cout << "Окошко для ввода чит-кода: ";
        do
        {
            cin >> otvet;
        } while (otvet.find_first_not_of("0123456789") != -1);
        int hp = 100, RacushkaHill = 0, Deff = 0, yr = 0, OP = 0, KillSliz = 0, Tox = 0, boss = 0, dialog = 0, hod = 0, CritMonstr = 0, CritUser = 0, fish = 0, AngelHil = 0, kyky = 0;
        bool SheepDeff = false, kyr = false, GS = false;
        if (otvet == "505311") { yr = 1; }
        if (otvet == "4123") { yr = 3; boss = 1; }
        while (hp > 0) {
            system("cls");
            //1 глава
            if (yr == 0) { 
                if (dialog == 0) {
                    dialog++;
                    cout << "Где-то 300 лет назад в далёкую деревню, под названием 'Запределье', пришла беда." << endl << endl << "Прилетела проклятая виверна, что поселилась в горах." << endl << endl;
                    cout << "Из-за скверны в лесу неподалёку стали появляться чудища." << endl << endl << "Странные существа, что появились на свет из-за проклятия." << endl << endl;
                    cout << "Они стали досаждать жителям деревни." << endl << endl << "И ты - герой всего мира, который избавит деревушку от страданий!" << endl << endl;
                    cout << "Существует лишь один способ и это - убить виверну." << endl << endl << "Старик:" << endl << endl;
                    cout << "-Спустя 20 лет жизни в деревне ты можешь наконец-то отправиться в горы, чтобы убить дракона и избавить нас от его проклятья." << endl << endl << "-Но докажи, что ты готов. Иди поубивай диких тупых скотинок, посмотрим на что ты годишься, хе~" << endl << endl;
                    system("pause");
                    system("cls");
                }
                RandomMonstr = 1 + rand() % 35; 
                switch (RandomMonstr) {
                case 1: {BIK(slizn, hp, yr); if (hp > 0) { OP++; } else { Tips = 1; }break; } //бык
                case 2: {BIK(slizn, hp, yr); if (hp > 0) { OP++; } else { Tips = 1; }break; } //бык
                case 3: {olen(slizn, hp, yr); if (hp > 0) { OP++; } else { Tips = 2; } break; } //олень
                case 7: {olen(slizn, hp, yr); if (hp > 0) { OP++; } else { Tips = 2; }break; } //олень
                case 5: {CHICK(slizn, hp, yr); if (hp > 0) { if (kyr == false) { kyr = true; } else if (kyr == true) { kyr = false; OP = OP + 1; } } else if (hp <= 0) { Tips = 8; } break; } //курица
                case 6: {CHICK(slizn, hp, yr); if (hp > 0) { if (kyr == false) { kyr = true; } else if (kyr == true) { kyr = false; OP = OP + 1; } } else if (hp <= 0) { Tips = 8; } break; } //курица
                case 4: {pobeg = GOLD(slizn, hp, yr); if (pobeg != 1 and hp > 0) { GS = true; } else if(hp <= 0) { Tips = 3; } break; } // золотая овца
                case 8: {pobeg = gnuk(slizn, hp, yr); if (pobeg != 1 and hp > 0) { OP = 10; } else if (hp <= 0) { Tips = 4; } break; } //разбойник - уворот
                case 9: {BIK(slizn, hp, yr); if (hp > 0) { OP++; } else { Tips = 1; }break; } //бык
                case 10: {olen(slizn, hp, yr); if (hp > 0) { OP++; } else { Tips = 2; } break; } //олень
                case 13: {CHICK(slizn, hp, yr); if (hp > 0) { OP = OP + 0.5; } else if (hp <= 0) { Tips = 8; }break; } //курица
                case 15: {BIK(slizn, hp, yr); if (hp > 0) { OP++; } else { Tips = 1; }break; } //бык
                case 16: {olen(slizn, hp, yr); if (hp > 0) { OP++; } else { Tips = 2; } break; } //олень
                case 18: {BIK(slizn, hp, yr); if (hp > 0) { OP++; } else { Tips = 1; }break; } //бык
                case 21: {olen(slizn, hp, yr); if (hp > 0) { OP++; } else { Tips = 2; } break; } //олень
                case 19: {BIK(slizn, hp, yr); if (hp > 0) { OP++; } else { Tips = 1; }break; } //бык
                case 20: {olen(slizn, hp, yr); if (hp > 0) { OP++; } else { Tips = 2; } break; } //олень
                case 11: {CHICK(slizn, hp, yr); if (hp > 0) { if (kyr == false) { kyr = true; } else if (kyr == true) { kyr = false; OP = OP + 1; } } else if (hp <= 0) { Tips = 8; }break; } //курица
                case 17: {CHICK(slizn, hp, yr); if (hp > 0) { if (kyr == false) { kyr = true; } else if (kyr == true) { kyr = false; OP = OP + 1; } } else if (hp <= 0) { Tips = 8; }break; } //курица
                case 23: {BIK(slizn, hp, yr); if (hp > 0) { OP++; } else { Tips = 1; }break; } //бык
                case 24: {olen(slizn, hp, yr); if (hp > 0) { OP++; } else { Tips = 2; } break; } //олень
                case 22: {CHICK(slizn, hp, yr); if (hp > 0) { if (kyr == false) { kyr = true; } else if (kyr == true) { kyr = false; OP = OP + 1; } } else if (hp <= 0) { Tips = 8; }break; } //курица
                case 26: {BIK(slizn, hp, yr); if (hp > 0) { OP++; } else { Tips = 1; }break; } //бык
                case 27: {olen(slizn, hp, yr); if (hp > 0) { OP++; } else { Tips = 2; } break; } //олень
                case 25: {CHICK(slizn, hp, yr); if (hp > 0) { if (kyr == false) { kyr = true; } else if (kyr == true) { kyr = false; OP = OP + 1; } } else if (hp <= 0) { Tips = 8; }break; } //курица
                case 28: {BIK(slizn, hp, yr); if (hp > 0) { OP++; } else { Tips = 1; }break; } //бык
                case 29: {pobeg = Taika(slizn, hp, yr); if (pobeg != 1 and hp > 0) { OP = 10; } else if (hp <= 0) { Tips = 5; }break; } //разбойник - мушкет
                case 31: {pobeg = Zeld(slizn, hp, yr); if (pobeg != 1 and hp > 0) { OP = 10; } else if (hp <= 0) { Tips = 6; }break; } //разбойник - маска
                case 30: {EZ(slizn, hp, yr); if (hp > 0) { OP++; } else {Tips = 7;} break; } //Ёж
                case 32: {EZ(slizn, hp, yr); if (hp > 0) { OP++; } else { Tips = 7;} break; } //Ёж
                case 33: {BIK(slizn, hp, yr); if (hp > 0) { OP++; } else { Tips = 1; }break; } //бык
                case 34: {olen(slizn, hp, yr); if (hp > 0) { OP++; } else { Tips = 2; } break; } //олень
                case 35: {CHICK(slizn, hp, yr); if (hp > 0) { if (kyr == false) { kyr = true; } else if (kyr == true) { kyr = false; OP = OP + 1; } } else if (hp <= 0) { Tips = 8; } break; } //курица
                }
            } 

            //вторая глава
            else if (yr > 0 and boss == 0) { 
                if (dialog == 1) {
                    dialog++; //второй диалог
                    cout << "Ты доказал, что достаточно силён." << endl << endl << "Теперь ты готов к настоящей битве." << endl << endl << "Вы направляетесь в лес.." << endl;
                    system("pause");
                    system("cls");
                }
                if (KillSliz != 0 and KillSliz % 3 == 0) { Tox++; KillSliz = 0; }
                RandomMonstr = 1 + rand() % (11 + Tox); //11
                switch (RandomMonstr) {
                case 1: {SLIZ(slizn, hp, yr); if (hp > 0) { OP++; } else { Tips = 9; } KillSliz++; break; } //слизнь
                case 2: {cout << "Здоровья было: " << hp << endl; wop = 10 + rand() % 11 + yr * 10; hp = hp - wop; 
                    cout << "Ты попал в капкан и пока выбирался из него, потерял много крови: " << wop << endl << "У тебя осталось здоровья: " << hp << endl; 
                    system("pause"); if (hp <= 0) { Tips = 11; break; } 
                    system("cls"); }
                case 3: {SLOG(zlog, hp, yr); if (hp > 0) { OP++; } else { Tips = 10; } break; } //злогер
                case 4: {SLIZEN(slizen, hp); break; } //добрый слизьн
                case 5: {SLIZ(slizn, hp, yr); if (hp > 0) { OP++; } else { Tips = 9; } KillSliz++; break; } //слизнь
                case 6: {if (Mimicril(slizn, hp, yr) == 1) { OP++; } else { Tips = 13; } break; }
                case 7: {SLIZEN(slizen, hp); break; } //добрый слизьн
                case 8: {SLOG(zlog, hp, yr); if (hp > 0) { OP++; } else { Tips = 10;} break; } //злогер
                case 9: {cout << "Ты нашёл мясо неизвестного животного.." << endl << "Попробовать его приготовить и съесть?" << endl << "1 - Да" << endl << "2 - Нет" << endl; //мясо
                    do {
                        cout << "Выбор: ";
                        cin >> CommandProtection;
                    } while (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "55556" and CommandProtection != "410");
                    Command = stoi(CommandProtection);
                    RandomMonstr = 1 + rand() % 3;
                    if (Command == 55556) { RandomMonstr = 3; }
                    if (Command == 410) { RandomMonstr = 1; }
                    if (Command == 1 or Command == 55556 or Command == 410) {
                        switch (RandomMonstr) {
                        case 1: {cout << "Здоровья было: " << hp << endl; wop = 10 + rand() % 11 + yr * 10 + 8; hp = hp - wop; cout << "Мясо оказалось не съестным." << endl << "Здоровья осталось: " << hp << endl; break; }
                        case 2: {cout << "Здоровья было: " << hp << endl; wop = 10 + rand() % 11; hp = hp + wop; cout << "Мясо оказалось съестным." << endl << "Здоровья осталось: " << hp << endl; break; }
                        case 3: {cout << "Здоровья было: " << hp << endl; wop = 10 + rand() % 6 + yr * 5; hp = hp + wop; cout << "Мясо оказалось съестным." << endl << "Здоровья осталось: " << hp << endl; break; }
                        }
                    }
                    system("pause");
                    if (hp <= 0) { Tips = 12; break; }
                    system("cls");
                }
                case 10: {SLIZ(slizn, hp, yr); if (hp > 0) { OP++; } else { Tips = 9; } KillSliz++; break; } //слизнь
                case 11: {EZ(slizn, hp, yr); if (hp > 0) { OP++; } else { Tips = 7; } break; } //Ёж
                default: {ToxicSlizn(toxic, hp, yr); Tox = Tox - 1; KillSliz = 0; if (hp > 0) { boss++; } else { Tips = 14; } break; } //босс вокс
                case 15: {Zomb(toxic, hp, yr); if (hp > 0) { OP = 10 + OP + (5 - OP); } else { Tips = 15; }  break; }
                }
            }

            //третья глава
            else {
                yr += 2;
                OP = yr*5;
                hp = 100 + (OP / 5) * 10;
                OP = 0; //улучшения на 2 уровня
                cout << "Ваш уровень повышен до " << yr << "!" << endl << "Ваши навыки сражение улучшилтсь, а тело закалилось!" << endl << endl;
                system("pause");
                system("cls");
                cout << "Вы заходите в чащу леса.." << endl << endl;
                system("pause");
                system("cls");
                cout << "Ты встретил ленивого рыбака. ..  . Он заговорил:" <<endl;
                if (GS == true) { masha = 4; }
                else { masha = 1 + rand() % 3; }
                switch (masha)
                { //оружие
                case 1: {cout << "Вижу тебе нужно оружие.." << endl << "Жаль, на этот раз мои карманы пусты, но я видел, как что-то упало в те кусты." << endl << "Ты пошарился в кустах в поисках небесного дара, но отыскал испражнение Божье."<<endl << endl;  break; }
                case 2: {cout << "Вижу тебе нужно оружие.." << endl << "Какое совпадение, что неподалёку только-только завершилась битва двух господ." << endl << "Оба лодыря погоибли, но их оружие не пропадёт даром."<< endl <<"Рыбак вручил тебе фехтовальный щит."<<endl << endl; break; }
                case 3: {cout << "Вижу тебе нужно оружие.." << endl << "Я, тут, случайненько выловил легендарный магический артефакт." <<endl << "За ним охотятся столетеями соискатели и даже империи."<< endl << "Рыбак вручил тебе ракушечку."<<endl << endl; break; }
                case 4: {cout << "Вижу у тебя за пазухой шкурка золотая.." << endl << "Дай-ка сюда, я тебе кое-что сделаю." << endl << "Рыбак вручил тебе золотую шубку." << endl << endl; SheepDeff = true;  break; }
                }
                system("pause");
                system("cls");
                //пчела
                lol.HP = 110 + rand() % (41);
                RandomMonstr = 1 + rand() % (5);
                switch (RandomMonstr)
                {
                case 1: {cout << "Тебе встретилось странное существо.. Это бомбоновая розовая пчёлка!" << endl << endl << "Здоровье: " << lol.HP << endl << "У тебя здоровья: " << hp << endl << endl; break; }
                case 2: {cout << "Тебе встретилось странное существо.. Это бомбоновая синяя пчёлка!" << endl << endl << "Здоровье: " << lol.HP << endl << "У тебя здоровья: " << hp << endl << endl; break; }
                case 3: {cout << "Тебе встретилось странное существо.. Это бомбоновая фиолетовая пчёлка!" << endl << endl << "Здоровье: " << lol.HP << endl << "У тебя здоровья: " << hp << endl << endl; break; }
                case 4: {cout << "Тебе встретилось странное существо.. Это бомбоновая серая пчёлка!" << endl << endl << "Здоровье: " << lol.HP << endl << "У тебя здоровья: " << hp << endl << endl; break; }
                case 5: {cout << "Тебе встретилось странное существо.. Это бомбоновая белая пчёлка!" << endl << endl << "Здоровье: " << lol.HP << endl << "У тебя здоровья: " << hp << endl << endl; break; }
                }
                while (lol.HP > 0 and hp > 0)
                {
                    hod++;
                    AttakMonstr = 1 + rand() % 2;
                    switch (AttakMonstr) {
                    case 1: {lol.UR = 1 + rand() % 6; cout << "Пчёлка сейчас нанесёт урона: " << lol.UR << endl << endl; break; }
                    case 2: {lol.UR = 0; cout << "Пчёлка прыгает.." << endl << endl; break; }
                    }
                    ViborOne = 1 + rand() % 3;
                    switch (ViborOne) {
                    case 1: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * yr + 15; } else { AttakUserA = 5 + rand() % 11 + 3 * yr; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
                    case 2: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * yr + 20; } else { AttakUserA = 5 + rand() % 11 + 3 * yr; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
                    case 3: {AttakUserA = 0; cout << "1 - Отдохнуть" << endl; break; }
                    }
                    ViborTwo = 1 + rand() % 3;
                    switch (ViborTwo) {
                    case 1: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * yr + 10; } else { AttakUserS = 5 + rand() % 11 + 3 * yr; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
                    case 2: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * yr + 20; } else { AttakUserS = 5 + rand() % 11 + 3 * yr; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
                    case 3: {AttakUserS = 0; cout << "2 - Отдохнуть" << endl; break; }
                    }
                    if (masha == 1)
                    {
                        cout << "3 - Помолиться какашке Господня" << endl;
                    }
                    else if (masha == 2)
                    {
                        ViborTree = 1 + rand() % 5;
                        switch (ViborTree) {
                        case 1: { cout << "3 - Отдохнуть" << endl; break; }
                        case 2: { cout << "3 - Отдохнуть" << endl; break; }
                        case 3: { cout << "3 - Отдохнуть" << endl; break; }
                        case 4: {
                            if (CritUser > 1)
                            {
                                AttakUserD = 5 + rand() % 11 + 3 * yr + 5 + 5;
                            }
                            else
                            {
                                AttakUserD = 5 + rand() % 11 + 3 * yr + 5;
                            }
                            cout << "3 - Ударить щитом" << endl;
                            CritUser = 0;
                            break;
                        }
                        case 5: {cout << "3 - Прикрыться щитом" << endl; break; }
                        }
                    }
                    else if (masha == 3)
                    {
                        ViborTree = 1 + rand() % 5;
                        switch (ViborTree) {
                        case 1: { cout << "3 - Приложить ракушечку к ушечку" << endl; break; }
                        default: {cout << "3 - Отдохнуть" << endl; break; }
                        }
                    }
                    else if (masha == 4)
                    {
                        if (SheepDeff == true)
                        {
                            cout << "3 - Блокировать" << endl;
                        }
                        else{ cout << "3 - Отдохнуть" << endl; }
                    }
                    cout << "Выбери действие : ";
                    do {
                        cin >> ComPr; //cin >> ComPr;
                        if (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010" and ComPr != "3") cout << "Такой команды нет, попробуй ещё раз: ";
                    } while (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010" and ComPr != "3");
                    Pr = stoi(ComPr);
                    switch (Pr) {
                    case 1: { if (AttakUserA != 0) {
                        CritUser = 0;
                        lol.HP = lol.HP - AttakUserA;
                        cout << "Ты нанёс урон" << endl;
                    }
                          else { cout << "Ты отдохнул" << endl; CritUser++; }
                          break; }
                    case 2: { if (AttakUserS != 0) {
                        CritUser = 0;
                        lol.HP = lol.HP - AttakUserS;
                        cout << "Ты нанёс урон" << endl;
                    }
                          else { cout << "Ты отдохнул" << endl; CritUser++; }
                          break; }
                    case 666778: {lol.HP = 0;  break; }
                    case 2010: {hp = 0; }
                    case 3: {
                        if (masha == 1) { cout << "Ты помолился какашке" << endl; }
                        else if (masha == 2)
                        {
                            if (ViborTree == 4)
                            {
                                CritUser = 0;
                                lol.HP = lol.HP - AttakUserD;
                                cout << "Ты нанёс урон" << endl;
                            }
                            else if (ViborTree == 5)
                            {
                                if (lol.HP != 0) { Deff = 1 + rand() % (lol.UR + 1); }
                            }
                            else { cout << "Ты отдохнул" << endl; CritUser++; }
                        }
                        else if (masha == 3)
                        {
                            if (ViborTree == 1)
                            {
                                RacushkaHill += 5;
                            }
                            else { cout << "Ты отдохнул" << endl; CritUser++; }
                        }
                        else if (masha == 4)
                        {
                            if (SheepDeff == true)
                            {
                                lol.UR = 0;
                                SheepDeff = false;
                            }
                            else { cout << "Ты отдохнул" << endl; CritUser++; }
                        }
                    }
                    }
                    if (lol.HP > 0 and hp > 0) {
                        if (lol.UR > 0) {
                            hp = hp - lol.UR + Deff;
                            Deff = 0;
                        }
                        cout << "Ход#" << hod << " закончился. ..  ." << endl;
                        system("pause");
                        system("cls");
                        cout << "У пчёлки осталось здоровья: " << lol.HP << endl;
                        cout << "У тебя осталось здоровья: " << hp << endl << endl;
                    }
                }
                system("cls");
                if (lol.HP <= 0) {
                    cout << "Пчёлка повержена!" << endl << "Ходов сделано: " << hod << endl;
                    system("pause");
                    system("cls");
                }
                else if (hp <= 0)
                {
                    Tips = 16;
                    break;
                }
                SheepDeff = true;
                if(masha == 3 and hp > 0)
                {
                    cout << "Бой закончился, из ракушечки начала доноситься мелодия на секундочки: " << 5 + RacushkaHill << endl << endl;
                    hp = hp + 5 + RacushkaHill;
                    system("pause");
                    system("cls");
                    RacushkaHill = 0;
                }

                //босс - червячок
                CritUser = 0;
                hod = 0;
                lol.HP = 290 + rand() % (311);
                cout << "Тебе встретилось.. Червячок?" << endl << endl << "Здоровье: " << lol.HP << endl << "У тебя здоровья: " << hp << endl << endl;
                while (lol.HP > 0 and hp > 0)
                {
                    hod++;
                    AttakMonstr = 1 + rand() % 12;
                    switch (AttakMonstr) {
                    case 1: {
                        AttakMonstr = 10 + rand() % 141;
                        cout << "Нахваленная регенерация червяков даёт о себе знать." << endl << "Червячок отрегенирировал на: " << AttakMonstr << endl << endl;;
                        lol.HP += AttakMonstr;
                        system("pause");
                        system("cls");
                        continue;
                    }
                    default: {lol.UR = 0 + rand() % 13; cout << "Червячок сейчас нанесёт урона: " << lol.UR << endl << endl; break; }
                    }
                    ViborOne = 1 + rand() % 3;
                    ViborTwo = 1 + rand() % 3;
                    
                    switch (ViborOne) {
                    case 1: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * yr + 15; } else { AttakUserA = 5 + rand() % 11 + 3 * yr; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
                    case 2: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * yr + 20; } else { AttakUserA = 5 + rand() % 11 + 3 * yr; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
                    case 3: {AttakUserA = 0; cout << "1 - Отдохнуть" << endl; break; }
                    }
                    switch (ViborTwo) {
                    case 1: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * yr + 10; } else { AttakUserS = 5 + rand() % 11 + 3 * yr; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
                    case 2: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * yr + 20; } else { AttakUserS = 5 + rand() % 11 + 3 * yr; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
                    case 3: {AttakUserS = 0; cout << "2 - Отдохнуть" << endl; break; }
                    }
                    if (masha == 1)
                    {
                        cout << "3 - Помолиться какашке Господня" << endl;
                    }
                    else if (masha == 2)
                    {
                        ViborTree = 1 + rand() % 5;
                        switch (ViborTree) {
                        case 1: { cout << "3 - Отдохнуть" << endl; break; }
                        case 2: { cout << "3 - Отдохнуть" << endl; break; }
                        case 3: { cout << "3 - Отдохнуть" << endl; break; }
                        case 4: {
                            if (CritUser > 1)
                            {
                                AttakUserD = 5 + rand() % 11 + 3 * yr + 5 + 5;
                            }
                            else
                            {
                                AttakUserD = 5 + rand() % 11 + 3 * yr + 5;
                            }
                            cout << "3 - Ударить щитом" << endl;
                            CritUser = 0;
                            break;
                        }
                        case 5: {cout << "3 - Прикрыться щитом" << endl; break; }
                        }
                    }
                    else if (masha == 3)
                    {
                        ViborTree = 1 + rand() % 5;
                        switch (ViborTree) {
                        case 1: { cout << "3 - Приложить ракушечку к ушечку" << endl; break; }
                        default: {cout << "3 - Отдохнуть" << endl; break; }
                        }
                    }
                    else if (masha == 4)
                    {
                        if (SheepDeff == true)
                        {
                            cout << "3 - Блокировать" << endl;
                        }
                        else { cout << "3 - Отдохнуть" << endl; }
                    }
                    cout << "Выбери действие : ";
                    do {
                        cin >> ComPr; //cin >> ComPr;
                        if (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010" and ComPr != "3") cout << "Такой команды нет, попробуй ещё раз: ";
                    } while (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010" and ComPr != "3");
                    Pr = stoi(ComPr);
                    switch (Pr) {
                    case 1: { if (AttakUserA != 0) {
                        CritUser = 0;
                        lol.HP = lol.HP - AttakUserA;
                        cout << "Ты нанёс урон" << endl;
                    }
                          else { cout << "Ты отдохнул" << endl; CritUser++; }
                          break; }
                    case 2: { if (AttakUserS != 0) {
                        CritUser = 0;
                        lol.HP = lol.HP - AttakUserS;
                        cout << "Ты нанёс урон" << endl;
                    }
                          else { cout << "Ты отдохнул" << endl; CritUser++; }
                          break; }
                    case 666778: {lol.HP = 0;  break; }
                    case 2010: {hp = 0; }
                    case 3: {
                        if (masha == 1) { cout << "Ты помолился какашке" << endl; }
                        else if (masha == 2)
                        {
                            if (ViborTree == 4)
                            {
                                CritUser = 0;
                                lol.HP = lol.HP - AttakUserD;
                                cout << "Ты нанёс урон" << endl;
                            }
                            else if (ViborTree == 5)
                            {
                                if (lol.HP != 0) { Deff = 1 + rand() % (lol.UR + 1); }
                            }
                            else { cout << "Ты отдохнул" << endl; CritUser++; }
                        }
                        else if (masha == 3)
                        {
                            if (ViborTree == 1)
                            {
                                RacushkaHill += 5;
                            }
                            else { cout << "Ты отдохнул" << endl; CritUser++; }
                        }
                        else if (masha == 4)
                        {
                            if (SheepDeff == true)
                            {
                                lol.UR = 0;
                                SheepDeff = false;
                            }
                            else { cout << "Ты отдохнул" << endl; CritUser++; }
                        }
                    }
                    }
                    if (lol.HP > 0 and hp > 0) {
                        if (lol.UR > 0) {
                            hp = hp - lol.UR + Deff;
                            Deff = 0;
                        }
                        cout << "Ход#" << hod << " закончился. ..  ." << endl;
                        system("pause");
                        system("cls");
                        cout << "У червячка осталось здоровья: " << lol.HP << endl;
                        cout << "У тебя осталось здоровья: " << hp << endl << endl;
                    }
                }
                system("cls");
                if (lol.HP <= 0) {
                    cout << "Червячок повержен!" << endl << "Ходов сделано: " << hod << endl;
                    system("pause");
                    system("cls");
                }
                else if (hp <= 0)
                {
                    Tips = 17;
                    break;
                }
                SheepDeff = true;
                if (masha == 3 and hp > 0)
                {
                    cout << "Бой закончился, из ракушечки начала доноситься мелодия на секундочки: " << 5 + RacushkaHill << endl << endl;
                    hp = hp + 5 + RacushkaHill;
                    system("pause");
                    system("cls");
                    RacushkaHill = 0;
                }

                //лечение
                cout << "Неожиданно тебе навстречу идёт рыбак. Он предлагает тебе любую копчёную рыбку из ведра, взять?" << endl << "1) Да" << endl << "2) Нет" << endl << endl;
                    do {
                        cout << "Выбор: ";
                        cin >> CommandProtection;
                    } while (CommandProtection != "1" and CommandProtection != "2" and CommandProtection != "25+" and CommandProtection != "6+" and CommandProtection != "10+");
                    Command = stoi(CommandProtection);
                    if (Command != 2) {
                        RandomMonstr = 0 + rand() % 26;
                        if (CommandProtection == "25+")
                        {
                            RandomMonstr = 25;
                        }
                        else if (CommandProtection == "6+")
                        {
                            RandomMonstr = 6;
                        }
                        else if (CommandProtection == "10+")
                        {
                            RandomMonstr = 10;
                        }
                        switch (RandomMonstr) {
                        case 0: {cout << "Здоровья было: " << hp << endl; hp = hp + 100; cout << "Вкусная Филаденская рыбка" << endl << "Здоровья осталось: " << hp << endl << endl; break; }
                        case 1: {cout << "Здоровья было: " << hp << endl; hp = hp + 50; cout << "Вкусная Филаденская рыбка, жаль маленькая" << endl << "Здоровья осталось: " << hp << endl << endl; break; }
                        case 2: {cout << "Здоровья было: " << hp << endl; hp = hp - 50; cout << "Шипастая фуга пирату в зад!" << endl << "Здоровья осталось: " << hp << endl << endl; break; }
                        case 3: {cout << "Здоровья было: " << hp << endl; hp = hp + 50; cout << "Вкусная Филаденская рыбка, жаль маленькая" << endl << "Здоровья осталось: " << hp << endl << endl; break; }
                        case 4: {cout << "Здоровья было: " << hp << endl; hp = hp + 100; cout << "Вкусная Филаденская рыбка" << endl << "Здоровья осталось: " << hp << endl << endl; break; }
                        case 5: {cout << "Здоровья было: " << hp << endl; hp = hp + 100; cout << "Вкусная Филаденская рыбка" << endl << "Здоровья осталось: " << hp << endl << endl; break; }
                        case 6: {hp = hp + 50; fish = 10; cout << "Призмаринка - очень сочный сорт рыбка. Вы чувствуете прилив сил!" << endl << "Бонусные очки: " << fish << endl << endl; break; }
                        case 7: {cout << "Здоровья было: " << hp << endl; hp = hp + 100; cout << "Вкусная Филаденская рыбка" << endl << "Здоровья осталось: " << hp << endl << endl; break; }
                        case 8: {cout << "Здоровья было: " << hp << endl; hp = hp + 100; cout << "Вкусная Филаденская рыбка" << endl << "Здоровья осталось: " << hp << endl << endl; break; }
                        case 9: {cout << "Здоровья было: " << hp << endl; hp = hp + 50; cout << "Вкусная Филаденская рыбка, жаль маленькая" << endl << "Здоровья осталось: " << hp << endl << endl; break; }
                        case 10: {cout << "Здоровья было: " << hp << endl; hp = hp + 150; fish = -10; cout << "Отвратительная Вершь, но зато сытная.." << endl << "Здоровья осталось: " << hp << endl << "Бонусные очки: " << fish << endl << endl; break; }
                        case 11: {cout << "Здоровья было: " << hp << endl; hp = hp + 100; cout << "Вкусная Филаденская рыбка" << endl << "Здоровья осталось: " << hp << endl << endl; break; }
                        case 12: {cout << "Здоровья было: " << hp << endl; hp = hp + 100; cout << "Вкусная Филаденская рыбка" << endl << "Здоровья осталось: " << hp << endl << endl; break; }
                        case 13: {cout << endl; hp = hp + 50; fish = -10; cout << "Отвратительная Вершь, и маленькая.." << endl << "Бонусные очки: " << fish << endl << endl; break; }
                        case 14: {cout << "Здоровья было: " << hp << endl; hp = hp + 100; cout << "Вкусная Филаденская рыбка" << endl << "Здоровья осталось: " << hp << endl << endl; break; }
                        case 15: {cout << "Здоровья было: " << hp << endl; hp = hp + 100; cout << "Вкусная Филаденская рыбка" << endl << "Здоровья осталось: " << hp << endl << endl; break; }
                        case 16: {cout << "Здоровья было: " << hp << endl; hp = hp + 100; cout << "Вкусная Филаденская рыбка" << endl << "Здоровья осталось: " << hp << endl << endl; break; }
                        case 17: {cout << "Здоровья было: " << hp << endl; hp = hp + 100; cout << "Вкусная Филаденская рыбка" << endl << "Здоровья осталось: " << hp << endl << endl; break; }
                        case 18: {cout << "Здоровья было: " << hp << endl; hp = hp + 100; cout << "Вкусная Филаденская рыбка" << endl << "Здоровья осталось: " << hp << endl << endl; break; }
                        case 19: {cout << "Здоровья было: " << hp << endl; hp = hp + 100; cout << "Вкусная Филаденская рыбка" << endl << "Здоровья осталось: " << hp << endl << endl; break; }
                        case 20: {cout << "Здоровья было: " << hp << endl; hp = hp + 100; cout << "Вкусная Филаденская рыбка" << endl << "Здоровья осталось: " << hp << endl << endl; break; }
                        case 21: {cout << "Здоровья было: " << hp << endl; hp = hp + 100; cout << "Вкусная Филаденская рыбка" << endl << "Здоровья осталось: " << hp << endl << endl; break; }
                        case 22: {cout << "Здоровья было: " << hp << endl; hp = hp + 100; cout << "Вкусная Филаденская рыбка" << endl << "Здоровья осталось: " << hp << endl << endl; break; }
                        case 23: {cout << "Здоровья было: " << hp << endl; hp = hp + 100; cout << "Вкусная Филаденская рыбка" << endl << "Здоровья осталось: " << hp << endl << endl; break; }
                        case 24: {cout << "Здоровья было: " << hp << endl; hp = hp + 100; cout << "Вкусная Филаденская рыбка" << endl << "Здоровья осталось: " << hp << endl << endl; break; }
                        case 25: {cout << "Ого, кальмарчик!" << endl << endl << "Кальмар оказался отравленным." << endl << "Пока Вы приходили в чувство, то кто-то украл ваше оружие." << endl << endl; masha = 0; break; }
                        }
                        if (hp <= 0)
                        {
                            Tips = 18;
                        }
                    }
                    system("pause");
                    system("cls");
                CritUser = 0;
                hod = 0;
                AttakMonstr = 1 + rand() % 9;

                        //каменный голем
                if(AttakMonstr == 1 or AttakMonstr == 3 or AttakMonstr == 5 or AttakMonstr == 8)
                {
                    lol.HP = 3 + rand() % (3);
                    cout << "Тебе встретилось существо.. Это каменный голем!" << endl << endl << "Здоровье: " << lol.HP << endl << "У тебя здоровья: " << hp << endl << endl;
                    while (lol.HP > 0 and hp > 0)
                    {
                        hod++;
                        //атака монстра
                        lol.UR = 10 + rand() %10;
                        cout << "Голем сейчас нанесёт урона: " << lol.UR << endl << endl;   
                        ViborOne = 1 + rand() % 3;
                        switch (ViborOne) {
                        case 1: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * yr + 10 + fish; } else { AttakUserA = 5 + rand() % 11 + 3 * yr + fish; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
                        case 2: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * yr + 20 + fish; } else { AttakUserA = 5 + rand() % 11 + 3 * yr + fish; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
                        case 3: {AttakUserA = 0; cout << "1 - Отдохнуть" << endl; break; }
                        }
                        //второй вариант
                        ViborTwo = 1 + rand() % 3;
                        switch (ViborTwo) {
                        case 1: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * yr + 15 + fish; } else { AttakUserS = 5 + rand() % 11 + 3 * yr + fish; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
                        case 2: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * yr + 20 + fish; } else { AttakUserS = 5 + rand() % 11 + 3 * yr + fish; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
                        case 3: {AttakUserS = 0; cout << "2 - Отдохнуть" << endl; break; }
                        }
                        //3 вариант - какашка
                        if (masha == 1)
                        {
                            cout << "3 - Помолиться какашке Господня" << endl;
                        }
                        //3 вариант - щит
                        else if (masha == 2)
                        {
                            ViborTree = 1 + rand() % 5;
                            switch (ViborTree) {
                            case 1: { cout << "3 - Отдохнуть" << endl; break; }
                            case 2: { cout << "3 - Отдохнуть" << endl; break; }
                            case 3: { cout << "3 - Отдохнуть" << endl; break; }
                             case 4: {
                                if (CritUser > 1)
                                {
                                    AttakUserD = 5 + rand() % 11 + 3 * yr + 5 + 5 + fish;
                                }
                                else
                                {
                                    AttakUserD = 5 + rand() % 11 + 3 * yr + 5 + fish;
                                }
                                cout << "3 - Ударить щитом" << endl;
                                CritUser = 0;
                                break;
                            }
                            case 5: {cout << "3 - Прикрыться щитом" << endl; break; }
                            }
                        }
                        //3 вариант - ракушка
                        else if (masha == 3)
                        {
                            ViborTree = 1 + rand() % 5;
                            switch (ViborTree) {
                            case 1: { cout << "3 - Приложить ракушечку к ушечку" << endl; break; }
                            default: {cout << "3 - Отдохнуть" << endl; break; }
                            }
                        }
                        //3 вариант - золотая шкурка
                        else if (masha == 4)
                        {
                            if (SheepDeff == true)
                            {
                                cout << "3 - Блокировать" << endl;
                            }
                            else { cout << "3 - Отдохнуть" << endl; }
                        }
                        if (masha == 0)
                        {
                            cout << "Выбери действие : ";
                            do {
                                cin >> ComPr;;
                                if (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010") cout << "Такой команды нет, попробуй ещё раз: ";
                            } while (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010");
                        }
                        else
                        {
                            cout << "Выбери действие : ";
                            do {
                                cin >> ComPr;
                                if (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010" and ComPr != "3") cout << "Такой команды нет, попробуй ещё раз: ";
                            } while (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010" and ComPr != "3");
                        }
                        Pr = stoi(ComPr);
                        switch (Pr) {
                            //если выбрал 1
                        case 1: { if (AttakUserA != 0) {
                            //если урон
                            CritUser = 0;
                            lol.HP = lol.HP - 1;
                            cout << "Ты нанёс урон" << endl;
                        }
                              //если отдых
                              else { cout << "Ты отдохнул" << endl; CritUser++; }
                              break; }
                              //если выбрал 2
                              //если урон
                        case 2: { if (AttakUserS != 0) {
                            CritUser = 0;
                            lol.HP = lol.HP - 1;
                            cout << "Ты нанёс урон" << endl;
                        }
                              //если отдых
                              else { cout << "Ты отдохнул" << endl; CritUser++; }
                              break; }
                        case 666778: {lol.HP = 0;  break; }
                        case 2010: {hp = 0;}
                                 //если выбрал 3
                        case 3: {
                            //если оружие какашка
                            if (masha == 1) { cout << "Ты помолился какашке" << endl; }
                            //если оружие щит
                            else if (masha == 2)
                            {
                                if (ViborTree == 4)
                                {
                                    CritUser = 0;
                                    lol.HP = lol.HP - 1;
                                    cout << "Ты нанёс урон" << endl;
                                }
                                else if (ViborTree == 5)
                                {
                                    if (lol.HP != 0) { Deff = 1 + rand() % (lol.UR + 1); }
                                }
                                else { cout << "Ты отдохнул" << endl; CritUser++; }
                            }
                            //если оружие ракушка
                            else if (masha == 3)
                            {
                                if (ViborTree == 1)
                                {
                                    RacushkaHill += 8;
                                }
                                else { cout << "Ты отдохнул" << endl; CritUser++; }
                            }
                            //если золотая шкура
                            else if (masha == 4)
                            {
                                if (SheepDeff == true)
                                {
                                    lol.UR = 0;
                                    SheepDeff = false;
                                }
                                else { cout << "Ты отдохнул" << endl; CritUser++; }
                            }
                        }
                        }
                        //конец хода
                        if (lol.HP > 0 and hp > 0) {
                            if (lol.UR > 0) {
                                hp = hp - lol.UR + Deff;
                                Deff = 0;
                            }
                            cout << "Ход#" << hod << " закончился. ..  ." << endl;
                            system("pause");
                            system("cls");
                            cout << "У голема осталось здоровья: " << lol.HP << endl;
                            cout << "У тебя осталось здоровья: " << hp << endl << endl;
                        }
                    }
                    //оповещение о победе
                    system("cls");
                    if (lol.HP <= 0) {
                        cout << "Голем повержен!" << endl << "Ходов сделано: " << hod << endl;
                        system("pause");
                        system("cls");
                    }
                    //если проиграл
                    else if (hp <= 0)
                    {
                        Tips = 19;
                        break;
                    }
                }

                        //стальной голем
                else if (AttakMonstr == 2 or AttakMonstr == 6)
                {
                    lol.HP = 7 + rand() % (4);
                    cout << "Тебе встретилось существо.. Это истукан стальной!" << endl << endl << "Здоровье: " << lol.HP << endl << "У тебя здоровья: " << hp << endl << endl;
                    while (lol.HP > 0 and hp > 0)
                    {
                        hod++;
                        //атака монстра
                        AttakMonstr = 1 + rand() % 2;
                        switch (AttakMonstr) {
                        case 1: {lol.UR = 19 + rand() % 13; cout << "Голем сейчас нанесёт урона: " << lol.UR << endl << endl; break; }
                        case 2: {lol.UR = 0; cout << "Голем содрожает землю.." << endl << endl; break; }
                        }
                        ViborOne = 1 + rand() % 3;
                        switch (ViborOne) {
                        case 1: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * yr + 10 + fish; } else { AttakUserA = 5 + rand() % 11 + 3 * yr + fish; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
                        case 2: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * yr + 20 + fish; } else { AttakUserA = 5 + rand() % 11 + 3 * yr + fish; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
                        case 3: {AttakUserA = 0; cout << "1 - Отдохнуть" << endl; break; }
                        }
                        //второй вариант
                        ViborTwo = 1 + rand() % 3;
                        switch (ViborTwo) {
                        case 1: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * yr + 15 + fish; } else { AttakUserS = 5 + rand() % 11 + 3 * yr + fish; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
                        case 2: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * yr + 20 + fish; } else { AttakUserS = 5 + rand() % 11 + 3 * yr + fish; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
                        case 3: {AttakUserS = 0; cout << "2 - Отдохнуть" << endl; break; }
                        }
                        //3 вариант - какашка
                        if (masha == 1)
                        {
                            cout << "3 - Помолиться какашке Господня" << endl;
                        }
                        //3 вариант - щит
                        else if (masha == 2)
                        {
                            ViborTree = 1 + rand() % 5;
                            switch (ViborTree) {
                            case 1: { cout << "3 - Отдохнуть" << endl; break; }
                            case 2: { cout << "3 - Отдохнуть" << endl; break; }
                            case 3: { cout << "3 - Отдохнуть" << endl; break; }
                            case 4: {
                                if (CritUser > 1)
                                {
                                    AttakUserD = 5 + rand() % 11 + 3 * yr + 5 + 5 + fish;
                                }
                                else
                                {
                                    AttakUserD = 5 + rand() % 11 + 3 * yr + 5 + fish;
                                }
                                cout << "3 - Ударить щитом" << endl;
                                CritUser = 0;
                                break;
                            }
                            case 5: {cout << "3 - Прикрыться щитом" << endl; break; }
                            }
                        }
                        //3 вариант - ракушка
                        else if (masha == 3)
                        {
                            ViborTree = 1 + rand() % 5;
                            switch (ViborTree) {
                            case 1: { cout << "3 - Приложить ракушечку к ушечку" << endl; break; }
                            default: {cout << "3 - Отдохнуть" << endl; break; }
                            }
                        }
                        //3 вариант - золотая шкурка
                        else if (masha == 4)
                        {
                            if (SheepDeff == true)
                            {
                                cout << "3 - Блокировать" << endl;
                            }
                            else { cout << "3 - Отдохнуть" << endl; }
                        }
                        if (masha == 0)
                        {
                            cout << "Выбери действие : ";
                            do {
                                cin >> ComPr;;
                                if (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010") cout << "Такой команды нет, попробуй ещё раз: ";
                            } while (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010");
                        }
                        else
                        {
                            cout << "Выбери действие : ";
                            do {
                                cin >> ComPr;
                                if (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010" and ComPr != "3") cout << "Такой команды нет, попробуй ещё раз: ";
                            } while (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010" and ComPr != "3");
                        }
                        Pr = stoi(ComPr);
                        switch (Pr) {
                            //если выбрал 1
                        case 1: { if (AttakUserA != 0) {
                            //если урон
                            CritUser = 0;
                            lol.HP = lol.HP - 1;
                            cout << "Ты нанёс урон" << endl;
                        }
                              //если отдых
                              else { cout << "Ты отдохнул" << endl; CritUser++; }
                              break; }
                              //если выбрал 2
                              //если урон
                        case 2: { if (AttakUserS != 0) {
                            CritUser = 0;
                            lol.HP = lol.HP - 1;
                            cout << "Ты нанёс урон" << endl;
                        }
                              //если отдых
                              else { cout << "Ты отдохнул" << endl; CritUser++; }
                              break; }
                        case 666778: {lol.HP = 0;  break; }
                        case 2010: {hp = 0; }
                                 //если выбрал 3
                        case 3: {
                            //если оружие какашка
                            if (masha == 1) { cout << "Ты помолился какашке" << endl; }
                            //если оружие щит
                            else if (masha == 2)
                            {
                                if (ViborTree == 4)
                                {
                                    CritUser = 0;
                                    lol.HP = lol.HP - 1;
                                    cout << "Ты нанёс урон" << endl;
                                }
                                else if (ViborTree == 5)
                                {
                                    if (lol.HP != 0) { Deff = 1 + rand() % (lol.UR + 1); }
                                }
                                else { cout << "Ты отдохнул" << endl; CritUser++; }
                            }
                            //если оружие ракушка
                            else if (masha == 3)
                            {
                                if (ViborTree == 1)
                                {
                                    RacushkaHill += 8;
                                }
                                else { cout << "Ты отдохнул" << endl; CritUser++; }
                            }
                            //если золотая шкура
                            else if (masha == 4)
                            {
                                if (SheepDeff == true)
                                {
                                    lol.UR = 0;
                                    SheepDeff = false;
                                }
                                else { cout << "Ты отдохнул" << endl; CritUser++; }
                            }
                        }
                        }
                        //конец хода
                        if (lol.HP > 0 and hp > 0) {
                            if (lol.UR > 0) {
                                hp = hp - lol.UR + Deff;
                                Deff = 0;
                            }
                            cout << "Ход#" << hod << " закончился. ..  ." << endl;
                            system("pause");
                            system("cls");
                            cout << "У голема осталось здоровья: " << lol.HP << endl;
                            cout << "У тебя осталось здоровья: " << hp << endl << endl;
                        }
                    }
                    //оповещение о победе
                    system("cls");
                    if (lol.HP <= 0) {
                        cout << "Голем повержен!" << endl << "Ходов сделано: " << hod << endl;
                        system("pause");
                        system("cls");
                    }
                    //если проиграл
                    else if (hp <= 0)
                    {
                        Tips = 20;
                        break;
                    }
                }

                //ангел
                else if(AttakMonstr == 4 or AttakMonstr == 7 or AttakMonstr == 9)
                {
                    lol.HP = 100 + rand() % (21);
                    cout << "Тебе встретилось существо.. Это ангел!" << endl << endl << "Здоровье: " << lol.HP << endl << "У тебя здоровья: " << hp << endl << endl;
                    while (lol.HP > 0 and hp > 0 and lol.HP != 666666)
                    {
                        //атака монстра
                        AttakMonstr = 1 + rand() % 2;
                        switch (AttakMonstr) {
                        case 1: {lol.UR = 5 + rand() % 8 + CritMonstr * 6; CritMonstr = 0; cout << "Агнел сейчас нанесёт урона: " << lol.UR << endl << endl; break; }
                        case 2: {lol.UR = 0; CritMonstr++; cout << "Агнел молится.." << endl << endl; break; }
                        }
                        //1 вариант
                        ViborOne = 1 + rand() % 3;
                        switch (ViborOne) {
                        case 1: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * yr + 10 + fish; } else { AttakUserA = 5 + rand() % 11 + 3 * yr + fish; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
                        case 2: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * yr + 20 + fish; } else { AttakUserA = 5 + rand() % 11 + 3 * yr + fish; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
                        case 3: {AttakUserA = 0; cout << "1 - Отдохнуть" << endl; break; }
                        }
                        //второй вариант
                        ViborTwo = 1 + rand() % 3;
                        switch (ViborTwo) {
                        case 1: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * yr + 15 + fish; } else { AttakUserS = 5 + rand() % 11 + 3 * yr + fish; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
                        case 2: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * yr + 20 + fish; } else { AttakUserS = 5 + rand() % 11 + 3 * yr + fish; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
                        case 3: {AttakUserS = 0; cout << "2 - Отдохнуть" << endl; break; }
                        }
                        //3 вариант - какашка
                        if (masha == 1)
                        {
                            cout << "3 - Помолиться какашке Господня" << endl;
                        }
                        //3 вариант - щит
                        else if (masha == 2)
                        {
                            ViborTree = 1 + rand() % 5;
                            switch (ViborTree) {
                            case 1: { cout << "3 - Отдохнуть" << endl; break; }
                            case 2: { cout << "3 - Отдохнуть" << endl; break; }
                            case 3: { cout << "3 - Отдохнуть" << endl; break; }
                            case 4: {
                                if (CritUser > 1) 
                                { 
                                    AttakUserD = 5 + rand() % 11 + 3 * yr + 5 + 5;
                                } 
                                else 
                                { 
                                    AttakUserD = 5 + rand() % 11 + 3 * yr + 5 + fish; 
                                } 
                                cout << "3 - Ударить щитом" << endl; 
                                CritUser = 0;
                                break; 
                            }
                            case 5: {cout << "3 - Прикрыться щитом" << endl; break; }
                            }
                        }
                        //3 вариант - ракушка
                        else if (masha == 3)
                        {
                            ViborTree = 1 + rand() % 5;
                            switch (ViborTree) {
                            case 1: { cout << "3 - Приложить ракушечку к ушечку" << endl; break; }
                            default: {cout << "3 - Отдохнуть" << endl; break; }
                            }
                        }
                        //3 вариант - золотая шкурка
                        else if (masha == 4)
                        {
                            if (SheepDeff == true)
                            {
                                cout << "3 - Блокировать" << endl;
                            }
                            else { cout << "3 - Отдохнуть" << endl; }
                        }
                        cout << "Выбери действие : ";
                        if (masha == 0)
                        {
                            do {
                                cin >> ComPr;;
                                if (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010") cout << "Такой команды нет, попробуй ещё раз: ";
                            } while (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010");
                        }
                        else
                        {
                            do {
                                cin >> ComPr;
                                if (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010" and ComPr != "3") cout << "Такой команды нет, попробуй ещё раз: ";
                            } while (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010" and ComPr != "3");
                        }
                        Pr = stoi(ComPr);
                        switch (Pr) {

                            //если выбрал 1
                        case 1: { if (AttakUserA != 0) {
                            //если урон
                            if (AttakMonstr == 2)
                            {
                                CritUser = 0;
                                CritMonstr = 0;
                                lol.HP = lol.HP + AttakUserA;
                                cout << "Ты нанёс урон" << endl;
                            }
                            else
                            {
                                CritUser = 0;
                                lol.HP = lol.HP - AttakUserA;
                                cout << "Ты нанёс урон" << endl;
                            }
                        }
                              //если отдых
                              else { cout << "Ты отдохнул" << endl; CritUser++; hp = hp - 5; }
                              break; }
                              //если выбрал 2
                              //если урон
                        case 2: { if (AttakUserS != 0) {
                            if (AttakMonstr == 2)
                            {
                                CritUser = 0;
                                CritMonstr = 0;
                                lol.HP = lol.HP + AttakUserS;
                                cout << "Ты нанёс урон" << endl;
                            }
                            else
                            {
                                CritUser = 0;
                                lol.HP = lol.HP - AttakUserS;
                                cout << "Ты нанёс урон" << endl;
                            }
                        }
                              //если отдых
                              else { cout << "Ты отдохнул" << endl; CritUser++; hp = hp - 5;}
                              break; }
                        case 666778: {lol.HP = 0;  break; }
                        case 2010: {hp = 0; }
                                 //если выбрал 3
                        case 3: {
                            //если оружие какашка
                            if (masha == 1) 
                            { 
                                lol.HP = 666666;
                            }
                            //если оружие щит
                            else if (masha == 2)
                            {
                                if (ViborTree == 4)
                                {
                                    if (AttakMonstr == 2)
                                    {
                                        CritUser = 0;
                                        lol.HP = lol.HP + AttakUserD;
                                        CritMonstr = 0;
                                        cout << "Ты нанёс урон" << endl;
                                    }
                                    else
                                    {
                                        CritUser = 0;
                                        lol.HP = lol.HP - AttakUserD;
                                        cout << "Ты нанёс урон" << endl;
                                    }
                                }
                                else if (ViborTree == 5)
                                {
                                    if (lol.HP != 0) { Deff = 1 + rand() % (lol.UR + 1); }
                                }
                                else { cout << "Ты отдохнул" << endl; CritUser++; hp = hp - 5;}
                            }
                            //если оружие ракушка
                            else if (masha == 3)
                            {
                                if (ViborTree == 1)
                                {
                                    RacushkaHill += 8;
                                }
                                else { cout << "Ты отдохнул" << endl; CritUser++; hp = hp - 5;}
                            }
                            //если золотая шкура
                            else if (masha == 4)
                            {
                                if (SheepDeff == true)
                                {
                                    lol.UR = 0;
                                    SheepDeff = false;
                                }
                                else { cout << "Ты отдохнул" << endl; CritUser++; hp = hp - 5;}
                            }
                        }
                        }
                        //конец хода
                        if (lol.HP > 0 and hp > 0) {
                            if (lol.UR > 0) {
                                hp = hp - lol.UR + Deff;
                                Deff = 0;
                            }
                            cout << "Ход#" << hod << " закончился. ..  ." << endl;
                            system("pause");
                            system("cls");
                            cout << "У Агнела осталось здоровья: " << lol.HP << endl;
                            cout << "У тебя осталось здоровья: " << hp << endl << endl;
                        }
                    }
                    //оповещение о победе
                    system("cls");
                    if (lol.HP <= 0) {
                        cout << "Агнел свержен!" << endl << "Ходов сделано: " << hod << endl;
                        system("pause");
                        system("cls");
                    }
                    //если проиграл
                    else if (hp <= 0)
                    {
                        Tips = 21;
                        break;
                    }

                    else if (lol.HP == 666666)
                    {
                        masha = 0;
                        cout << "Ты помолился какашке" << endl;
                        system("pause");
                        system("cls");
                        cout << "Твои мысли заглушаются и в твоей голове раздаётся эхо:\n" << endl << "'Страшно карать верующего и Богу приближённого.'\0'Ты помилован грешник'" << endl << endl << "Агнел покинул лес" << endl << endl;
                        system("pause");
                        system("cls");
                    }
                }
             

             //обнуляем
             SheepDeff = true;
             //хилл отракушки
             if (masha == 3 and hp > 0)
             {
                 cout << "Бой закончился, из ракушечки начала доноситься мелодия на секундочки: " << 5 + RacushkaHill << endl << endl;
                 hp = hp + 5 + RacushkaHill;
                 system("pause");
                 system("cls");
                 RacushkaHill = 0;
             }
             CritUser = 0;
             hod = 0;

                    //кукушка
             cout << "Ты заметил кукушку. ..  ." << endl << "Чутьё подсказывает, что, кукушка приведёт к сильному противнику." << endl << "0) Уйти" << endl << "1) Последовать за кукушкой" << endl << endl;
             cout << "Выбери действие : ";
             do {
                 cin >> ComPr;;
                 if (ComPr != "1" and ComPr != "0") cout << "Такой команды нет, попробуй ещё раз: ";
             } while (ComPr != "1" and ComPr != "0");

             system("pause");
             system("cls");

             if (ComPr == "1")
             {
                 cout << "Кукушка ждёт, пока ты кукукнешь.." << endl << "Выбери уровень сложности:" << endl << "1" <<  endl<< "2"<<  endl << "3"<< endl  << endl;
                 cout << "Выбери: ";
                 do {
                     cin >> ComPr;;
                     if (ComPr != "1" and ComPr != "2" and ComPr != "3") cout << "Такой команды нет, попробуй ещё раз: ";
                 } while (ComPr != "1" and ComPr != "2" and ComPr != "3");
             }

             system("pause");
             system("cls");

                //если 1 куку
             if (ComPr == "1")
             {
                 lol.HP = 200 + rand() % (301);
                 cout << "Тебе встретилось припятствие! Крапива.." << endl << endl << "Здоровье: " << lol.HP << endl << "У тебя здоровья: " << hp << endl << endl;
                 while (lol.HP > 0 and hp > 0)
                 {
                     //1 вариант
                     ViborOne = 1 + rand() % 3;
                     switch (ViborOne) {
                     case 1: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * yr + 10 + fish; } else { AttakUserA = 5 + rand() % 11 + 3 * yr + fish; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
                     case 2: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * yr + 20 + fish; } else { AttakUserA = 5 + rand() % 11 + 3 * yr + fish; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
                     case 3: {AttakUserA = 0; cout << "1 - Отдохнуть" << endl; break; }
                     }
                     cout << endl << "Выбери действие : ";
                         do {
                             cin >> ComPr;
                             if (ComPr != "1" and  ComPr != "666778" and ComPr != "2010") cout << "Такой команды нет, попробуй ещё раз: ";
                         } while (ComPr != "1" and ComPr != "666778" and ComPr != "2010");
                     
                     Pr = stoi(ComPr);
                     switch (Pr) {

                         //если выбрал 1
                     case 1: { if (AttakUserA != 0) {
                         //если урон
                         CritUser = 0;
                         lol.HP = lol.HP - AttakUserA;
                         cout << "Ты нанёс урон жгучей крапиве" << endl;
                         hp = hp - (1 + rand() % 5);
                     }
                           //если отдых
                           else { cout << "Ты отдохнул" << endl; CritUser++; }
                           break; }
                     case 666778: {lol.HP = 0;  break; }
                     case 2010: {hp = 0; }
                              //если выбрал 3
                     }
                     //конец хода
                     if (lol.HP > 0 and hp > 0) {
                         cout << "Ход#" << hod << " закончился. ..  ." << endl;
                         system("pause");
                         system("cls");
                         cout << "У крапивы осталось здоровья: " << lol.HP << endl;
                         cout << "У тебя осталось здоровья: " << hp << endl << endl;
                     }
                 }
                 //оповещение о победе
                 system("cls");
                 if (lol.HP <= 0) {
                     cout << "Крапива повержена!" << endl << "Ходов сделано: " << hod << endl;
                     system("pause");
                     system("cls");
                     fish = fish + 5;
                 }
                 //если проиграл
                 else if (hp <= 0)
                 {
                     Tips = 22;
                     break;
                 }
             }

                //если 2 куку
             else if(ComPr == "2")
             {
                 lol.HP = 85 + rand() % (31);
                 cout << "Тебе встретилось существо.. Это медовый упырь!" << endl << endl << "Здоровье: " << lol.HP << endl << "У тебя здоровья: " << hp << endl << endl;
                 while (lol.HP > 0 and hp > 0)
                 {
                     hod++;
                     //атака монстра
                     AttakMonstr = 1 + rand() % 5;
                     switch (AttakMonstr) {
                     default: {lol.UR = 5 + rand() % 6 + CritMonstr * 4; CritMonstr += 2; cout << "Медовый упырь рассткается: " << lol.UR << endl << endl; break; }
                     //case 1: {lol.UR = 0; CritMonstr = CritMonstr + 4; cout << "Медовый упырь расстекается.." << endl << endl; break; }
                     }
                     //1 вариант
                     ViborOne = 1 + rand() % 3;
                     switch (ViborOne) {
                     case 1: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * yr + 10 + fish; } else { AttakUserA = 5 + rand() % 11 + 3 * yr + fish; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
                     case 2: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * yr + 20 + fish; } else { AttakUserA = 5 + rand() % 11 + 3 * yr + fish; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
                     case 3: {AttakUserA = 0; cout << "1 - Отдохнуть" << endl; break; }
                     }
                     //второй вариант
                     ViborTwo = 1 + rand() % 3;
                     switch (ViborTwo) {
                     case 1: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * yr + 15 + fish; } else { AttakUserS = 5 + rand() % 11 + 3 * yr + fish; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
                     case 2: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * yr + 20 + fish; } else { AttakUserS = 5 + rand() % 11 + 3 * yr + fish; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
                     case 3: {AttakUserS = 0; cout << "2 - Отдохнуть" << endl; break; }
                     }
                     //3 вариант - какашка
                     if (masha == 1)
                     {
                         cout << "3 - Помолиться какашке Господня" << endl;
                     }
                     //3 вариант - щит
                     else if (masha == 2)
                     {
                         ViborTree = 1 + rand() % 5;
                         switch (ViborTree) {
                         case 1: { cout << "3 - Отдохнуть" << endl; break; }
                         case 2: { cout << "3 - Отдохнуть" << endl; break; }
                         case 3: { cout << "3 - Отдохнуть" << endl; break; }
                         case 4: {
                             if (CritUser > 1)
                             {
                                 AttakUserD = 5 + rand() % 11 + 3 * yr + 5 + 5 + fish;
                             }
                             else
                             {
                                 AttakUserD = 5 + rand() % 11 + 3 * yr + 5 + fish;
                             }
                             cout << "3 - Ударить щитом" << endl;
                             CritUser = 0;
                             break;
                         }
                         case 5: {cout << "3 - Прикрыться щитом" << endl; break; }
                         }
                     }
                     //3 вариант - ракушка
                     else if (masha == 3)
                     {
                         ViborTree = 1 + rand() % 5;
                         switch (ViborTree) {
                         case 1: { cout << "3 - Приложить ракушечку к ушечку" << endl; break; }
                         default: {cout << "3 - Отдохнуть" << endl; break; }
                         }
                     }
                     //3 вариант - золотая шкурка
                     else if (masha == 4)
                     {
                         if (SheepDeff == true)
                         {
                             cout << "3 - Блокировать" << endl;
                         }
                         else { cout << "3 - Отдохнуть" << endl; }
                     }
                     if (masha == 0)
                     {
                         cout << "Выбери действие : ";
                         do {
                             cin >> ComPr;;
                             if (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010") cout << "Такой команды нет, попробуй ещё раз: ";
                         } while (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010");
                     }
                     else
                     {
                         cout << "Выбери действие : ";
                         do {
                             cin >> ComPr;
                             if (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010" and ComPr != "3") cout << "Такой команды нет, попробуй ещё раз: ";
                         } while (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010" and ComPr != "3");
                     }
                     Pr = stoi(ComPr);
                     switch (Pr) {

                         //если выбрал 1
                     case 1: { if (AttakUserA != 0) {
                         //если урон
                         CritUser = 0;
                         lol.HP = lol.HP - AttakUserA;
                         cout << "Ты нанёс урон" << endl;
                     }
                           //если отдых
                           else { cout << "Ты отдохнул" << endl; CritUser++; }
                           break; }
                           //если выбрал 2
                           //если урон
                     case 2: { if (AttakUserS != 0) {
                         CritUser = 0;
                         lol.HP = lol.HP - AttakUserS;
                         cout << "Ты нанёс урон" << endl;
                     }
                           //если отдых
                           else { cout << "Ты отдохнул" << endl; CritUser++; }
                           break; }
                     case 666778: {lol.HP = 0;  break; }
                     case 2010: {hp = 0; }
                              //если выбрал 3
                     case 3: {
                         //если оружие какашка
                         if (masha == 1) { cout << "Ты помолился какашке" << endl; }
                         //если оружие щит
                         else if (masha == 2)
                         {
                             if (ViborTree == 4)
                             {
                                 CritUser = 0;
                                 lol.HP = lol.HP - AttakUserD;
                                 cout << "Ты нанёс урон" << endl;
                             }
                             else if (ViborTree == 5)
                             {
                                 Deff = 1 + rand() % (lol.UR + 1);
                             }
                             else { cout << "Ты отдохнул" << endl; CritUser++; }
                         }
                         //если оружие ракушка
                         else if (masha == 3)
                         {
                             if (ViborTree == 1)
                             {
                                 RacushkaHill += 20;
                             }
                             else { cout << "Ты отдохнул" << endl; CritUser++; }
                         }
                         //если золотая шкура
                         else if (masha == 4)
                         {
                             if (SheepDeff == true)
                             {
                                 lol.UR = 0;
                                 SheepDeff = false;
                             }
                             else { cout << "Ты отдохнул" << endl; CritUser++; }
                         }
                     }
                     }
                     //конец хода
                     if (lol.HP > 0 and hp > 0) {
                         if (lol.UR > 0) {
                             hp = hp - lol.UR + Deff;
                             Deff = 0;
                         }
                         cout << "Ход#" << hod << " закончился. ..  ." << endl;
                         system("pause");
                         system("cls");
                         cout << "У медового упыря осталось здоровья: " << lol.HP << endl;
                         cout << "У тебя осталось здоровья: " << hp << endl << endl;
                     }
                 }
                 //оповещение о победе
                 system("cls");
                 if (lol.HP <= 0) {
                     kyky = 15;
                     cout << "Медовый упырь повержен!" << endl << "Ходов сделано: " << hod << endl;
                     system("pause");
                     system("cls");
                 }
                 //если проиграл
                 else if (hp <= 0)
                 {
                     Tips = 23;
                     break;
                 }
                 //обнуляем
                 SheepDeff = true;
                 //хилл отракушки
                 if (masha == 3 and hp > 0)
                 {
                     cout << "Бой закончился, из ракушечки начала доноситься мелодия на секундочки: " << 5 + RacushkaHill << endl << endl;
                     hp = hp + 5 + RacushkaHill;
                     system("pause");
                     system("cls");
                     RacushkaHill = 0;
                 }
             }

             //если 3 куку
             else if (ComPr == "3")
             {
             lol.HP = 150 + rand() % (51);
             cout << "Тебе встретилось существо.. Это детёныш гризли!" << endl << endl << "Здоровье: " << lol.HP << endl << "У тебя здоровья: " << hp << endl << endl;
             while (lol.HP > 0 and hp > 0)
             {
                 hod++;
                 //атака монстра
                 AttakMonstr = 1 + rand() % 3;
                 switch (AttakMonstr) {
                 case 1: {lol.UR = 25 + rand() % 21 + CritMonstr * 15; CritMonstr = 0; cout << "Гризли сейчас нанесёт урона: " << lol.UR << endl << endl; break; }
                 case 2: {lol.UR = 20 + rand() % 21 + CritMonstr * 15; CritMonstr = 0; cout << "Гризли сейчас нанесёт урона: " << lol.UR << endl << endl; break; }
                 case 3: {lol.UR = 0; CritMonstr++; cout << "Гризли замахивается.." << endl << endl; break; }
                 }
                 //1 вариант
                 ViborOne = 1 + rand() % 3;
                 switch (ViborOne) {
                 case 1: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * yr + 10 + fish; } else { AttakUserA = 5 + rand() % 11 + 3 * yr + fish; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
                 case 2: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * yr + 20 + fish; } else { AttakUserA = 5 + rand() % 11 + 3 * yr + fish; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
                 case 3: {AttakUserA = 0; cout << "1 - Отдохнуть" << endl; break; }
                 }
                 //второй вариант
                 ViborTwo = 1 + rand() % 3;
                 switch (ViborTwo) {
                 case 1: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * yr + 15 + fish; } else { AttakUserS = 5 + rand() % 11 + 3 * yr + fish; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
                 case 2: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * yr + 20 + fish; } else { AttakUserS = 5 + rand() % 11 + 3 * yr + fish; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
                 case 3: {AttakUserS = 0; cout << "2 - Отдохнуть" << endl; break; }
                 }
                 //3 вариант - какашка
                 if (masha == 1)
                 {
                     cout << "3 - Помолиться какашке Господня" << endl;
                 }
                 //3 вариант - щит
                 else if (masha == 2)
                 {
                     ViborTree = 1 + rand() % 5;
                     switch (ViborTree) {
                     case 1: { cout << "3 - Отдохнуть" << endl; break; }
                     case 2: { cout << "3 - Отдохнуть" << endl; break; }
                     case 3: { cout << "3 - Отдохнуть" << endl; break; }
                     case 4: {
                         if (CritUser > 1)
                         {
                             AttakUserD = 5 + rand() % 11 + 3 * yr + 5 + 5 + fish;
                         }
                         else
                         {
                             AttakUserD = 5 + rand() % 11 + 3 * yr + 5 + fish;
                         }
                         cout << "3 - Ударить щитом" << endl;
                         CritUser = 0;
                         break;
                     }
                     case 5: {cout << "3 - Прикрыться щитом" << endl; break; }
                     }
                 }
                 //3 вариант - ракушка
                 else if (masha == 3)
                 {
                     ViborTree = 1 + rand() % 5;
                     switch (ViborTree) {
                     case 1: { cout << "3 - Приложить ракушечку к ушечку" << endl; break; }
                     default: {cout << "3 - Отдохнуть" << endl; break; }
                     }
                 }
                 //3 вариант - золотая шкурка
                 else if (masha == 4)
                 {
                     if (SheepDeff == true)
                     {
                         cout << "3 - Блокировать" << endl;
                     }
                     else { cout << "3 - Отдохнуть" << endl; }
                 }
                 if (masha == 0)
                 {
                     cout << "Выбери действие : ";
                     do {
                         cin >> ComPr;;
                         if (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010") cout << "Такой команды нет, попробуй ещё раз: ";
                     } while (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010");
                 }
                 else
                 {
                     cout << "Выбери действие : ";
                     do {
                         cin >> ComPr;
                         if (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010" and ComPr != "3") cout << "Такой команды нет, попробуй ещё раз: ";
                     } while (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010" and ComPr != "3");
                 }
                 Pr = stoi(ComPr);
                 switch (Pr) {

                     //если выбрал 1
                 case 1: { if (AttakUserA != 0) {
                     //если урон
                     CritUser = 0;
                     lol.HP = lol.HP - AttakUserA;
                     cout << "Ты нанёс урон" << endl;
                 }
                       //если отдых
                       else { cout << "Ты отдохнул" << endl; CritUser++; }
                       break; }
                       //если выбрал 2
                       //если урон
                 case 2: { if (AttakUserS != 0) {
                     CritUser = 0;
                     lol.HP = lol.HP - AttakUserS;
                     cout << "Ты нанёс урон" << endl;
                 }
                       //если отдых
                       else { cout << "Ты отдохнул" << endl; CritUser++; }
                       break; }
                 case 666778: {lol.HP = 0;  break; }
                 case 2010: {hp = 0; }
                          //если выбрал 3
                 case 3: {
                     //если оружие какашка
                     if (masha == 1) { cout << "Ты помолился какашке" << endl; }
                     //если оружие щит
                     else if (masha == 2)
                     {
                         if (ViborTree == 4)
                         {
                             CritUser = 0;
                             lol.HP = lol.HP - AttakUserD;
                             cout << "Ты нанёс урон" << endl;
                         }
                         else if (ViborTree == 5)
                         {
                             Deff = 1 + rand() % (lol.UR + 1);
                         }
                         else { cout << "Ты отдохнул" << endl; CritUser++; }
                     }
                     //если оружие ракушка
                     else if (masha == 3)
                     {
                         if (ViborTree == 1)
                         {
                             RacushkaHill += 20;
                         }
                         else { cout << "Ты отдохнул" << endl; CritUser++; }
                     }
                     //если золотая шкура
                     else if (masha == 4)
                     {
                         if (SheepDeff == true)
                         {
                             lol.UR = 0;
                             SheepDeff = false;
                         }
                         else { cout << "Ты отдохнул" << endl; CritUser++; }
                     }
                 }
                 }
                 //конец хода
                 if (lol.HP > 0 and hp > 0) {
                     if (lol.UR > 0) {
                         hp = hp - lol.UR + Deff;
                         Deff = 0;
                     }
                     cout << "Ход#" << hod << " закончился. ..  ." << endl;
                     system("pause");
                     system("cls");
                     cout << "У гризли осталось здоровья: " << lol.HP << endl;
                     cout << "У тебя осталось здоровья: " << hp << endl << endl;
                 }
             }
             //оповещение о победе
             system("cls");
             if (lol.HP <= 0) {
                 kyky = 20;
                 fish = fish + 10;
                 cout << "Гризли повержен!" << endl << "Ходов сделано: " << hod << endl;
                 system("pause");
                 system("cls");
             }
             //если проиграл
             else if (hp <= 0)
             {
                 Tips = 24;
                 break;
             }
             //обнуляем
             SheepDeff = true;
             //хилл отракушки
             if (masha == 3 and hp > 0)
             {
                 cout << "Бой закончился, из ракушечки начала доноситься мелодия на секундочки: " << 5 + RacushkaHill << endl << endl;
                 hp = hp + 5 + RacushkaHill;
                 system("pause");
                 system("cls");
                 RacushkaHill = 0;
             }
             }

             //босс - оборотни
             cout << "Встретив рыбака, он заговорил: " << endl << endl << "'Ты же идёшь к виверне, да?'" << endl << "'Многие пытались до тебя, но они не смогли дойти до этого проклятого леса..'" << endl << "'Ты, наверное, многому научился, многое познал. Я проведу тебя до виверны безопасным путём, пойдём.'"<< endl << endl;
             system("pause");
             system("cls");
             cout << "Вы собираетесь идти, как вдруг в рыбака вонзается стрела. Вы видите как вас окружило несколько волков." << endl << " Он серьёзно ранен и вот-вот упадёт без сознания, но из последних сил он говорит тебе:" << endl <<
                   endl << "'Добей меня, я ведь буду твоим пятым добитым врагом, да?" << endl << "Так добей меня и одалей их, с новым уровнем ты точно сможешь это сделать.'" << endl << endl
                 << "Ты нанёс урон" << endl << endl;
             cout << "Ход#" << 1 << " закончился. ..  ." << endl;
             system("pause");
             system("cls");
             cout << "Рыбак повержен!" << endl << "Ходов сделано: 1" << endl;
             system("pause");
             system("cls");
             yr += 1;
             OP = yr * 5;
             hp = 100 + (OP / 5) * 10 + kyky;
             OP = 0;
             cout << "Ваш уровень повышен до " << yr << "!" << endl << "Ваши навыки сражение улучшилтсь, а тело закалилось!" << endl << endl;
             system("pause");
             system("cls");
             cout << "Ты встретил трёх странных существ.. Это стальные обортни!" << endl << endl;
             Wolf A(40 + rand() % (11), "Волк", 2, 19, 20);
             Wolf S(70 + rand() % (31), "Волчий шахтёр", 3, 10, 11);
             Wolf D(40 + rand() % (21), "Стальной оборотень", 5, 15, 26);
                //цикл оборотни
             while ((A.Zd > 0 or S.Zd > 0 or D.Zd > 0) and hp > 0)
             {
                 hod++;
                 cout << "1) ";
                 A.Dis();
                 cout << "2) ";
                 S.Dis();
                 cout << "3) ";
                 D.Dis();
                 cout << "Выбери кого атокавать: ";
                 do {
                     cin >> WolfPr;
                     if (WolfPr != "1" and WolfPr != "2" and WolfPr != "3") cout << "Такого враг нет, попробуй ещё раз: ";
                     if ((A.Zd <= 0 and WolfPr == "1") or (S.Zd <= 0 and WolfPr == "2") or
                         (D.Zd <= 0 and WolfPr == "3"))
                     {
                         cout << "Враг повержен, попробуй ещё раз: ";
                         WolfPr = "4";
                     }
                 } while (WolfPr != "1" and WolfPr != "2" and WolfPr != "3");
                 //1 вариант
                 ViborOne = 1 + rand() % 3;
                 switch (ViborOne) {
                 case 1: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * yr + 10 + fish; } else { AttakUserA = 5 + rand() % 11 + 3 * yr + fish; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
                 case 2: { if (CritUser > 1) { AttakUserA = 5 + rand() % 11 + 3 * yr + 20 + fish; } else { AttakUserA = 5 + rand() % 11 + 3 * yr + fish; } cout << "1 - Нанести " << AttakUserA << " урона" << endl; break; }
                 case 3: {AttakUserA = 0; cout << "1 - Отдохнуть" << endl; break; }
                 }
                 //второй вариант
                 ViborTwo = 1 + rand() % 3;
                 switch (ViborTwo) {
                 case 1: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * yr + 15 + fish; } else { AttakUserS = 5 + rand() % 11 + 3 * yr + fish; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
                 case 2: { if (CritUser > 1) { AttakUserS = 5 + rand() % 11 + 3 * yr + 20 + fish; } else { AttakUserS = 5 + rand() % 11 + 3 * yr + fish; } cout << "2 - Нанести " << AttakUserS << " урона" << endl; break; }
                 case 3: {AttakUserS = 0; cout << "2 - Отдохнуть" << endl; break; }
                 }
                 //3 вариант - какашка
                 if (masha == 1)
                 {
                     cout << "3 - Помолиться какашке Господня" << endl;
                 }
                 //3 вариант - щит
                 else if (masha == 2)
                 {
                     ViborTree = 1 + rand() % 5;
                     switch (ViborTree) {
                     case 1: { cout << "3 - Отдохнуть" << endl; break; }
                     case 2: { cout << "3 - Отдохнуть" << endl; break; }
                     case 3: { cout << "3 - Отдохнуть" << endl; break; }
                     case 4: {
                         if (CritUser > 1)
                         {
                             AttakUserD = 5 + rand() % 11 + 3 * yr + 5 + 5 + fish;
                         }
                         else
                         {
                             AttakUserD = 5 + rand() % 11 + 3 * yr + 5 + fish;
                         }
                         cout << "3 - Ударить щитом" << endl;
                         CritUser = 0;
                         break;
                     }
                     case 5: {cout << "3 - Прикрыться щитом" << endl; break; }
                     }
                 }
                 //3 вариант - ракушка
                 else if (masha == 3)
                 {
                     ViborTree = 1 + rand() % 5;
                     switch (ViborTree) {
                     case 1: { cout << "3 - Приложить ракушечку к ушечку" << endl; break; }
                     default: {cout << "3 - Отдохнуть" << endl; break; }
                     }
                 }
                 //3 вариант - золотая шкурка
                 else if (masha == 4)
                 {
                     if (SheepDeff == true)
                     {
                         cout << "3 - Блокировать" << endl;
                     }
                     else { cout << "3 - Отдохнуть" << endl; }
                 }
                 if (masha == 0)
                 {
                     cout << "Выбери действие : ";
                     do {
                         cin >> ComPr;;
                         if (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010") cout << "Такой команды нет, попробуй ещё раз: ";
                     } while (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010");
                 }
                 else
                 {
                     cout << "Выбери действие : ";
                     do {
                         cin >> ComPr;
                         if (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010" and ComPr != "3") cout << "Такой команды нет, попробуй ещё раз: ";
                     } while (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010" and ComPr != "3");
                 }
                 Pr = stoi(ComPr);
                 switch (Pr) {
                     //если выбрал 1
                 case 1: { if (AttakUserA != 0) {
                     //если урон
                     CritUser = 0;
                     if (WolfPr == "1")
                     {
                         A.Zd = A.Zd - AttakUserA;
                         if (A.Zd <= 0) { A.Adk = 0; }
                     }
                     else if (WolfPr == "2")
                     {
                         S.Zd = S.Zd - AttakUserA;
                         if (S.Zd <= 0) { S.Adk = 0; }
                     }
                     else if (WolfPr == "3")
                     {
                         D.Zd = D.Zd - AttakUserA;
                         if (D.Zd <= 0) { D.Adk = 0; }
                     }
                     cout << "Ты нанёс урон" << endl;
                 }
                       //если отдых
                       else { cout << "Ты отдохнул" << endl; CritUser++; }
                       break; }
                       //если выбрал 2
                       //если урон
                 case 2: { if (AttakUserS != 0) {
                     CritUser = 0;
                     if (WolfPr == "1")
                     {
                         A.Zd = A.Zd - AttakUserS;
                         if (A.Zd <= 0) { A.Adk = 0; }
                     }
                     else if (WolfPr == "2")
                     {
                         S.Zd = S.Zd - AttakUserS;
                         if (S.Zd <= 0) { S.Adk = 0; }
                     }
                     else if (WolfPr == "3")
                     {
                         D.Zd = D.Zd - AttakUserS;
                         if (D.Zd <= 0) { D.Adk = 0; }
                     }
                     cout << "Ты нанёс урон" << endl;
                 }
                       //если отдых
                       else { cout << "Ты отдохнул" << endl; CritUser++; }
                       break; }
                 case 666778: {D.Zd = 0; A.Zd = 0; S.Zd = 0; break; }
                 case 2010: {hp = 0; }
                          //если выбрал 3
                 case 3: {
                     //если оружие какашка
                     if (masha == 1) { cout << "Ты помолился какашке" << endl; }
                     //если оружие щит
                     else if (masha == 2)
                     {
                         if (ViborTree == 4)
                         {
                             CritUser = 0;
                             if (WolfPr == "1")
                             {
                                 A.Zd = A.Zd - AttakUserD;
                                 if (A.Zd <= 0) { A.Adk = 0; }
                             }
                             else if (WolfPr == "2")
                             {
                                 S.Zd = S.Zd - AttakUserD;
                                 if (A.Zd <= 0) { A.Adk = 0; }
                             }
                             else if (WolfPr == "3")
                             {
                                 D.Zd = D.Zd - AttakUserD;
                                 if (D.Zd <= 0) { D.Adk = 0; }
                             }
                             cout << "Ты нанёс урон" << endl;
                         }
                         else if (ViborTree == 5)
                         {
                             if (WolfPr == "1")
                                 Deff = 1 + rand() % (A.Adk + 1);
                             else if (WolfPr == "2")
                                 Deff = 1 + rand() % (S.Adk + 1);
                             else if (WolfPr == "3")
                                 Deff = 1 + rand() % (D.Adk + 1);
                         }
                         else { cout << "Ты отдохнул" << endl; CritUser++; }
                     }
                     //если оружие ракушка
                     else if (masha == 3)
                     {
                         if (ViborTree == 1)
                         {
                             RacushkaHill = 10 + rand() % 11;
                             cout << "Из ракушечки начала доноситься мелодия: " << RacushkaHill << endl << endl;
                             hp = hp + RacushkaHill;
                         }
                         else { cout << "Ты отдохнул" << endl; CritUser++; }
                     }
                     //если золотая шкура
                     else if (masha == 4)
                     {
                         if (SheepDeff == true)
                         {
                             A.Adk = 0;
                             S.Adk = 0;
                             D.Adk = 0;
                             SheepDeff = false;
                         }
                         else { cout << "Ты отдохнул" << endl; CritUser++; }
                     }
                 }
                 }
                 //конец хода
                 if ((A.Zd > 0 or S.Zd > 0 or D.Zd > 0) and hp > 0) {
                     hp = hp - A.Adk - S.Adk - D.Adk + Deff;
                     Deff = 0;
                     cout << "Ход#" << hod << " закончился. ..  ." << endl;
                     system("pause");
                     system("cls");
                     cout << "У тебя осталось здоровья: " << hp << endl << endl;
                 }
             }
             system("cls");
             if (hp > 0) {
                 cout << "Стальные оборотни повержены!" << endl << "Ходов сделано: " << hod << endl;
                 system("pause");
                 system("cls");
                 cout << "Ты заходишь в ущелье горы.." << endl << "Ты прошёл долгий путь и готов отомстить за гнёт своей деревни, за рыбака, за все раны. Спустя годы тренировок и всех монстров. Остался последний этап." << endl 
                     << endl << "Так ты себя успокаивал.." << endl << endl;
                 system("pause");
                 system("cls");
                 cout << "Тебе встретилось старое и ослабленное существо.. Это виверна!" << endl << endl << "Здоровье: 1" << endl << "У тебя здоровья: " << hp << endl << endl;
                 cout << "Виверна, испустив тяжёлый вздох, готовит атаку.. " << endl << endl;
                 AttakUserA = 5 + rand() % 11 + 3 * yr + fish;
                 cout << "1 - Нанести " << AttakUserA << " урона" << endl << "2 - Отдохнуть" << endl;
                 //3 вариант - какашка
                 if (masha == 1)
                 {
                     cout << "3 - Помолиться какашке Господня" << endl;
                 }
                 //3 вариант - щит
                 else if (masha == 2)
                 {
                     cout << "3 - Отдохнуть" << endl; 
                 }
                 //3 вариант - ракушка
                 else if (masha == 3)
                 {
                    cout << "3 - Отдохнуть" << endl;
                 }
                 //3 вариант - золотая шкурка
                 else if (masha == 4)
                 {
                    cout << "3 - Блокировать" << endl; 
                 }
                 if (masha == 0)
                 {
                     cout << "Выбери действие : ";
                     do {
                         cin >> ComPr;;
                         if (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010") cout << "Такой команды нет, попробуй ещё раз: ";
                     } while (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010");
                 }
                 else
                 {
                     cout << "Выбери действие : ";
                     do {
                         cin >> ComPr;
                         if (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010" and ComPr != "3") cout << "Такой команды нет, попробуй ещё раз: ";
                     } while (ComPr != "1" and ComPr != "2" and ComPr != "666778" and ComPr != "2010" and ComPr != "3");
                 }
                 if (ComPr == "2" or ComPr == "3")
                 {
                     cout << endl << endl << "Её старое сердце не выдержало. Виверна упала." << endl << endl;
                 }
                 else
                 {
                     cout << "Ты нанёс урон" << endl << endl;
                 }
                 system("pause");
                 system("cls");
                 cout << "Виверна повержена!" << endl << "Ходов сделано: 0" << endl;
                 system("pause");
                 system("cls");
                 cout << "Виверна мертва.."<< endl << "Но тебя не покидает ощущение, что вовсе не вы освободили свою долину.." << endl << "Ты отправляетесь дальше для..";
                 Sleep(9000);
                 system("cls");
                 cout << "RSZ: 'Долина дисбаланса'" << endl << "Пройдя это приключение - ты потдвердил, что настоящий соискатель, но зачем?.." << endl << "RSZ - Дальше Только Хуже" << endl;;
                 system("pause");
                 system("cls");
                 return 0;
             }
             //если проиграл
             else if (hp <= 0)
             {
                 Tips = 25;
                 break;
             }
             }
        
            if (OP != 0 and OP % 5 == 0) { OP++; hp = 100 + (OP / 5) * 10; yr = OP / 5; cout << endl << "Ваш уровень повышен до " << yr << "!" << endl << "Ваши навыки сражение улучшилтсь, а тело закалилось!" << endl; system("pause"); } // СМЕРТЬ
            }
            system("cls");

            switch (Tips)
            {
            case 1: {cout << "Будьте осторожны с дикими кабанами." << endl << "Они агрессивны и забавно топаяют копытцами перед тем, как побежать на тебя." << endl
                << "Лучше увернуться от их атаки."; break; }
            case 2: {cout << "Издавна в вашей долине водятся боевой вид оленя." << endl << "Но как любое дикое животное - они не обращают внимания на бездвижные объекты."; break; }
            case 3: {cout << "Как и Мидас - золотая овечка обращает в золото то, до чего дотронется копытцем." << endl << "Лучше убить её до того, как она проснётся." << endl 
                << "Возможно за её смерть ты получишь что-то особенное."; break; }
            case 4: {cout << "Гнок проворен." << endl << "Гнок с арбалетом." << endl << "Гнок молодец!"; break; }
            case 5: {cout << "Тайка - умная девушка-инженер." << endl << "В юные годы она смогла изобрести мушкет и научилась пользоваться порохом." << 
                endl << "Она стала разбойницей из-за клейма 'Ведьмы'."; break; }
            case 6: {cout << "Таинственный разбойник в маске." << endl << "Никто не знает его личность и даже пол." 
                << endl << "Из-за его маски нельзя понять, истекает ли он кровью." << endl << "А навыки не дают определить его действия."; break; }
            case 7: {cout << "Если ты умер из-за того, что слишком сильно ударил ёжика.." << endl << "то сочувствую."; break; }
            case 8: {cout << "Как?!"; break; }
            case 9: {cout << "Слизнь - скопление духов в одно круглое тельце." << endl << "Это тельце имеет больше не физическую оболочку, а духовную."
                << endl << "Поэтому ты не можешь нанести ему почти никакого урона, как и он тебе."; break; }
            case 10: {cout << "Злогер появляется из-за скоплений нескольких трупов в одном месте." << endl << "Спустя время трупы скрещиваются в единое целое и оживают." << 
                endl << "После чего бездушно бродит по лесу, нападая на всё живое." << endl << "Хотя его части тела разваливаются даже при беге - он достаточно силён."
                << endl << "Все охотники боятся их. И не всем удавалось сбежать." << endl << "Возможо злогеры появляются из-за эффекта пыльцы бомбоновой пчелы."; break; }
            case 11: {cout << "Интересно, кто в такой глуши поставил капкан?"; break; }
            case 12: {cout << "Всем охотникам известно: 'Перед тем, как есть мясо убедись, что это не отвалившаяся лапа злогера.'"; break; }
            case 13: {cout << "Мимикрылы - маленькие летающие существа." << endl << "Они летают группами, обычно питаются овощами с грядок, но достаточно агрессивны и трусливы." 
                << endl << "Они принимают облик вещей, чтобы замаскироваться на огороде, но живут на полянах у леса."; break; }
            case 14: {cout << "После геноцида слизней их духи не погибли, а лишь покинули свою оболочку." << endl << "Слившись в, одного из мстительных духов, Вокса - они готовы дать реванш."
                << endl << "Надо помнить советы учителя: 'Сильная аура духов - плохо влияет на человека.'"; break; }
            case 15: {cout << "В отличии от злогера - зомби более сгнивший труп." << endl << "Ни один лекарь  не сможет вылечить заражение крови."; break; }
            case 16: {cout << "Смешная бомбоновая пчёлка не умеет летать, но зато прекрасно прыгает." << endl << "Это благодаря её упругому и мягкому телу."
                << endl << "Но не стоит недооценивать её за размеры и безобидность." << endl << "Её пыльца отравляет природу, а иногда и воскрешает мёртвых."; break; }
            case 17: {cout << "Когда ты учился в школе, то читал про огромных песчанных червей." << endl << "Но даже не знал, что такие водятся и в ваших краях."
                << endl << "А также в учебниках не говорилось про их регенерацию.."; break; }
            case 18: {cout << "Было сытно."; break; }
            case 19: {cout << "Голем из камня." << endl << "Но кто его сделал?"; break; }
            case 20: {cout << "Голем из неизвестного металла." << endl << "Но кто его сделал?"; break; }
            case 21: {cout << "Кто сказал, что ангелы обязательно добрые?"; break; }
            case 22: {cout << "Из-за проклятья крапива оставляет сильные ожоги.."; break; }
            case 23: {cout << "Этот мёд сделали неправильные пчёлы." << endl << "Бомбоновые пчёлы."; break; }
            case 24: {cout << "Чтобы в мире не происходило, а природа остаётся сильнее.."; break; }
            case 25: {cout << "Стальные оборотни - одни из разумных существ. Они обитают рядом с шахтами и зачем-то добывают руду."
                << endl << "Не все из них обладают интеллектом и собратья поумней используют таких, как ручных собак."
                << endl << "Некоторые научились пользоваться оружием, а некоторые - магией."; break; }
            }
            Sleep(11000);
            system("cls");
        cout << "Ты умер!)" << endl << "Твой опыт: "<< OP << endl << "Если хочешь попробовать ещё раз введи число - 4" << endl << "Если хочешь закончить - 7" << endl << "Твой выбор: "; // СМЕРТЬ
        Stupid = 0;
        do {
            cin >> CommandProtection; //cin >> CommandProtection;
            if (CommandProtection.find_last_not_of("47") != -1 or CommandProtection.size() > 1 or CommandProtection.empty() == true) { Stupid++; }
            if (Stupid == 2) { system("cls"); cout << "Иди учи уроки! Тема для изучения: цифры (4 и 7)" << endl; return 0; }
            if (CommandProtection.find_last_not_of("47") != -1 or CommandProtection.size() > 1 or CommandProtection.empty() == true) { cout << "Ты дурак? Такого нет, попробуй ещё раз: "; }
        } while (CommandProtection.find_last_not_of("47") != -1 or CommandProtection.size() > 1 or CommandProtection.empty() == true);
        CommandZiclGame = stoi(CommandProtection);
        }
} 