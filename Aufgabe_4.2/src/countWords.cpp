//=======================================================================================
//              Filename:   countWords.cpp
//
//          Beschreibung:   Programmierung mit C++ 1,
//                          Blatt 9 / Aufgabe 4.2,
//                          W�rter in einem Text abz�hlen.
//
//              Aufgabe:    4.2
//
//      Praktikumsgruppe:   [V-08:30] - Is-VAI-B1A
//                Author:   Tim Pauksch
//      Erstellungsdatum:   08.11.2015
//    Letzte Anpassungen:   09.11.2015
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

   int  maxstring        = 256;    //Puffer bzw. Feldgr��e
   int  i                = 0;      //Schleifenz�hler und Feldindex
   int  summeAlpha       = 0;      //Summe der Buchstaben
   int  summeDigit       = 0;      //Summe der Ziffern
   int  summeWorte       = 0;      //Summe der Worte
   bool zustand = false;           //Zustandsvaiable (Wort: true/false)
   char text[maxstring];           //Feld f�r die Aufnahme der Buchstaben/Ziffern
   char c;                         //Zwischenspeicher f�r Buchstabe/Ziffer

   //====================================================================================
   // Hauptprogramm
   //====================================================================================

   cout << "***** W�rter in einem Text abz�hlen *****\n" << endl;
   cout << "Geben Sie eine Textzeile ein: ";

   while ((c = cin.get()) != '\n') {                //Einzelzeichen lesen
      text[i] = c;                                  //und im Feld ablegen
      i++;                                          //Schleifenzaehler erh�hen
   }
   text[i] = '\0';                                  //Zeichenkette abschlie�en

   for (i = 0; text[i] != '\0'; i++) {
      if (isalpha(text[i])) {                       //Pr�fung auf Buchstabe
         summeAlpha++;

         //Pr�fung ob sich der Buchstabe in einem Wort befindet
         if (zustand == false && isalpha(text[i])) {
            summeWorte++;
         }

         zustand = true;                            //Zustand setzen

      } else if (isdigit(text[i])) {                //Pr�fung auf Ziffer
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
   cout << setw(6) << summeDigit << " Ziffern" << endl;
   cout << "Programm beendet." << endl;

   return 0;
}
