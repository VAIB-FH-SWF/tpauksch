//=======================================================================================
//              Filename:   countWordsNumbers.cpp
//
//          Beschreibung:   Programmierung mit C++ 1,
//                          Blatt 10 / Aufgabe 4.3,
//                          W�rter und Zahlen in einem Text abz�hlen.
//
//               Aufgabe:   4.3
//
//      Praktikumsgruppe:   [V-08:30] - Is-VAI-B1A
//                Author:   Tim Pauksch
//      Erstellungsdatum:   08.11.2015
//    Letzte Anpassungen:   19.11.2015
//
//               Version:   1.0
//              Compiler:   g++
//=======================================================================================

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

int main() {

   //====================================================================================
   // Variablendeclaration
   //====================================================================================

   int  maxstring       = 1;           //Puffer bzw. Feldgr��e
   int  i               = 0;           //Schleifenz�hler und Feldindex
   int  summeAlpha      = 0;           //Summe der Buchstaben
   int  summeDigit      = 0;           //Summe der Ziffern
   int  summeWorte      = 0;           //Summe der Worte
   int  summeZahlen     = 0;           //Summe der Zahlen
   int  zustand         = 0;           //Zustandsvaiable (Sonstiges:0, Wort:1, Zahl:2)
   char c;                             //Zwischenspeicher f�r Buchstabe/Zahl
   string datei         = "text.txt";  //Dateiname
   ifstream ifs;                       //Datei-Stream

   //====================================================================================
   // Hauptprogramm
   //====================================================================================

   cout << "***** W�rter und Zahlen in einem Text abz�hlen *****\n" << endl;

   //�ffnen der Datei
   ifs.open(datei.c_str());

   //Verhindert, dass Leerzeichen ignoriert werden
   ifs >> noskipws;

   //Pr�fung ob Datei ge�ffnet werden kann
   if (!ifs) {
      cerr << "\nERROR : Failed to open input file daten.txt." << endl;
      exit(1);
   } else {
      maxstring++;
   }

   //Ausloten der Puffergr��e
   while (ifs >> c) {
      maxstring++;
   }

   //Puffervariable erstellen
   maxstring++;
   char text[maxstring];

   //Zur�cksetzen der Zeigerposition
   ifs.close();
   ifs.open(datei.c_str());

   //Text einlesen
   while (i < maxstring && ((text[i] = ifs.get()) != EOF)) {
      i++;
   }
   text[i] = '\0';
   ifs.close();

   //Pr�fung der einzelnen Zeichen
   for (i = 0; text[i] != '\0'; i++) {
      if (isalpha(text[i])) {

         //Pr�fung ob sich der Buchstabe in einem Wort befindet
         if (zustand == 0) {
            summeWorte++;
         }

         //Pr�fung ob sich der Buchstabe in einer Zahl befindet
         if (zustand == 2) {
            cout << "Fehler. Fehlerhaftes Wort.";
            exit(1);
         }

         //Setzen des Zustands f�r ein Wort
         zustand = 1;
         summeAlpha++;

      } else if (isdigit(text[i])) {

         //Pr�fung ob sich die Ziffer in einer Zahl befindet
         if (zustand == 0) {
            summeZahlen++;
         }

         //Pr�fung ob sich die Ziffer in einem Wort befindet
         if (zustand == 1) {
            cout << "Fehler. Fehlerhafte Zahl.";
            exit(1);
         }

         //Setzen des Zustands f�r eine Zahl
         zustand = 2;
         summeDigit++;
      } else {

         //Setzen des Zustands f�r �brige Zeichen
         zustand = 0;
      }
   }

   //====================================================================================
   // Ausgabe
   //====================================================================================
   cout << "Der eingegebene Text lautet: \n" << endl;
   cout << text << "\n" << endl;
   cout << "Anzahl der Elemente:" << endl;
   cout << setw(6) << summeAlpha << " Buchstaben" << endl;
   cout << setw(6) << summeWorte << " Worte" << endl;
   cout << setw(6) << summeDigit << " Ziffern" << endl;
   cout << setw(6) << summeZahlen << " Zahlen" << endl;
   cout << "Programm beendet." << endl;

   return 0;
}
