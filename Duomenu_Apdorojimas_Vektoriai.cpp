#include "Header.h"


int main()
{
	int n = 0; // mokiniu skaicius
	bool Med_Vid = 0;// mediana ar vidurkis // tikrinimui ar yra duomenu failas

	if (Tikrinimas())
	{
		Med_Vid = Ivedimas();
		vector<Universitetas> Studentas(1);
		Skaitymas(Studentas, n, Med_Vid);
		Isvedimas(Studentas, Med_Vid, n);
	}

	system("PAUSE");
}
