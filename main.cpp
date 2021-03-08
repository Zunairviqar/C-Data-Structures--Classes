//created by Zunair Viqar and Yusra Khan

#include <iostream>
#include "CStudent.hpp"
#include "CCourse.hpp"
#include "CDept.hpp"

// test the cstudent class
void TestStudent()
{
    cout<<"START of TestStudent() "<<endl;
    cout<<"------------------------------------------------"<<endl;
    
    //testing displayInfo() of class CStudent
    char sname[] =  "zunair";
    int sid =9;
    CStudent FS(sname, sid);
    FS.displayInfo();
    
    //testing enroll() of CStudent
    char cname1[] = "DataStructures";
    int ccode1 = 12;
    CCourse* M;
    M = new CCourse(cname1, ccode1);
    FS.enroll(M);
    cout<< "Total number of enrolled courses: "<<FS.getnbCourses()<<endl;
    
    char cname2[] = "DiscreteMaths";
    int ccode2 = 11;
    CCourse* N;
    N = new CCourse(cname2, ccode2);
    FS.enroll(N);
    cout<< "Total number of enrolled courses: "<<FS.getnbCourses()<<endl;
    
    //testing other functions of CStudent
    int grades1[NBEXAMS] = {70,71,72,73,74};
    int grades2[NBEXAMS] = {80,81,82,83,84};
    FS.setCourseGrades(0, grades1);
    FS.displayExamGrades();
    FS.setExamGrades(0, 2, 80);
    FS.setCourseGrades(1, grades2);
    FS.displayExamGrades();
    FS.displayCourses();
    
    //testing calcAverages() and getnbCourses() of CStudent
    double* averagescore;
    averagescore = FS.calcAverages();
    for(int i =0; i <FS.getnbCourses();i++)
    cout<<"The Average Scores are: "<< *(averagescore+i)<<endl;
    
    //testing isFull() and isEnrolledIn() of CStudent
    if (FS.isFull())
        cout<< "The Array is Full"<<endl;
    else
        cout<< "The Array is not Full"<<endl;
    
    if (FS.isEnrolledIn(M))
        cout<< "The Student is Enrolled in "<< M->getname() <<endl;
    else
        cout<< "The Student is not Enrolled in "<< M->getname() << endl;
    
    //testing getIndex() of CStudent
    int indexc;
    indexc = FS.getIndex(N);
    cout<<"The Index Of N is: "<< indexc<< endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"END of TestStudent() "<<endl;
}

// test the cstudent class
void TestCourse()
{
    cout<<"START of TestCourse() "<<endl;
    cout<<"------------------------------------------------"<<endl;
    
    //testing displayInfo() of CCourse
    char cname[] = "Algorithms";
    int ccode = 10;
    CCourse FC(cname, ccode);
    FC.displayInfo();
    
    //testing enroll() of CCourse
    char sname1[] =  "Yusra";
    int sid1 =8;
    CStudent* P;
    P = new CStudent(sname1, sid1);
    FC.enroll(P);
    cout<< "Total number of students enrolled: "<<FC.getnbEnrolled()<<endl;
    
    char sname2[] =  "Umair";
    int sid2 =7;
    CStudent* Q;
    Q = new CStudent(sname2, sid2);
    FC.enroll(Q);
    cout<< "Total number of students enrolled: "<<FC.getnbEnrolled()<<endl;
    
    //testing displayStudents() of CCourse
    FC.displayStudents();
    
    //testing getStudent() of CCourse
    CStudent* R;
    R = FC.getStudent(0);
    cout<<"Get Student"<<endl;
    R->displayInfo();
    
    //testing calcAverages() of CCourse
    int grades1[NBEXAMS] = {70,71,72,73,74};
    int grades2[NBEXAMS] = {90,91,92,93,94};
    P->setCourseGrades(0, grades1);
    Q->setCourseGrades(0, grades2);
    double* avgscores;
    avgscores = FC.calcAverages();
    for (int i=0; i<FC.getnbEnrolled(); i++) {
    cout<<"Average Score for student "<<(i+1)<<" is: "<<*(avgscores+i)<<endl;
    }
    
    //testing findBestStudent() of CCourse
    double Bas =0;
    int Basindex =0;
    FC.findBestStudent(Bas, Basindex);
    cout<< "The Best Average Score is: "<<Bas<<endl;
    
    //testing isFull() of CCourse
    if (FC.isFull())
        cout<< "The Array is Full"<<endl;
    else
        cout<< "The Array is not Full"<<endl;
    
    cout<<"------------------------------------------------"<<endl;
    cout<<"END of TestCourse() "<<endl;
}

// main fucntion to test the depart functionnalities
int main(int argc, const char * argv[])
{
    // Test the CStudent class
    TestStudent() ;
    
    // Test the CCourse class
    TestCourse() ;

    // Create one dept with some default courses and students
    // Then display all the students and all the courses
        //---- do it here ----
    CDept dept;
    dept.displayStudents();
    dept.displayCourses();
    
    // Display the courses taken by a student with index 2
        //---- do it here ----
    //CStudent* student = dept.getStudent(2);
    cout<<endl;
    dept.getStudent(2)->displayCourses();
    
    // Find the best student in a particular course
    // Dispaly the student info and his/her Total average score
        //---- do it here ----
    cout<<endl;
    CCourse* course = dept.getCourse(2); //get a particular course
    CStudent* bestStu = dept.findBestStudent(course); //get the best student in that course
    bestStu->displayInfo(); //display info for that student
    double* average;
    double avg=0;
    average = bestStu->calcAverages();
    for (int i=0; i<bestStu->getnbCourses(); i++) { //add all the averages
        avg += *(average + i);
    }
    avg = avg/bestStu->getnbCourses(); //calculate total average
    cout<<"Total average score for this student: "<<avg<<endl;
    
    // Create one dept with some default courses and students
        //---- do it here ----
    CDept dept2;
    
    // Find the courses taken by a particular student
        //---- do it here ----
    CStudent* newstudent = dept2.getStudent(1); //get a particular student
    newstudent->displayCourses(); //display all the courses taken by that student
    
    // Create a new course and add it to the department offering
        //---- do it here ----
    bool check = false;
    check = dept2.addCourse();
    
    // Register 2 students in a newly created course
        //---- do it here ----
    int yo=0;
    CStudent* fstudent = dept2.getStudent(1); //get two students
    CStudent* sstudent = dept2.getStudent(2);
    yo = dept2.getnbCourses();
    CCourse *n1course = dept2.getCourse(yo-1); //get the last course created
    bool check2 = false;
    check2 = dept2.enroll(fstudent,n1course); //enroll both students in that course
    check2 = dept2.enroll(sstudent,n1course);
    dept2.displayStudents();
    
    
    // Display the updated list of all courses offered
        //---- do it here ----
   dept2.displayCourses();
    
    // Register 2 students in a newly created course
        //---- do it here ----
    int zo=0;
    CStudent* tstudent = dept2.getStudent(3);
    CStudent* fostudent = dept2.getStudent(4);
    zo = dept2.getnbCourses();
    CCourse *n2course = dept2.getCourse(zo-1);
    bool check3 = false;
    check3 = dept2.enroll(tstudent,n2course);
    check3 = dept2.enroll(fostudent,n2course);
    dept2.displayStudents();
    
    // Enter the grades of these 2 students in the new course
        //---- do it here ----
    int grades1[NBEXAMS];
    int grades2[NBEXAMS];
    int NE1;
    int NE2;
    cout<<"How many exams has the first student taken"<<endl; //get number of exams and grades
    cin>>NE1;                                                 //by user input
    cout<<"Enter the grades of the first student"<<endl;
    for(int i =0; i<NE1;i++){
        cout<<"Grade "<<(i+1)<<" :"<<endl;
        cin>>grades1[i];
    }
    dept2.enterStudentGrades(fstudent, n2course, grades1);
    
    cout<<"How many exams has the second student taken"<<endl;
    cin>>NE2;
    cout<<"Enter the grades of the second student"<<endl;
    for(int j =0; j<NE2;j++){
        cout<<"Grade "<<(j+1)<<" :"<<endl;
        cin>>grades2[j];
    }
    dept2.enterStudentGrades(sstudent, n2course, grades2);
    
    
    cout << "\n---- I am done ---- Au revoir ----\n\n";
    return 0;
}
