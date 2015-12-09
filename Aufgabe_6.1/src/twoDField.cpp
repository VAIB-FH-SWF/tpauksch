//=============================================================================
//              Filename:   twoDField.cpp
//
//          Beschreibung:   Programmierung mit C++ 1,
//                          Blatt 15 / Aufgabe 6.1,
//                          Belegung zweidimensionaler Felder.
//
//              Aufgabe:    6.1
//
//      Praktikumsgruppe:   [V-08:30] - Is-VAI-B1A
//                Author:   Tim Pauksch
//      Erstellungsdatum:   05.12.2015
//    Letzte Anpassungen:   09.12.2015
//
//               Version:   1.0
//              Compiler:   g++
//=============================================================================

#include <iostream>
#include <iomanip>

using namespace std;

typedef unsigned int uint;

const unsigned int nmat = 10;

//Diese Funktion zeichnet eine Diagonale in die Feld-Matrix.
void matrix_diag (int mat[nmat][nmat], uint n, int diag, int value){
   //Hier wird der Wert auf die nächst größte Anzahl an Diagonalen hochgerechnet.
   int anzahlDiag = diag/2 +1;
   int iterationMax = n;

   //Die Diagonalen entstehen während der Iteration, indem von oben links
   //nach unten rechts die Werte gesetzt werden. Im Beispiel für diag=1
   //jeweils die Punkte P1(x+1/y), P2(x/y-1) und Punkt P3(x/y) der
   //Hauptdiagonalen.
   for(int i = 0; i < iterationMax; i++){
      for(int j = 0; j < anzahlDiag; j++){
         if (i+j < iterationMax){
            mat[i+j][i] = value;
            mat[i][i+j] = value;
         }
      }
   }
}

//Diese Funktion zeichnet ein Dreieck am oberen linken Rand in die Feld-Matrix.
void matrix_dreieck (int mat[nmat][nmat], uint n, int k, int value){
   int iterationMax = n;
   if (k > 2*iterationMax-1){   //Abfangen unzulässiger Werte
      k = 2*iterationMax-1;
   }

   for(int i = 0; i < iterationMax; i++){
      for (int j = 0; j < k; j++){
         mat[i][j] = value;
      }
      //Hier wird für den Effekt des Dreiecks die Iterationsgrenze der inneren Schleife
      //mit jedem Durchlauf der Äußeren verkleinert.
      k--;
   }
}

void matrix_frame (int mat[nmat][nmat], uint n, uint frame, int value){
   if (frame > n/2){    //Abfangen ungültiger Werte
      frame = n/2;
   }
   int iterationMax = n;
   int leftFrame    = frame;
   int rightframe   = n - frame;

   //Hier wird zuerst das ganze Feld mit dem Value gefüllt.
   for(int i = 0; i < iterationMax; i++){
      for(int j = 0; j < iterationMax; j++){
         mat[i][j] = value;
      }
   }

   //Statt explizit den Rahmen zu zeichnen wird der Mittelteil
   //neu gezeichnet.
   for(int i = leftFrame; i < rightframe; i++){
      for(int j = leftFrame; j < rightframe; j++){
         mat[i][j] = 0;
      }
   }
}

//Funktion zum setzen der Feldelemente auf den Wert Null.
void matrix_null (int mat[nmat][nmat], uint n){
   int iterationMax = n;
   for(int i = 0; i < iterationMax; i++){
      for(int j = 0; j < iterationMax; j++){
         mat[i][j] = 0;
      }
   }
}

//Ausgabefunktion für eine Feld-Matrix
void matrix_print (int mat[nmat][nmat], uint n){
   int iterationMax = n;

   cout << endl;

   for(int i = 0; i < iterationMax; i++){
      for(int j = 0; j < iterationMax; j++){
         cout << setw(2) << mat[i][j];
      }
      cout << endl;
   }
}

int main(){

   //=============================================================================
   // Variablendeklaration
   //=============================================================================

   //Die Felder erhalten gemäß der Konstante "nmat" die jeweilige Höhe und Breite.
   int mat[nmat][nmat];
   int matDiag[nmat][nmat];
   int matFrame[nmat][nmat];
   int matDreieck[nmat][nmat];

   //=============================================================================
   // Hauptprogramm
   //=============================================================================

   //Belegung der Feldelemente mit Nullen
   matrix_null(mat, nmat);
   matrix_null(matDiag, nmat);
   matrix_null(matFrame, nmat);
   matrix_null(matDreieck, nmat);

   //Beispielhaftes Ausführen der Funktionen
   matrix_diag(matDiag, nmat, 4, 1);        //matrix_diag(Feld, Feldbreite, Anz. Diagonale, Füllwert)
   matrix_frame(matFrame, nmat, 2, 2);      //matrix_frame(Feld, Feldbreite, Rahmenbreite, Füllwert)
   matrix_dreieck(matDreieck, nmat, 5, 1);  //matrix_dreieck(Feld, Feldbreite, Dreieckhöhe, Füllwert)

   //=============================================================================
   // Ausgabe
   //=============================================================================

   cout << "Aufgabe: Belegung zweidimensionaler Felder." << endl;

   matrix_print(mat, nmat);                 //matrix_print(Feld, Feldbreite)
   matrix_print(matDiag, nmat);
   matrix_print(matFrame, nmat);
   matrix_print(matDreieck, nmat);

   cout << '\n' << "Programm ende." << endl;
   return 0;
}
