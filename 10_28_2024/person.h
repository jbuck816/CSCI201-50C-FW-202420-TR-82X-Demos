#ifndef PERSON_H
#define PERSON_H
#include <string>
enum raceType
{
    NATIVE,
    ISLANDER,
    HISPANIC,
    WHITE,
    ASIAN,
    BLACK,
    OTHER
};

class person
{
public:
    person(std::string first_name, std::string last_name, int a, raceType r, double h, double w, std::string hair, std::string eye, char middle = '\0');
    std::string getName();
    std::string getFName();
    std::string getLName();
    std::string getMI();
    int getAge();
    std::string getRace();
    double getHeight();
    double getWeight();
    std::string getHairColor();
    std::string getEyeColor();
    void setName(std::string fn, std::string ln, char m = '\0');
    void setFName(std::string);
    void setLName(std::string);
    void setMI(char);
    void incrementAge(int);
    void setHeight(double);
    void setWeight(double);
    void setHairColor(std::string);

private:
    std::string fname;
    std::string lname;
    char mi;
    int age;
    raceType race;
    double height;
    double weight;
    std::string hairColor;
    std::string eyeColor;
};

class employee : public person
{
public:
    std::string getHireDate();
    double getSalary();
    int getEmpID();
    std::string getPosition();
    bool isHourly();
    void setSalary(double salary);
    void setPosition(std::string position);
    void setHourly(bool);

private:
    std::string hireDate;
    double salary;
    int empID;
    std::string position;
    bool hourly;
};

class student : public person
{
    double GPA;
    std::string major;
};

#endif