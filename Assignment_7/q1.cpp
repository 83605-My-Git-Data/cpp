
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
    int choice;
    Employee *arr[10];
    int index = 0;


    do{

    cout<<"Press 0 : To exit"<<endl;
    cout<<"Press 1 : To Accept Employee"<<endl;
    cout<<"Press 2 : To Display count of Emp wrt designation"<<endl;
    cout<<"Press 3 : To Display all Managers"<<endl;
    cout<<"Press 4 : To Display all Salesman"<<endl;
    cout<<"Press 5 : To Display all SalesManagers"<<endl;
    cout<<"Press 6 : To Display all Data "<<endl;

    cout<<"Enter choice: "<<endl;
    cin>>choice;

    switch (choice)
    {
    case 0:
    {

        for(int i =0 ;i<index;i++){
            delete arr[i];
            arr[i] = NULL;

        }
        cout<<"Thank you.."<<endl;
    
        break;
    }
    case 1:
    {
        if(index < 10)
        {
                int accept;
                cout<<"Which kind of employee you want to add ?"<<endl;
                cout<<"1.Employee\n2.Manager\n3.Salesman\n4.SalesManager"<<endl;
                cin>>accept;
                switch (accept)
                {
                case 1:
                {
                    arr[index] = new Employee();
                    arr[index]->accept();
                    index++;
                    break;
                }
                case 2:
                {
                    arr[index] = new Manager();
                    arr[index]->accept();
                    index++;
                    break;
                }
                case 3:
                {
                    arr[index] = new Salesman();
                    arr[index]->accept();
                    index++;
                    break;
                }
                
                case 4:
                {
                    arr[index] = new SalesManager();
                    arr[index]->accept();
                    index++;
                    break;
                }
                
                
                default:
                    break;
                }
            
        }

        break;
    }
    case 2:
    {

        int employeeCount = 0;
        int managerCount = 0;
        int salesmanCount = 0;
        int SalesManagerCount = 0;

        for(int i= 0;i<index;i++){
            if(typeid(*arr[i]) == typeid(Employee)){
                employeeCount++;
            }
        }
        for(int i= 0;i<index;i++){
            if(typeid(*arr[i]) == typeid(Manager)){
                managerCount++;
            }
        }
        for(int i= 0;i<index;i++){
            if(typeid(*arr[i]) == typeid(Salesman)){
                salesmanCount++;
            }
        }
        for(int i= 0;i<index;i++){
            if(typeid(*arr[i]) == typeid(Manager)){
                SalesManagerCount++;
            }
        }

        cout<<"Count of :"<<endl;
        cout<<"1.Employee: "<<employeeCount<<endl;
        cout<<"2.Manager: "<<managerCount<<endl;
        cout<<"3.Salesperson: "<<salesmanCount<<endl;
        cout<<"4.Salesmanager: "<<SalesManagerCount<<endl;
    


        break;
    }
    case 3:

    {
        for(int i= 0;i<index;i++){
            if(typeid(*arr[i]) == typeid(Manager)){
                arr[i]->display();
            }
        }

        break;
    }
    case 4:
    {
        for(int i= 0;i<index;i++){
            if(typeid(*arr[i]) == typeid(Salesman)){
                arr[i]->display();
            }
        }
        break;
    }
    case 5:
    {
        for(int i= 0;i<index;i++){
            if(typeid(*arr[i]) == typeid(SalesManager)){
                arr[i]->display();
            }
        }
        break;
    }
    case 6:
        for(int i = 0;i<index;i++){
            arr[i]->display();
        }
         
    
    default:
        break;
    }


    }while (choice != 0);

    
    
}





// int main(){

//     // Employee obj;
//     // obj.accept();
//     // obj.display();

//     // Manager obj;
//     // obj.accept();
//     // obj.display();

//     SalesManager obj;
//     obj.accept();
//     obj.display();

//     return 0;

// }