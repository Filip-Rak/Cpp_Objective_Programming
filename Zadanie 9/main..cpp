#include <iostream>



class Osoba {

	friend std::ostream& operator<<(std::ostream& out, Osoba os);

protected:

	std::string imie, nazwisko;

	int rok_urodzenia;

public:

	Osoba(std::string i = "imie", std::string n = "nazwisko", int r = 0) : imie(i), nazwisko(n), rok_urodzenia(r) {}



	virtual void wypisz()

	{

		std::cout << this->imie << " " << this->nazwisko << " " << this->rok_urodzenia;

	}



	virtual int wiek()

	{

		return 2022 - this->rok_urodzenia;

	}

};



class Student : public Osoba{

	friend std::ostream& operator<<(std::ostream& out, Student s);

	std::string kierunek_studiow;

	int rok_studiow;

public:

	Student(std::string k, int r, std::string i, std::string n, int r2) 

		: kierunek_studiow(k), rok_studiow(r), Osoba(i, n, r2) {}



	virtual void wypisz()

	{

		std::cout << "\n\tImie: " << this->imie << "\n\tNazwisko: " << this->nazwisko;

		std::cout << "\n\tData urodzenia: " << this->rok_urodzenia;

		std::cout << "\n\tKierunek: " << this->kierunek_studiow << "\n\tRok studiow: " << this->rok_studiow;

	}



	virtual int wiek()

	{

		return 2022 - this->rok_urodzenia;

	}

};



class Pracownik : public Osoba{

	friend std::ostream& operator<<(std::ostream& out, Pracownik p);

	std::string miejsce_pracy, zawod;

public:

	Pracownik(std::string m, std::string z, std::string i, std::string n, int r2) 

		: miejsce_pracy(m), zawod(z), Osoba(i, n, r2) {}



	Pracownik(Pracownik& p, std::string n, int r) //konstruktor kopiujacy

		: miejsce_pracy(p.miejsce_pracy), zawod(p.zawod), Osoba(p.imie, n, r) {}



	virtual void wypisz()

	{

		std::cout << "\n\tImie: " << this->imie << "\n\tNazwisko: " << this->nazwisko;

		std::cout << "\n\tData urodzenia: " << this->rok_urodzenia;

		std::cout << "\n\tMiejsce pracy: " << this->miejsce_pracy << "\n\tZawod: " << this->zawod;

	}



	virtual int wiek()

	{

		return 2022 - this->rok_urodzenia;

	}



};



std::ostream& operator<<(std::ostream& out, Osoba os)

{

	out << os.imie << " " << os.nazwisko << " " << os.rok_urodzenia;



	return out;

}



std::ostream& operator<<(std::ostream& out, Student s)

{

	out << "\n\tImie: " << s.imie << "\n\tNazwisko: " << s.nazwisko;

	out << "\n\tData urodzenia: " << s.rok_urodzenia;

	out << "\n\tKierunek: " << s.kierunek_studiow << "\n\tRok studiow: " << s.rok_studiow;



	return out;

}



std::ostream& operator<<(std::ostream& out, Pracownik p)

{

	out << "\n\tImie: " << p.imie << "\n\tNazwisko: " << p.nazwisko;

	out << "\n\tData urodzenia: " << p.rok_urodzenia;

	out << "\n\tMiejsce pracy: " << p.miejsce_pracy << "\n\tZawod: " << p.zawod;



	return out;

}



int  funckja(Osoba** tab, int size, Osoba** dest)

{

	int j = 0;



	for (int i = 0; i < size; i++)

	{

		if (tab[i]->wiek() < 30)

			j++;

	}



	Osoba** nowa = new Osoba*[j];



	int w = 0;

	for (int i = 0; i < size; i++)

	{

		//if (tab[i]->wiek() < 30)

			//nowa[w++] = tab[i];

	}

	dest = nowa;



	return w;

}



int main()

{

	Osoba* os = new Osoba("Maciej", "Sfinks", 1989);

	std::cout << "Zadanie 1:\n\t" << *os;





	Student s("Informatyka", 4, "Michau", "Ek", 15);

	std::cout << "\n\nZadanie 2: " << s;





	Pracownik p1("Krakow", "Mechanik", "Tomek", "Borowy", 2002), p2(p1, "Makrela", 1985);

	std::cout << "\n\nZadanie 3: " << p1 << "\n";

	std::cout << p2;

	



	Osoba** tab = new Osoba*[4];

	tab[0] = os; 

	tab[1] = &s;

	tab[2] = &p1;

	tab[3] = &p2;



	std::cout << "\n\nZadanie 4: ";

	for (int i = 0; i < 4; i++)

	{

		tab[i]->wypisz();

		std::cout << "\n";

	}





	std::cout << "\n\nZadanie 5: ";

	Osoba** nowa = new Osoba*[4];

	int ssize = funckja(tab, 4, nowa);



	for (int i = 0; i < ssize; i++)

	{

		nowa[i]->wypisz();

	}



}