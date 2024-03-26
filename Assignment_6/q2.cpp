// Q2. A shop sells book or tapes. The Book class holds id, title, author, and price; whereas Tape class 
// holds id, title, artist, and price. There is 5% discount on tapes, while 10% discount on books. 
// Assuming that each user purchase 3 products (either book or tape), calculate final bill. The program 
// should be menu driven and should not cause memory leakage.
// Hint - Create class Product and inherit into Book and Tape. Also create array like Product* arr[3] 


#include<iostream>
using namespace std;




class Product{

    private:
        int id;
        string title;
        double price;

    public:
        int getId()
        {
            return id;
        }

    
        void setId(int id)
        {
            this->id= id;
        }

    
        string getTitle()
        {
            return title;
        }

   
        void setTitle(string title)
        {
            this->title = title;
        }

    
        double getPrice()
        {
            return price;
        }

    
        void setPrice(double price)
        {
            this->price = price;
        }

   
        virtual void accept(){

            cout<<"Enter id: "<<endl;
            cin>>id;
            cout<<"title: "<<endl;
            cin>>title;
            cout<<"price: "<<endl;
            cin>>price;

        }

        virtual void display(){
            cout<<"ID: "<<id<<endl;
            cout<<"Title: "<<title<<endl;
            cout<<"Price: "<<price<<endl;

        }

        virtual double discountPrice(){
            return price;
        }

        virtual ~Product(){}

};



class Book : public Product{

    private:
        string author;
        
    public:

    

        void accept(){
            
            Product::accept();
            cout<<"Enter author name: "<<endl;
            cin>>author;
            


        }

        virtual void display(){
            Product::display();
            cout<<"Author: "<<author;

        }

        double discountPrice(){
            return getPrice()-(getPrice()*0.10);
        }


};




class Tape: public Product{

    private:
       
        
        string artist;
       

    public:
        void accept(){
            Product::accept();

            cout<<"Enter the artist name: "<<endl;
            cin>>artist;



        }

        virtual void display(){
            Product::display();
            cout<<"Artist name is: "<<artist;

        }

        double discountPrice(){
            return getPrice()-(getPrice()*0.05);
        }
};

int main(){

    int choice;
    Product *ptr[3];
    int index = 0;


    do
    {
       
        cout<<"Press 0 : To exit\nPress 1 : To add a Book:\nPress 2: To add a Tape\nPress 3 : To view the bill\n";
        cin>>choice;

        switch (choice)
        {
        case 0:
        {
            cout<<"Thanks, you can leave now"<<endl;
            break;
        }

        case 1:
        {
            ptr[index]= new Book();
           
            ptr[index]->accept();
             index++;
            
            break;
        }

        case 2:
        {
            ptr[index] = new Tape();
            
            ptr[index]->accept();
            index++;
            
            break;
        }

        case 3:
        {
            double totalBill= 0.0;
            cout<<"Your bill is : "<<endl;
            for(int i=0 ;i<index;i++){
                ptr[i]->display();
                totalBill = totalBill+ ptr[i]->discountPrice();
            }
            cout<<"Total bill: "<<totalBill<<endl;
        }

        
        default:
            break;
        }
    } while (choice != 0);

    for(int i= 0;i<3;i++){
        delete ptr[i];
        
    }
    return 0;



}