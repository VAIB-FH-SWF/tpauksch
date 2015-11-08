//=============================================================================
//              Filename:   countToken.cpp
//
//          Beschreibung:   Programmierung mit C++ 1,
//                          Blatt 9 / Aufgabe 4.1,
//                          Buchstaben und Ziffern in einem Text abzeahlen.
//
//              Aufgabe:    4.1
//
//      Praktikumsgruppe:   [V-08:30] - Is-VAI-B1A
//                Author:   Tim Pauksch
//      Erstellungsdatum:   07.11.2015
//    Letzte Anpassungen:   07.11.2015
//
//               Version:   1.0
//              Compiler:   g++
//=============================================================================

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

   //=============================================================================
   // Variablendeclaration
   //=============================================================================

   int maxstring = 256;     //Puffer bzw. Feldgroeﬂe
   int i = 0;               //Schleifenzaehler und Feldindex
   int summeAlpha = 0;      //Summe der Buchstaben
   int summeDigit = 0;      //Summe der Zahlen
   char text[maxstring];    //Feld fuer die Aufnahme der Buchstaben/Ziffern
   char c;                  //Zwischenspeicher fuer Buchstabe/Zahl

   //=============================================================================
   // Hauptprogramm
   //=============================================================================

   cout << "***** Buchstaben und Zahlen abz‰hlen *****\n" << endl;
   cout << "Geben Sie eine Textzeile mit Zahlen ein: ";

   while ((c = cin.get()) != '\n') {       //Einzelzeichen lesen
      text[i] = c;                         //und im Feld ablegen
      i++;                                 //Schleifenzaehler erhoehen
   }
   text[i] = '\0';                         //Zeichenkette abschlieﬂen

   for (i = 0; text[i] != '\0'; i++) {
      if (isalpha(text[i]))                //Pruefung auf Buchstabe
         summeAlpha++;
      if (isdigit(text[i]))                //Pruefung auf Zahl
         summeDigit++;
   }

   //=============================================================================
   // Ausgabe
   //=============================================================================

   cout << "Der eingegebene Text lautet: '" << text << "'" << endl;
   cout << setw(6) << summeAlpha << " Buchstaben" << endl;
   cout << setw(6) << summeDigit << " Zahlen" << endl;
   cout << "Programm beendet." << endl;

   return 0;
}
