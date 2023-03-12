#include "Polinoms.h"

Monom::Monom(double _coeff, int _degree) : coeff(_coeff), degree(_degree) {};

Monom& Monom::ex(double x) {
    coeff *= x;
    return*this;
}

void Monom::Set_coeff(double _coeff) {
    coeff = _coeff;
}

void Monom::ex_monom(const Monom& tmp) {
    this->coeff *= tmp.coeff;
    this->degree += tmp.degree;
}

int Monom::Get_degree() { return degree; }

double Monom::Get_coeff() { return coeff; }

void Monom::print() {
    cout << '(' << coeff << "x^" << degree / 100 << "y^" << degree / 10 % 10 << "z^" << degree % 10 << ')';
}

void Monom::sum_coeff(double a1, double a2) {
    this->coeff = a1 + a2;
}




Polinom::Polinom(vector<Monom> arr) {
    List<Monom> tmp(arr);
    list = tmp;
}

Polinom::Polinom(const Polinom& pol) {
    List<Monom> tmp(pol.list);
    list = tmp;
}

Polinom::Polinom(const List<Monom>& list) {
    this->list = list;
}

Polinom& Polinom::operator=(const Polinom& right) {
    this->list = right.list;
    return*this;
}

Polinom Polinom::operator*(double x) {
    Polinom tmp;
    tmp = list * x;
    return tmp;
}

Polinom Polinom::operator+(const Polinom& right) {
    Polinom tmp;
    tmp = list + right.list;
    return tmp;
}

Polinom Polinom::operator-(const Polinom& right) {
    Polinom tmp;
    tmp = list - right.list;
    return tmp;
}

Polinom Polinom::operator*(const Polinom& right) {
    Polinom tmp;
    tmp = list * right.list;
    return tmp;
}

void Polinom::Print() {
    list.Print();
}










