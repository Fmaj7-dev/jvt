
#include <iostream>
#include <string>

struct SPerson
{
    int age;
};

void printData(SPerson& p)
{
    std::cout<<p.age<<"\n";
}

class CPerson
{
public:
    int age;
    std::string name;

    CPerson(int a, std::string n)
    {
        age = a;
        name = n;
    }

    void printData()
    {
        std::cout<<age<<" "<<name<<"\n";
    }

};


int main()
{
    CPerson cp(18, "Javier");
    
    cp.printData();

    SPerson sp;
    sp.age = 18;
}