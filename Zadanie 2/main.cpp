#include <iostream>

class Pasazer {
	std::string name, surname;
	int age;

public:
	Pasazer(std::string name = "Imie", std::string surname = "Nazwisko", int age = 20)
	{
		this->name = name;
		this->surname = surname;
		this->age = age;
	}

	void setName(std::string name) { this->name = name; }
	void setSurname(std::string surname) { this->surname = surname; }
	void setAge(int age) { this->age = age; }

	std::string getSurname() { return this->surname; }
	std::string getName() { return this->name; }
	int getAge() { return this->age; }
};


class Autokar {
	std::string cel;
	Pasazer** pasazerowie;
	int ilosc_pasazerow;
	int wolne_miejsca;

public:
	Autokar(std::string cel, Pasazer* pasazerowie, int ilosc_pasazerow, int wolne_miejsca)
	{
		this->cel = cel;
		this->wolne_miejsca = wolne_miejsca;


		if (wolne_miejsca > ilosc_pasazerow)  //jezeli pasazerow jest mniej niz miejsc to
		{
			this->ilosc_pasazerow = ilosc_pasazerow;	//wszyscy sie mieszcza i ich wpisuje
			this->pasazerowie = new Pasazer * [ilosc_pasazerow];

			for (int i = 0; i < ilosc_pasazerow; i++)
				this->pasazerowie[i] = &pasazerowie[i];
			
			this->wolne_miejsca -= ilosc_pasazerow;

		}
		else 	// pasazerowie zajmuja wszystkie wolne miejsca i pierwsi zostana przepisani
		{
			this->pasazerowie = new Pasazer * [wolne_miejsca];
			this->ilosc_pasazerow = wolne_miejsca;

			for (int i = 0; i < this->wolne_miejsca; i++){
				this->pasazerowie[i] = &pasazerowie[i];
			}

			this->wolne_miejsca = 0;
		}
		

	}

	bool zmienWiek(int id, int new_age)
	{
		if (id >= this->ilosc_pasazerow || this->ilosc_pasazerow < 0)
			return false;
		
		this->pasazerowie[id]->setAge(new_age);
		return true;
	}

	void wyswietlDane()
	{
		std::cout << "-----Autokar-----";
		std::cout << "\nWolne miejsca: " << this->wolne_miejsca;
		std::cout << "\nZajete miejsca: " << this->ilosc_pasazerow;
		std::cout << "\nCel podrzy: " << this->cel;
		std::cout << "\nPasazerowie: \n";

		std::cout << "\tID\tImie:\tNazwisko:\tWiek:\n";
		for (int i = 0; i < this->ilosc_pasazerow; i++)
			std::cout << "\t" << i+1 << "\t" << this->pasazerowie[i]->getName() << "\t" << this->pasazerowie[i]->getSurname() << "\t" << this->pasazerowie[i]->getAge() << "\n";
	}
};

int main()
{
	Pasazer michau;
	michau.setName("Michal");
	michau.setSurname("Sfinks");

	std::cout << michau.getSurname() << "\n";  //podpunkt a

	const int p_size = 200;
	Pasazer* arr = new Pasazer[p_size];  //Podpunkt b: kontruktor wypelnil tablcie domyslnymi danymi


	Autokar autokar("Bieszczady", arr, p_size, 20);  //podpunkt C

	std::cout << "zmienWiek() = " << autokar.zmienWiek(0, 35) << "\n\n";  //Podpunkt D
	autokar.wyswietlDane();
}