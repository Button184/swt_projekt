#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream> //datei einlesen
#include <iomanip> //formatierten Tabelle der Playlist hier: setw
#include "BibliothekEinlesen.h"
#include "LiedHinzufuegen.h"
#include "LiedLoeschen.h"
#include "BibliothekAnzeigen.h"
#include "BibliothekSpeichern.h"
#include "MetaDatenAendern.h"

using namespace std;

    void BibliothekEinlesen();
    void LiedHinzufuegen();
    void LiedLoeschen();
    void BibliothekAnzeigen();
    void BibliothekSpeichern();
    void SongDataAendern();


typedef struct {
    string artist;
    string songname;
    string genre;
    int duration;
} Lied;

string playlist = "C:/Users/Admin/Desktop/Code/VSC/swt_projekt_playlist/playlist.csv";

void BibliothekEinlesen(const string playlist) {

    //vektor "lieder" wird deklariert und speichert Lied-Objekte
    vector<Lied> lieder;
    ifstream datei(playlist);


    if(!datei.is_open()) {
        cerr << "!!Datei konnte nicht geoeffnet werden!!" <<endl;
        return;
    }
    string line;
    getline(datei,line);

    while(getline(datei,line)){

        stringstream stream(line);

        //Songstruktur mit hilfsvariabel fuer dauer des einzelnen Lieds
        Lied lied;
        string duration_string;


        getline(stream, lied.artist, ';');
        getline(stream, lied.songname, ';');
        getline(stream, lied.genre, ';');
        getline(stream, duration_string, ';');
        lied.duration = stoi(duration_string); //konvert string to integer
        lieder.push_back(lied); //fuegt integer zeile fuer zeile hinzu
        }
    datei.close();

    const int widthArtist = 30;
    const int widthSong = 40;
    const int widthGenre = 30;
    const int widthDuration = 20;

    cout <<left  //linksbuendig
    <<setw(widthArtist) << "Kuenstler"
    <<setw(widthSong) << "Titel"
    <<setw(widthGenre) << "Genre"
    <<setw(widthDuration) << "Dauer (sek)"
    <<endl;

    cout << string(widthArtist+widthSong+widthGenre+widthDuration,'-')<<endl;

    //ausgabe der tabellierung
    for(const auto& lied :lieder) {
        cout << left
        <<setw(widthArtist) << lied.artist
        <<setw(widthSong) << lied.songname
        <<setw(widthGenre) << lied.genre
        <<setw(widthDuration) << lied.duration
        <<endl;
        }

    }

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

    }

    void LiedLoeschen(const string playlist) {
        string titel;

        cout<<"Gebe den Songtitel ein, um das entsprechende Lied zu löschen.\n";
        cin.ignore();
        getline(cin, titel);

        ifstream datei(playlist);

        if(!datei.is_open()) {
            cerr << "!!Datei konnte nicht geoeffnet werden!!" <<endl;
            return;
        }

        vector<string>lines;
        string line;
        bool found = false;

        while(getline(datei, line)) {
            size_t pos = line.find(titel);
            if(pos !=string::npos) {
                cout<<line<< "Wird erntfernt..." <<endl;
                found = true; continue;
            }
            lines.push_back(line);

        }
        datei.close();

        ofstream datei_neu(playlist, ios::trunc);
        if (!datei_neu.is_open()) {
            cerr <<"!!Datei konnte nicht erstellt werden!!"<< endl;
            return;
        }
        for(const auto& l : lines) {
            datei_neu << l << endl;
        }
        datei_neu.close();
        cout<<"**Lied erfolgreich entfernt!**"<<endl;

    }

    void BibliothekAnzeigen(const string playlist) {
        cout<<"function not yet build"<<endl;

    }

    void BibliothekSpeichern() {
        cout<<"function not yet build"<<endl;

    }

    void SongDataAendern() {
        cout<<"function not yet build"<<endl;

    }

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
                BibliothekSpeichern();
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
