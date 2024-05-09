#include <iostream>
#include <vector>

using namespace std;

struct PhanSo {
    int on, un;
    friend istream& operator>> (istream &is, PhanSo &p) {
        is >> p.on >> p.un;
        return is;
    }
    static int gcd (const PhanSo &p) {
        int x = p.on, y = p.un;
        while (y) {
            int tmp = x % y;
            x = y;
            y = tmp;
        }
        return x;
    }
    friend ostream& operator<< (ostream &os, PhanSo &p) {
        int ucln = gcd (p);
        os << p.on / ucln << '/' << p.un / ucln;
        return os;
    }
    friend PhanSo operator+ (PhanSo p1, PhanSo p2) {
        PhanSo p3;
        p3.on = p1.on * p2.un + p1.un * p2.on;
        p3.un = p1.un * p2.un;
        return p3;
    }
};

template <typename t>
struct Arr {
    int size;
    t arr[1000];
    t in () {
        this->size = 0;
        t i;
        while (cin >> i) this->arr[this->size++] = i; 
    }
    t sum () {
        t result = arr[0];
        for (int i = 1; i < size; i++) result = result + arr[i] ;
        cout << result;
    }
};

int main () {
    char c; cin >> c;
    switch (c) {
        case 'a':
        Arr<int> a;
        a.in ();
        a.sum (); break;
        case 'b':
        Arr<PhanSo> b;
        b.in ();
        b.sum ();
    }
    return 0;
}
