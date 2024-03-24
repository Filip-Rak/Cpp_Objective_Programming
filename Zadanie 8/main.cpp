#include <iostream>

class Wektor {
	friend std::ostream& operator<<(std::ostream& out, Wektor w);
	friend Wektor operator+(Wektor a, Wektor b);
	friend double operator*(Wektor a, Wektor b);
	friend void printOrdered(Wektor* arr, int size);
	friend Wektor closest(Wektor tgt, Wektor* arr, int size);

	int x, y;
	double length = NULL;
public:
	Wektor(int x = 0, int y = 0) : x(x), y(y){
		policzDlugosc();
	}
	
	void policzDlugosc()
	{
		this->length = sqrt(pow(this->x, 2) + pow(this->y, 2));
	}
};

std::ostream& operator<<(std::ostream& out, Wektor w)
{
	out << "x: " << w.x << "\ty: " << w.y << "\tdl: " << w.length;
	return out;
}

Wektor operator+(Wektor a, Wektor b){
	return Wektor((a.x + b.x), a.y + b.y);
}

double operator*(Wektor a, Wektor b)
{
	return (a.x * b.x) + (b.y * a.y);
}

void printOrdered(Wektor* arr, int size)
{
	std::cout << "\nZadanie 4:\n";

	for (int i = 0; i < size; i++)	//posortuj wektory
	{
		int min = i;

		for (int j = i + 1; j < size; j++)
		{
			if (arr[j].length < arr[min].length)
				min = j;
		}

		//Zamien wektory
		Wektor cp = arr[min];
		arr[min] = arr[i];
		arr[i] = cp;

		//od razu wypisz wektor

		std::cout << "\tWektor: " << arr[i] << "\n";
	}
}

Wektor closest(Wektor tgt, Wektor* arr, int size)
{
	int min = 0;

	for (int i = 1; i < size; i++)
	{
		if (abs(arr[i].length - tgt.length) < abs(arr[min].length - tgt.length))
			min = i;
	}

	return arr[min];
}

int main()
{
	Wektor w1(3, 5), w2(-2, 7);
	std::cout << "Zadanie 1:\n\t" << w1 << "\n\t" << w2;
	std::cout << "\n\nZadanie 2:\n\tw1 + w2 = " << w1 + w2 << "\n";
	std::cout << "\nZadanie 3:\n\tw1 * w2 = " << w1 * w2 << "\n";

	const int size = 20;
	Wektor arr[size];

	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		int x = (rand() % 31) - 15;
		int y = (rand() % 31) - 15;

		arr[i] = Wektor(x, y);
	}

	printOrdered(arr, size);

	std::cout << "\nZadanie 5:\n\tWektor: " << w1 << "\n\tNajblizszy dlugoscia: " << closest(w1, arr, size) << "\n";
}