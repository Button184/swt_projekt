#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

string playlist = "C:/Users/Admin/Desktop/Code/swt_projekt_playlist/playlist.csv";

typedef struct {
    string artist;
    string songname;
    string genre;
    int duration;
} Lied;


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
