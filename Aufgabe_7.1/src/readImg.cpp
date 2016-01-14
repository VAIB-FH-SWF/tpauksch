//=============================================================================
//              Filename:   readImg.cpp
//
//          Beschreibung:   Programmierung mit C++ 1,
//                          Blatt 19 / Aufgabe 7.1,
//                          Bilddatei lesen und speichern.
//
//              Aufgabe:    7.1
//
//      Praktikumsgruppe:   [V-08:30] - Is-VAI-B1A
//                Author:   Tim Pauksch
//      Erstellungsdatum:   06.01.2015
//    Letzte Anpassungen:   14.01.2015
//
//               Version:   1.0
//              Compiler:   g++
//=============================================================================
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <limits.h>
#include <iomanip>

using namespace std;

//=============================================================================
// Definitionen
//=============================================================================

const int N = 1000;                 // Feld-Dimension für Bild-Feld
typedef unsigned char Pixel;        // Feldtyp


//=============================================================================
// Funktionen
//=============================================================================

/*
 * Diese Funktion konvertiert einen String- in einen Integer-Wert.
 * Dient dem Auslesen der Metadaten und Konvertieren.
 */
int stringToInt(string &input) {
   double output  = 0;
   int    length  = input.length() - 1;
   int    dec     = 1;
   bool   negativ = false;

   if (input[0] == '-') {
      input[0] = '0';
      negativ = true;
   }

   for (int i = length; i >= 0; i--) {
      if (!isdigit(input[i])) {
         cout << "\nERROR : Fehler in Metadaten. Dimension nicht nummerisch."
               << endl;
         exit(1);
      }
      output += (input[i] - '0') * dec;
      dec *= 10;
   }

   if (negativ) {
      output *= -1;
   }

   if (output > INT_MAX) {
      cout << "Der Wert des Strings ist zu groß. Max-Wert gestezt." << endl;
      output = INT_MAX;
   } else if (output < INT_MIN) {
      cout << "Der Wert des Strings ist zu klein. Min-Wert gestezt." << endl;
      output = INT_MIN;
   }
   return (int) output;
}

// Struktur zur Speicherung der Metadaten.
struct metaInfo {
   string coding;
   int dimension[2];
   string greyscale;
   void print();
   void stripeDimension(string input);
   void initValues();
};

/*
 *  Teilt den String mit den Größendimensionen der
 *  per getline gelesen wird mit Hilfe der stringToInt
 *  Funktion auf.
 */
void metaInfo::stripeDimension(string input) {
   int separator = input.find(' ');

   string width = input.substr(0, separator);
   string height = input.substr(separator + 1);

   dimension[0] = stringToInt(width);
   dimension[1] = stringToInt(height);
}

// Initialisiert die Struktur-Variablen.
void metaInfo::initValues() {
   coding = "";
   dimension[0] = 0;
   dimension[1] = 0;
   greyscale = "";
}

// Gibt die Metainfos aus.
void metaInfo::print(){
   cout << "Metainfos: "<< endl;
   cout << "Coding: "   << coding << endl;
   cout << "Breite: "   << dimension[0] << endl;
   cout << "Höhe: "     << dimension[1] << endl;
   cout << "Max Grauwert: " << greyscale << endl;
}

/*
 * Funktion zum einlesen der Bildatei, modifizierung und
 * Ausgabe in eine neue Datei.
 */
void readInFile(string inputFile, string outputFile) {
   if (inputFile == outputFile) {
      cerr << "\nERROR : Fehler. Dateinamen identisch." << endl;
      exit(1);
   }

   unsigned char image[N][N];
   metaInfo metaInfo;                  // Struktur für Metainformationen.
   string tmpDimension;                // Wird später in zwei Metainformationen geteilt.
   int ifsInput = 0;                   // Nimmt ifs-Strom auf.
   ifstream ifs;
   ofstream ofs;

   ifs.open(inputFile.c_str());
   ofs.open(outputFile.c_str());

   if (!ifs.is_open()) {
      cerr << "\nERROR : Failed to open input file " << inputFile << "."
            << endl;
      exit(1);
   }

   if (!ofs.is_open()) {
      cerr << "\nERROR : Failed to open output file geheim.txt." << endl;
      exit(1);
   }

   metaInfo.initValues();              // Initialisierung der Metainfo-Vars.

   /*
    * Lesen der Metainfos samt verarbeitung.
    */
   getline(ifs, metaInfo.coding);
   getline(ifs, tmpDimension);
   metaInfo.stripeDimension(tmpDimension);
   getline(ifs, metaInfo.greyscale);

   /*
    * Verbesserung der lesbarkeit der Dimensionen.
    */
   int width = metaInfo.dimension[0];
   int height = metaInfo.dimension[1];

   /*
    * Prüfung auf Dateidimensionen.
    */
   if ((width > N) || (height > N)){
      cerr << "\nERROR : Dateidimensionen dürfen 1000 Pixel nicht überschreiten." << endl;
      exit(1);
   }

   /*
    * Ausgabe der Metainfos.
    */
   metaInfo.print();

   /*
    * Einlesen der Eingabedatei.
    */
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         ifs >> ifsInput;
         image[i][j] = ifsInput;
      }
   }

   /*
    * Schreiben der Metainfos in Ausgabedatei.
    */
   ofs << metaInfo.coding << endl;
   ofs << metaInfo.dimension[0] << ' ' << metaInfo.dimension[1] << endl;
   ofs << metaInfo.greyscale << endl;

   /*
    * Schreiben des Ausgabebildes in Ausgabedatei.
    */
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         ifsInput = image[i][j];
         ofs << setw(3) << ifsInput << ' ';
      }
      ofs << endl;
   }

   /*
    * Schließen der Dateien.
    */
   ifs.close();
   ofs.close();
}

//=============================================================================
// Hauptprogramm
//=============================================================================

int main() {
   string inputFile = "dreifach.pgm";
   string outputFile = "dreifach.out.pgm";

   cout << "Aufgabe 7.1 - Bilddatei lesen und speichern." << endl;
   cout << endl;
   cout << "Datei "<< inputFile <<" wird eingelesen und unter "<< outputFile <<" gespeichert." << endl;

   readInFile(inputFile, outputFile);
   cout << "Datei kopiert." << endl;
   cout << "Programm beendet." << endl;
   return 0;
}
