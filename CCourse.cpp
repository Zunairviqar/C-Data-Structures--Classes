#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std ;
#include "constants.h"
#include "CCourse.hpp"
#include "CStudent.hpp"

CCourse::CCourse(char* vname, int vcode)
{
    // --- add constructor definition here
    name = new char [strlen(vname)+1];
    strcpy(name, vname);
    code = vcode;
    capacity = MAXSTCR;
    nbEnrolled = 0;
}

CCourse::~CCourse()
{
    // --- add destructor definition here
    delete name;
}

void CCourse::enroll(CStudent* newstudent) //enroll student in course if there is space
{
    if (nbEnrolled < capacity)
    {
        enrolled[nbEnrolled] = newstudent;
        newstudent->enroll(this); //enroll course in student too
        nbEnrolled++;
    }
}

int CCourse::getnbEnrolled()
{
    return nbEnrolled;
}

void CCourse::displayStudents() //call displayInfo of each student enrolled in the course
{
    for (int i=0; i<nbEnrolled; i++)
    {
        enrolled[i]->CStudent::displayInfo();
    }
    
}

void CCourse::displayInfo() {
cout<<"Name of the Course is "<<name<<endl;
cout<<"Code of the Course is "<<code<<endl;
cout<<"Capacity of the Course is "<<capacity<<endl;
cout<<"Number of students enrolled in the course is "<<nbEnrolled<<endl;
}

char* CCourse::getname()
{
    return name;
}

double* CCourse::calcAverages()
{
    double *ab;
    static double avg[MAXCRST];
    int aindex=-1;
    for(int i =0; i < nbEnrolled; i++)
    {
        //get the index of the course in the course list for every student
        aindex = enrolled[i]->getIndex(this);
        ab = enrolled[i]->calcAverages(); //get array of averages for the student
        avg[i]=ab[aindex]; //append only the average of the specific course
        cout<<"CalcAverages Called "<<endl;
    }
    return avg;
}

CStudent* CCourse::getStudent(int ind)
{
    if (ind >-1 && ind <nbEnrolled)
        return enrolled[ind];
    else
        return NULL;
}

bool CCourse::isFull()
{
    if (nbEnrolled == MAXSTCR)
        return true;
    else
        return false;
}

void CCourse::findBestStudent(double &bas, int &indexbas)
{
    bas = 0;
    double *newarr;
    newarr = this->calcAverages();
    for(int i =0; i < nbEnrolled; i ++)
    {
        if( newarr[i] > bas)
        {
            bas =newarr[i];
            indexbas =i;
        }
}
}

