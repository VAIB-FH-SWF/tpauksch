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
#include <ctime>


using namespace std;

//=============================================================================
// Funktionen
//=============================================================================

// Funktion zum befuellen eines Feldes mit Zufallszahlen
void initField(double field[], double fieldRange, int randomRange){
   srand(time(NULL));
   for (int i = 0; i < fieldRange; ++i) {
      field[i] = rand() % randomRange;
   }
}

// Funktion zur Ermittlung des arythmetischen Mittelwertes
double returnAverageValue(double field[], double fieldRange){
   double averageValue = 0;

   for (int i = 0; i < fieldRange; ++i) {
      averageValue += field[i];
   }
   averageValue = averageValue / fieldRange;

   return averageValue;
}

// Funktion zur Wiedergabe des kleinsten Wertes im Feld
double returnMinimum(double field[], double fieldRange, int randomRange){
   double minValue = randomRange + 1;
   for (int i = 0; i < fieldRange; ++i) {
      if (field[i] < minValue) {
         minValue = field[i];
      }
   }
   return minValue;
}

// Funktion zur Wiedergabe des größten Wertes im Feld
double returnMaximum(double field[], double fieldRange, int randomRange){
   double maxValue = -1;
   for (int i = 0; i < fieldRange; ++i) {
      if (field[i] > maxValue) {
         maxValue = field[i];
      }
   }
   return maxValue;
}

int main() {

   //=============================================================================
   // Variablendeclaration
   //=============================================================================

   int      fieldRange      =   100;                // Feldlaenge
   int      counter         =   0;                  // Hilfsvariable fuer Zwischenausgabe
   int      randomRange     =   51;                 // Grenze fuer Zufallszahlen
   int      minValue        =   0;                  // Kleinste generierte Zufallszahl
   int      maxValue        =   0;                  // Groeßte generierte Zufallszahl
   double   averageValue    =   0;                  // Arythetischer Mittelwert des Felds
   double   a[fieldRange];                          // Feld für die Aufnahme von Zufallszahlen


   //=============================================================================
   // Hauptprogramm
   //=============================================================================

   // Befuellen des Felds mit Zufallszahlen
   initField(a, fieldRange, randomRange);

   // Rueckgabe des minimalen Wertes aus dem Feld
   minValue = returnMinimum(a, fieldRange, randomRange);

   // Rueckgabe des maximalen Wertes aus dem Feld
   maxValue = returnMaximum(a, fieldRange, randomRange);

   // Rueckgabe des Durschnittswertes
   averageValue = returnAverageValue(a, fieldRange);

   //=============================================================================
   // Ausgabe
   //=============================================================================

   // Ausgabe des Felds mit 10 Werten pro Zeile
   cout << "Ausgabe eines mit Zufallszahlen gefüllten Feldes: " << endl;
   for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
         cout << setw(2) << setfill('0') << a[counter] << ' ';
         counter++;
      }
      cout << endl;
   }

   //Ausgabe des arythmetischen Mittelwertes
   cout << endl;
   cout << "Arythmetisches Mittel: " << averageValue << endl;

   //Ausgabe des Min- und Max-Wertes
   cout << endl;
   cout << "Kleinster Feld-Wert: " << minValue << endl;
   cout << "Größter Feld-Wert: " << maxValue << endl;


   return 0;
}
