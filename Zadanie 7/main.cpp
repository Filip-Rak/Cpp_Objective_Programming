#include <iostream>

class Ulamek {
	friend Ulamek dodaj(Ulamek u1, Ulamek u2);
	friend std::ostream& operator<<(std::ostream& output, Ulamek u);
	int licznik, mianownik;

public:
	Ulamek(int l, int m): licznik(l), mianownik(m) {}
	Ulamek(int l) : licznik(l), mianownik(1) {}

	void skrocUlamek()
	{
		int min = this->mianownik;
		if (this->licznik < min)
			min = this->licznik;

		for (int i = min; i > 1; i--)
		{
			if (this->licznik % i == 0 && this->mianownik % i == 0)
			{
				this->licznik /= i;
				this->mianownik /= i;

				return;
			}
		}
	}

	operator double()
	{
		return double(this->licznik) / double(this->mianownik);
	}
};

std::ostream& operator<<(std::ostream& output, Ulamek u)
{
	output << u.licznik << " / " << u.mianownik;
	return output;
}

Ulamek dodaj(Ulamek u1, Ulamek u2)
{
	int bottom = u1.mianownik * u2.mianownik;
	int top = (u1.licznik * u2.mianownik) + (u2.licznik * u1.mianownik);

	return Ulamek(top, bottom);
}

double kwadratLiczby(double num)
{
	return num * num;
}

void losoweUlamki(int amount)  //w poleceniu nie pisze bym zapisywal gdziekolwiek te obiekty, dlatego nie zrobilem tablicy
{
	srand(time(NULL));
	Ulamek max(0, 1);
	std::cout << "\n\nZadanie 6:\n";

	if (amount > 0) 
	{
		int top = (rand() % 2001) - 1000;
		int bottom = 0;	
		do		//losuj mianownik dopoki nie bedzie rozny od zera
		{
			bottom = (rand() % 2001) - 1000;
		} 
		while (bottom == 0);

		Ulamek u(top, bottom);
		std::cout << "\ti = 0 | " << u << "\n";
		max = u;
	}


	for (int i = 1; i < amount; i++)
	{
		int top = (rand() % 2001) - 1000;
		int bottom = 0;
		do		//losuj mianownik dopoki nie bedzie rozny od zera
		{
			bottom = (rand() % 2001) - 1000;
		} while (bottom == 0);

		Ulamek u(top, bottom);
		std::cout << "\ti = " << i << " | " << u << "\n";

		if (double(u) > double(max))
			max = u;
	}

	std::cout << "\tNajwiekszy ulamek: " << max << "\n";
}

int main()
{
	Ulamek arr[3] = {
		Ulamek(1, 2),
		Ulamek(5, 8),
		Ulamek(7, 9),
	};

	int arr_size = sizeof(arr) / sizeof(Ulamek);

	std::cout << "Zadanie 1:\n";
	for (int i = 0; i < arr_size; i++)
		std::cout << "\tarr[" << i << "] = " << arr[i] << "\n";

	std::cout << "\nZadanie 2:\n\tWynik dodawania: " << dodaj(arr[0], arr[1]);
	std::cout << "\n\nZadanie 3:\n\tWynik dodawania: " << dodaj(arr[0], Ulamek(7));
	std::cout << "\n\nZadanie 4:\n\tWynik potegowania: " << kwadratLiczby(arr[2]);

	Ulamek ulek(88, 22);
	ulek.skrocUlamek();

	std::cout << "\n\nZadanie 5:\n\tSkrocony ulamek (88/22): " << ulek;

	//Zadanie 6
	int N = 5;
	losoweUlamki(N);
}