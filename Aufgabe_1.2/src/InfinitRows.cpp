//=============================================================================
//				Filename:	InfinitRows.cpp
//
//		 	Beschreibung:	Programmierung mit C++ 1,
//							Blatt 1 / Aufgabe 1.2,
//							Summenbildung bei endlichen Reihen
//
//				 Aufgabe:	1.2
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
#include <math.h>

using namespace std;

//=============================================================================
// Hauptprogramm
//=============================================================================

int main() {

	cout <<"Praktikum 'Programmierung mit C++' / Blatt1 / Aufgabe 1.2 \n";
	cout <<"Summenbildung bei unendlicher Reihe \n\n";

	//Variablendeclaration
	double G = 0;				//Summe G
	double G2 = 1;				//Hilfsvariable
	int i = 0;					//Anzahl der Summanden


	//Die While-Schleife endet wenn sich die Werte für H und H2 aufgrund
	//des darstellbaren Wertebereichs nicht mehr unterscheiden.
	while(G != G2){
		G2 = G;
		G = G + (1.0/ pow(2,i));
		i++;
	}


//Ausgabe der Werte
	cout << "Anzahl der Summanden: " << "\t \t" << fixed << i << "\n";
	cout << "Naeherungswert: " << "\t \t";
	cout << fixed << setprecision(16) << G << "\n";
	cout << "Vergleichswert (Aufgabe 1.1):" << "\t" << "2.00000" << "\n";
	return 0;
}
