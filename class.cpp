#include <iostream>
using std::string;

class employee
{
private:
    string name;
    string company;
    int age;

public:
    void setName(string Name)
    {
        name = Name;
    }
    void setCompany(string Company)
    {
        company = Company;
    }
    void setAge(int Age)
    {
        if (Age > 18)
        {
            age = Age;
        }
    }

    string getName() { return name; }
    string getCompany() { return company; }
    int getAge() { return age; }
    void IntroduceYourself()
    {
        // test
        std::cout << "Name: " << name << std::endl;
        std::cout << "Company: " << company << std::endl;
        std::cout << "Age: " << age << std::endl;
    }

    employee(string Name, string Company, int Age)
    {
        name = Name;
        company = Company;
        age = Age;
    }
};

int main()
{
    employee employee1 = employee("John", "Tesla", 35);
    
    employee1.IntroduceYourself();

    employee1.setAge(15);
    std::cout << employee1.getName() << " is " << employee1.getAge() << " years old" << std::endl;

    return 0;
}