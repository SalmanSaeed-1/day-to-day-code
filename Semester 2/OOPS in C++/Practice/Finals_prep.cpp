// #include <iostream>
// #include <vector>
// #include<list>
// #include<stack>

// using namespace std;

// // struct student
// // {
// //     int age;
// //     string name;
// //     int marks[5];
// // };

// // class Distance {
// //     int dist;

// // public:
// //     Distance() : dist(0) {
// //     }

// //     friend int addfive(Distance &d);

// //     int getdistance(){
// //         return dist;
// //     }
// // };

// // int addfive(Distance &d) {
// //     d.dist += 5;
// //     return d.dist;
// // }

// // class calc
// // {
// // private:
// //     int a;
// //     int b;

// // public:
// //     int add(int a, int b)
// //     {
// //         return a + b;
// //     }
// //     int subtract(int a, int b)
// //     {
// //         return a - b;
// //     }
// //     int multiply(int a, int b)
// //     {
// //         return a * b;
// //     }
// //     int divide(int a, int b)
// //     {
// //         return a / b;
// //     }
// // };

// // class Bankaccount
// // {
// //     int balance;
// //     string name;

// // public:
// //     Bankaccount();
// //     Bankaccount(int balance, string name);
// //     void withdrawmoney(int amount);
// //     void depositamount(int amount);
// //     void display();
// //     ~Bankaccount();
// // };

// // Bankaccount::Bankaccount()
// // {
// //     balance = 0;
// //     name = "unknown";
// // }

// // Bankaccount::Bankaccount(int balance, string name)
// // {
// //     this->balance = balance;
// //     this->name = name;
// // }

// // void Bankaccount::depositamount(int amount)
// // {
// //     this->balance += amount;
// // }

// // void Bankaccount::withdrawmoney(int amount)
// // {
// //     this->balance -= amount;
// // }

// // void Bankaccount::display()
// // {
// //     cout << "Name " << name;
// //     cout << endl
// //          << "Balance : " << balance;
// // }
// // Bankaccount::~Bankaccount()
// // {
// //     cout << "Destructor  ";
// // }

// // class Complex{
// //     int real;
// //     int imag;

// //     public:
// //     Complex(int real , int imag){
// //         this->real = real;
// //         this->imag = imag;
// //     }

// //     Complex operator+(Complex &comp){
// //         Complex c1(0,0);
// //         c1.real = real + comp.real;
// //         c1.imag = imag + comp.imag;
// //         return c1;
// //     }

// //     Complex operator++(){
// //         real++;
// //         imag++;
// //         return *this;
// //     }
// //     Complex operator++(int){
// //         Complex temp = *this;
// //         real++;
// //         imag++;
// //         return temp;
// //     }
// // };

// // class base
// // {
// // public:
// //     virtual void show()
// //     {
// //         cout << "Inside base class";
// //     }
// // };
// // class derived : public base
// // {
// // public:
// //     void show()
// //     {
// //         cout << "Inside derived class";
// //     }
// // };
// // template <class X>

// // void Swap (X &a , X &b){
// //     X tp;
// //     tp = a;
// //     a = b;
// //     b = tp;
// // }

// int main()
// {
//     student s1[5];
//     for(int i=0 ; i<5 ; i++){
//         cout<<"Enter age of "<<i+1<<" Student : ";
//         cin>>s1[i].age;
//         cout<<"Enter name of "<<i+1<<" Student : ";
//         cin>>s1[i].name;
//         cout<<"Enter marks of 5 subjects  of "<<i+1<<" Student : ";
//         for(int k=0 ; k<5 ; k++){
//             cin>>s1[i].marks[k];
//         }
//     }
//     cout<<endl;
//     for(int i=0 ; i<5 ; i++){
//         cout<<"Student "<<i+1<<" Details :"<<endl;
//         cout<<"Student age :"<<s1[i].age<<endl;
//         cout<<"Student name : "<<s1[i].name<<endl;
//         cout<<"Student Marks : ";
//         for(int k=0 ; k<5 ; k++){
//             cout<<s1[i].marks[k]<<" , ";
//         }
//         cout<<endl;
//     }
//     int (*fun_ptr)(int a , int b);
//     int choice;
//     cout<<"1 - add \n 2 - sub \n 3 - mul \n 4 - div\n";
//     cout<<"Enter your choice ";
//     cin>>choice;
//     if(choice == 1){
//         fun_ptr = &add;
//     }
//     else if(choice == 2){
//         fun_ptr = &subtract;
//     }
//     else if(choice == 3){
//         fun_ptr = &multiply;
//     }
//     else{
//         fun_ptr = &divide;
//     }
//     int a , b;
//     cout<<"Enter 2 numbers : ";
//     cin>>a>>b;
//     cout<<fun_ptr(a , b);

//     int *arr = new int[5];
//     for(int i=0 ; i<5 ; i++){
//         cout<<"Enter "<<i+1<<" Value for dynamic array :";
//         cin>>arr[i];
//     }
//     for(int i=0 ; i<5 ; i++){
//         cout<<arr[i]<<" , ";
//     }
//     delete []arr;
//     arr = nullptr;

//     int max = 5;
//     int n = max;
//     int *array = new int[max];
//     for(int i=0 ; i<5 ; i++){
//         cout<<"Enter "<<i+1<<" Value for dynamic array : ";
//         cin>>array[i];
//     }
//     char choice;
//     do{
//         cout<<"Do you want to enter more value : ";
//         cin>>choice;
//         if(choice == 'y' || choice == 'Y'){
//             max = max + 1;
//             int *temp = new int[max];
//             for(int i=0 ; i<n ; i++){
//                 temp[i] = array[i];
//             }
//             delete []array;
//             array = temp;

//             cout<<"Enter another value : ";
//             cin>>array[n];
//             n++;
//         }
//         else{
//             break;
//         }
//     }while(choice == 'y' || choice == 'Y');

//     cout << "Complete array : ";

//     for(int i=0 ; i<n ; i++){
//         cout<<array[i]<<" ";
//     }
//     delete []array;
//     array = nullptr;

//     int capacity = 5;
//     int count = 0;

//     int *arra = new int[capacity];

//     while(true){
//         if(count == capacity){
//             capacity = capacity * 2;

//             int *temp = new int[capacity];
//             for(int i=0 ; i<count ; i++){
//                 temp[i] = arra[i];
//             }

//             delete []arra;
//             arra = temp;
//         }

//         cout<<"Enter the marks for student "<<count+1<<" : ";
//         cin>>arra[count];
//         if(arra[count] == 100){
//             break;
//         }
//         count++;
//     }

//     cout<<"Final array : ";
//     for(int i=0 ; i<count ; i++){
//         cout<<arra[i]<<"  ";
//     }

//     calc c1;
//     int add = c1.add(3 , 4);
//     cout<<add;

//     Bankaccount b1(500000, "Salman");
//     b1.depositamount(50000);
//     b1.withdrawmoney(20000);
//     b1.display();
//     cout << endl;
//     Distance d1;
//     addfive(d1);
//     cout<<d1.getdistance();

//     Complex c1(5 , 5);
//     Complex c2(5 , 5);
//     Complex c3 = c1 + c2;
//     Complex c4 = c3++;
//     ++c4;

//     derived d1;
//     d1.show();
//     base *b;
//     cout<<endl;
//     derived d2;
//     b = &d2;
//     b->show();
//     int k = 5;
//     int l = 10;
//     int h = 15.7;
//     int g = 44.6;

//     Swap(k,l);
//     Swap(h,g);
//     cout << k << l<< h << g;
//     vector<int> vec;

//     for (int i = 0; i < 5; i++)
//     {
//         vec.push_back(i);
//     }

//     vector<int>::iterator v = vec.begin();
//     while (v != vec.end())
//     {
//         cout << "Value of v : " << *v;
//         v++;
//         cout << endl;
//     }

//     list<int> li;
//     list<int>::iterator i;

//     li.push_back(3);
//     li.push_back(4);

//     i = li.begin();

//     li.insert(i , 1);
//     cout<<"All elements in the list are : ";
//     for(i = li.begin() ; i!=li.end() ; i++){
//         cout<<*i<<" , ";
//     }

//     cout<<endl;
//     li.reverse();



//     for(i = li.begin() ; i!=li.end() ; i++){
//         cout<<*i<<" , ";
//     }

//     li.remove(2);

//     li.pop_back();
//     li.pop_front();



//     stack<int> st;
//     for(int i=0 ; i<5 ; i++){
//         st.push(i);
//     }

//     cout<<"Size of stack : "<<st.size();

//     cout<<"Top element of stack is "<<st.top();

//     for(int i=0 ; i<5 ; i++){
//         st.pop();
//     }

//     if(st.empty()){
//         cout<<"Stack is empty";
//     }
//     else{
//         cout<<"Stack is not empty";
//     }









//     return 0;
// }