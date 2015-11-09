//=======================================================================================
//              Filename:   countWordsNumbers.cpp
//
//          Beschreibung:   Programmierung mit C++ 1,
//                          Blatt 10 / Aufgabe 4.3,
//                          Wörter und Zahlen in einem Text abzählen.
//
//               Aufgabe:   4.3
//
//      Praktikumsgruppe:   [V-08:30] - Is-VAI-B1A
//                Author:   Tim Pauksch
//      Erstellungsdatum:   08.11.2015
//    Letzte Anpassungen:   08.11.2015
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

   int  maxstring       = 1;           //Puffer bzw. Feldgröße
   int  i               = 0;           //Schleifenzähler und Feldindex
   int  summeAlpha      = 0;           //Summe der Buchstaben
   int  summeDigit      = 0;           //Summe der Ziffern
   int  summeWorte      = 0;           //Summe der Worte
   int  summeZahlen     = 0;           //Summe der Zahlen
   bool wort = false;                  //Zustandsvaiable (Wort: true/false)
   bool zahl = false;                  //Zustandsvaiable (Zahl: true/false)
   char c;                             //Zwischenspeicher für Buchstabe/Zahl
   string datei         = "text.txt";  //Dateiname
   ifstream ifs;                       //Datei-Stream

   //====================================================================================
   // Hauptprogramm
   //====================================================================================

   cout << "***** Wörter und Zahlen in einem Text abzählen *****\n" << endl;

   //Öffnen der Datei
   ifs.open(datei.c_str());

   //Verhindert, dass Leerzeichen ignoriert werden
   ifs >> noskipws;

   //Prüfung ob Datei geöffnet werden kann
   if (!ifs) {
      cerr << "\nERROR : Failed to open input file daten.txt." << endl;
      exit(1);
   } else {
      maxstring++;
   }

   //Ausloten der Puffergröße
   while (ifs >> c) {
      maxstring++;
   }

   //Puffervariable erstellen
   maxstring++;
   char text[maxstring];

   //Zurücksetzen der Zeigerposition
   ifs.close();
   ifs.open(datei.c_str());

   //Text einlesen
   while (i < maxstring && ((text[i] = ifs.get()) != EOF)) {
      i++;
   }
   text[i] = '\0';
   ifs.close();

   //Prüfung der einzelnen Zeichen
   for (i = 0; text[i] != '\0'; i++) {
      if (isalpha(text[i])) {
         summeAlpha++;

         //Prüfung ob sich der Buchstabe in einem Wort befindet
         if (wort == false && isalpha(text[i])) {
            summeWorte++;
         }

         //Prüfung ob sich der Buchstabe in einer Zahl befindet
         if (zahl == true && isalpha(text[i])) {
            cout << "Fehler. Fehlerhaftes Wort.";
            exit(1);
         }

         //Setzen des Zustands für ein Wort
         wort = true;

      } else if (isdigit(text[i])) {
         summeDigit++;

         //Prüfung ob sich die Ziffer in einer Zahl befindet
         if (zahl == false && isdigit(text[i])) {
            summeZahlen++;
         }

         //Prüfung ob sich die Ziffer in einem Wort befindet
         if (wort == true && isdigit(text[i])) {
            cout << "Fehler. Fehlerhafte Zahl.";
            exit(1);
         }

         //Setzen des Zustands für eine Zahl
         zahl = true;
      } else {
         //Setzen des Zustands für übrige Zeichen
         wort = false;
         zahl = false;
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
