/*
* g++ -Wall -std=c++17 lecture2.cpp
* g++ -Wall -std=c++17 lecture2.cpp -o lectureCode
* g++ -Wall -std=c++17 lecture2.cpp -o lectureCode && ./lectureCode 
*/

#include <iostream>
#include <vector>
#include <fstream>

class Student 
{
    std::string m_first = "First";
    std::string m_last  = "Last"; 
    int         m_id    = 0;
    float       m_avg   = 0;


public:
    Student() {}
    Student(std::string first, std::string last, int id, float avg)
        : m_first(first)
        , m_last(last)
        , m_id(id)
        , m_avg(avg)
    {    
    }

    int getAvg() const
    {
        return m_avg;
    }
    int getID() const
    {
        return m_id;
    }
    std::string getFirst() const
    {
        return m_first;
    }
    std::string getLast() const
    {
        return m_last;
    }

    
    void print() const
    {
        std::cout << m_first << " " << m_last << " ";
        std::cout << m_id << " " << m_avg << "\n";
    }
};

class Course{
private:
    std::string m_name = "Course";
    std::vector<Student> m_students;

public:
    Course(){}

    Course(const std::string& name)
        : m_name(name)
    {
    }

    void addStudent(const Student& student)
    {
        m_students.push_back(student);
    }

    const std::vector<Student>& getStudents() const
    {
        return m_students;
    }

    void loadFromFile(const std::string& filename )
    {
        std::ifstream fin(filename);
        std::string first, last;
        int id;
        float avg;

        //fin will send it next string token into temp
        // while (fin >> temp)
        //in this case a toke is a string separated by while space 
        //or a new line
        while (fin >> first){
            fin >> last >> id >> avg;

            addStudent(Student(first, last, id, avg));
        }
    }

    void print() const
    {
        for(const auto& s : m_students)
        {
            s.print();
        }
    }
};

int main(int argc, char * argv[])
{
    int a = 42;
    int b = 10;

    int age = 30;
    std::string first = "Andre";
    std::string last = "Jarboe";

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << age << std::endl;
    std::cout << first << " " << last << std::endl;    

    std::vector<float> vec;
    vec.push_back(42);
    vec.push_back(10);

    std::cout << vec[0] << "\n";
    std::cout << vec[1] << "\n";
    std::cout << vec[2] << "\n"; // prints "memory" even though the vector is not that long...

    for(size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << "\n";
    }

    std::cout << "****Range****\n"; 
    for(int items : vec)
    {
        std::cout << items << "\n";
    }
    std::cout << "****Range with auto (be careful)****\n"; 
    for(auto items : vec)
    {
        std::cout << items << "\n";
    }
    std::cout << "**** Students ****\n"; 
    Student s1;
    Student s2("Andre", "Jarboe", 1, 95.6);

    /*
        never ant this one to change
        will get errors though:
        error: passing ‘const Student’ as ‘this’ argument discards qualifiers 
        so we have to add const to the student method:
        void print() const
        so any method that is not changing the class should be const
        this is const correctness  
    */
    const Student s3("Jane", "Doe", 20220001, 3.14);

    // std::cout << s3.getLast() << "\n";
    // s3.print();

    // Course comp4300("COMP 4300");
    // comp4300.addStudent(s1);
    // comp4300.addStudent(s2);
    // comp4300.addStudent(s3);
    // comp4300.addStudent(Student("Billy", "Paterson", 3, 50.0));

    // comp4300.print();

    Course c("COMP 4300");
    c.loadFromFile("students.txt");
    c.print();



    return 0;
}