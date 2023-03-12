#pragma once


#include"Stack.h"



struct Monom {
private:

    double coeff;
    int degree;

public:

    Monom(double _coeff, int _degree);

    Monom& ex(double x);

    void Set_coeff(double _coeff);

    void ex_monom(const Monom& tmp);

    int Get_degree();

    double Get_coeff();

    void print();

    void sum_coeff(double a1, double a2);

};


class Polinom {
private:
    List<Monom> list;
public:
    Polinom() {};

    Polinom(vector<Monom> arr);

    Polinom(const Polinom& pol);

    Polinom(const List<Monom>& list);

    Polinom& operator=(const Polinom& right);

    Polinom operator*(double x);

    Polinom operator+(const Polinom& right);

    Polinom operator-(const Polinom& right);

    Polinom operator*(const Polinom& right);

    void Print();

};


