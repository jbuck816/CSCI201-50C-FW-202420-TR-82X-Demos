#include "person.h"

// add two members to student, prototype getters and setters, implement constructor
int main()
{
    person p("Lawrence", "Long", 64, HISPANIC, 5.5, 156.4, "brown", "brown", 'E');
    employee e("M\'lara", "Horon", 63, OTHER, 5.42, 209, "purple", "yellow", "2024-03-31", 89725, -3651, "Route driver", true);
    e.getFName();

    return 0;
}