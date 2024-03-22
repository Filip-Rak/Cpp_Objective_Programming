#include <iostream>

int main()
{
	const int size = 100;
	int arr[size];

	for (int i = 0; i < size; i++)
		arr[i] = i;

	if (arr[9] % 2 == 0)
		std::cout << "element 10-ty jest podzielny przez 2\n";
	else
		std::cout << "element 10-ty nie jest podzielny przez 2\n";

	int* pointer = &arr[10];  //11-ty element
	std::cout << *pointer;
}