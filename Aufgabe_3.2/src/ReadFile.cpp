//=============================================================================
//              Filename:   ReadFile.cpp
//
//          Beschreibung:   Programmierung mit C++ 1,
//                          Blatt 7 / Aufgabe 3.1,
//                          Kennwerte einer Zahlenreihe aus einer Datei.
//
//              Aufgabe:    3.2
//
//      Praktikumsgruppe:   [V-08:30] - Is-VAI-B1A
//                Author:   Tim Pauksch
//      Erstellungsdatum:   25.10.2015
//    Letzte Anpassungen:   25.10.2015
//
//               Version:   1.0
//              Compiler:   g++
//=============================================================================

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

int main() {

   //=============================================================================
   // Variablendeclaration
   //=============================================================================

   ifstream ifs;                                        // Eingabestrom-Objekt
   double output    =   0;                              // Eingelesene Zeile
   double counter   =   0;                              // Zaehler fuer Anzahl der Elemente
   double minValue  =   numeric_limits<double>::max();  // Variable fuer kleinsten Wert
   double maxValue  =   0;                              // Variable fuer groeﬂten Wert
   double sum       =   0;                              // Summe aller Werte aus der Datei


   //=============================================================================
   // Hauptprogramm
   //=============================================================================

   // Oeffnen der Datei
   ifs.open("daten.txt", ifstream::in);
   if(!ifs){
      cerr << "\nERROR : Failed to open input file daten.txt." <<  endl;
      exit (1);
   }else{
      cout << "Datei geoeffnet." << endl;
   }

   // Zeilenweiser Durchlauf
   while(ifs >> output){
      // Aufaddieren der Werte
      sum += output;

      // Kontrolle des Wertes auf Minimum bzw. Maximum
      if(output < minValue){
         minValue = output;
      }else if(output > maxValue){
         maxValue = output;
      }

      // Zaehler fuer Anzahl der Elemente
      counter ++;
   }

   //=============================================================================
   // Ausgabe
   //=============================================================================
   cout << "Programm: Kennwerte einer Zahlenreihe aus einer Datei" << endl;
   cout << "Anzahl der Werte in der Datei: " << "\t" << counter << endl;
   cout << "Kleinster Wert: " << "\t\t" << minValue <<endl;
   cout << "Grˆﬂter Wert: " << "\t\t\t" << maxValue << endl;
   cout << "DurschnittsWert: " << "\t\t" << sum / counter << endl;

   // Schlieﬂen der Datei und Programmende
   ifs.close();
   cout << "Programm beendet." << endl;
   return 0;
}
