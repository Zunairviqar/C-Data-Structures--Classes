#ifndef CCourse_hpp
#define CCourse_hpp
#include "constants.h"

#include <stdio.h>
#include "CStudent.hpp"

class CStudent;

class CCourse {
private:
    // --- add attributes here
    char * name;
    int code;
    int capacity;
    CStudent* enrolled[MAXSTCR];
    int nbEnrolled;

   
public:
    // --- add constr, distructor, memory management methods here
    CCourse(char* vname, int vcode);
    ~CCourse() ;
 
public:
    // --- add getters and setters here
    void enroll(CStudent* newstudent);
    void displayStudents();
    void displayInfo();
    CStudent* getStudent(int ind);
    void findBestStudent(double &bas, int &indexbas);
   
    char* getname();
    int getnbEnrolled();
public:
    // --- add othe methods here
    double* calcAverages();
    bool isFull();
   
} ;
#endif
