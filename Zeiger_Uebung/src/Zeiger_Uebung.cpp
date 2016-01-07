//============================================================================
// Name        : Zeiger_Uebung.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
   int a    = 1;
   int *pa  = &a;
   int **ppa = &pa;

   cout << "Länge einer Int-Adresse: " << sizeof(int *) << endl;
   cout << "Länge einer Char-Adresse: " << sizeof(char *) << endl;
   cout << "   a: " << a << endl;
   cout << "  &a: " << &a << endl;
   cout << "  pa: " << pa << endl;
   cout << " *pa: " << *pa << endl;
   cout << " &pa: " << &pa << endl;
   cout << "&*pa: " << &*pa << endl;
   cout << "*ppa: " << *ppa << endl;
   cout << endl;
   cout << "Adresse &a: " << &a << endl;
   cout << "Inhalt a: " << a << endl;
   cout << "Adresse &pa: " << &pa << endl;
   cout << "Inhalt pa: " << pa << endl;
   cout << "*pa: " << *pa << endl;
   cout << "ppa: "  << ppa << endl;
   cout << "&ppa: "  << &ppa << endl;
   cout << "**ppa: "  << **ppa << endl;


   return 0;
}
