#include <iostream>
#include "List.cpp"
#include "func.h"
using namespace std;

int main() {
    List<int> a, b;

    int c = 3, n = 6, l = 77, j = 95, zz = 21, mk = 8;

    a.Add(c);
    a.Add(n);
    a.Add(l);
    a.Add(j);
    a.Add(zz);
    a.Add(mk);


    a.ListPrint();
    cout << "\n";
    a.Delete(2);
    a.ListPrint();

    saveBin(a);
    loadBin(b);
    b.ListPrint();
}
