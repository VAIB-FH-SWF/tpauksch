//=============================================================================
//				Filename:	Dreiecksflaeche.cpp
//
//		 	Beschreibung:	Programmierung mit C++ 1,
//							Blatt 6 / Aufgabe 2.3,
//							Flaeche eines Dreiecks.
//
//				 Aufgabe:	2.3
//
//		Praktikumsgruppe:	[V-08:30] - Is-VAI-B1A
//      	  	  Author: 	Tim Pauksch
//    	Erstellungsdatum: 	15.10.2015
// 	  Letzte Anpassungen:	22.10.2015
//
//			 	 Version:	1.0
//				Compiler:	g++
//=============================================================================
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

//=============================================================================
// Variablendeclaration
//=============================================================================

   int      lengthA         = 1;
   int      lengthB         = 1;
   int      lengthC         = 1;

   double   flaeche1        = 0;
   double   flaeche2        = 0;
   double   s               = 0;

   string   formel1         = "A = (s*(s-a)*(s-b)*(s-c))^(1/2)";
   string   formel2         = "A = (1/4)*((a+b+c)*(a+b-c)*(b+c-a)*(c+a-b))^(1/2)";


//=============================================================================
// Hauptprogramm
//=============================================================================

   //Ueberschrift
   cout << "Berechnung der Fläche eines Dreiecks mit dem Satz von Heron." << endl;
   cout << "-------------------------------------------------------------" << endl;
   cout << endl;
   cout << "Nutzen Sie für die Eingabe bitte positive Zahlen." << endl;
   cout << endl;

   //Werteeingabe
   cout << "Bitte geben Sie Länge 'a' des Dreiecks ein und bestätigen Sie mit 'Return':" << endl;
   cin >> lengthA;

   cout << "Bitte geben Sie Länge 'b' des Dreiecks ein und bestätigen Sie mit 'Return':" << endl;
   cin >> lengthB;

   cout << "Bitte geben Sie Länge 'c' des Dreiecks ein und bestätigen Sie mit 'Return':" << endl;
   cin >> lengthC;

   //Werteprüfung
   if(lengthA < 0){
      cout << "Der eingegebene Wert 'a' entspricht nicht den Vorgaben. Das Programm wird abgebrochen." << endl;
      cout << "Programm beendet." << endl;
      return 0;
   }else if(lengthB < 0){
      cout << "Der eingegebene Wert 'b' entspricht nicht den Vorgaben. Das Programm wird abgebrochen." << endl;
      cout << "Programm beendet." << endl;
      return 0;
   }else if(lengthC < 0){
      cout << "Der eingegebene Wert 'c' entspricht nicht den Vorgaben. Das Programm wird abgebrochen." << endl;
      cout << "Programm beendet." << endl;
      return 0;
   }

   //Kontrollausgabe
   cout << "Länge 'a' wurde auf '" << lengthA << "' gesetzt." << endl;
   cout << "Länge 'b' wurde auf '" << lengthB << "' gesetzt." << endl;
   cout << "Länge 'c' wurde auf '" << lengthC << "' gesetzt." << endl;
   cout << endl;

   //Berechnung des Halben Dreieckumfangs
   s = (1.0/2.0)*(lengthA+lengthB+lengthC);

   //Pruefung auf negativen Wurzelwert
   if( ((s-lengthA)<0) || ((s-lengthB)<0) || ((s-lengthC)<0)){
      cout << "Negativer Wert in einer Wurzel entdeckt. Passen Sie bitte Ihre Werte an" << endl;
      cout << "Das Programm wird abgebrochen." << endl;
      cout << "Programm beendet." << endl;
      return 0;
   }

   //Berechnung der Fläche mit Formel1
   flaeche1 = sqrt(s*(s-lengthA)*(s-lengthB)*(s-lengthC));

   //Berechnung der Fläche mit Formel2
   flaeche2 = (1.0/4.0)*(sqrt((lengthA+lengthB+lengthC)*(lengthA+lengthB-lengthC)*(lengthB+lengthC-lengthA)*(lengthC+lengthA-lengthB)));

   //Ergebnisse
   cout << "Ergebnisse:" << endl;
   cout << "-------------------------------------------------------------" << endl;
   cout << "Der halbe Umfang(s) des Dreiecks beträgt: " << s << endl;
   cout << "Ergebnis der Berechnung mit Formel 1: " << endl;
   cout << formel1 << " = " << flaeche1 << endl;
   cout << "A = " << flaeche1 << endl;
   cout << endl;
   cout << "Ergebnis der Berechnung mit Formel 2: " << endl;
   cout << formel2 << " = " << flaeche2 << endl;
   cout << "A = " << flaeche2 << endl;

   cout << "Programm beendet." << endl;
   return 0;
}
