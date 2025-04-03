/*
Create a C++ program that allows users to manage student records, this includes their name, their student ID (int) and their grades for 4 exams 
(assume each student has taken 4 exams, so their grades for the semester would be a 4 element integer array.
Example: {82, 67, 89, 99}) For each student, the program can also calculate their average grade. 
The program should also be able to determine if the student has passed for the year, at this school, 
as long as you have a average grade of 60 between the 4 exams, you have passed
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
    private:
        string name;
        int id;
        double grades[4];
    
    public:
    //setter
        void setName(){
            string newName;
            cout << "Enter students name: \n";
            cin.ignore();
           getline(cin, newName);
            name = newName;
        }
        void setId(){
            int newId;
            cout << "Enter students Id: \n";
            cin >> newId;
            id = newId;
        }
        void setGrades(){
            for (int i = 0; i < 4; i++){
                cout << "Enter student's grades(last 4 exams) " << i+1 <<": \n";
                cin >> grades[i];
            }
        }
        string getName(){
            return name;
        }
        int getId(){
            return id;
        }
        vector<int> getGrades(){
            vector<int> gradeList;
            for (int i = 0; i < 4; i++){
                gradeList.push_back(grades[i]);
            }
            return gradeList;
        }
        double getaverageGrade(){
            double sum = 0;
            for(int i = 0; i < 4; i++){
                sum += grades[i];
        }
         double averagegrade = sum / 4;

                return averagegrade;
        }
        void displayPassFail(){
            if (getaverageGrade() < 60){
                cout << "Fail! \n";
            }
            else {
                cout << "Pass! \n";
            }
        }

};

    void menu(){
        cout << "\nStudent Grade Management System\n";
        cout << "1.Add a new student\n";
        cout << "2.Display all students\n";
        cout << "3.Calculate and display average grades\n";
        cout << "4.Show pass/fail status\n";
        cout << "5.Exit\n";
        cout << "Choose an option. \n";
    }

int main(){
    const int MAX_STUDENTS = 100;
    Student students[MAX_STUDENTS];
    int studentCount = 0;

    while(true){
        menu();
        int options;
        cin >> options;
       if (cin.fail()) {
        cin.clear(); // Clear error flag
        cin.ignore(1000, '\n'); // Discard invalid input
        cout << "Incorrect Input! Please enter a number between 1 and 5.\n";
    } 
    else if (options < 1 || options > 5) {
        cout << "Incorrect Input! Enter a number between 1 and 5.\n";
    } 

        switch(options){
            case 1:
            if (studentCount >= MAX_STUDENTS){
                cout << "Limit Reached! \n";
                break;
            }
           students[studentCount].setName();
           students[studentCount].setId();
           students[studentCount].setGrades();
           studentCount++;
           break;

           case 2:
           if (studentCount == 0){
            cout << "No students have been added yet. \n";
           }
           else{
            cout <<"Students added: " <<studentCount << endl;

            for(int i = 0; i < studentCount; i++){
                cout << students[i].getName() << " "; //"john"
                cout << students[i].getId() << endl; //123
            }
           }
           break;

            case 3:
             if (studentCount == 0){
            cout << "No students have been added yet. \n";
           }
           else{
            for (int i = 0; i < studentCount; i++){
                cout << "Students average grade: " << endl;
                cout << students[i].getaverageGrade() << endl;
            }
            }
            break;
            case 4:
             if (studentCount == 0){
            cout << "No students have been added yet. \n";
           }
           else{
            for (int i = 0; i < studentCount; i++){
                students[i].displayPassFail();
            }
            }
            break;
            case 5:
                cout<< "goodbye.\n";
                exit(0);
            }
        }
    }