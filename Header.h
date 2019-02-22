#pragma once

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <random>
#include <vector>
#include <ctype.h>
#include <cctype>
#include <fstream>
#include <stdlib.h>
#include <sstream>



using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;
using std::left;
using std::sort;
using std::max;
using std::right;
using std::setprecision;
using std::fixed;
using std::vector;
using std::getline;

struct Universitetas {
	string Vardas;
	string Pavarde;
	vector<int> Pazymiai;
	int Egzaminas;
	double Galutinis;
	int Pazymiu_Skaicius;
};

void Ilgiausias(vector<Universitetas> A, int n, int &Vardas, int &Pavarde);
bool Ivedimas();
double Mediana(vector<Universitetas> &A, int e, int i);
double Vidurkis(vector<Universitetas> A, int e, int i);
bool is_alpha(const std::string &str);
void VardasPavarde(vector<Universitetas> &A, int i);
void PazymiuRikiavimas(vector<Universitetas> &Studentas, int i);
bool Rikiavimas(Universitetas stud1, Universitetas stud2);
void Isvedimas(vector<Universitetas> &Studentas, int Med_Vid, int n);
void Generavimas(vector<Universitetas> &Studentas, int Med_Vid, int i);
void Skaitymas(vector<Universitetas> &Studentas, int &n, int Med_Vid);
bool Tikrinimas();




