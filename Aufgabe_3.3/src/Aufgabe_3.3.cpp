//=============================================================================
//              Filename:   GenPseudo.cpp
//
//          Beschreibung:   Programmierung mit C++ 1,
//                          Blatt 7 / Aufgabe 3.3,
//                          Erzeugung von Pseudozufallszahlen.
//
//              Aufgabe:    3.3
//
//      Praktikumsgruppe:   [V-08:30] - Is-VAI-B1A
//                Author:   Tim Pauksch
//      Erstellungsdatum:   25.10.2015
//    Letzte Anpassungen:   25.10.2015
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
   int range    =   10;         // Anzahl der Pseudozufallszahlen
   int width    =   6;          // Breite der Zahlen-Ausgabe

   //=============================================================================
   // Hauptprogramm
   //=============================================================================

   cout << range <<" Zufallszahlen:" << endl;

   // Generierung der Zufallszahlen und Ausgabe
   for (int i = 0; i < range ; ++i) {
      x2 = (a*x+b) % m;
      x  = x2;
      cout << setw(width) << x2 << endl;
   }
}
