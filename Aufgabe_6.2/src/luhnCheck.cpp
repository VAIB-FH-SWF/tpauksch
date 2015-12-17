//=============================================================================
//              Filename:   luhnCheck.cpp
//
//          Beschreibung:   Programmierung mit C++ 1,
//                          Blatt 17 / Aufgabe 6.2,
//                          Luhn-Algorithmus.
//
//              Aufgabe:    6.2
//
//      Praktikumsgruppe:   [V-08:30] - Is-VAI-B1A
//                Author:   Tim Pauksch
//      Erstellungsdatum:   09.12.2015
//    Letzte Anpassungen:   16.12.2015
//
//               Version:   1.0
//              Compiler:   g++
//=============================================================================

#include <iostream>
#include <stdlib.h>
using namespace std;

//Funktion zur Berechnung der Quersumme f�r nat�rliche Zahlen im Interval [0;99].
int crossTotal(int value){
   int tens = value / 10;       //Ermittelt Zehnerstelle
   int units  = value % 10;     //Ermittelt Einerstelle
   return tens + units;         //Bildet die Summe aus Zehner- und Einerstelle
}

//Funktion zur Ausgabe des G�ltigkeitsstatus.
void printValid(bool valid, string number){
   if (valid == true){
      cout << "Nummer " << number <<" ist g�ltig." << endl;
   }else{
      cout << "Nummer " << number <<" ist ung�ltig." << endl;
   }
}

//Pr�fung ob sich nur Ziffern im String befinden.
void checkValidString(string inputString){
   for (unsigned int i = 0; i < inputString.length(); i++) {
      if(!isdigit(inputString[i])){
         cout << "Ung�ltige Nummer." << "\n" << "Programm beendet." << endl;
         exit(1);
      }
   }
}

//Funktion zur Pr�fung eines Zahlen-Strings nach dem Luhn-Algorithmus.
bool luhn_check(string number){
   checkValidString(number);    //Pr�fung auf g�ltige Eingabe.

   bool valid    = false;       //R�ckgabevariable.
   int  length   = 0;           //L�nge des Strings.
   int  sum      = 0;           //Summe f�r Pr�fung nach Luhn-Algorithmus.
   int  factor   = 0;           //Faktor (1 oder 2). Initial auf 0, wird im ersten Durchlauf auf 1 gesetzt.

   length = number.length();    //Ermittlung der String-L�nge

   //Hier wird in jedem Durchlauf beginnend mit 1, der Faktor zwischen 1 und 2 gewechselt
   //dann die Ziffer an h�chster Position (absteigend) mit dem Faktor multipliziert.
   //Anschlie�end wird die Quersumme gebildet und diese dann in der Variablen "sum" aufsummiert.
   for (int i = length; i > 0; i--) {
      if (factor == 1){
         factor = 2;
      }else{
         factor = 1;
      }

      sum += crossTotal((number[i-1]-'0') * factor);
   }

   //Wenn die Summe ohne Rest durch 10 teilbar ist gibt die Funktion "true" zur�ck.
   if((sum % 10) == 0){
      valid = true;
   }
   return valid;
}

int main() {

   //=============================================================================
   // Variablendeklaration
   //=============================================================================

   //Array mit Test-Nummern (Wichtig, nur Ziffern verwenden):
   string examples[5] = {
         "446667651", "49927398716", "49927398717", "1234567812345678", "1234567812345670",
   };

   //=============================================================================
   // Hauptprogramm / Ausgabe
   //=============================================================================

   cout << "Programm: Luhn-Algorithmus." << endl;

   for (int i = 0; i < 5; ++i) {
      printValid(luhn_check(examples[i]), examples[i]);
   }

   cout << "Programm beendet." << endl;

   return 0;
}
