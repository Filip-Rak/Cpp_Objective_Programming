#include <iostream>

int* doubleArray(int arr[4])
{
	for (int i = 0; i < 4; i++)
		arr[i] *= 2;

	return arr;
}

int main()
{
	int arr[4] = { 1, 6, -7, 3 };
	doubleArray(arr);

	for (int i = 0; i < 4; i++)
		std::cout << arr[i] << "\n";
}