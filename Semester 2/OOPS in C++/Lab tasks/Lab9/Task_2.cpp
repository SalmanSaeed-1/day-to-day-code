#include<iostream>

using namespace std;

class Vehicle{  //base class
    protected:  //protected attributes 
    int veh_num;
    string veh_type;

    public:  //public function and constructors 
    Vehicle(){
        cout<<"Vehicle comstructor called."<<endl;
    }
    void inputVehicleinfo(){
        cout<<"Enter the vehicle number : ";
        cin>>veh_num;
        cout<<"Enter the Vehcle Type : ";
        cin>>veh_type;
    }
    void showVehicleInfo(){
        cout<<"Vehicle number : "<<veh_num<<endl;
        cout<<"Vehicle type : "<<veh_type<<endl;
    }
    ~Vehicle(){
        cout<<"Vehicle destructor called."<<endl;
    }
};


class FourWheeler: public Vehicle{  //derived class inherited from Vehicle class 
    private :   //private attributes 
    int engineCapacity;
    string fuelType;

    public:  //public constructor and functions 
    FourWheeler(){
        cout<<"FourWheeler constructor called."<<endl;
    }

    void inputFourWheelerInfo() {
        inputVehicleinfo(); // call base
        cout << "Enter Engine Capacity: ";
        cin >> engineCapacity;
        cout << "Enter Fuel Type: ";
        cin >> fuelType;
    }

    void showFourWheelerInfo() {
        showVehicleInfo();
        cout << "Engine Capacity: " << engineCapacity << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }

    ~FourWheeler() {
        cout << "FourWheeler Destructor Called\n";
    }
};

class Car : public FourWheeler{  //derived class car derived from Fourwheeler class 
    private:   //private attributes 
    string mod_name;
    int seat_cap;

    public:   //public constructor and functions 
    Car(){
        cout<<"Car constructor called."<<endl;
    }

    void inputCarInfo() {
        inputFourWheelerInfo();
        cout << "Enter Model Name: ";
        cin >> mod_name;
        cout << "Enter Seating Capacity: ";
        cin >> seat_cap;
    }

    void showCarInfo() {
        showFourWheelerInfo();
        cout << "Model Name: " << mod_name << endl;
        cout << "Seating Capacity: " << seat_cap << endl;
    }

    ~Car() {
        cout << "Car Destructor Called\n";
    }
};

class Bike : public Vehicle {  //derived class bike nherited from vehicle class 
private:   //private attributes 
    string engineType;
    string hasCarrier;

public:   //public constructor and functions 
    Bike() {
        cout << "Bike Constructor Called\n";
    }

    void inputBikeInfo() {
        inputVehicleinfo();
        cout << "Enter Engine Type: ";
        cin >> engineType;
        cout << "Has Carrier (yes/no): ";
        cin >> hasCarrier;
    }

    void showBikeInfo() {
        showVehicleInfo();
        cout << "Engine Type: " << engineType << endl;
        cout << "Has Carrier: " << hasCarrier << endl;
    }

    ~Bike() {
        cout << "Bike Destructor Called\n";
    }
};

int main(){   //main

    cout << "Car Object"<<endl;
    Car c1;
    c1.inputCarInfo();
    cout << "\nCar Details:"<<endl;
    c1.showCarInfo();

    cout << "\n Bike Object\n"<<endl;;
    Bike b1;
    b1.inputBikeInfo();
    cout << "\nBike Details:\n";
    b1.showBikeInfo();

    return 0;
}