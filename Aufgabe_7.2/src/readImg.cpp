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
//    Letzte Anpassungen:   06.01.2015
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
const int N = 1000;
typedef unsigned char Pixel;

//=============================================================================
// Funktionen
//=============================================================================

int stringToInt (string &input) {
	double output   = 0;
	int length   = input.length() - 1;
	int dec      = 1;
	bool negativ = false;

	if (input[0] == '-'){
		input[0] = '0';
		negativ   = true;
	}

	for (int i = length; i >= 0; i--){
		if (!isdigit(input[i])){
			cout << "\nERROR : Fehler in Metadaten. Dimension nicht nummerisch." << endl;
			exit(1);
		}

		output += (input[i] - '0') * dec;
		dec *= 10;
	}

	if (negativ){
		output *= -1;
	}

	if (output > INT_MAX) {
		cout << "Der Wert des Strings ist zu groß. Max-Wert gestezt." << endl;
		output = INT_MAX;
	} else if (output < INT_MIN) {
		cout << "Der Wert des Strings ist zu klein. Min-Wert gestezt." << endl;
		output = INT_MIN;
	}
	return (int)output;
}

struct metaInfo {
	string coding;
	int  dimension[2];
	string greyscale;
	void stripeDimension(string input);
	void initValues();
};

void metaInfo::stripeDimension(string input){
	int separator = input.find(' ');

	string width  = input.substr(0, separator);
	string height = input.substr(separator + 1);

	dimension[0]  = stringToInt(width);
	dimension[1]  = stringToInt(height);
}

void metaInfo::initValues(){
	coding = "";
	dimension[0] = 0;
	dimension[1] = 0;
	greyscale  = "";
}

metaInfo getMetaInfo(string filename) {
	ifstream ifs;                            //Eingabestrom
	metaInfo tmpMetaInfo;
	string tmpDimension;

	tmpMetaInfo.initValues();

	ifs.open(filename.c_str());

	if (!ifs.is_open()) {                    //Kontrolle ob Datei geöffnet wurde.
	  cerr << "\nERROR : Failed to open input file " << filename << "." << endl;
	  exit(1);
	}

	getline(ifs, tmpMetaInfo.coding);
	getline(ifs, tmpDimension);
	tmpMetaInfo.stripeDimension(tmpDimension);
	getline(ifs, tmpMetaInfo.greyscale);

	ifs.close();
	return tmpMetaInfo;
}

void glaetten( Pixel bild1[N][N], Pixel bild2[N][N], int nz, int ns){
	for (int i = 0; i < nz; i++){
		for (int j = 0; j < ns; j++){
			int summ = 0;
			if ((i-1 >= 0) || (j-1 >= 0)){
				summ += bild1[i-1][j-1];
				summ += bild1[i-1][j];
				summ += bild1[i-1][j+1];

				summ += bild1[i][j-1];
				summ += bild1[i][j];
				summ += bild1[i][j+1];

				summ += bild1[i+1][j-1];
				summ += bild1[i+1][j];
				summ += bild1[i+1][j+1];

				bild2[i][j] = summ / 9;
			}
		}
	}
}

void invertieren(Pixel bild1[N][N], Pixel bild2[N][N], int nz, int ns, int graumax){
	for (int i = 0; i < nz; i++){
		for (int j = 0; j < ns; j++){
			bild2[i][j] = graumax - bild1[i][j];
		}
	}
}

void kantenbildung(Pixel bild1[N][N], Pixel bild2[N][N], int nz, int ns){
	for (int i = 0; i < nz; i++){
			for (int j = 0; j < ns; j++){
				int summ = 0;
				if ((i-1 >= 0) || (j-1 >= 0)){
					summ += bild1[i-1][j-1] * 0;
					summ += bild1[i-1][j] * -1;
					summ += bild1[i-1][j+1] * 0;

					summ += bild1[i][j-1] * -1;
					summ += bild1[i][j] * 4;
					summ += bild1[i][j+1] * -1;

					summ += bild1[i+1][j-1] * 0;
					summ += bild1[i+1][j] * -1;
					summ += bild1[i+1][j+1] * 0;

					bild2[i][j] = abs(summ/9);
				}
			}
		}
}

void schaerfen(Pixel bild1[N][N], Pixel bild2[N][N], int nz, int ns, int graumax){
	for (int i = 0; i < nz; i++){
		for (int j = 0; j < ns; j++){
			int summ = 0;
			if ((i-1 >= 0) || (j-1 >= 0)){
				summ += bild1[i-1][j-1] * -1;
				summ += bild1[i-1][j] * -1;
				summ += bild1[i-1][j+1] * -1;

				summ += bild1[i][j-1] * -1;
				summ += bild1[i][j] * 9;
				summ += bild1[i][j+1] * -1;

				summ += bild1[i+1][j-1] * -1;
				summ += bild1[i+1][j] * -1;
				summ += bild1[i+1][j+1] * -1;

				if (summ < 0) {
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

void readInFile(string inputFile, string outputFile, char input){
	if (inputFile == outputFile) {
	  cerr << "\nERROR : Fehler. Dateinamen identisch."<< endl;
	  exit(1);
	}

	metaInfo metaInfo;
	string tmpDimension;

	int tmp = 0;

	ifstream ifs;
	ofstream ofs;
	ifs.open(inputFile.c_str());
	ofs.open(outputFile.c_str());
	Pixel bild1[N][N];
	Pixel bild2[N][N];

	if (!ifs.is_open()) {
	  cerr << "\nERROR : Failed to open input file " << inputFile << "." << endl;
	  exit(1);
	}

	if (!ofs.is_open()) {
	  cerr << "\nERROR : Failed to open output file geheim.txt." << endl;
	  exit(1);
	}

	metaInfo.initValues();

	getline(ifs, metaInfo.coding);
	getline(ifs, tmpDimension);
	metaInfo.stripeDimension(tmpDimension);
	getline(ifs, metaInfo.greyscale);

	int width = metaInfo.dimension[0];
	int height  = metaInfo.dimension[1];

	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			ifs >> tmp;
			bild1[i][j] = tmp;
		}
	}

	switch (input) {
		case 'g': glaetten(bild1, bild2, height, width); break;
		case 'i': invertieren(bild1, bild2, height, width, 255); break;
		case 'k': kantenbildung(bild1, bild2, height, width); break;
		case 's': schaerfen(bild1, bild2, height, width, 255); break;
		default:break;
	}

	ofs << metaInfo.coding << endl;
	ofs << metaInfo.dimension[0] << ' ' << metaInfo.dimension[1] << endl;
	ofs << metaInfo.greyscale << endl;

	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			tmp = bild2[i][j];
			ofs << setw(3) << tmp << ' ';
		}
		ofs << endl;
	}

	ifs.close();
	ofs.close();
}

int main() {
	char tmp;
	cout << "Bitte wählen: g|i|k|s|e" << endl;
	cin >> tmp;

	readInFile("dreifach.pgm","dreifach.out.pgm", tmp);
	return 0;
}
