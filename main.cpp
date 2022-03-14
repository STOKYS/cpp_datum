#include <iostream>
#include <ctime>
#include "datum.hpp"

using std::cout;
using std::endl;
using std::cin;

int main() {
    int d;
    int m;
    int r;
    cout << "Zadej den: ";
    cin >> d;
    cout << "Zadej mesic: ";
    cin >> m;
    cout << "Zadej rok: ";
    cin >> r;
    datum d1(d, m, r);
    cout << "Zadané datum " << d1 << endl;
    cout << "Pocet dni od 1.1.1900 je: " << d1.pocetDni() << endl;
    cout << "Je " << d1.denTyden() << ". den v tydnu" << endl;
    datum d2;
    cout << "Dnes je: " << d2 << endl;
    cout << "Pocet dni od 1.1.1900 je: " << d2.pocetDni() << endl;
    cout << "Je " << d2.denTyden() << ". den v tydnu" << endl;
    datum d3(8, 5, 2004);
    cout << "Dalsi datum " << d3 << endl;
    cout << "Pocet dni od 1.1.1900 je: " << d3.pocetDni() << endl;
    cout << "Je " << d3.denTyden() << ". den v tydnu" << endl;
    return 0;
}