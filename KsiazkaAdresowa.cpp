#include "KsiazkaAdresowa.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>

using namespace std;

void KsiazkaAdresowa::rejestracjaUzytkownika(){
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}
