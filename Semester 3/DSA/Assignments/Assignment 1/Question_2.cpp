#include<iostream>

using namespace std;

struct UniverseCoordinate{
    int s_number;
    int x_position;
    int y_position;
    bool is_snake;
};


int main(){

    int rows = 2;
    int columns = 2;

    UniverseCoordinate** UniverseData = new UniverseCoordinate*[rows];

    for(int i=0 ; i<rows ; i++){
        UniverseData[i] = new UniverseCoordinate[columns];
    }

    int snake_count = 0;

    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j<columns ; j++){

            UniverseData[i][j].s_number = 0;
            UniverseData[i][j].x_position = j + 1;
            UniverseData[i][j].y_position = i + 1;

            char choice;

            cout<<"Is there a snake at ("<<j + 1<<" , "<<i + 1<<") ? (y/n) : ";
            cin>>choice;

            if(choice == 'y' || choice == 'Y'){
                snake_count++;
                UniverseData[i][j].s_number = snake_count;
                UniverseData[i][j].is_snake = true;
            }
            else{
                UniverseData[i][j].is_snake = false;
            }
        }
    }

    char expand;

    cout<<"\nDo you want to expand the system? (y/n) : ";
    cin>>expand;

    while(expand == 'y' || expand == 'Y'){

        int n_rows;
        int n_columns;

        cout<<"Enter new number of rows : ";
        cin>>n_rows;

        cout<<"Enter new number of columns : ";
        cin>>n_columns;

        if(n_rows > rows && n_columns > columns){

            UniverseCoordinate** newUniverseData = new UniverseCoordinate*[n_rows];

            for(int i=0 ; i<n_rows ; i++){
                newUniverseData[i] = new UniverseCoordinate[n_columns];
            }

            for(int i=0 ; i<n_rows ; i++){
                for(int j=0 ; j<n_columns ; j++){

                    newUniverseData[i][j].s_number = 0;
                    newUniverseData[i][j].x_position = j + 1;
                    newUniverseData[i][j].y_position = i + 1;
                    newUniverseData[i][j].is_snake = false;
                }
            }

            for(int i=0 ; i<rows ; i++){
                for(int j=0 ; j<columns ; j++){
                    newUniverseData[i][j] = UniverseData[i][j];
                }
            }

            for(int i=0 ; i<rows ; i++){
                delete[] UniverseData[i];
            }

            delete[] UniverseData;

            UniverseData = newUniverseData;

            for(int i=rows ; i<n_rows ; i++){
                for(int j=0 ; j<n_columns ; j++){

                    char choice;

                    cout<<"Is there a snake at ("<<j + 1<<" , "<<i + 1<<") ? (y/n) : ";
                    cin>>choice;

                    if(choice == 'y' || choice == 'Y'){
                        snake_count++;
                        UniverseData[i][j].s_number = snake_count;
                        UniverseData[i][j].is_snake = true;
                    }
                }
            }

            for(int i=0 ; i<rows ; i++){
                for(int j=columns ; j<n_columns ; j++){

                    if(i < rows){
                        char choice;

                        cout<<"Is there a snake at ("<<j + 1<<" , "<<i + 1<<") ? (y/n) : ";
                        cin>>choice;

                        if(choice == 'y' || choice == 'Y'){
                            snake_count++;
                            UniverseData[i][j].s_number = snake_count;
                            UniverseData[i][j].is_snake = true;
                        }
                    }
                }
            }

            rows = n_rows;
            columns = n_columns;
        }
        else{
            cout<<"New size must be greater than the current size."<<endl;
        }

        cout<<"\nDo you want to expand the system again? (y/n) : ";
        cin>>expand;
    }

    cout<<"\nUniverse Data : \n";

    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j<columns ; j++){
            if(UniverseData[i][j].is_snake){
                cout<<"Snake  # "<<UniverseData[i][j].s_number<<" at ("<<UniverseData[i][j].x_position<<" , "<<UniverseData[i][j].y_position<<")"<<endl;
            }
        }
    }

    for(int i=0 ; i<rows ; i++){
        delete [] UniverseData[i];
    }

    delete[] UniverseData;


    return 0;
}