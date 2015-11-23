//=============================================================================
//              Filename:   caesar.cpp
//
//          Beschreibung:   Programmierung mit C++ 1,
//                          Blatt 12 / Aufgabe 5.2,
//                          Caesar-Verschlüsselung.
//
//              Aufgabe:    5.2
//
//      Praktikumsgruppe:   [V-08:30] - Is-VAI-B1A
//                Author:   Tim Pauksch
//      Erstellungsdatum:   22.11.2015
//    Letzte Anpassungen:   23.11.2015
//
//               Version:   1.0
//              Compiler:   g++
//=============================================================================

#include <iostream>
#include <string>

using namespace std;

void feld_wenden(char a[], unsigned int n){
   int  iterations  = n / 2;                //Anzahl symmetrischer Vertauschungen der Feldelemente.
   int  maxIndex    = n - 1;                //Größter Feldindex, abhängig von Feldbreite.
   char leftChar;                           //Linkes Tauschelement, dient als Puffervariable.
   char rightChar;                          //Rechtes Tauschelement.

   for(int i = 0; i < iterations; i++){     //Diese Schleife wechselt symmetrisch die Feldelemente.
      leftChar         = a[i];
      rightChar        = a[maxIndex - i];

      a[i]              = rightChar;
      a[maxIndex - i]   = leftChar;
   }
}

void feld_links_rotieren(char a[], unsigned int n, unsigned int shift){
   //Eingabekontrolle
   if (shift == 0){                         //Ende der Funktion, ohne Shift.
      return;
   }
   shift = shift % n;                       //Verarbeitung von Vielfachen.

   //Deklarationen
   int leftLength   = shift;                //Festlegung der Teilbereiche für
   int rightLength  = n - shift;            //die Rotation (Linker und rechter Teil).

   char leftField[leftLength];              //Definition des linken
   char rightField[rightLength];            //und des rechten Feldes.

   //1. Linken Bereich wenden
   for (int i = 0; i < leftLength; i++){    //Befüllen des linken Feldes.
      leftField[i] = a[i];
   };

   feld_wenden(leftField, leftLength);      //Wenden des linken Feldes.

   for (int i = 0; i < leftLength; i++){    //Zurückschreiben des linken Feldes in Eingabefeld.
      a[i] = leftField[i];
   };

   //2. Gesamtes Feld wenden.
   feld_wenden(a, n);                       //Wenden des Eingabefeldes.

   for (int i = 0; i < rightLength; i++){   //Befüllen des rechten Feldes.
      rightField[i] = a[i];
   };

   //3. Rechten Bereich wenden
   feld_wenden(rightField, rightLength);    //Wenden des rechten Feldes.

   for (int i = 0; i < rightLength; i++){   //Zurückschreiben des rechten Feldes in Eingabefeld.
      a[i] = rightField[i];
   };
}

void feld_rechts_rotieren(char a[], unsigned int n, unsigned int shift){
   //Eingabekontrolle
   if (shift == 0){                         //Ende der Funktion, ohne Shift.
      return;
   }
   shift = shift % n;                       //Verarbeitung von Vielfachen.

   int rightShift = n - shift;              //Übersetzung des linken Shift in rechten.
   feld_links_rotieren(a, n, rightShift);   //Aufruf des angepassten linken Shift.
}

int main() {

   //=============================================================================
   // Variablendeklaration
   //=============================================================================

   int leftShiftValue    = 2;               //Wert für Feldverschiebung nach links.
   int rightShiftValue   = 2;               //Wert für Feldverschiebung nach rechts.
   int fieldSize1        = 26;              //Feldgröße Beispielfeld 1.
   int fieldSize2        = 26;              //Feldgröße Beispielfeld 2.

   //Beispielfeld 1
   char field1[]  = {
         'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
         'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
   };

   //Beispielfeld 2
   char field2[] = {
         'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
         'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
   };

   //=============================================================================
   // Hauptprogramm / Ausgabe
   //=============================================================================

   cout << "***** Caesar Verschlüsselung. *****\n" << endl;

   //Ausgabe des Beispielfelds 1.
   cout << "Beispielfeld 1: " << endl;
   for (int i = 0; i < fieldSize1; i++){
      cout << field1[i];
   }
   cout << endl;

   //Aufruf der Funktion für linken Shift.
   feld_links_rotieren(field1, fieldSize1, leftShiftValue);

   //Ausgabe des Beispielfelds 1 nach linkem Shift.
   cout << "Beispielfeld 1 mit Links-Shift um " << leftShiftValue << " Stellen: " << endl;
   for (int i = 0; i < fieldSize1; i++){
      cout << field1[i];
   }
   cout << endl;

   //Ausgabe des Beispielfelds 2.
   cout << "Beispielfeld 2: " << endl;
   for (int i = 0; i < fieldSize2; i++){
      cout << field2[i];
   }
   cout << endl;

   //Aufruf der Funktion für rechten Shift.
   feld_rechts_rotieren(field2, fieldSize2, rightShiftValue);

   //Ausgabe des Beispielfelds 2 nach rechtem Shift.
   cout << "Beispielfeld 2 mit Rechts-Shift um " << rightShiftValue << " Stellen: " << endl;
   for (int i = 0; i < fieldSize2; i++){
      cout << field2[i];
   }
   cout << endl;

   cout << "Programm beendet." << endl;
   return 0;
}
