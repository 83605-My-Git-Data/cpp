// Q3. Implement following classes. Test all functionalities in main() of each created class. Note that 
// employee is inherited into manager and salesman.



#include<iostream>
using namespace std;

class Employee{
    private:
        int id;
        double salary;

    

    public:

        Employee(){
            cout<<"Inside employee()"<<endl;
        }

        Employee(int id,double salary){
            cout<<"Inside employee(int,double)"<<endl;
        }

        
        int getId()
        {
            return id;
        }

   
        void setId(int id)
        {
            this->id = id;
        }

        
        double getSalary()
        {
            return salary;
        }

    
        void setSalary(double salary)
        {
            this->salary = salary;
        }


       virtual void accept(){
            cout<<"Enter employee id: "<<endl;
            cin>>id;
            cout<<"Enter employee salary: "<<endl;
            cin>>salary;
        }

       virtual void display(){
            cout<<"ID: "<<id<<endl;
            cout<<"Salary: "<<salary<<endl;
        }


        virtual ~Employee(){
            cout<<"Inside ~Employee()"<<endl;
        }







};


class Manager: virtual public Employee{
    private:
        double bonus;
    protected:

     void acceptManager(){
            cout<<"Enter the bonus: "<<endl;
            cin>>bonus;
        }
        
    void displayManager(){
            cout<<"Bonus: "<<bonus<<endl;
        }


    

    public:
        Manager(){
            cout<<"Inside manager()"<<endl;
        }

        Manager(int id,double salary,double bonus){
            cout<<"Inside manager(int,dobule,double)"<<endl;
        }

        
        double getBonus()
        {
            return bonus;
        }

    
        void setBonus(double bonus)
        {
            this->bonus = bonus;
        }

        void accept(){
            Employee::accept();
            acceptManager();
        }

        void display(){
            Employee::display();
            displayManager();
        }

        ~Manager(){
            cout<<"Inside ~Manager()"<<endl;
        }




       

};

class Salesman : virtual public Employee{
    private:
        double comission;

    

    protected:
        void acceptSalesman(){
            cout<<"Enter the commissiom: "<<endl;
            cin>>comission;
        }

        void displaySalesman(){
            cout<<"Commission: "<<comission<<endl;
        }

    public:
        Salesman(){
            cout<<"Inside Salesman()"<<endl;
        }

        Salesman(int id,double salary,double commission){
            cout<<"Inside Salesman(int ,double,double)"<<endl;
        }

        
        double getComission()
        {
            return comission;
        }

    
        void setComission(double comission)
        {
            this->comission = comission;
        }

        void accept(){
            Employee::accept();
            acceptSalesman();
        }

        void display(){
            Employee::display();
            displaySalesman();
        }

        ~Salesman(){
            cout<<"Inside ~Salesman()"<<endl;
        }



};

class SalesManager: public Manager,public Salesman{

    public:

    SalesManager()
    {
        cout << "Inside Salesmanager()" << endl;
    }
    SalesManager(int id, double salary, double bonus, double commission)
    {
        cout << "Inside SalesManager(int,double,double,double)" << endl;
    }

    void accept(){
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }

    void display(){
        Employee::display();
        displayManager();
        displaySalesman();
    }

    ~SalesManager(){
        cout<<"~Salesmanager()"<<endl;
    }

  


};
int main(){
    // Employee e;
    // e.accept();
    // e.display();

    // Manager m;
    // m.accept();
    // m.display();

    // Salesman s;
    // s.accept();
    // s.display();

    // SalesManager sm;
    // sm.accept();
    // sm.display();

    // Employee *e = new Employee();
    // e->accept();
    // e->display();

    //  Employee *e = new Manager();
    // e->accept();
    // e->display();

    //  Employee *e = new Salesman();
    // e->accept();
    // e->display();

    //  Employee *e = new SalesManager();
    // e->accept();
    // e->display();





}

// Q3.  Steps to perform for testing the functunality
// 1. Define class of employee. Create the object and call accept and display
// 2. Define class manager inherited from employee. Create the object and call accept and display.
// 3. Define class salesman inherited from employee. Create the object and call accept and display.
// 4. Define class salesmanager inherited from manager and salesmanager. Create the object and call 
// accept and display.
// 5. Observe the ctor and dtor calls.
// 6. create the pointer of employee and object of employee and call accept and display on employee 
// pointer.
// 7. create the pointer of employee and object of manager and call accept and display on employee 
// pointer.
// 8. create the pointer of employee and object of salesman and call accept and display on employee 
// pointer.
// 9. create the pointer of employee and object of salesmanager and call accept and display on 
// employee pointer.
// 10. Observe the ctor and dtor calls.