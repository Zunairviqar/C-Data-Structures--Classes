#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "constants.h"
#include "CDept.hpp"
#include "CCourse.hpp"
#include "CStudent.hpp"

CDept::CDept() {
    // -- do it here --
    students = new CStudent* [MAXNBST];
    courses = new CCourse* [MAXNBCR];
    createStudents();
    createCourses();
    enrollStudentsInCourses();
    createDefaultGrades();
}

CDept::~CDept() {
    // -- do it here --
    delete[] students;
    delete[] courses;
}

CStudent* CDept::getStudent(int index)
{
    // -- do it here --
    if (index>-1 && index<nbStudents)
        return students[index];
    else
        return NULL; //Added to avoid compiler error. Replace it with the right return statement
}

CCourse* CDept::getCourse(int index)
{
    // -- do it here --
    if (index>0 && index<nbCourses)
        return courses[index];
    else
        return NULL ; //Added to avoid compiler error. Replace it with the right return statement
}

void CDept::createStudents() {
    char* stNames[] = {(char*)"Bill", (char*)"Alex", (char*)"Bob", (char*)"Ana", (char*)"Lilya",
        (char*)"Julie", (char*)"Chris", (char*)"Stef", (char*)"Max", (char*)"Ray"} ;
    int stCodes[]   = {105, 115, 125, 135, 145, 155, 165, 175, 185, 195} ;
   
    // Let's create 5 students,
    nbStudents= 5 ;
    for(int st= 0; st<nbStudents; st++) students[st] = new CStudent(stNames[st], stCodes[st]) ;
}

void CDept::createCourses() {
    char* crNames[] = {(char*)"CSO", (char*)"OS", (char*)"DB", (char*)"D. Math", (char*)"Software Eng",
        (char*)"logic", (char*)"AI", (char*)"Algo", (char*)"NLP", (char*)"Prog 1"} ;
    int crCodes[]   = {106, 116, 126, 206, 216, 226, 306, 316, 326, 406} ;
   
    // Let's create 5 students,
    nbCourses= 5 ;
    for(int cr= 0; cr<nbCourses; cr++) courses[cr] = new CCourse(crNames[cr], crCodes[cr]) ;
}

void CDept::enrollStudentsInCourses()
{
    srand((unsigned int)time(0));
    // -- do it here --
    int nbc, c;
    for (int i=0; i<nbStudents; i++) { //repeat for every student
        nbc=rand() % nbCourses; //get a random number of courses to enroll the student in
        int added[nbc];
        for (int j=0; j<nbc; j++) {
            bool found = true;
            c=rand() % nbCourses; //get a random course index to enroll
            added[j] = c;
            while (found == true) { //loop to check if already enrolled in the course
                found = false;
                for (int k=0; k<j; k++) {
                    if (added[k] == c) {
                        found = true;
                        c=rand() % nbCourses;
                    }
                }
            }
            enroll(students[i], courses[c]);
        }
    }

}

void CDept::createDefaultGrades()
{
    // Use current time as seed for random generator
    srand((unsigned int)time(0));
   
    // -- do it here --
    int nbc, score;
    for (int i=0; i<nbStudents; i++) { //for every student
        nbc = students[i]->getnbCourses();
        for (int j=0; j<nbc; j++) { //for every course
            for (int k=0; k<NBEXAMS; k++) { //for every exam
                score = rand() % 101; //create random grade

                students[i]->setExamGrades(j, k, score);
            }
        }
    }

}

bool CDept::addStudent() {
    // -- do it here --
 /*   char* stNames[] = {(char*)"Bill", (char*)"Alex", (char*)"Bob", (char*)"Ana", (char*)"Lilya",
           (char*)"Julie", (char*)"Chris", (char*)"Stef", (char*)"Max", (char*)"Ray"} ;
    int stCodes[]   = {105, 115, 125, 135, 145, 155, 165, 175, 185, 195} ; */

    string n;
    int sCode =0;
    //add a student by user input
    cout<< "Enter The Name Of The Student"<<endl;
    cin>>n;
    cout<<"Enter the ID of the Student"<<endl;
    cin>>sCode;
    
    int s = n.length();
    char* sName;
    sName = new char[s+1];
       strcpy(sName, n.c_str());
      
    if(nbStudents<MAXNBST){ //check capacity
        students[nbStudents] = new CStudent(sName, sCode);
        nbStudents++;
        cout<< "Student Added To The Department"<<endl;
        return true;
    }
    else{
        cout<< "Already a maximum number of students in the department"<<endl;
        return false;//or return false
    }
    
}

void CDept::enterStudentGrades(CStudent* ps, CCourse* pc, int gr[])
{
    int index = -1;
    for (int i=0; i<nbStudents; i++) { //get the index to be entered grades in
        if (pc->getname() == courses[i]->getname()) {
            index = i;
        }
    }
    ps->setCourseGrades(index, gr);
    cout<<"Course Grades Entered"<<endl;
}

bool CDept::addCourse() {
    string n;
    int crCode =0;
    //add course by user input
    cout<< "Enter The Name Of The Course"<<endl;
    cin>>n;
    cout<<"Enter the code of the Course"<<endl;
    cin>>crCode;
    
    int s = n.length();
    char* crName;
    crName = new char[s+1];
       strcpy(crName, n.c_str());
      
    if(nbCourses<MAXNBCR){ //check capacity
        courses[nbCourses] = new CCourse(crName, crCode);
        nbCourses++;
        cout<< "Course Added To The Department"<<endl;
        return true;
    }
    else{
        cout<< "Already a maximum number of courses in the department"<<endl;
        return false;//or return false
    }
}

bool CDept::enroll(CStudent* ps, CCourse* pc) {
    // -- do it here --
   if (!ps->isFull() && !pc->isFull()) {
        pc->enroll(ps);
        return true;
    }

    return false; //or return false
}

void CDept::displayStudents() {
    // -- do it here --
    for (int i=0; i<nbStudents; i++) {
        students[i]->displayInfo();
    }
}

void CDept::displayCourses() {
    // -- do it here --
    for (int i=0; i<nbCourses; i++) {
        courses[i]->displayInfo();
    }
}

void CDept::findCourses(CStudent* ps) {
    ps->displayCourses();
}

CStudent* CDept::findBestStudent(CCourse* pc) {
    double bas;
    int indexbas;
    pc->findBestStudent(bas, indexbas);
    CStudent* best = pc->getStudent(indexbas);
    
    return best;
}

CStudent* CDept::highestAvgGrade() {
    double average = 0;
    double max = 0;
    int maxIndex = -1;
    for (int i=0; i<nbStudents; i++) { //check every student
        if (students[i]->getnbCourses() > 2) { //if student has at least 3 courses
            for (int j=0; j<students[i]->getnbCourses(); j++) {
                average += students[i]->calcAverages()[j]; //add all the averages
            }
            average = average/students[i]->getnbCourses(); //find total average
        }
        if (average > max) { //if average greater than current average
            max = average;
            maxIndex = i;
        }
    }
    
    return students[maxIndex];
}

int CDept::getnbCourses()
{
    return nbCourses;
}
