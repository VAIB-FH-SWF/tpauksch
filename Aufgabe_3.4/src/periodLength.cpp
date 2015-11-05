//=============================================================================
//              Filename:   periodLength.cpp
//
//          Beschreibung:   Programmierung mit C++ 1,
//                          Blatt 8 / Aufgabe 3.4,
//                          Periodenlaenge von Pseudozahlen.
//
//              Aufgabe:    3.4
//
//      Praktikumsgruppe:   [V-08:30] - Is-VAI-B1A
//                Author:   Tim Pauksch
//      Erstellungsdatum:   26.10.2015
//    Letzte Anpassungen:   05.11.2015
//
//               Version:   1.0
//              Compiler:   g++
//=============================================================================

#include <iostream>

using namespace std;

int main() {

   //=============================================================================
   // Variablendeclaration
   //=============================================================================

   int a        =   16333;      // Faktor fuer vorangegangenen Zufallswert
   int b        =   25887;      // Verschiebung
   int m        =   256*128;    // Anzahl der Moeglichen Zufallszahlen
   int x        =   0;          // Initalwert
   int x2       =   0;          // Zufallswert an Position i
   int counter  =   0;          // Counter fuer Periodenlaenge
   //=============================================================================
   // Hauptprogramm
   //=============================================================================

   cout << "Aufgabe: Reriodenlänge von Pseudozahlen:" << endl;
   cout << endl;

   // Generierung der Zufallszahlen
   do {
      x2 = (a*x+b) % m;
      x  = x2;
      counter++;
   } while(x != 0);

   //=============================================================================
   // Ausgabe
   //=============================================================================

   cout << "Die Periodenlaenge der Gleichung mit den Parametern..." << endl;
   cout << "a = " << a << endl;
   cout << "b = " << b << endl;
   cout << "m = " << m << endl;
   cout << "beträgt: " << counter << endl;
   cout << endl;
   cout << "Programm beendet." << endl;

}
