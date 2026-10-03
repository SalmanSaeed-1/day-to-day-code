#include<iostream>

using namespace std;

#define max 5

int top = -1;
int stack_arr[5];

class stack{

    public:
    void push(int val){
        if(top == 4){
            cout<<"stack overflowed!"<<endl;
            return;
        }
        top++;
        stack_arr[top] = val;
    }

    void pop(){
        if(top == -1){
            cout<<"stack is empty"<<endl;
            return;
        }
        cout<<"Popped value : "<<stack_arr[top];
        top--;
    }
    
    int get_top(){
        if(top == -1){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return stack_arr[top];
    }
    
    bool isempty(){
        if(top == -1){
            return true;
        }
        return false;
    }

    void show(){
        for(int i=top ; i>=0 ; i--){
            cout<<stack_arr[i]<<endl;
        }
    }
};

int main(){
    stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.show(); // Output: 30 -> 20 -> 10 -> NULL

    cout << "Top element is: " << st.get_top() << endl; // Output: 30

    st.pop();
    cout<<endl;
    cout << "After popping one element:" << endl;
    st.show(); // Output: 20 -> 10 -> NULL

    return 0;
}