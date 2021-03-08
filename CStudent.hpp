#ifndef CStudent_hpp
#define CStudent_hpp
#include <string>
#include <stdio.h>
#include "CCourse.hpp"
#include "constants.h"

using namespace std;

 class CCourse;

 class CStudent {
 private:
     // --- add attributes here
     char* name;
     int ID;
     int maxCourses;
     CCourse *courses[MAXCRST];
     int nbCourses;
     int **grades;
     
 public: //Memory management methods
     // --- constr, desctructor add Memory management methods here
     CStudent(char* vname, int vid) ;
     ~CStudent() ;
     
 public:
     // --- add getters and setters here
     void enroll(CCourse* newcourse);
     void setCourseGrades(int ci, int arrscores[]);
     void setExamGrades(int ci, int ei, int score);
     void displayCourses();
     void displayInfo();
     int getIndex(CCourse* cp);
    
     char* getName();
     int getID();
     int getmaxCourses();
     int getnbCourses();
     void displayExamGrades();
 public:
     // --- add grades methods here
     double* calcAverages();
     
 public:
     // --- add other methods here
     bool isFull();
     bool isEnrolledIn(CCourse *pc);
} ;

#endif
