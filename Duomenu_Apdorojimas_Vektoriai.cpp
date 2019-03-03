#include "Header.h"

int main()
{
	
	int n = 0; // mokiniu skaicius
	bool Med_Vid = 0;// mediana ar vidurkis // tikrinimui ar yra duomenu failas
	Med_Vid = Ivedimas();
	DuomenuKurimas();
	int Skaicius = 1000;
	for (int i = 0; i < 5; i++)
	{
		auto start = std::chrono::system_clock::now();
		if (Tikrinimas(i))
		{
			n = 0;
			vector<Universitetas> Studentas;
			Studentas.reserve(Skaicius);
			Skaitymas(Studentas, n, Med_Vid,i);
			Isvedimas(Studentas, Med_Vid, n,i);
			
		}
		auto end = std::chrono::system_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start) * 0.001;
		std::cout << setprecision(4) << elapsed.count() << '\n';
		Skaicius *= 10;
	}
	system("PAUSE");
}
