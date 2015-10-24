//=============================================================================
//              Filename:   RandomFeld.cpp
//
//          Beschreibung:   Programmierung mit C++ 1,
//                          Blatt 7 / Aufgabe 3.1,
//                          Feld mit Zufallszahlen belegen.
//
//              Aufgabe:    3.1
//
//      Praktikumsgruppe:   [V-08:30] - Is-VAI-B1A
//                Author:   Tim Pauksch
//      Erstellungsdatum:   24.10.2015
//    Letzte Anpassungen:   24.10.2015
//
//               Version:   1.0
//              Compiler:   g++
//=============================================================================

#include <iostream>
#include <cstdlib>
#include <iomanip>
//#include <cmath>


using namespace std;

int main() {

   //=============================================================================
   // Variablendeclaration
   //=============================================================================

   int      fieldRange      =   100;                // Feldlaenge
   int      counter         =   0;                  // Hilfsvariable fuer Zwischenausgabe
   int      randomRange     =   51;                 // Grenze fuer Zufallszahlen
   int      minValue        =   randomRange + 1;    // Kleinste generierte Zufallszahl
   int      maxValue        =   -1;                  // Groeßte generierte Zufallszahl
   double   a[fieldRange];                          // Feld für die Aufnahme von Zufallszahlen


   //=============================================================================
   // Hauptprogramm
   //=============================================================================

   // Befuellen des Felds mit Zufallszahlen
   for (int i = 0; i < fieldRange; ++i) {
      a[i] = rand() % randomRange;
   }

   // Zwischenausgabe mit 10 Werten pro Zeile
   for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
         cout << setw(2) << setfill('0') << a[counter] << ' ';
         counter++;
      }
      cout << endl;
   }

   // Pruefung aller Arraywerte auf Min- und Max-Wert
   for (int i = 0; i < fieldRange; ++i) {
      if (a[i] < minValue) {
         minValue = a[i];
      } else if (a[i] > maxValue) {
         maxValue = a[i];
      }
   }

   //Ausgabe des Min- und Max-Wertes
   cout << endl;
   cout << "Kleinster Feld-Wert: " << minValue << endl;
   cout << "Größter Feld-Wert: " << maxValue << endl;


   return 0;
}
