#include <iostream>
#include "MetodyPomocnicze.h"

using namespace std;

string MetodyPomocnicze::konwerjsaIntNaString(int liczba){
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

bool MetodyPomocnicze::czyPlikJestPusty(fstream &plikTekstowy){
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}
