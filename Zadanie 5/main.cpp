#include <iostream>

class Pasazer
{
	std::string imie, nazwisko;
	int rok_urodzenia;
	static int licznik;

public:
	Pasazer(std::string imie = "Joe", std::string nazwisko = "Doe", int rok_urodzenia = 2000)	//domyslny / wieloargumentowy
		: imie(imie), rok_urodzenia(rok_urodzenia), nazwisko(nazwisko) { this->licznik++; }  

	Pasazer(const Pasazer& p) : imie(p.imie), nazwisko(p.nazwisko), rok_urodzenia(p.rok_urodzenia) { this->licznik++; }  //kopiujacy

	~Pasazer() { this->licznik--; };

	void print()
	{
		std::cout << this->imie << " " << this->nazwisko << " " << this->rok_urodzenia << "\n";
	}

	int getLicznik() { return this->licznik; }
};

int Pasazer::licznik = 0;

class Autokar
{
	std::string miejsce_docelowe;
	int max_predkosc;
	static const int calkowita_ilosc_miejsc = 20;
	Pasazer* lista_pasazerow[calkowita_ilosc_miejsc];

public:
	Autokar(std::string md, int mp): miejsce_docelowe(md), max_predkosc(mp) 
	{
		for (int i = 0; i < this->calkowita_ilosc_miejsc; i++)  //zerowanie tablicy
			lista_pasazerow[i] = nullptr;
	}

	Autokar(const Autokar& a) : miejsce_docelowe(a.miejsce_docelowe), max_predkosc(a.max_predkosc)
	{
		for (int i = 0; i < this->calkowita_ilosc_miejsc; i++)   //przepisywanie pasazerow
			this->lista_pasazerow[i] = a.lista_pasazerow[i];
	}

	bool dodajPasazerow(Pasazer* tab, int size)
	{
		bool success = false;

		int j = 0;
		for (int i = 0; i < this->calkowita_ilosc_miejsc && j < size; i++)
		{

			if (!lista_pasazerow[i])  //dodaj pasazera
			{
				lista_pasazerow[i] = &tab[j++];
				success = true;
			}
		}

		return success;  //Prawda dodano przynajmniej jedna osobe / falsz - niedodano nikogo
	}

	void print()
	{
		std::cout << "Cel: " << this->miejsce_docelowe << "\tMax predkosc: " << this->max_predkosc << "\n";
		std::cout << "Pasazerowie: \n";
		
		for (int i = 0; i < this->calkowita_ilosc_miejsc; i++)
		{
			if (this->lista_pasazerow[i])
			{
				std::cout << "\t";
				lista_pasazerow[i]->print();
			}

		}
	}

	bool usun(int start, int end)
	{
		if (start > this->calkowita_ilosc_miejsc || end > this->calkowita_ilosc_miejsc)
			return false;
		else
		{
			for (int i = start; i < end; i++)
				this->lista_pasazerow[i] = nullptr;

			return true;
		}
	}
};

int main()
{
	const int size1 = 3;
	Pasazer p1[size1] = { 
		Pasazer(),
		Pasazer("Maciej", "Chodyn", 5), 
		Pasazer(p1[1]) 
	};

	std::cout << "Zadsanie 1:\n";
	for (int i = 0; i < size1; i++)
		p1[i].print();

	int size2 = 100;
	Pasazer* p2 = new Pasazer[size2];

	std::cout << "\nZadanie 2:\nLicznik: " << p1[0].getLicznik() << "\n";


	Autokar a("Katowice", 4);
	a.dodajPasazerow(p1, size1);
	a.dodajPasazerow(p2, size2);

	std::cout << "\n\nZadanie 3: ";
	a.print();



	Autokar a2(a);
	a2.usun(0, 3);

	std::cout << "\n\nZadanie 4:";
	a2.print();

	std::cout << "\n\nZadanie 5:\n";

	delete[] p2;

	std::cout << "licznik po usunieciu tablicy dynamicznej: " << p1[0].getLicznik() << " (dodalem destruktor do klasy Pasazer)\n";
}