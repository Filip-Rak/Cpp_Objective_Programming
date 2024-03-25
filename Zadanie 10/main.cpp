#include <iostream>

template<typename t, typename u>
class kalkulator {

public:
	kalkulator(t a, u b)
	{
		std::cout << "Dla: " << a << ", " << b << "\n";
		std::cout << "Dodawanie:\t" << this->dodawanie(a, b) << "\n";
		std::cout << "Odejmowanie:\t" << this->odejmowanie(a, b) << "\n";
		std::cout << "Mnozenie:\t" << this->mnozenie(a, b) << "\n";
		
		try {
			std::cout << "Dzielenie:\t" << this->dzielenie(a, b) << "\n\n";
		}
		catch (std::exception& e) {
			std::cout << "Blad: " << e.what() << "\n";
		}
	}

	t dodawanie(t a, u b) { return a + b; }
	t odejmowanie(t a, u b) { return a - b; }
	t mnozenie(t a, u b) { return a * b; }

	t dzielenie(t a, u b)
	{ 
		if (b == 0)
		{
			throw std::exception("dzielenie przez zero");
		}
		else
			return a / b; 
	}
};

int main()
{
	{
		int a = 3;
		int b = 8;
		kalkulator<int, int> k(a, b);
	}
	
	{
		float a = 2.53;
		float b = 2.99;
		kalkulator<float, float> k(a, b);
	}
	
	{
		double a = 5.22;
		unsigned int b = 7;
		kalkulator<double, unsigned int> k(a, b);
	}
}