//=============================================================================
//				Filename:	FinitRows.cpp
//
//		 	Beschreibung:	Programmierung mit C++ 1,
//							Blatt 1 / Aufgabe 1.1,
//							Summenbildung bei endlichen Reihen
//
//				 Aufgabe:	1.1
//
//		Praktikumsgruppe:	[V-08:30] - Is-VAI-B1A
//      	  	  Author: 	Tim Pauksch
//    	Erstellungsdatum: 	01.10.2015
// 	  Letzte Anpassungen:	07.10.2015
//
//			 	 Version:	1.0
//				Compiler:	g++
//=============================================================================
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//=============================================================================
// Hauptprogramm
//=============================================================================

int main() {

	cout <<"Praktikum 'Programmierung mit C++' / Blatt1 / Aufgabe 1.1 \n";
	cout <<"Summenbildung bei endlichen Reihen \n\n";

	//Variablendeklaration:
	double H = 0;				// Summe H
	double A = 0;				// Summe A
	double L = 0;				// Summe L
	double G = 0;				// Summe G

	double index = 1000;		//Anzahl der Summanden
	int precision = 5;			//Nachkommastellen


	// Schleife fuer Summe H,L und A (i=1 bis n)
	for (double i = 1; i <= index; i++) {
		H = H + (1.0/i);
		A = A + (pow(-1,(i+1))) / i;
		L = L + (pow(-1,(i+1))) / ((2*i)-1);
	}

	// Schleife fuer Summe G (i=0 bis n)
	for (double i = 0; i < index; i++) {
		G = G + (1.0 / (pow(2,i)));
	}

	//Ausgabe der Werte
	cout << "Summe der harmonischen Reihe: \t\t\t";
	cout << fixed << setprecision(precision) << H << "\n";
	cout << "Summe der alternierend harmonischen Reihe: \t";
	cout << fixed << setprecision(precision) << A << "\n";
	cout << "Summe der Leibnizschen Reihe: \t\t\t";
	cout << fixed << setprecision(precision) << L << "\n";
	cout << "Summe der Gemometrischen Reihe: \t\t";
	cout << fixed << setprecision(precision) << G << "\n";
	return 0;
}
