//=============================================================================
//              Filename:   countToken.cpp
//
//          Beschreibung:   Programmierung mit C++ 1,
//                          Blatt 9 / Aufgabe 4.1,
//                          Buchstaben und Ziffern in einem Text abz�hlen.
//
//              Aufgabe:    4.1
//
//      Praktikumsgruppe:   [V-08:30] - Is-VAI-B1A
//                Author:   Tim Pauksch
//      Erstellungsdatum:   07.11.2015
//    Letzte Anpassungen:   09.11.2015
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

   int  maxstring         = 256;    //Puffer bzw. Feldgroe�e
   int  i                 = 0;      //Schleifenz�hler und Feldindex
   int  summeAlpha        = 0;      //Summe der Buchstaben
   int  summeDigit        = 0;      //Summe der Ziffern
   char text[maxstring];            //Feld f�r die Aufnahme der Buchstaben/Ziffern
   char c;                          //Zwischenspeicher f�r Buchstabe/Ziffer

   //=============================================================================
   // Hauptprogramm
   //=============================================================================

   cout << "***** Buchstaben und Ziffern in einem Text abz�hlen *****\n" << endl;
   cout << "Geben Sie eine Textzeile mit Ziffern ein: ";

   while ((c = cin.get()) != '\n') {       //Einzelzeichen lesen
      text[i] = c;                         //und im Feld ablegen
      i++;                                 //Schleifenz�hler erh�hen
   }
   text[i] = '\0';                         //Zeichenkette abschlie�en

   for (i = 0; text[i] != '\0'; i++) {
      if (isalpha(text[i]))                //Pr�fung auf Buchstabe
         summeAlpha++;
      if (isdigit(text[i]))                //Pr�fung auf Ziffer
         summeDigit++;
   }

   //=============================================================================
   // Ausgabe
   //=============================================================================

   cout << "Der eingegebene Text lautet: '" << text << "'" << endl;
   cout << setw(6) << summeAlpha << " Buchstaben" << endl;
   cout << setw(6) << summeDigit << " Ziffern" << endl;
   cout << "Programm beendet." << endl;

   return 0;
}
