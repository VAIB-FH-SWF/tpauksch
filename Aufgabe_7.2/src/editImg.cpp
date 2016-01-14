//=============================================================================
//              Filename:   editImg.cpp
//
//          Beschreibung:   Programmierung mit C++ 1,
//                          Blatt 21 / Aufgabe 7.2,
//                          Grauwertbild bearbeiten.
//
//              Aufgabe:    7.2
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

const int N = 1000;						// Feld-Dimension für Bild-Feld
typedef unsigned char Pixel;			// Feldtyp

//=============================================================================
// Funktionen
//=============================================================================

/*
 * Diese Funktion konvertiert einen String in einen Integer-Wert.
 * Dient dem Auslesen der Metadaten und Konvertieren.
 */
int stringToInt(string &input) {
   double   output  = 0;
   int      length  = input.length() - 1;
   int      dec     = 1;
   bool     negativ = false;

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
   int    dimension[2];
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

// Initialisiert die Struktur-Variablen
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
 * Zielpixel wird durch generierung des Mittelwerts aus
 * originalpixel und umliegenden gebildet.
 */
void glaetten(Pixel bild1[N][N], Pixel bild2[N][N], int nz, int ns) {
   for (int i = 0; i < nz; i++) {               // Schleifen durchlaufen Eingabebild. nz = Höhe
      for (int j = 0; j < ns; j++) {            // ns = breite.
         int summ = 0;                          // Summe der Elemente.
         if ((i - 1 >= 0) || (j - 1 >= 0)) {
            summ += bild1[i - 1][j - 1];        // Erste Reihe der 3x3 Matrix.
            summ += bild1[i - 1][j];
            summ += bild1[i - 1][j + 1];

            summ += bild1[i][j - 1];            // Zweite Reihe der 3x3 Matrix.
            summ += bild1[i][j];
            summ += bild1[i][j + 1];

            summ += bild1[i + 1][j - 1];        // Dritte Reihe der 3x3 Matrix.
            summ += bild1[i + 1][j];
            summ += bild1[i + 1][j + 1];

            bild2[i][j] = summ / 9;
         }
      }
   }
}

/*
 * Umkehrung der Bildwerte in Abhängigkeit vom Maximalwert.
 */
void invertieren(Pixel bild1[N][N], Pixel bild2[N][N], int nz, int ns,
      int graumax) {
   for (int i = 0; i < nz; i++) {
      for (int j = 0; j < ns; j++) {
         bild2[i][j] = graumax - bild1[i][j];
      }
   }
}

/*
 * Kantenglättung. Analoge Funktionsweise zur Funktion glaetten().
 */
void kantenbildung(Pixel bild1[N][N], Pixel bild2[N][N], int nz, int ns) {
   for (int i = 0; i < nz; i++) {
      for (int j = 0; j < ns; j++) {
         int summ = 0;
         if ((i - 1 >= 0) || (j - 1 >= 0)) {
            summ += bild1[i - 1][j - 1] * 0;
            summ += bild1[i - 1][j] * -1;
            summ += bild1[i - 1][j + 1] * 0;

            summ += bild1[i][j - 1] * -1;
            summ += bild1[i][j] * 4;
            summ += bild1[i][j + 1] * -1;

            summ += bild1[i + 1][j - 1] * 0;
            summ += bild1[i + 1][j] * -1;
            summ += bild1[i + 1][j + 1] * 0;

            bild2[i][j] = abs(summ / 9);
         }
      }
   }
}

/*
 * Kantenglättung. Analoge Funktionsweise zur Funktion glaetten().
 */
void schaerfen(Pixel bild1[N][N], Pixel bild2[N][N], int nz, int ns,
      int graumax) {
   for (int i = 0; i < nz; i++) {
      for (int j = 0; j < ns; j++) {
         int summ = 0;
         if ((i - 1 >= 0) || (j - 1 >= 0)) {
            summ += bild1[i - 1][j - 1] * -1;
            summ += bild1[i - 1][j] * -1;
            summ += bild1[i - 1][j + 1] * -1;

            summ += bild1[i][j - 1] * -1;
            summ += bild1[i][j] * 9;
            summ += bild1[i][j + 1] * -1;

            summ += bild1[i + 1][j - 1] * -1;
            summ += bild1[i + 1][j] * -1;
            summ += bild1[i + 1][j + 1] * -1;

            if (summ < 0) {                     // Prüfung auf min- und max-Wert.
               bild2[i][j] = 0;
            } else if (summ > graumax) {
               bild2[i][j] = graumax;
            } else {
               bild2[i][j] = summ;
            }
         }
      }
   }
}

/*
 * Funktion zum einlesen der der Bildatei, modifizierung und
 * Ausgabe in eine neue Datei.
 */
void readInFile(string inputFile, string outputFile, char input) {
   if (inputFile == outputFile) {
      cerr << "\nERROR : Fehler. Quell- und Ziel-Datei identisch." << endl;
      exit(1);
   }

   metaInfo metaInfo;                  // Struktur für Metainformationen.
   string tmpDimension;                // Wird später in zwei Metainformationen geteilt.
   int ifsInput = 0;                   // Nimmt ifs-Strom auf.
   ifstream ifs;
   ofstream ofs;
   Pixel bild1[N][N];                  // Eingabebild.
   Pixel bild2[N][N];                  // Modifiziertes Bild.

   ifs.open(inputFile.c_str());
   ofs.open(outputFile.c_str());

   if (!ifs.is_open()) {
      cerr << "\nERROR : Failed to open input file." << inputFile << "."
            << endl;
      exit(1);
   }

   if (!ofs.is_open()) {
      cerr << "\nERROR : Failed to open output file." << endl;
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
         bild1[i][j] = ifsInput;
      }
   }

   /*
    * Verabeitung in Abhängigkeit der Benutzereingaben.
    */
   switch (input) {
   case 'g':
      glaetten(bild1, bild2, height, width);
      break;
   case 'i':
      invertieren(bild1, bild2, height, width, 255);
      break;
   case 'k':
      kantenbildung(bild1, bild2, height, width);
      break;
   case 's':
      schaerfen(bild1, bild2, height, width, 255);
      break;
   default:
      break;
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
         ifsInput = bild2[i][j];
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

   char userInput;
   cout << "Aufgabe 7.2 - Grauwertbild bearbeiten." << endl;
   cout << "Bitte wählen sie eine Bearbeitungsart: " << endl;
   cout << "g: Glättung" << endl;
   cout << "i: Invertierung" << endl;
   cout << "k: Kantenbildung" << endl;
   cout << "s: Schärfung" << endl;
   cout << "e: ende" << endl;
   cout << endl;
   cout << "Auswahl: " << endl;
   cin >> userInput;

   if (userInput == 'e'){
      cout << "Programm beendet." << endl;
      exit(1);
   }

   readInFile("dreifach.pgm", "dreifach.out.pgm", userInput);
   cout << "Programm beendet." << endl;
   return 0;
}
