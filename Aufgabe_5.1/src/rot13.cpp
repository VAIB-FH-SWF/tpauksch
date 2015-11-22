//=============================================================================
//              Filename:   rot13.cpp
//
//          Beschreibung:   Programmierung mit C++ 1,
//                          Blatt 11 / Aufgabe 5.1,
//                          Die Verschiebechiffre ROT13.
//
//              Aufgabe:    5.1
//
//      Praktikumsgruppe:   [V-08:30] - Is-VAI-B1A
//                Author:   Tim Pauksch
//      Erstellungsdatum:   22.11.2015
//    Letzte Anpassungen:   22.11.2015
//
//               Version:   1.0
//              Compiler:   g++
//=============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {

   //=============================================================================
   // Variablendeklaration
   //=============================================================================

   char rot13[] = {                         //Schlüsselfeld
         'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
         'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
   };
   char     c;                              //Zeichenpuffer
   ifstream ifs;                            //Eingabestrom
   ofstream ofs;                            //Ausgabestrom
   string   decryptFile   = "klar.txt";     //Eingabedatei (nicht chiffriert)
   string   encryptFile   = "geheim.txt";   //Ausgabedatei (chiffriert)

   //=============================================================================
   // Hauptprogramm
   //=============================================================================

   ifs.open(decryptFile.c_str());           //Öffnen der Datei für die Eingabe.
   ofs.open(encryptFile.c_str());           //Öffnen der Datei für die Ausgabe.

   if (!ifs.is_open()) {                    //Kontrolle ob Datei geöffnet wurde.
      cerr << "\nERROR : Failed to open input file klar.txt." << endl;
      exit(1);
   }

   if (!ofs.is_open()) {                    //Kontrolle ob Datei geöffnet wurde.
      cerr << "\nERROR : Failed to open output file geheim.txt." << endl;
      exit(1);
   }

   cout << "***** Verschiebechiffre ROT13. *****\n" << endl;

   while ((c = ifs.get()) != EOF) {         //Schrittweises einlesen der Zeichen aus der Eingabe.
      if (isupper(c)){                      //Prüfung des Zeichen nach Ziffer.
         ofs << rot13[(c-'A')];             //Ausgabe des ROT13-Zeichen. Index = Char-Wert aus Eingabe
      } else {                              //abzüglich des ASCII-Wertes für 'A'.
         ofs << c;                          //Ausgabe ohne Chiffrierung.
      }
   }

   //=============================================================================
   // Ausgabe
   //=============================================================================

   cout << "Die Datei '" << decryptFile << "' wurde chiffriert." << endl;
   cout << "Ausgabe Datei: " << encryptFile << endl;

   ifs.close();                             //Schließen des Eingabestroms.
   ofs.close();                             //Schließen des Ausgabestroms.
   return 0;
}
