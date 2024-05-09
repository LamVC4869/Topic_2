#include <iostream>

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
    bool operator < (PhanSo p2) {
        return this->tu * p2.mau < p2.tu * this->mau;
    }
};

template<typename t>
struct Arr {
    int size = 0;
    t arr[100010];
    void in () {
        t c;
        cin >> c; 
        this->arr[this->size++] = c;
    }
    void Min () {
        if (this->size == 0) cout << "khong co" << endl;
        else {
            t min = arr[0];
            for (int i = 1; i < this->size; i++) if (this->arr[i] < min) min = this->arr[i];
            cout << min << endl;
        }
    }
};

int main () {
    char kt;
    Arr<int> a;
    Arr<double> b;
    Arr<PhanSo> c;
    while (cin >> kt) {
        if (kt == 'a') a.in ();
        if (kt == 'b') b.in ();
        if (kt == 'c') c.in ();
    }
    a.Min ();
    b.Min ();
    c.Min ();
    return 0;
}
