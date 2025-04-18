#include "BibliothekAnzeigen.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
/*
struct Lied {
    string artist;
    string songname;
    string genre;
    int duration;
};*/

void BibliothekAnzeigen(const string playlist) {
    ifstream datei(playlist);

    if (!datei.is_open()) {
        cerr << "!!Datei konnte nicht geoeffnet werden!!" << playlist << endl;
        return;
    }

    string line;
    while (getline(datei, line)) {
        stringstream ss(line);
        string feld;
        while (getline(ss, feld, ';')) {
            cout << feld << " ";
        }
        cout << endl;
    }
    datei.close();
    cout << "Bibliothek erfolgreich angezeigt!" << endl; // debug ausgabe
}
