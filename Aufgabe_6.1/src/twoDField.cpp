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
//    Letzte Anpassungen:   05.12.2015
//
//               Version:   1.0
//              Compiler:   g++
//=============================================================================

#include <iostream>
#include <iomanip>

using namespace std;

typedef unsigned int uint;

const unsigned int nmat = 10;

void matrix_diag (int mat[nmat][nmat], uint n, int diag, int value){
   int iterationMax = n;

   for(int i = 0; i < iterationMax; i++){
      for(int j = 0; j < diag; j++){
         if (i+j < iterationMax){
            mat[i+j][i] = value;
            mat[i][i+j] = value;
         }
      }
   }
}

void matrix_dreieck (int mat[nmat][nmat], uint n, int k, int value){
   int iterationMax = n;
   if (k > 2*iterationMax-1){
      k = 2*iterationMax-1;
   }

   for(int i = 0; i < iterationMax; i++){
      for (int j = 0; j < k; j++){
         mat[i][j] = value;
      }
      k--;
   }
}

void matrix_frame (int mat[nmat][nmat], uint n, uint frame, int value){
   if (frame > n/2){
      frame = n/2;
   }
   int iterationMax = n;
   int leftFrame    = frame;
   int rightframe   = n - frame;

   for(int i = 0; i < iterationMax; i++){
      for(int j = 0; j < iterationMax; j++){
         mat[i][j] = value;
      }
   }

   for(int i = leftFrame; i < rightframe; i++){
      for(int j = leftFrame; j < rightframe; j++){
         mat[i][j] = 0;
      }
   }
}

void matrix_null (int mat[nmat][nmat], uint n){
   int iterationMax = n;
   for(int i = 0; i < iterationMax; i++){
      for(int j = 0; j < iterationMax; j++){
         mat[i][j] = 0;
      }
   }
}

void matrix_print (int mat[nmat][nmat], uint n){
   int iterationMax = n;
   for(int i = 0; i < iterationMax; i++){
      for(int j = 0; j < iterationMax; j++){
         cout << setw(2) << mat[i][j];
      }
      cout << endl;
   }
}

int main(){
   int mat[nmat][nmat];

   matrix_null(mat, nmat);
   //matrix_frame(mat, nmat, 2, 2);
   //matrix_diag(mat, nmat, 1, 1);
   //matrix_dreieck(mat, nmat, 18, 1);
   matrix_print(mat, nmat);
   return 0;
}
