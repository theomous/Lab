#ifndef STUDENT_H
#define STUDENT_H

#include <ostream>
#include <string>

class Student
{
private:
    std::string name;
    int aem;
    int age;
    float grade;

public:
    Student();
    Student(int, int, float);
    Student(std::string, int, int, float);
    int getAem() const;
    float getGrade() const;
    std::string getName();
    void setName(std::string);
    friend std::ostream &operator<<(std::ostream&, const Student&);
};



#endif