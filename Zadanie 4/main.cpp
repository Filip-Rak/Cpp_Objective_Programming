#include <iostream>

class Samochod {
	std::string marka, model;
	int cena;

public:
	Samochod(std::string marka = "marka", std::string model = "model", int cena = 15) : marka(marka), model(model), cena(cena) {}
	
	int getCena() { return this->cena; }
	void print()
	{
		std::cout << "Marka: " << this->marka << " Model: " << this->model << " Cena: " << this->cena << "\n";
	}
};

class Garaz {
	std::string nazwa;
	int iterator = 0;
	Samochod* samochody[15];

public:
	Garaz(std::string nazwa, Samochod* samochody, int size) :nazwa(nazwa)
	{
		dodajSamochody(samochody, size);
		std::cout << "stworzono garaz: " << nazwa << "\n";
	}

	void dodajSamochody(Samochod* noweSamochody, int size)
	{
		int end;
		if (size < 15 - this->iterator)
			end = size;
		else {
			end = 15 - this->iterator;
			std::cout << this->nazwa << ": Nie wszystkie samochody sie zmiescily!\n";
		}

		for (int i = 0; i < end; i++)
			this->samochody[iterator++] = &noweSamochody[i];
	}

	int wartoscAut()
	{
		int sum = 0;
		for (int i = 0; i < this->iterator; i++)
			sum += samochody[i]->getCena();

		return sum;
	}

	void printAll()
	{
		std::cout << "Nazwa: " << this->nazwa;
		std::cout << "\nSamochody: \n";
		
		for (int i = 0; i < this->iterator; i++)
			samochody[i]->print();
	}
};


int main()
{
	Samochod tab1[2], tab2[3];  //podpunkt a


	std::cout << "Podpunkt A:\n";
	for (int i = 0; i < 2; i++)
		tab1[i].print();

	for (int i = 0; i < 3; i++)
		tab2[i].print();

	std::cout << "\n\nPodpunkt B:\n";

	Garaz g1("Garaz 1", tab1, 2), g2("Garaz 2", tab2, 3);  //popdunkt b
	g2.dodajSamochody(tab1, 2);


	std::cout << "\n\nPodpunkt C:\n"; g1.printAll(); //podpunkt c
	std::cout << "\n"; g2.printAll();

	std::cout << "\n\nPodpunkt D: \n";
	std::cout << "g1 cena: " << g1.wartoscAut() << "\n";
	std::cout << "g2 cena: " << g2.wartoscAut() << "\n";
}