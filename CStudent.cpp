#include <iostream>
#include "constants.h"
#include "CStudent.hpp"
#include "CCourse.hpp"

CStudent::CStudent(char* vname, int vid)
{
     // --- add constructir definition here
    name = new char [strlen(vname) +1];
    strcpy(name,vname);
    ID = vid;
    maxCourses = MAXCRST;
    nbCourses = 0;
    for(int i = 0 ; i <MAXCRST ;i++)
    {
        courses[i] = NULL;
    }
    grades = new int* [maxCourses];
    for(int i=0 ; i<maxCourses ; i++) {
    grades[i] = new int [NBEXAMS] ;
    }
    for(int i =0; i <maxCourses; i++)
        for(int j =0; j< NBEXAMS; j++)
            grades[i][j] = -1;
}

CStudent::~CStudent()
{
    // --- add destructor definition here
    delete name;
    
    for (int i=0 ; i<maxCourses ; i++) {
    delete [] grades[i];
    }
    delete [] grades;
}
void CStudent::enroll(CCourse* newcourse)
{
    if(nbCourses < MAXCRST)
    {
    courses[nbCourses] = newcourse;
    nbCourses++;
    }
}

char* CStudent::getName()
{
    return name;
}

int CStudent::getID()
{
    return ID;
}

int CStudent::getmaxCourses()
{
    return maxCourses;
}
int CStudent::getnbCourses()
{
    return nbCourses;
}


void CStudent::setCourseGrades(int ci, int arrscores[])
{
    if(ci > -1 && ci < nbCourses){
    for(int i =0; i < NBEXAMS; i++)
    {
        grades[ci][i]=arrscores[i];
    }
    }
}
void CStudent::setExamGrades(int ci, int ei, int score)
{
    if(ci > -1 && ci < nbCourses){
    if(ei > -1 && ei < NBEXAMS){
    grades[ci][ei]=score;
    }
    }
}
void CStudent::displayExamGrades()
{
    for(int i =0; i <nbCourses; i++)
    {
        for(int j =0; j< NBEXAMS; j++)
        {
           cout<< grades[i][j] << " ";
        }
        cout<<endl;
    }
}


void CStudent::displayCourses()
{
    for(int i =0; i < nbCourses; i ++)
        {
            courses[i]->displayInfo();
        }
}

void CStudent::displayInfo()
{
    cout<<"Name Of The Student Is "<<name<<endl;
    cout<<"ID Of The Student Is "<<ID<<endl;
    cout<<"Number Of Courses Of The Student Is "<<nbCourses<<endl;
}

double* CStudent::calcAverages()
{
    double examsgiven =0;
    double total[nbCourses];
    static double average[MAXCRST];
    for(int i =0; i <nbCourses; i++)
    {
        for(int j =0; j< NBEXAMS; j++) //total all the grades for a course
        {
            if(grades[i][j] != -1){
                total[i] = grades[i][j] + total[i];
                examsgiven++;
            }
        }
        average[i] = total[i]/examsgiven;
        examsgiven =0;
    }
    return average;
}

bool CStudent::isFull()
{
    if (nbCourses == MAXCRST)
        return true;
    else
        return false;
}
bool CStudent::isEnrolledIn(CCourse *pc) //changed
{
    for(int i=0; i<nbCourses; i++)
    {
        if(courses[i] == pc)
            return true;
    }
    return false;
}

int CStudent::getIndex(CCourse* cp)
{
    for(int i =0; i < nbCourses; i++)
    {
        if (courses[i] == cp)
            return i;
    }
    return -1;
}
