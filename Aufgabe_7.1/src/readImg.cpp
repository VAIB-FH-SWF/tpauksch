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
	void print();
	void initValues();
};

void metaInfo::stripeDimension(string input){
	int separator = input.find(' ');

	string width  = input.substr(0, separator);
	string height = input.substr(separator + 1);

	dimension[0]  = stringToInt(width);
	dimension[1]  = stringToInt(height);
}

void metaInfo::print(){
	cout << "Coding: " 	<< coding << endl;
	cout << "Breite: " 	<< dimension[0] << endl;
	cout << "Höhe: "  	<< dimension[1] << endl;
	cout << "Max Grauwert: " << greyscale << endl;
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

void readInFile(string inputFile, string outputFile){
	if (inputFile == outputFile) {
	  cerr << "\nERROR : Fehler. Dateinamen identisch."<< endl;
	  exit(1);
	}

	metaInfo metaInfo;
	string tmpDimension;
	metaInfo.initValues();
	int tmp = 0;

	ifstream ifs;
	ofstream ofs;
	ifs.open(inputFile.c_str());
	ofs.open(outputFile.c_str());

	if (!ifs.is_open()) {
	  cerr << "\nERROR : Failed to open input file " << inputFile << "." << endl;
	  exit(1);
	}

	if (!ofs.is_open()) {
	  cerr << "\nERROR : Failed to open output file geheim.txt." << endl;
	  exit(1);
	}

	getline(ifs, metaInfo.coding);
	getline(ifs, tmpDimension);
	metaInfo.stripeDimension(tmpDimension);
	getline(ifs, metaInfo.greyscale);

	int width = metaInfo.dimension[0];
	int height  = metaInfo.dimension[1];

	unsigned char image[height][width];

	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			ifs >> tmp;
			image[i][j] = tmp;
			cout << image[i][j] << ' ';
		}
		cout << endl;
	}

	ofs << metaInfo.coding << endl;
	ofs << metaInfo.dimension[0] << ' ' << metaInfo.dimension[1] << endl;
	ofs << metaInfo.greyscale << endl;

	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			tmp = image[i][j];
			ofs << setw(3) << tmp << ' ';
		}
		ofs << endl;
	}

	ifs.close();
	ofs.close();
}

int main() {
	readInFile("dreifach.pgm","dreifach.out.pgm");
	return 0;
}
