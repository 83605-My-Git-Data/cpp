// Q1. Write a menu driven program to calculate volume of the box(length * width * height).
// Provide parameterless, parameterized(with 3 parameters) and single paramaterized constructor.
// Create the local objects in respective case and call the function to caluclate area.
// Menu options -> 
// 1. Calculate Volume with default values
// 2. Calculate Volume with length,breadth and height with same value
// 3. Calculate Volume with different length,breadth and height values

#include<iostream>
using namespace std;

class Box{
    private:
        int length;
        int width;
        int height;

    public:
        Box() : Box(1,1,1){};

        Box(int length,int width,int height){
            this->length = length;
            this->width = width;
            this->height = height;
        }
        Box(int length): Box(length,length,length){}

        int calculateVolume(){
            int volume = length*width*height;
            return volume;
        }



};


int main(){
    int choice;

    do{
    cout<<"\nPress 0: To exit\nPress 1: To calculate volume with default values\nPress 2: To calculate volume with same lbh values\nPress 3: Enter different values for lbh"<<endl;
    cin>>choice;

    

    switch (choice)
    {
    case 0:
        break;
    case 1:
    {
        Box b;
        int ans = b.calculateVolume();
        cout<<"Volume with default values: "<<ans;
        break;
    }
    case 2:
        {
            int value;
            cout<<"Enter value for all lbh"<<endl;
            cin>>value;
            Box b(value);
            int ans = b.calculateVolume();
            cout<<"Volume with same lbh values: "<<ans;
            break;

        }
    case 3:
        {
            int l;
            int b;
            int h;
            cout<<"Enter value for lbh"<<endl;
            cin>>l>>b>>h;
            Box box(l,b,h);
            int ans = box.calculateVolume();
            cout<<"Volume with different lbh values: "<<ans;
            break;
            
        }
    
    default:
        break;
    }}while (choice != 0);
    
    

    



    return 0;
}