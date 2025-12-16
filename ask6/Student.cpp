#include "Student.h"

Student::Student()
{
    name= "";
    aem = 0;
    age = 0;
    grade = 0.0;
}

Student::Student(int aem, int age, float grade)
{
    this->name = "";
    this->aem = aem;
    this->age = age;
    this-> grade = grade;
}

Student::Student(std::string name, int aem, int age, float grade)
{
    this->name = name;
    this->aem = aem;
    this->age = age;
    this-> grade = grade;
}

int Student::getAem() const
{
    return aem;
}

float Student::getGrade() const
{
    return grade;
}

void Student::setName(std::string name)
{
    this->name = name;
}

std::string Student::getName()
{
    return name;
}

std::ostream &operator<<(std::ostream& os, const Student& s)
{
    os << "Name: " << s.name << "\t"
             << "AEM : " << s.aem << "\t" 
             << "Age : " << s.age << "\t" 
             << "Grade: " << s.grade;   
    return os;
}