//
//  main.cpp
//  Assignment 3 Question 1
//  Written by Shakya Don
//
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main() {
    int choice;
    char another;
    
    do{
        cout<<"1. Enter student records\n";
        cout<<"2. Display student records\n";
        cout<<"3. Search student by roll number\n";
        cout<<"4. Exit\n";
        cout<<"Choose an option: ";
        cin>>choice; //prompting user input
        
        if (choice==1){ //entering student records
            ofstream fout;
            fout.open("student.txt", ios::app); //append mode to be able to add new data without overwriting existing data
            if (!fout) {
                cout<<"Could not open file!";
                return 0; //to prevent the program crashing if file not found
            }
            
            do{
                string name;
                int roll;
                float marks;
                
                // prompting user input
                cout<<"Enter student name: ";
                cin>>name;
                cout<<"Enter roll number: ";
                cin>>roll;
                cout<<"Enter marks: ";
                cin>>marks;
                
                fout<<name<<" "<<roll<<" "<<marks<<endl; //write the data into the file in a single
                cout<<"Do you want to enter another record (y/n): ";
                cin>>another;
            } while (another=='y'|| another=='Y');
            
            fout.close(); //close file
        }
        else if (choice==2) { //displaying student records
            ifstream fin;
            fin.open("student.txt");
            if(!fin){
                cout<<"Could not open file!"; //to prevent the program crashing if file not found
                return 0;
            }
            string name;
            int roll;
            float marks;
            cout<<"Student records: \n";
            while (fin>>name>>roll>>marks){ //reads data from file
                cout<<"Name "<<name<<" Roll no: "<<roll<<" Marks: "<<marks<<endl;
            }
            fin.close(); //close file
        }
        
        else if (choice==3){ //searching student by roll no
            ifstream fin;
            fin.open("student.txt");
            if (!fin) {
                cout<<"Could not open file!"; //to prevent the program crashing if file not found
                return 0;
            }
            int rollSearch;
            cout<<"Enter roll number: ";
            cin>>rollSearch; //prompting user input
            
            string name;
            int roll;
            float marks;
            bool found=false; //false until student has been found
            while (fin>>name>>roll>>marks){ //reads data from file
                if(roll==rollSearch){
                    cout<<"Name: "<<name<<" Roll no: "<<roll<<" Marks: "<<marks<<endl;
                    found=true; //true because student has been found
                    break; //stop searching
                }
            }
            if (!found) {
                cout<<"No record has been found!"<<endl;
            }
            fin.close(); //close file
        }
        else if (choice==4){
            cout<<"Exiting program...\n"; //exit program when user wants to
        }
        else{
            cout<<"Invalid choice, please try again!";
        }
    } while (choice !=4); //close the loop
    
    return 0;
}
        
      
