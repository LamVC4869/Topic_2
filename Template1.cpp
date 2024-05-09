#include <iostream>

using namespace std;

template<typename T>
T Max(T digit1, T digit2, T digit3) {
    T max = digit1;
    if (digit2 > max) max = digit2;
    if (digit3 > max) max = digit3;
    return max;
}

struct PhanSo {
    int on, un;
    friend istream& operator>> (istream &is, PhanSo &p) {
        is >> p.on >> p.un;
        return is;
    }
    friend ostream& operator<< (ostream &os, PhanSo p) {
        os << p.on << '/' << p.un;
        return os;
    }
    friend bool operator > (PhanSo p1, PhanSo p2) {
        return p1.on / p1.un > p2.on / p2.un;
    }
};

int main () {
    char c; cin >> c;
    switch (c) {
        case 'a':
        int a, b, c; cin >> a >> b >> c;
        cout << Max (a, b, c); break;
        case 'b':
        double x, y, z; cin >> x >> y >> z;
        cout << Max (x, y, z); break;
        case 'c':
        PhanSo arr[3];
        for (PhanSo &p : arr) cin >> p;
        cout << Max (arr[0], arr[1], arr[2]);
    }
    return 0;
}
