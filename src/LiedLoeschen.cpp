


/*
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
