#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void bubble_sort_array(int arr[] , int size){
    for(int i=0 ; i<size ; i++){
        bool swapped = false;
        for(int j=0 ; j<size-i-1 ; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}


void bubble_sort_ll(Node* head){
    for(Node* i = head ; i != NULL ; i = i->next){
        for(Node* j =head ; j->next!= NULL ; j = j->next){
            if(j->data>j->next->data){
                int temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}

void selection_sort_array(int arr[] , int size){
    for(int i=0 ; i<size-1 ; i++){
        int min_index = i;
        for(int j=i+1 ; j<size ; j++){
            if(arr[j]<arr[min_index]){
                min_index = j;
            }
        }
        if(min_index!=i){
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}


void selection_sort_ll(Node* head){
    for(Node* current = head ; current!= NULL ; current = current->next){
        Node* minimum = current;
        for(Node* scan = current->next ; scan!=NULL ; scan = scan->next){
            if(scan->data<minimum->data){
                minimum = scan;
            }
        }
        int temp = current->data;
        current->data = minimum->data;
        minimum->data = temp;

    }
}



void insertion_sort_array(int arr[], int size){
    for(int i=1 ; i<size ; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// Insert values into the sorted part without changing links.
void insertion_sort_ll(Node* head){
    if(head==nullptr){
        return;
    }
    for(Node* current = head->next ; current!=NULL ; current = current->next){
        int key = current->data;
        Node* position = head;
        // Find the first value greater than key.
        while(position!=current && position->data<=key){
            position= position->next;
        }
        // Carry each displaced value one node forward.
        while(position!=current){
            int temp = position->data;
            position->data = key;
            key = temp;
            position = position->next;
        }
        current->data = key;
    }
}


