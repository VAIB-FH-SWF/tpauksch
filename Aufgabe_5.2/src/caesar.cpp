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
//    Letzte Anpassungen:   22.11.2015
//
//               Version:   1.0
//              Compiler:   g++
//=============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void feld_wenden(char a[], unsigned int n){
   int  iterations   = n / 2;               //Anzahl symmetrischer Vertauschungen der Feldelemente.
   int  maxIndex     = n - 1;               //Größter Feldindex, abhängig von Feldbreite.
   char leftChar;                           //Linkes Tauschelement, dient als Puffervariable.
   char rightChar;                          //Rechtes Tauschelement.

   for(int i = 0; i < iterations; i++){     //Diese Schleife wechselt symmetrisch die Feldelemente
      leftChar         = a[i];
      rightChar        = a[maxIndex - i];

      a[i]              = rightChar;
      a[maxIndex - i]   = leftChar;
   }
}

void feld_links_rotieren(char a[], unsigned int n, unsigned int shift){
   if (shift == 0){                         //Ende der Funktion, ohne Shift.
      return;
   }
   shift = shift % n;                       //Verarbeitung von Vielfachen.

   int leftLength   = shift;                //Festlegung der Teilbereiche für
   int rightLength  = n - shift;            //die Rotation (Linker und rechter Teil)

   char leftField[leftLength];              //Definition des linken
   char rightField[rightLength];            //und des rechten Feldes.

   for (int i = 0; i < leftLength; i++){    //Befüllen des linken Feldes.
      leftField[i] = a[i];
   };

   feld_wenden(leftField, leftLength);      //Wenden des linken Feldes.

   for (int i = 0; i < leftLength; i++){    //Zurückschreiben des linken Feldes in Eingabefeld.
      a[i] = leftField[i];
   };

   feld_wenden(a, n);                       //Wenden des Eingabefeldes.

   for (int i = 0; i < rightLength; i++){   //Befüllen des rechten Feldes.
      rightField[i] = a[i];
   };

   feld_wenden(rightField, rightLength);    //Wenden des rechten Feldes.

   for (int i = 0; i < rightLength; i++){   //Zurückschreiben des rechten Feldes in Eingabefeld.
      a[i] = rightField[i];
   };
}

void feld_rechts_rotieren(char a[], unsigned int n, unsigned int shift){
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

   char rot13[] = {                         //Schlüsselfeld
         'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
         'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
   };


   //=============================================================================
   // Hauptprogramm
   //=============================================================================

   cout << "***** Caesar Verschlüsselung. *****\n" << endl;

   // Hier fehlt noch ein vernünftiger, beispielhafter Aufruf der Funktion ...

   feld_links_rotieren(rot13, 26, 30);      //Aufruf der Funktion für linken Shift.

   //=============================================================================
   // Ausgabe
   //=============================================================================

   for (int i = 0; i < 26; i++){
      cout << rot13[i];
   }

   return 0;
}
