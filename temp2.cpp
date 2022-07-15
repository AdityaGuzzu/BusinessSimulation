//A program to demonstrate the use of default constructiors in inheritance
#include<iostream>
#include<stdlib.h>
class par      //parent class    
{
	public:
	int x;
	par()    //Parent class constructor
	{
		
		std::cout<<"\nWelcome to the parent class";
	}
};
class child: public par   //child classs inherited publicly
{
    public:
    child()        //child class constructor
    {  
        std::cout<<"\nWelcome to child class";
    }
};

int main()
{
    par obj;        //object of parent class
    child obj2;     //object of child class
}