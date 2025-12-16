#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cctype>
#include "Student.h"

using namespace std;

const float EPS = 1e-6f;

vector<const Student*> findTopStudent(const vector<Student>& students)
{
    vector<const Student*> bestStudent;
    if(students.empty()) { throw runtime_error("No students available"); }

    float maxGrade = students[0].getGrade();
    bestStudent.emplace_back(&students[0]);
    for(size_t i=1; i < students.size(); i++)
    {
        if(students[i].getGrade() > maxGrade)
        {
            maxGrade = students[i].getGrade();
            bestStudent.clear();
            bestStudent.emplace_back(&students[i]);
        }
        else
        {
            if(std::fabs(students[i].getGrade() - maxGrade) < EPS)
            {
                bestStudent.emplace_back(&students[i]);
            }
        }
    }
    return bestStudent;
}


double averageGrade(const vector<Student>& students)
{
    if(students.size() == 0) {return 0.0;}

    double sum = 0.0;
    for(const Student& s : students)
    {
        sum += s.getGrade(); 
    }

    return sum/students.size();
}

float minGrade(const vector<Student>& students)
{
    if(students.empty()) { throw runtime_error("No students available"); }
    float min = students[0].getGrade();
    for(size_t i=1; i < students.size(); i++)
    {
        if(students[i].getGrade() < min)
        {
            min = students[i].getGrade();
        }
    }
    return min;
}

void sortStudents(vector<Student>& students)
{
    sort(students.begin(), students.end(), 
            [](const Student& a, const Student& b){return a.getGrade() > b.getGrade();});
}

struct Age
{
    static constexpr int min = 18;
    static constexpr int max = 60;
};

struct Grade
{
    static constexpr float min = 0.0f;
    static constexpr float max = 10.0f;
};

struct Aem
{
    static constexpr int min = 001;
    static constexpr int max = 99999;
};

struct N
{
    static constexpr int min = 1;
    static constexpr int max = 30;
};


template <typename T, typename Rule>
T readValue(const string& msg)
{
    T value;
    while(true)
    {
        cout << msg;
        cin >> value;
        if(cin.fail() || value < Rule::min || value > Rule::max)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input" << endl;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

bool isValidName(const std::string& name)
{
    if(name.empty() || name.length() > 32)
        return false;

    bool previousSpace = false;

    for(size_t i = 0; i < name.length(); i++)
    {
        char c = name[i];

        if(std::isalpha(static_cast<unsigned char>(c)))
        {
            previousSpace = false;
        }
        else if(c == ' ')
        {
            
            if(i == 0 || previousSpace)
                return false;

            previousSpace = true;
        }
        else
        {
            
            return false;
        }
    }

    if(name.back() == ' ')
        return false;

    return true;
}


std::string readName(const std::string& msg)
{
    std::string name;
    while(true)
    {
        std::cout << msg;
        std::getline(std::cin, name);

        if(isValidName(name))
            return name;

        std::cout << "Invalid name (letters & one space only, max 32 chars)\n";
    }
}

Student* findByAem(std::vector<Student>& students, int aem)
{
    for(Student& s : students)
        if(s.getAem() == aem)
            return &s;
    return nullptr;
}

Student* findByName(std::vector<Student>& students, const std::string& name)
{
    for(Student& s : students)
        if(s.getName() == name)
            return &s;
    return nullptr;
}

int main()
{
    int n, aem, age;
    float grade;
    std::string name;
    n = readValue<int, N>("How many Students do you want to register? : ");

    vector<Student> students;
    for(int i=0; i<n; i++)
    {
        cout << i+1 << " Student:" << endl;
        name = readName("Name: ");
        aem = readValue<int, Aem>("AEM : ");
        age = readValue<int, Age>("Age : ");
        grade = readValue<float, Grade>("Grade : ");
        students.emplace_back(name, aem, age, grade);
        cout << endl;
    }

    vector<const Student*> top = findTopStudent(students);
    cout<<"Top Students : " << endl;
    for (const Student* s : top) 
    {
        cout << *s << endl;
    }
    cout << "\n";
    float minG = minGrade(students);
    cout << "Minimum Grade is: " << minG << endl;
    cout << "\n";
    cout << "The average grade is: " << averageGrade(students) << endl;
    cout << "\n";
    sortStudents(students);

    /*cout << "All Students: " << endl;
    for (const Student& s : students) 
    {
        cout << s << endl;
    }*/
    char choice;
    do
    {
        std::cout << "\nSearch Student by:\n";
        std::cout << "1. Name\n";
        std::cout << "2. AEM\n";
        std::cout << "q. Quit\n";
        std::cout << "Choice: ";

        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(choice)
        {  
            case '1':
            {
                name = readName("Enter Name: ");

                Student* s = findByName(students, name);

                if(s)
                    std::cout << "Found: " << *s << endl;
                else
                    std::cout << "Student not found\n";
                break;
            }

            case '2':
            {
                int aem = readValue<int, Aem>("Enter AEM: ");

                Student* s = findByAem(students, aem);

                if(s)
                    std::cout << "Found: " << *s << endl;
                else
                    std::cout << "Student not found\n";
                break;
            }

            case 'q':
                std::cout << "Exiting program...\n";
                break;

            default:
                std::cout << "Invalid choice. Press 1, 2 or q.\n";
        }

    } while(choice != 'q');

    return 0;
}