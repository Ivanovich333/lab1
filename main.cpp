//Вариант 3
//Класс – банковский вклад. Параметры (поля класса): ФИО владельца, текущая сумма,
//годовая процентная ставка (проценты начисляются ежегодно с капитализацией начисленных процентов с основной суммой).
//Статус доступа всех полей private. Класс включает: конструктор,
//при необходимости функции доступа к полям, функцию печати параметров,
//функцию расчета суммы на счету через заданное число лет (число лет – параметр функции).
//Вывести на печать параметры всех вкладов и суммарную сумму на счетах через заданное число лет,
//которое вводится с клавиатуры.

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class BankDep {
    string FIO;
    double capital;
    int percent;
public:
    BankDep (string  n, double c, int p): FIO(std::move(n)), capital(c), percent(p) {}
    void print() {
        cout << "\nFIO: " << FIO << "\nCapital: " << capital << "\nPercent: " << percent;
    }
    double calcFunc(int y) {
        return capital*pow(1+double(percent)/100, y);
    }
};



int main() {
    vector<BankDep> mas = {
            BankDep("Ivanov V.V.", 60000, 14),
            BankDep("Nikita E.R", 44000, 23),
            BankDep("Anton D.A.", 36000, 20),
    };
    int y;
    for (BankDep i: mas) {
        i.print();
        cout << "\n";
        cin >> y;
        cout << "\nCapital before " << y << " years: " << i.calcFunc(y);
    }
    return 0;
}
