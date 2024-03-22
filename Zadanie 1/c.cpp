#include <iostream>

struct Batonik {
private:
	std::string marka;
	float waga;
	int liczba_kalorii;

public:
	Batonik(std::string marka, float waga, int kalorie)
	{
		this->marka = marka;
		this->waga = waga;
		this->liczba_kalorii = kalorie;
	}

	void print()
	{
		std::cout << "Marka:\t" << this->marka;
		std::cout << "\nWaga:\t" << this->waga;
		std::cout << "\nLiczba Kalorii:\t" << this->liczba_kalorii;
	}
};

int main()
{
	Batonik snack("Bounty", 57, 278);
	snack.print();
}