#include <iostream>

class Kwadrat;
class Punkt;
class Okrag;

void wypisz(Okrag o);
void wypisz(Kwadrat k);
void wypisz(Punkt p);


class Punkt {
	friend void wypisz(Punkt p);
	friend void wypisz(Kwadrat k);
	friend void wypisz(Okrag o);
	friend class Kwadrat;
	friend class Okrag;
	int x, y;

public:
	Punkt(int x = 0, int y = 0) : x(x), y(y) {}
};

class Kwadrat {
	friend void wypisz(Kwadrat k);
	Punkt poczatek_przekatnej, koniec_przekatnej;

public:
	Kwadrat(Punkt poczatek = Punkt(0, 0), Punkt koniec = Punkt(0,0)) : poczatek_przekatnej(poczatek), koniec_przekatnej(koniec) {}

	int poleKwadratu()
	{
		int dlugosc_boku = abs(poczatek_przekatnej.x - koniec_przekatnej.x);

		return dlugosc_boku * dlugosc_boku;
	}
};


class Okrag {
	friend void wypisz(Okrag o);
	Punkt srodek;
	int promien;

public:
	Okrag(Punkt srodek = (0, 0), int promien = 1) : srodek(srodek), promien(promien) {}

	void rozlacznosc(Okrag* arr, int size)
	{
		int wew = 0, zew = 0;

		for (int i = 0; i < size; i++)
		{
			int distance = sqrt((pow(arr[i].srodek.x - this->srodek.x, 2) + pow(arr[i].srodek.y - this->srodek.y, 2)));


			int difference = abs(arr[i].promien - this->promien);
			if (distance < difference)
				wew++;

			int sum = arr[i].promien + this->promien;
			if (distance > sum)
				zew++;
		}

		std::cout << "Styczne zewnetrznie: " << zew;
		std::cout << "\nStyczne wewnetrznie: " << wew;
	}
};


void wypisz(Okrag o)
{
	std::cout << "srodek: "; wypisz(o.srodek);
	std::cout << "promien: " << o.promien << "\n";
}

void wypisz(Kwadrat k)
{
	std::cout << "poczatek przekoatnej: "; wypisz(k.poczatek_przekatnej);
	std::cout << "Koniec przekatnej: "; wypisz(k.koniec_przekatnej);
}

void wypisz(Punkt p)
{
	std::cout << "x: " << p.x << " y: " << p.y << "\n";
}

int main()
{
	Kwadrat arr[2] = {
		Kwadrat(Punkt(0, 0), Punkt(3,3)),
		Kwadrat(Punkt(-8, 8), Punkt(-1, 1))
	};

	std::cout << "podpunkt b:\n";

	for (int i = 0; i < 2; i++)
	{
		std::cout << arr[i].poleKwadratu() << "\n";
	}

	Okrag okrag1(Punkt(10, 10), 5);
	Okrag arr2[500];

	srand(time(NULL));

	for (int i = 0; i < sizeof(arr2) / sizeof(Okrag); i++)
	{
		int x = (rand() % 31) - 10;
		int y = rand() % 21;
		int radius = (rand() % 5) + 1;

		Okrag o(Punkt(x, y), radius);
		arr2[i] = o;
	}

	std::cout << "\n\npopdunkt d:\n";
	okrag1.rozlacznosc(arr2, 500);

	std::cout << "\n\nPodpunkt e: \n\n";
	std::cout << "Kwadrat: \n";wypisz(arr[0]);
	std::cout << "\nOkrag: \n";wypisz(okrag1);
}