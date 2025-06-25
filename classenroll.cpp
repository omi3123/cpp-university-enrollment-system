#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Course {
public:
    int course_id;
    string course_name;
    Course(int id, string name) {
        course_id = id;
        course_name = name;
    }
    void display() const {
        cout << "Course ID: " << course_id << " | Name: " << course_name << endl;
    }
};
class Student {
public:
    int student_id;
    string name;
    vector<Course> enrolled_courses;
    Student(int id, string n) {
        student_id = id;
        name = n;
    }
    void enroll(Course course) {
        enrolled_courses.push_back(course);
        cout << name << " enrolled in " << course.course_name << endl;
    }
    void display() const {
        cout << "Student ID: " << student_id << " | Name: " << name << endl;
        cout << "Enrolled Courses:" << endl;
        for (const Course& c : enrolled_courses) {
            cout << " - " << c.course_name << endl;
        }
    }
};
class University {
public:
    vector<Student> students;
    vector<Course> courses;
    void add_student(int id, string name) {
        students.emplace_back(id, name);
        cout << "Student " << name << " added.\n";
    }
    void add_course(int id, string name) {
        courses.emplace_back(id, name);
        cout << "Course " << name << " added.\n";
    }
    void enroll_student(int student_id, int course_id) {
        Student* student = nullptr;
        Course* course = nullptr;
        for (auto& s : students)
            if (s.student_id == student_id)
                student = &s;
        for (auto& c : courses)
            if (c.course_id == course_id)
                course = &c;
        if (student && course)
            student->enroll(*course);
        else
            cout << "Student or course not found.\n";
    }
    void view_all_students() {
        for (const Student& s : students)
            s.display();
    }
};