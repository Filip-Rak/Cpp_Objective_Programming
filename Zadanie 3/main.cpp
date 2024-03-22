#include <iostream>

namespace Ksiazki
{
	class Ksiazka {
		std::string tytul, autor;
		int rok_wydania;
		static int licznik;

	public:
		Ksiazka(std::string tytul = "title", std::string autor = "author", int rok_wydania = 2023): tytul(tytul), autor(autor), rok_wydania(rok_wydania)
		{
			std::cout << "Utworzono ksiazke nr: " << ++this->licznik << "\n";
		}

		bool czyXXwiek()
		{
			return rok_wydania >= 1901 && rok_wydania <= 2000;
		}
		
		void print(){
			std::cout << "Tytul: " << this->tytul << " Autor: " << this->autor << " Rok wydania: " << this->rok_wydania << "\n";
		}

		int getYear() { return this->rok_wydania; }
		int getCounter() { return this->licznik; }
	};

	int Ksiazka::licznik = 0;
}


void sortArr(Ksiazki::Ksiazka* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int max_index = i;
		for (int j = 1 +  i; j < size; j++)  //znajdz najwiekszy element
		{
			if (arr[j].getYear() > arr[max_index].getYear())
				max_index = j;
		}

		Ksiazki::Ksiazka buffer = arr[max_index]; //zamien elementy
		arr[max_index] = arr[i];
		arr[i] = buffer;
	}
}


int main() 
{
	Ksiazki::Ksiazka b("Wichorwe Wzgorza", "Maciej", 1886);  //podpunkt a
	const int size = 4;
	Ksiazki::Ksiazka books[size] = {   
		Ksiazki::Ksiazka("Muminki", "Antonio", 1989),
		Ksiazki::Ksiazka("the witch", "Andrew Dud", 1785),
		Ksiazki::Ksiazka("Night", "50 cent", 2000),
		Ksiazki::Ksiazka("Amongus", "Sus", 2004),
	}; 

	std::cout << "\nPodpunkt a\n";
	for (int i = 0; i < size; i++)
		books[i].print();

	std::cout << "\nPodpunkt b";  //Podpunkt b
	for (int i = 0; i < size; i++)  
		std::cout << "\nbooks[" << i << "], czyXXwiek() = " << books[i].czyXXwiek() << "";


	sortArr(books, size);  //podpunkt c

	std::cout << "\n\nPodpunkt c:\n";
	for (int i = 0; i < size; i++)
		books[i].print();


	//podpunkt d
	std::cout << "\nPodpunkt d: " << b.getCounter();
}