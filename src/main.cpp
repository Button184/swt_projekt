#include <iostream>
#include <filesystem>
#include <string>
#include <sstream>
#include <vector>
#include <fstream> //datei einlesen
#include <iomanip> //formatierten Tabelle der Playlist hier: setw


#include "BibliothekEinlesen.hpp"
#include "LiedHinzufuegen.hpp"
#include "LiedLoeschen.hpp"
#include "BibliothekAnzeigen.hpp"
#include "BibliothekSpeichern.hpp"
#include "DatenAendern.hpp"

using namespace std;

typedef struct {
    string artist;
    string songname;
    string genre;
    int duration;
} Lied;

string playlist = "C:/Users/Admin/Desktop/Code/swt_projekt/playlist.csv";

int main() {

    int auswahl;

    do {
        cout<<"**************************"<<endl;
        cout<<"Willkommen im Music Player"<<endl;
        cout<<"**************************"<<endl;
        cout<<"1. Bibliothek einlesen"<<endl;
        cout<<"2. Ein Lied hinzufuegen"<<endl;
        cout<<"3. Ein Lied aus Playlist entfernen"<<endl;
        cout<<"4. Bibliothek anzeigen lassen"<<endl;
        cout<<"5. Bibliothek speichern"<<endl;
        cout<<"6. Liedinformationen aendern"<<endl;
        cout<<"7. Programm beenden"<<endl;

    cout << "Wähle eine Aktion aus (1-7):";
    cin >> auswahl;

        switch(auswahl) {
            case 1: {
                BibliothekEinlesen(playlist);
                break; }
            case 2: {
                LiedHinzufuegen(playlist);
                break; }
            case 3:
                LiedLoeschen(playlist);
                break;
            case 4:
                BibliothekAnzeigen(playlist);
                break;
            case 5:
                BibliothekSpeichern(playlist);
                break;
            case 6:
                SongDataAendern();
                break;
            case 7:
                cout<<"Programm wird beendet. Bis zum nächsten Mal! :)";
                break;

            default:
            cout<<"Falsche Eingabe! Wähle eine Auswahl von 1-7."<<endl;
        }

    }   while(auswahl !=7);

    return 0;
}
