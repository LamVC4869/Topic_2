#include <iostream>
#include <vector>

using namespace std;

struct PhanSo {
    int tu, mau;
    friend istream& operator>> (istream &is, PhanSo &p) {
        is >> p.tu >> p.mau;
        return is;
    }
    static int gcd (PhanSo p) {
        int x = p.tu, y = p.mau;
        while (y) {
            int t = x % y;
            x = y;
            y = t;
        }
        return x;
    }
    friend ostream& operator<< (ostream &os, PhanSo p) {
        os << p.tu / gcd (p) << '/' << p.mau / gcd (p);
        return os;
    }
    friend PhanSo operator+ (PhanSo p1, PhanSo p2) {
        PhanSo p3;
        p3.tu = p1.tu * p2.mau + p2.tu * p1.mau;
        p3.mau = p1.mau * p2.mau;
        return p3;
    }
};

template<typename t>
t Tong (vector<t> vt) {
    if (vt.empty ()) cout << "khong co" << endl;
    else {
        t sum = vt[0];
        for (int i = 1; i < vt.size (); i++) sum = sum + vt[i];
        cout << sum << endl;
    }
}

int main () {
    char c[1000];
    int i = 0;
    vector<int> a;
    vector<PhanSo> b;
    while (cin >> c[i]) {
        if (c[i] == 'a') {
            int digit; cin >> digit; a.push_back (digit);
        } else if (c[i] == 'b') {
            PhanSo temp; cin >> temp; b.push_back (temp);
        } i++;
    }
    Tong (a);
    Tong (b);
    return 0;
}
