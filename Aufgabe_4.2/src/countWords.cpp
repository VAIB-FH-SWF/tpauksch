//=======================================================================================
//              Filename:   countWords.cpp
//
//          Beschreibung:   Programmierung mit C++ 1,
//                          Blatt 9 / Aufgabe 4.2,
//                          Wörter in einem Text abzählen.
//
//              Aufgabe:    4.2
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

using namespace std;

int main() {

   //====================================================================================
   // Variablendeclaration
   //====================================================================================

   int maxstring  = 256;    //Puffer bzw. Feldgroeße
   int i          = 0;      //Schleifenzaehler und Feldindex
   int summeAlpha = 0;      //Summe der Buchstaben
   int summeDigit = 0;      //Summe der Zahlen
   int summeWorte = 0;      //Summe der Worte
   bool zustand = false;    //Zustandsvaiable (Wort: true/false)
   char text[maxstring];    //Feld fuer die Aufnahme der Buchstaben/Ziffern
   char c;                  //Zwischenspeicher fuer Buchstabe/Zahl

   //====================================================================================
   // Hauptprogramm
   //====================================================================================

   cout << "***** Buchstaben und Zahlen abzählen *****\n" << endl;
   cout << "Geben Sie eine Textzeile mit Zahlen ein: ";

   while ((c = cin.get()) != '\n') {                //Einzelzeichen lesen
      text[i] = c;                                  //und im Feld ablegen
      i++;                                          //Schleifenzaehler erhoehen
   }
   text[i] = '\0';                                  //Zeichenkette abschließen

   for (i = 0; text[i] != '\0'; i++) {
      if (isalpha(text[i])) {                        //Pruefung auf Buchstabe
         summeAlpha++;

         //Pruefung ob sich der Buchstabe in einem Wort befindet
         if (zustand == false && isalpha(text[i])) {
            summeWorte++;
         }

         zustand = true;                            //Zustand setzen

      } else if (isdigit(text[i])) {                //Pruefung auf Zahl
         summeDigit++;
      } else {
         zustand = false;                           //Zustand 'false' bei Leerzeichen
      }
   }

   //====================================================================================
   // Ausgabe
   //====================================================================================
   cout << "Der eingegebene Text lautet: '" << text << "'" << endl;
   cout << setw(6) << summeAlpha << " Buchstaben" << endl;
   cout << setw(6) << summeWorte << " Worte" << endl;
   cout << setw(6) << summeDigit << " Zahlen" << endl;
   cout << "Programm beendet." << endl;

   return 0;
}
