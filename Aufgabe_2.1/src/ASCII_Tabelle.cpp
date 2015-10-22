//=============================================================================
//				Filename:	ASCII_Tabelle.cpp
//
//		 	Beschreibung:	Programmierung mit C++ 1,
//							Blatt 5 / Aufgabe 2.1,
//							ASCII-Tabelle
//
//				 Aufgabe:	2.1
//
//		Praktikumsgruppe:	[V-08:30] - Is-VAI-B1A
//      	  	  Author: 	Tim Pauksch
//    	Erstellungsdatum: 	12.10.2015
// 	  Letzte Anpassungen:	12.10.2015
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

   int      height  = 32;
   int      width   = 4;
   int      counter = 0;
   char     tmpChar = 0;


//=============================================================================
// Hauptprogramm
//=============================================================================

   //Ueberschrift
   cout << "***  ASCII-Tabelle  ***" << endl;
   cout << endl;

   //Zeilenbeschriftung
   for(int j = 0; j < width ; j++){
      cout << "Okt ";
      cout << "Dec ";
      cout << "Hex ";
      cout << "Zch ";
      cout << "    ";
   }
   cout << endl;

   //Trennlinie
   cout << "-------------------------------------------------------------------------------";
   cout << endl;

   //Tabelleninhalt
   for(int i = 0; i < height ; i++){
      for(int j = 0; j < width ; j++){
         cout << setw(3) << setfill('0') << oct << counter << ' ';
         cout << setw(3) << setfill('0') << dec << counter << ' ';
         cout << setw(3) << setfill('0') << hex << counter << ' ';

         tmpChar = counter;
         if ((counter < 32) || (counter > 126)){
            cout << "... ";
         }else{
            cout << setw(3) << setfill(' ') << tmpChar << ' ';
         }
         cout << "    ";
         counter += 32;
      }
      counter -= (32*width);
      cout << endl;
      counter++;
   }
   return 0;
}
