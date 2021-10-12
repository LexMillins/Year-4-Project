#include <iostream>

void change(int *x){

*x = 10;
}


void work(int*a){
	*a=11;
}
int main()


{
	//int *x = new int(5);
	//change(x);
	//std::cout << *x << std::endl;
	//delete x;
	int x = 10;
	work(&x);
	std::cout << x << std::endl;
	return 0;

}