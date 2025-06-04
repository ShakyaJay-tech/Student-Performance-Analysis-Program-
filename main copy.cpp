//
//  main.cpp
//  Assignment 3 Question 2
//  Written by Shakya Don (40263686)
//
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main() {
    int choice;
    do {
        cout<<"Student performance analysis program.\n";
        cout<<"***\n";
        cout<<"1. Find the student with the highest marks\n";
        cout<<"2. Find students who passed\n";
        cout<<"3. Calculate average marks\n";
        cout<<"4. Exit\n";
        cout<<"Choose an option: ";
        cin>>choice; //prompting user input
        
        if (choice==4) {
            cout<<"Exiting program...\n"; //exit program
            return 0;
        }
        
        ifstream fin("/Users/shakyajay/Documents/student.txt"); //open file for reading
        if (!fin){
            cout<<"Error could not open file!\n";
            return 0;
        }
        
       
            string name, topStudent;
            float marks, highestMarks=-1, totalMarks=0; //initialized with -1 to prevent student with 0 being identified as topscorer
            int roll, highestRoll=0, studentCount=0, passCount=0, passThresh;// intitialized to start from 0 and up
            
            while (fin>>name>>roll>>marks) { //read data from student.txt
                studentCount++; //counts number of students
                totalMarks+= marks; // getting sum of the marks from all students
                
                if (marks>highestMarks) { //getting top scorer
                    highestMarks = marks;
                    topStudent = name;
                    highestRoll = roll;
                }
            }
            fin.close();
            
            if (choice==1) { //display top student
                cout<<"Top student: "<<topStudent<<" "<<highestRoll<<" "<<highestMarks<<endl;
            }
            else if (choice==2){
                cout<<"Enter passing marks threshold: ";
                cin>>passThresh;
                
                fin.clear(); //clear file
                fin.open("/Users/shakyajay/Documents/student.txt");
                if (!fin){
                    cout<<"Error could not open file!\n";
                    return 0;
                }
                passCount=0; //reset passcount
                while (fin>>name>>roll>>marks) {
                    if (marks>=passThresh){
                        passCount++; //extracting number of students who passed
                    }
                }
                fin.close();
               
                cout<<"Total number of students: "<<studentCount<<endl;//total number of student in the file
                
                cout<<"Number of students who passed: "<<passCount<<endl; //number of students passed
            }
            else if (choice==3){
                float avgMks=totalMarks/studentCount; //calculating average marks
                cout<<"Average marks: "<<avgMks<<endl;
            }
            
            else {
                cout<<"Invalid choice, please try again!\n";
            }
            
        } while (choice !=4);// close the loop
        return 0;
    }
