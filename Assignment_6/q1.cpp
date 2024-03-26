// Q1. Create a class Date with data memebrs day,month and year.
// Cretae a class Person with data members name,address and birthdate. The birthdate shoud be of 
// type Date.
// Cretae a class Employee with data members id, sal, dept and joining date. The joining date should 
// be of type date.
// Employee class should be inherited from Person.
// Implement following classes. Test all functionalities in main().
// (Note - Perform the Association and Inheritance in the above case.)

// help 

#include<iostream>
using namespace std;

class Date{
    private:
        int day;
        int month;
        int year;
    
    public:


        Date(int day=1,int month=1,int year=2000){
            this->day = day;
            this->month = month;
            this->year = year;

        }
        void acceptDate(){

            cout<<"Enter Day:"<<endl;
            cin>>day;
            cout<<"Enter Month:"<<endl;
            cin>>month;
            cout<<"Enter Year:"<<endl;
            cin>>year;


        }

        void displayDate(){

            cout<<day<<"/"<<month<<"/"<<year<<"/";

        }
};

class Person{
    private:
        string name;
        string address;
        Date birthdate;

    public:

        Person(){
            name="";
            address="";
            
        }

       virtual void acceptData(){
            cout<<"\nFOR PERSON"<<endl;
            cout<<"Enter name: "<<endl;
            cin>>name;
            cout<<"Enter address: "<<endl;
            cin>>address;
            cout<<"For birthdate "<<endl;
            birthdate.acceptDate();

            
        }

        virtual  void  displayData(){
            cout<<"\nPerson details: "<<endl;
            cout<<"name: "<<name<<"\n"<<"address: "<<address<<endl;
            cout<<"Person Birthdate: "<<endl;
            birthdate.displayDate();

            
        }

        
};

class Employee : public Person {

    private:
        int empid;
        string dept;
        double salary;
        Date doj;

    public:

        
        void acceptData(){
            cout<<"Enter employee details"<<endl;
            cout<<"Enter empID: "<<endl;
            cin>>empid;
            cout<<"Enter employee salary: "<<endl;
            cin>>salary;
            cout<<"Enter employee dept: "<<endl;
            cin>>dept;
            cout<<"Joining DAte: "<<endl;
            doj.acceptDate();
        
            
            // Person::acceptData();
            
           
        }

        void displayData(){

            cout<<"\nEmployee details are: "<<endl;
            cout<<"id: "<<empid<<"\n"<<"salary: "<<salary<<"\n"<<"dept: "<<dept<<endl;
            cout<<"Date of joining of employee: "<<endl;
            doj.displayDate();
            // Person::displayData();
           
        }
};



int main(){
    // Person p;
    // p.acceptData();
    // p.displayData();

    // Employee e;
    // e.acceptData();
    // e.displayData();

    

    Person *ptr = new Employee();
    ptr->acceptData();
    ptr->displayData();
}












