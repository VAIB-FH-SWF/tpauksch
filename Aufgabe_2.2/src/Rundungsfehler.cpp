//=============================================================================
//				Filename:	Rundungsfehler.cpp
//
//		 	Beschreibung:	Programmierung mit C++ 1,
//							Blatt 6 / Aufgabe 2.2,
//							Rundungsfehler durch fortgesetzte Multiplikation/Division
//
//				 Aufgabe:	2.2
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
#include <math.h>
#include <iomanip>

using namespace std;

int main() {

//=============================================================================
// Variablendeclaration
//=============================================================================

   float    startValue      = 1000000;
   float    floatZahl       = startValue;
   float    floatfaktor     = 0.1693;
   int      index           = 10;

//=============================================================================
// Hauptprogramm
//=============================================================================

   //Ueberschrift
   cout << "Rundungsfehler durch fortgesetzte Multiplikation/Division." << endl;
   cout << "----------------------------------------------------------" << endl;

   for (int i = 0; i < index; i++){
      floatZahl *= floatfaktor;
   }

   for (int i = 0; i < index; i++){
      floatZahl /= floatfaktor;
   }

   //Ausgabetext und Wertevergleich
   cout << "Der Ausgangswert der Berechnung: " << scientific << setprecision(8) << startValue << endl;
   cout << "Der Endwert      der Berechnung: " << scientific << setprecision(8) << floatZahl << endl;
   cout << endl;

   if(startValue != floatZahl){
      cout << "Die Multiplikation mit anschließender Divison durch den" << endl;
      cout << "gleichen Faktor ergab einen Rundungsfehler." << endl;
      cout << "Die Werte sind nicht gleich." << endl;
   }else{
      cout << "Die Multiplikation mit anschließender Divison durch den" << endl;
      cout << "gleichen Faktor ergab keinen Rundungsfehler." << endl;
      cout << "Die Werte sind gleich." << endl;
   }

   return 0;
}
