#include<iostream>


using namespace std;

int main(){
    int max = 5;
    int n = max;
    int count = 0;

    int *arr = new int[max];
    for(int i=0 ; i<max ; i++){
        cout<<"Enter "<<i+1<<" value : ";
        cin>>arr[i];
        count++;
    }
    char choice;

    do{
        cout<<"DO you want to enter more values : ";
        cin>>choice;

        if(choice == 'y'){
            if(count == max){
                max = max * 2;
                int *new_arr = new int[max];
                for(int i=0 ; i<n ; i++){
                    new_arr[i] = arr[i];
                }
                delete arr;
                arr = new_arr;
            }
            cout<<"Enter another value : ";
            cin>>arr[n];
            n++;
            count++;
        }
    }while(choice == 'y');

    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }




    return 0;
}