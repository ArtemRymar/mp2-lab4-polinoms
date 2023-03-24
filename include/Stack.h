#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <algorithm>
#include <locale.h>

#define E 0.0000001

using namespace std;



template<typename T>
class List {
private:
    struct Node {
        T value;
        Node* next;
        Node* prev;
    public:
        Node(T _value, Node* _next, Node* _prev) : value(_value), next(_next), prev(_prev) {};
        
    };

    Node* pFirst;
    size_t sz;

public:

    List() : sz(-1), pFirst(nullptr) {}

    List(vector<T> arr) : sz(-1), pFirst(nullptr) {

        for (size_t i = 0; i < arr.size(); i++) PushBack(arr[i]);

    }

    List(const List& list) : pFirst(nullptr), sz(list.sz) {
        if (list.pFirst == nullptr) return;

        pFirst = new Node(*list.pFirst);
        Node* tmp = pFirst;

        while (tmp->next != nullptr) {
            tmp->next = new Node(*tmp->next);
            tmp->next->prev = tmp;
            tmp = tmp->next;

        }
    }

    size_t size() { return sz; }

    bool isEmpty() { return sz == -1; }

    Node& ToPos(size_t pos) {

        if (isEmpty() || pos < 0 || pos > sz) {
            string error = "Invalid position value or empty list"; throw error;
        }

        if (pos == 0) return *pFirst;

        size_t tmp = 0;
        Node* p = pFirst;
        while (tmp != pos) {
            p = p->next;
            tmp++;
        }
        return *p;
    }

    void PushBack(const T& val) {
        Node* tmp = new Node(val, nullptr, nullptr);

        if (isEmpty()) {
            pFirst = tmp;
            sz++;
        }
        else {
            Node* p = &ToPos(sz);
            p->next = tmp;
            tmp->prev = p;
            sz++;
        }
    }

    void Print() {
        if (isEmpty()) {
            string error = "Trying to output an empty polynomial"; throw error;
        }
        Node* p = pFirst;
        while (p) {
            p->value.print();
            if (p->next != nullptr) cout << " + ";
            p = p->next;
        }
        cout << endl;
    }

    List& operator=(const List& list) {
        this->~List();

        pFirst = new Node(*list.pFirst);
        Node* tmp = pFirst;
        sz = 0;

        while (tmp->next != nullptr) {
            tmp->next = new Node(*tmp->next);
            tmp->next->prev = tmp;
            tmp = tmp->next;
            sz++;
        }

        return *this;
    }

    List operator*(double x) {
        if (x == 0) { string error = "Attempt to multiply the full term by zero"; throw error; }

        List<T> tmp;
        Node* p = pFirst;

        for (size_t i = 0; i <= sz; p = p->next) {
            T mon(p->value.Get_coeff(), p->value.Get_degree());
            mon.ex(x);
            tmp.PushBack(mon);
            i++;
        }
        return tmp;
    }

    List operator+(const List& list) {

        int flag = -1;
        List<T> tmp;
        Node* p1 = this->pFirst;
        Node* p2 = list.pFirst;

        while (p1 != nullptr && p2 != nullptr) {

            if (p1->value.Get_degree() < p2->value.Get_degree()) {
                tmp.PushBack(p1->value);
                p1 = p1->next;
                flag++;
            }

            else if (p1->value.Get_degree() > p2->value.Get_degree()) {
                tmp.PushBack(p2->value);
                p2 = p2->next;
                flag++;
            }

            else {
                if (p1->value.Get_coeff() + p2->value.Get_coeff() > E || p1->value.Get_coeff() + p2->value.Get_coeff() < -E) {
                    T mon(p1->value.Get_coeff(), p1->value.Get_degree());
                    mon.sum_coeff(p1->value.Get_coeff(), p2->value.Get_coeff());
                    tmp.PushBack(mon);
                    flag++;

                }

                p1 = p1->next;
                p2 = p2->next;
            }
        }

        while (p2 != nullptr) {
            tmp.PushBack(p2->value);
            p2 = p2->next;
            flag++;
        }

        while (p1 != nullptr) {
            tmp.PushBack(p1->value);
            p1 = p1->next;
            flag++;
        }

        if (flag == -1) { string error = "Addition (subtraction) of polynomials with the same degrees and opposite coefficients"; throw error; }
        else { return tmp; }
    }

    List operator-(const List& list) {
        double x = -1.0;
        List<T> tmp1(list);
        List<T> tmp2;

        tmp1 = tmp1 * x;
        tmp2 = *this + tmp1;

        return tmp2;
    }

    List operator*(const List& list) {

        if (list.sz == -1) {
            string error;
            error = "Trying to multiply by an empty polynomial";
            throw error;
        }

        List<T> res;

        Node* p1 = this->pFirst;

        while (p1 != nullptr) {
            Node* p2 = list.pFirst;
            List<T> tmp;

            while (p2 != nullptr) {
                if (p1->value.Get_degree() / 100 + p2->value.Get_degree() / 100 > 9) {
                    string error = "Exceeding the possible degree of X"; throw error;
                }
                else if (p1->value.Get_degree() / 10 % 10 + p2->value.Get_degree() / 10 % 10 > 9) {
                    string error = "Exceeding the possible degree of Y"; throw error;
                }
                else if (p1->value.Get_degree() % 10 + p2->value.Get_degree() % 10 > 9) {
                    string error = "Exceeding the possible degree of Z"; throw error;
                }
                else {
                    T mon(p2->value.Get_coeff(), p2->value.Get_degree());
                    mon.ex_monom(p1->value);
                    tmp.PushBack(mon);
                    p2 = p2->next;

                }
            }
            res = res + tmp;
            p1 = p1->next;
        }
        return res;
    }

    ~List() {
        Node* p;
        while (pFirst != nullptr) {
            p = pFirst;
            pFirst = pFirst->next;
            delete p;
        }
    }

};


