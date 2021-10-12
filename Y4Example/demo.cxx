#include <iostream>

int main()
{
	int x = 5;
	int* y = &x;
	x = 6;
	int z = 10;
	y =&z;
	*y = 60;

	std::cout << &x << std::endl;
	std::cout << *y << " " << x << " " << z << std::endl;
	return 0;