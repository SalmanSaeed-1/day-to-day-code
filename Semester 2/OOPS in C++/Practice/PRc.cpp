#include<iostream>

using namespace std;


int main(){
    int max = 3;
    int n = max;
    int arr[max];

    for(int i=0 ; i<max ; i++){
        cout<<"Enter salary of "<<i+1<<" employee : ";
        cin>>arr[i];
    }
    float average_salry = 0;

    for(int i=0 ; i<max ; i++){
        average_salry += arr[i];
    }
    char check;
    do{
        cout<<"Do you want to enter more values ? press y for yes and n for no : ";
        cin>>check;

        if(check == 'y' || check == 'Y'){
            max = max + 1;
            int *new_arr = new int[max];

            for (int i=0 ; i<n ; i++){
                new_arr[i] = arr[i];
            }

            cout<<"Enter the new value for "<<n+1<<" employee : ";
            cin>>new_arr[n];
            average_salry += new_arr[n];
            n++;
        }
        else{
            break;
        }

    }while(check == 'y' || check == 'Y');

    average_salry = average_salry / n;

    cout<<"Average salary : "<<average_salry<<endl;
    
    return 0;
}