
#pragma once

#include <string>
#include <iostream>

class Person
{
public:

    void set_name(const std::string& new_name) {name = new_name;}
    void set_address(const std::string& new_address) {address = new_address;}

    const std::string& get_name() const {return name;}
    const std::string& get_address() const {return address;}

    bool equals(const Person& p);

private:

    std::string name;
    std::string address;
};

bool Person::equals(const Person& p)
{
    return name == p.name && address == p.address;
}

int main()
{
    int person_count = 0;
    Person persons[5];

    while(true)
    {
        if(person_count >= 5)
        {
            std::cout << "Cannot store any more persons!" << std::endl;
            break;
        }

        std::string temp;
        std::cout << "Do you want to add a new person (y or n)? ";
        std::cin >> temp;

        if(temp == "n")
            break;
        else if (temp == "y")
        {
            std::string name;
            std::string address;

            std::cout << "Please enter the name of the new person: ";
            std::cin >> name;

            std::cout << "Please enter the address of the new person: ";
            std::cin >> address;

            Person person;
            person.set_name(name);
            person.set_address(address);
            persons[person_count] = person;
            ++person_count;

#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
        }
    }

    for(int i = 0; i < person_count; ++i)
    {
        std::cout << (i + 1) << ") Person Info:\n"
            "Name: " << persons[i].get_name() << "\n"
            "Address: " << persons[i].get_address() << "\n" << std::endl;
    }

    return 0;
}