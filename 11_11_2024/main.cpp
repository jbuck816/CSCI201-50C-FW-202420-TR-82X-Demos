#include <iostream>
#include "person.h"

enum personType
{
    PERSON,
    EMPLOYEE,
    STUDENT
};

void addToParty(person **party, person *, int &nextPos);
person createPerson();

// fix the main (remove create person add student constructor and fill in createStudent)
// don't forget makeCopy in student
employee createEmployee();
student createStudent();

int main()
{
    person **party;
    party = new person *[10];
    int position = 0;
    while (true)
    {
        personType type;
        int personInt;
        std::cout << "What kind of person will be attending the party?" << std::endl;
        std::cout << "1. Person" << std::endl;
        std::cout << "2. Employee" << std::endl;
        std::cout << "3. Student" << std::endl;
        std::cin >> personInt;
        personInt -= 1;

        // insert validation loop here
        switch (personInt)
        {
        case PERSON:
        {
            person p = createPerson();
            addToParty(party, &p, position);
            break;
        }
        case EMPLOYEE:
        {
            employee e = createEmployee();
            addToParty(party, &e, position);
            break;
        }
        case STUDENT:
            break;
            // p = createStudent();
        }
        // addToParty(party, p, position);
        if (position == 10)
        {
            break;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        std::cout << party[i]->tostring() << std::endl
                  << std::endl;
    }
    return 0;
}

void addToParty(person **party, person *personToAdd, int &position)
{
    party[position] = personToAdd->makeCopy();
    position++;
}

person createPerson()
{

    return person("Harry", "Potter", 40, WHITE, 5.7, 175, "brown", "green");
}

employee createEmployee()
{

    return employee("Santa", "Claus", 565, OTHER, 6, 400, "white", "blue", "2024-11-10", 60000, 1, "Head delivery guy", false);
}

student createStudent()
{
    return nullptr;
}
