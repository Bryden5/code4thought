#include <iostream>

//initializing 3 subsystems
class SubSystemOne
{
public:
	void MethodOne(){ std::cout << "Adding: 32, 57, 8, 16 " << std::endl << "Answer: "; };
};

class SubSystemTwo
{
public:
	void MethodTwo(){ std::cout << "113"; };
};

class SubSystemThree
{
public:
	void MethodThree(){ std::cout << " multiplied by 1 is "; }
};


//The facade class containing x number of methods which make use of subsystems
class Facade
{
public:
    Facade()
    {
	pOne = new SubSystemOne();
	pTwo = new SubSystemTwo();
	pThree = new SubSystemThree();
    }

    void MethodA()
    {
	std::cout << "Entered addition Method.." << std::endl;
	pOne->MethodOne();
	pTwo->MethodTwo();
	std::cout << std::endl;
    }

    void MethodB()
    {
	std::cout << "Entered multiplication method.." << std::endl;
	pTwo->MethodTwo();
	pThree->MethodThree();
	pTwo->MethodTwo();
	std::cout << std::endl;
    }

private:
    SubSystemOne *pOne;
    SubSystemTwo *pTwo;
    SubSystemThree *pThree;
};

//main where methods from the facade class can be implemented 
int main()
{
    Facade *pFacade = new Facade();

    pFacade->MethodA();
    pFacade->MethodB();

    return 0;
}