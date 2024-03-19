// Write a menu driven program for Student in CPP language. Create a class student with data 
// members roll no, name and marks. Implement the following functions
// void initStudent();
// void printStudentOnConsole();
// void acceptStudentFromConsole();


#include<iostream>
using namespace std;

class Student{
    private:
        int rollNo;
        string name;
        double  marks;

    public:
        
        void acceptStudentFromConsole(){
            getchar();
            cout<<"Enter the student name: "<<endl;
            getline(cin,name);
            cout<<"Enter the roll number: "<<endl;
            
            cin>>rollNo;
            cout<<"Enter the marks of student: "<<endl;
            cin>>marks;

        }
        void printStudentOnConsole(){
            cout<<"Roll No: "<<rollNo<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Marks: "<<marks<<endl;

        }
        void initStudent(){
            rollNo = 0;
            name = '_';
            marks = 0;

        }


};

int main(){
    int value ;
    Student s;



do{
    
    cout<<"\nWelcome to the app !"<<endl;
    cout<<"Select for the Functionality : "<<endl;
    cout<<"Press 0: for exit "<<endl;
    cout<<"Press 1:for entering student details "<<endl;
    cout<<"Press 2: for displaying student details "<<endl;
    cout<<"Press 3: for default values "<<endl; 
    cin>>value;
    


    switch (value)
    {
    case 0:
        break;

    case 1:
        s.acceptStudentFromConsole();
        break;
    case 2:
        cout<<"Displaying the information :"<<endl;
        s.printStudentOnConsole();
        break;
    
    default:
        break;
    }
} while (value != 0);




    return 0;
    



    

}