#include "Polinoms.h"



bool comp(Monom a, Monom b) {
    return a.Get_degree() < b.Get_degree();
}


int main() {

    setlocale(LC_ALL, "Russian");

    try {
        int n;

        cout << "Добро пожаловать в калькулятор для полиномов!" << endl;
        cout << "Особенности калькулятора:" << endl;
        cout << "1) У каждого монома есть коэффициент типа данных double и степени переменных x, y, z" << endl;
        cout << "2) Степень вводится трехзначным числом(например, если вы ввели 123, то степень x - 1, степень y - 2, степень z - 3)" << endl;
        cout << "3) Возможные операции: сложение полиномов, вычитание одного полинома из другого, умножение полинома на константу, умножение полиномов" << endl;
        cout << "4) Запрещено: Сложение(вычитание) полиномов с одинаковыми степенями и противоположными коэффициентами, умножение на ноль, умножение полиномов, в результате которого хоть один моном будет иметь степень выше 999" << endl;
        cout << "5) Если, например, у x и y степени 0, а у z - 1, введите 001" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Введите количество мономов из которых будет состоять полином" << endl;

        cin >> n;

        cout << "Далее введите коэффицент и степени указанное количество раз" << endl;

        vector<Monom> monoms;

        for (size_t i = 0; i < n; i++) {
            double coeff;
            int degree;
            cout << "Для " << i + 1 << " монома коэффициент = ";
            cin >> coeff;
            cout << "; степени = ";
            cin >> degree;
            if (degree > 999 || degree < 0) { string error = "Неправильно введенная степень"; throw error; }

            Monom tmp(coeff, degree);

            monoms.push_back(tmp);

        }

        sort(monoms.begin(), monoms.end(), comp);

        Polinom a(monoms);
        cout << "Введенный вами полином:" << endl;
        a.Print();

        cout << "Выберите операцию: 1) сложение, 2) вычитание, 3) умножение , 4) умножение на константу" << endl;
        int choice;
        cin >> choice;

        Polinom c;

        if (choice == 4) {
            cout << "Введите константу, на которую хотите умножить полином:" << endl;
            double x;
            cin >> x;
            c = a * x;
            cout << "Результат:" << endl;
            c.Print();
        }

        else {

            cout << "Для этой операции вам нужен еще один полином" << endl;
            cout << "Введите количество мономов из которых будет состоять полином" << endl;
            cin >> n;
            cout << "Далее вводите коэффицент и степени указанное количество раз" << endl;

            vector<Monom> monoms2;

            for (size_t i = 0; i < n; i++) {
                double coeff;
                int degree;
                cout << "Для " << i + 1 << " монома коэффициент = ";
                cin >> coeff;
                cout << "; степени = ";
                cin >> degree;
                if (degree > 999 || degree < 0) { string error = "Неправильно введенная степень"; throw error; }

                Monom tmp2(coeff, degree);

                monoms2.push_back(tmp2);
            }

            sort(monoms2.begin(), monoms2.end(), comp);

            Polinom b(monoms2);
            cout << "Введенный вами полином:" << endl;
            b.Print();
            cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;


            switch (choice) {
            case 1:
                c = a + b;
                cout << "Результат:" << endl;
                c.Print();
                break;


            case 2:
                c = a - b;
                cout << "Результат:" << endl;
                c.Print();
                break;


            case 3:
                c = a * b;
                cout << "Результат:" << endl;
                c.Print();
                break;
            default:
                cout << "Введено неверное значение" << endl;
                break;
            }
        }
    }
    catch (const string error) {
        cout << "Wrong expression:" << endl << error << endl;
    }
}

