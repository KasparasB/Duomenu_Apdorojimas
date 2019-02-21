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


std::ifstream in("kursiokai.txt");
std::ofstream out("rezultatai.txt");

bool Tikrinimas()
{
	try
	{
		if (!in) throw "Duomenu failo nera!";
		return true;
	}
	catch (const char* cstr)
	{
	
		std::cerr << cstr << '\n';
		return false;
	}
}



struct Universitetas {
	string Vardas;
	string Pavarde;
	vector<int> Pazymiai;
	int Egzaminas;
	double Galutinis;
	int Pazymiu_Skaicius;
};

void Ilgiausias(vector<Universitetas> A, int n, int &Vardas, int &Pavarde);
void Ivedimas(int &n, int &Med_Vid);
double Mediana(vector<Universitetas> &A, int e, int i);
double Vidurkis(vector<Universitetas> A, int e, int i);
bool is_alpha(const std::string &str);
void VardasPavarde(vector<Universitetas> &A, int i);
void PazymiuRikiavimas(vector<Universitetas> &Studentas, int i);
bool Rikiavimas(Universitetas stud1, Universitetas stud2);
void Isvedimas(vector<Universitetas> &Studentas, int Med_Vid, int n);
void Generavimas(vector<Universitetas> &Studentas, int Med_Vid, int i);
void Skaitymas(vector<Universitetas> &Studentas, int &n, int Med_Vid);


bool is_alpha(const std::string &str)
{
	return std::all_of(str.begin(), str.end(), ::isalpha);
}

void Ilgiausias(vector<Universitetas> A, int n, int &Vardas, int &Pavarde) // Funkcija ilgiausiam vardui ar pavardei rasti
{
	int MAX_V = 0;
	int MAX_PV = 0;
	int ilgis1 = 0;
	int ilgis2 = 0;
	for (int i = 0; i < n; i++)
	{
		ilgis1 = A[i].Vardas.length();
		MAX_V = max(ilgis1, MAX_V);

		ilgis2 = A[i].Pavarde.length();
		MAX_PV = max(ilgis2, MAX_PV);
	}
	Vardas = MAX_V;
	Pavarde = MAX_PV;
}

void Ivedimas(bool &Med_Vid)
{
	cout << "Skaiciuoti pagal mediana ar vidurki? (0 - Mediana, 1 - Vidurkis)" << endl;
	string trap;
	getline(cin, trap);
	while (cin.fail() || (trap != "0" && trap != "1")) {
		cout << "Klaida ivedime! Iveskite 0 arba 1." << endl;
		getline(cin, trap);
	}
	if (trap == "0") Med_Vid = true;
	else Med_Vid = false;
}

double Mediana(vector<Universitetas> &A, int e, int i)
{
	double med = 0;
	if (e != 0)
	{
		if (e % 2 == 0) //Tikrinam ar lyginis skaicius elementu ar ne
		{
			med = ((double)A[i].Pazymiai[e / 2] + A[i].Pazymiai[(e / 2) - 1]) / 2;
		}
		else
		{
			med = (double)A[i].Pazymiai[e / 2];
		}
	}
		
	return med;
}

double Vidurkis(vector<Universitetas> A, int e, int i)
{
	double vid = 0;

	if (e != 0)
	{
		for (int x = 0; x < e; x++)
			vid += A[i].Pazymiai[x];

		vid = vid / e;
	}

	return vid;
}


void VardasPavarde(vector<Universitetas> &A, int i) // Vartotojas netgi turi galimybe istaisyti neteisinga varda tekstiniame faile :O
{

	while (!(is_alpha(A[i].Vardas))) //Prasoma stringo
	{
		std::cin.clear();
		cout << "Klaida tekstiniame faile! Pataisykite mokinio varda" << endl;
		cin >> A[i].Vardas;
	}

	while (!(is_alpha(A[i].Pavarde))) //Prasoma stringo
	{
		std::cin.clear();
		cout << "Klaida tekstiniame faile! Pataisykite mokinio pavarde" << endl;
		cin >> A[i].Pavarde;
	}
}

void PazymiuRikiavimas(vector<Universitetas> &Studentas, int i)
{
	sort(Studentas[i].Pazymiai.begin(), Studentas[i].Pazymiai.end()); // Surikiuojam pazymius
}

bool Rikiavimas(Universitetas stud1, Universitetas stud2)
{
	if (stud1.Vardas < stud2.Vardas)
		return 1;
	else if (stud1.Vardas == stud2.Vardas && stud1.Pavarde < stud2.Pavarde)
		return 1;
	else
		return 0;
}

void Isvedimas(vector<Universitetas> &Studentas, bool Med_Vid, int n)
{
	string gal = " "; //Susikuriu stringa, kad galeciau ji naudoti apacioje

	int Ilgiausias_Vardas; //Sukuriami intai, kad pagelbetu teksto lygiavime
	int Ilgiausia_Pavarde;

	Ilgiausias(Studentas, n, Ilgiausias_Vardas, Ilgiausia_Pavarde);

	//Del lygiavimo atlieku siuos pakeitimus
	if (Ilgiausias_Vardas < 6) Ilgiausias_Vardas = 6;
	if (Ilgiausia_Pavarde < 7) Ilgiausia_Pavarde = 7;

	if (Med_Vid) gal = "Galutinis (Med.)";
	else gal = "Galutinis (Vid.)";
	int Ilgis = Ilgiausias_Vardas + Ilgiausia_Pavarde + 19; // Nustatom kiek reikes padeti bruksneliu
	out << left << setw(Ilgiausias_Vardas) << "Vardas" << left << setw(Ilgiausia_Pavarde) << " Pavarde" << left << "  " << gal << endl;
	for (int i = 0; i < Ilgis; i++) out << "_";
	out << endl;

	std::sort(Studentas.begin(), Studentas.end()-1, Rikiavimas);

	for (int i = 0; i < n; i++)
	{
		out << left << setw(Ilgiausias_Vardas) << Studentas[i].Vardas << " " << left << setw(Ilgiausia_Pavarde) << Studentas[i].Pavarde << fixed << setprecision(2) << "  " << Studentas[i].Galutinis << endl;
	}
	in.close();
	out.close();
}

void Generavimas(vector<Universitetas> &Studentas, bool Med_Vid, int i)
{
	VardasPavarde(Studentas, i);

	PazymiuRikiavimas(Studentas, i);

	if (Med_Vid)// Mediana
		Studentas[i].Galutinis = Mediana(Studentas, Studentas[i].Pazymiu_Skaicius, i);
	else		//Vidurkis
		Studentas[i].Galutinis = Vidurkis(Studentas, Studentas[i].Pazymiu_Skaicius, i);

	Studentas[i].Galutinis = Studentas[i].Galutinis * 0.4 + 0.6 * Studentas[i].Egzaminas;
	Studentas[i].Pazymiai.erase(Studentas[i].Pazymiai.begin(), Studentas[i].Pazymiai.end() );
}

void Skaitymas(vector<Universitetas> &Studentas, int &n, bool Med_Vid)
{
	string duomuo;
	int e = 0;
	int pazymiu_sk = 0;
	while (true) // true  in.peek() != EOF
	{
		do
		{
			in >> duomuo;

			if (duomuo != "Pavarde" && e == 0)
			{
				cout << "Klaidingas duomenu failas" << endl;
				break;
			}
			if (duomuo != "Vardas" && e == 1)
			{
				cout << "Klaidingas duomenu failas" << endl;
				break;
			}
			e++;
		} while (e != 2);

		do
		{
			in >> duomuo;
			if (duomuo[0] != 'N' && duomuo[1] != 'D' && duomuo != "Egzaminas")
			{
				cout << "Klaidingas duomenu failas" << endl;
			}
			pazymiu_sk++;
		} while (duomuo != "Egzaminas");
		pazymiu_sk--;
		break;
	}
	in.ignore(80, '\n');
	
	int tmp;
	int egzaminas;
	string s1;
	e = 0;
	while (in.peek() != EOF)
	{
		getline(in, s1);
		std::istringstream eil(s1);

		eil >> Studentas[n].Vardas;
		eil >> Studentas[n].Pavarde;
		//Studentas[n].Pazymiu_Skaicius = pazymiu_sk;
		VardasPavarde(Studentas, n);
		e = 0;
		do
		{
			eil >> tmp;
			if (tmp >= 0 && tmp <= 10)
			{
				Studentas[n].Pazymiai.push_back(tmp);
				e++;
			}
			else
			{
				cout << "Klaida duomenu faile. Mokinys neturi pazymiu!" << endl;
				std::exit;
				break;
			}
		} while (eil.peek() != EOF);
		if (e == 1) cout << "Mokinys turi tik viena pazymi ir del to jo vidurkis nebus skaicuojamas" << endl;
		if (e > 0 && e!=1)
		{
			Studentas[n].Egzaminas = Studentas[n].Pazymiai[Studentas[n].Pazymiai.size() - 1];
			Studentas[n].Pazymiai.erase(Studentas[n].Pazymiai.begin() + Studentas[n].Pazymiai.size() - 1);
			Studentas[n].Pazymiu_Skaicius = e - 2;
			Generavimas(Studentas, Med_Vid, n);
			Studentas.push_back({ Studentas[n].Vardas, Studentas[n].Pavarde, Studentas[n].Pazymiai, Studentas[n].Egzaminas, Studentas[n].Galutinis, Studentas[n].Pazymiu_Skaicius });
			n++;
		}
		else
		{
			std::exit;
		}
		

	}
	
}


