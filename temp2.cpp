#include<iostream>
using namespace std;
int main()
{
    {
        class Aditya
        {
        int x;
        public:
           class C
           {
                public:
                C() {cout<<"\nWelcome to C";}
           };
           C obj;
           Aditya() {cout<<endl<<"Welcome to Aditya";}
        };
       Aditya obj;  
    }
   
}