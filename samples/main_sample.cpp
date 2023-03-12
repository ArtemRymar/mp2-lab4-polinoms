#include "Polinoms.h"



bool comp(Monom a, Monom b) {
    return a.Get_degree() < b.Get_degree();
}


int main() {

    setlocale(LC_ALL, "Russian");

    try {
        int n;

        cout << "����� ���������� � ����������� ��� ���������!" << endl;
        cout << "����������� ������������:" << endl;
        cout << "1) � ������� ������ ���� ����������� ���� ������ double � ������� ���������� x, y, z" << endl;
        cout << "2) ������� �������� ����������� ������(��������, ���� �� ����� 123, �� ������� x - 1, ������� y - 2, ������� z - 3)" << endl;
        cout << "3) ��������� ��������: �������� ���������, ��������� ������ �������� �� �������, ��������� �������� �� ���������, ��������� ���������" << endl;
        cout << "4) ���������: ��������(���������) ��������� � ����������� ��������� � ���������������� ��������������, ��������� �� ����, ��������� ���������, � ���������� �������� ���� ���� ����� ����� ����� ������� ���� 999" << endl;
        cout << "5) ����, ��������, � x � y ������� 0, � � z - 1, ������� 001" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "������� ���������� ������� �� ������� ����� �������� �������" << endl;

        cin >> n;

        cout << "����� ������� ���������� � ������� ��������� ���������� ���" << endl;

        vector<Monom> monoms;

        for (size_t i = 0; i < n; i++) {
            double coeff;
            int degree;
            cout << "��� " << i + 1 << " ������ ����������� = ";
            cin >> coeff;
            cout << "; ������� = ";
            cin >> degree;
            if (degree > 999 || degree < 0) { string error = "����������� ��������� �������"; throw error; }

            Monom tmp(coeff, degree);

            monoms.push_back(tmp);

        }

        sort(monoms.begin(), monoms.end(), comp);

        Polinom a(monoms);
        cout << "��������� ���� �������:" << endl;
        a.Print();

        cout << "�������� ��������: 1) ��������, 2) ���������, 3) ��������� , 4) ��������� �� ���������" << endl;
        int choice;
        cin >> choice;

        Polinom c;

        if (choice == 4) {
            cout << "������� ���������, �� ������� ������ �������� �������:" << endl;
            double x;
            cin >> x;
            c = a * x;
            cout << "���������:" << endl;
            c.Print();
        }

        else {

            cout << "��� ���� �������� ��� ����� ��� ���� �������" << endl;
            cout << "������� ���������� ������� �� ������� ����� �������� �������" << endl;
            cin >> n;
            cout << "����� ������� ���������� � ������� ��������� ���������� ���" << endl;

            vector<Monom> monoms2;

            for (size_t i = 0; i < n; i++) {
                double coeff;
                int degree;
                cout << "��� " << i + 1 << " ������ ����������� = ";
                cin >> coeff;
                cout << "; ������� = ";
                cin >> degree;
                if (degree > 999 || degree < 0) { string error = "����������� ��������� �������"; throw error; }

                Monom tmp2(coeff, degree);

                monoms2.push_back(tmp2);
            }

            sort(monoms2.begin(), monoms2.end(), comp);

            Polinom b(monoms2);
            cout << "��������� ���� �������:" << endl;
            b.Print();
            cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;


            switch (choice) {
            case 1:
                c = a + b;
                cout << "���������:" << endl;
                c.Print();
                break;


            case 2:
                c = a - b;
                cout << "���������:" << endl;
                c.Print();
                break;


            case 3:
                c = a * b;
                cout << "���������:" << endl;
                c.Print();
                break;
            default:
                cout << "������� �������� ��������" << endl;
                break;
            }
        }
    }
    catch (const string error) {
        cout << "Wrong expression:" << endl << error << endl;
    }
}

