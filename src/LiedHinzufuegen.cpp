#include "BibliothekEinlesen.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


void LiedHinzufuegen(const string& playlist) {

}

/*
void LiedHinzufuegen(const string playlist) {
    //ofstream u zum bearbeiten innerhalb einer datei, ios zum eintragen von integern,
    //app der modus, sodass zu datei hinzugefuegt wird, ohne zu ueberschreiben
    ofstream datei(playlist,ios::app);

    if(!datei.is_open()) {
        cerr << "!!Datei konnte nicht geoeffnet werden!!" <<endl;
        return;
    }

    Lied neuesLied;

    cout<< "Fuege ein Neues Lied hinzu und beachte die Reihenfolge!" <<endl;
    cin.ignore();
    cout<< "Kuenstler: ";
    getline(cin, neuesLied.artist);
    cout<< "Titel: ";
    getline(cin, neuesLied.songname);
    cout<< "Genre: ";
    getline(cin, neuesLied.genre);
    cout<<"Dauer in Sekunden: ";
    cin >>neuesLied.duration;

    datei <<"\n"<<neuesLied.artist <<";"<<neuesLied.songname<<";"<<neuesLied.genre<<";"<<neuesLied.duration<<";";

    datei.close();
    cout<<"**Lied erfolgreich hinzugefuegt!**"<<endl;

} */
