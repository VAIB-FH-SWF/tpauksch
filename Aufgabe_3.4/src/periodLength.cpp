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
//    Letzte Anpassungen:   26.10.2015
//
//               Version:   1.0
//              Compiler:   g++
//=============================================================================

#include <iostream>
#include <cstdlib>
#include <iomanip>


using namespace std;

int main() {

   //=============================================================================
   // Variablendeclaration
   //=============================================================================

   int a        =   16333;      //
   int b        =   25887;      //
   int m        =   256*128;    // Anzahl der Moeglichen Zufallszahlen
   int x        =   0;          //
   int x2       =   0;          //
   int counter  =   0;          // Counter fuer periodenlaenge
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
   cout << "beträgt " << counter << " Zahlen" << endl;
}
