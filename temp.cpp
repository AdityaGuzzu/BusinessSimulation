#include<iostream>
int main()
{
	
	int i = 1;
	for(i=1;i<=100;i++)
	{
		if(i%5 == 0 && i%3 == 0)
		{
			std::cout<<"\nFizzBuzz";
		}
		else if(i%5 == 0)
		{
			std::cout<<"\nBuzz";
		}
		else if(i%3 == 0)
		{
			std::cout<<"\nFizz";
		}
		else
		{
			std::cout<<"\n"<< i;
		}
	}
}