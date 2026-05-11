#include<iostream>

using namespace std;

class course{
    protected:
    int course_id;
    string course_name;
    int credit_hours;

    public:
    course();
    course(int id , string name , int credits);
    void display() const;
    int getCredits() const;
    bool operator==(const course&c);
    int getId() const;
};

course::course(){
    course_id = 0;
    course_name = "Nill";
    credit_hours = 0;
};

course::course(int id , string name , int credits){
    course_id = id;
    course_name = name;
    credit_hours = credits;
}

void course::display() const{
    cout<<"Course id : "<<course_id<<endl;
    cout<<"Course Nmae : "<<course_name<<endl;
    cout<<"credit_hours : "<<credit_hours<<endl;
    cout<<endl;
}

int course::getCredits() const{
    return credit_hours;
}

bool course::operator==(const course &c){
    if(course_id == c.course_id){
        return true;
    }
    return false;
}
int course::getId() const{
    return course_id;
}

class student{
    protected:
    int student_id;
    string name;
    course *courses;
    int count;
    int capacity;

    public:
    student();
    student(int id , string name);
    student(const student &s);
    virtual ~student(){
        delete[] courses;
    }

    void registarcourse(course c);
    void dropcourse(int course_id);
    void displaycourses() const;
    int totalCredits() const;
    student& operator=(const student&s){
        if(this != &s){
            delete[] courses;
            student_id = s.student_id;
            name = s.name;
            count = s.count;
            capacity = s.capacity;

            courses = new course[capacity];

            for(int i=0 ; i<count ; i++){
                courses[i] = s.courses[i];
            }
        }
        return *this;
    }

};

student::student(){
    student_id = 0;
    name = "Nill";
    capacity = 2;
    count = 0;
    courses = new course[capacity];
}

student::student(int id , string name){
    student_id = id;
    this->name = name;
    capacity = 2;
    count = 0;
    courses = new course[capacity];
}

student::student(const student &s){
    this->student_id = s.student_id;
    this->name = s.name;
    this->count = s.count;
    this->capacity = s.capacity;

    courses = new course[capacity];
    for(int i=0 ; i<count ; i++){
        courses[i] = s.courses[i];
    }
    
}

void student::registarcourse(course c){
    for(int i=0 ; i<count ; i++){
        if(courses[i] == c){
            throw runtime_error("Course already register");
        }
    }

    if(count == capacity){
        capacity = capacity * 2;
        course *temp = new course[capacity];

        for(int i=0 ; i<count ; i++){
            temp[i] = courses[i];
        }

        delete[] courses;
        courses = temp;
    }

    courses[count] = c;
    count++;
}

void student::dropcourse(int course_id){
    int index = -1;
    for(int i=0 ; i<count ; i++){
        if(courses[i].getId() == course_id){
            index = i;
            break;
        }
    }

    if(index == -1){
        throw runtime_error("Course not found");
    }
    else{
        for(int i=0 ; i<count-1 ; i++){
            courses[i] = courses[i+1];
        }
        count--;
    }
}

void student::displaycourses()const{
    cout<<"Student Id : "<<student_id<<endl;
    cout<<"Student name : "<<name;

    if(count == 0){
        cout<<"No courses registered";
    }
    else{
        cout<<"COurses registerd: "<<endl;
        for(int i=0 ; i<count ; i++){
            cout<<"Course "<<i+1<<" : "<<endl;
            courses[i].display();
        }
    }
}


int student::totalCredits()const{
    int total = 0;
    for(int i=0 ; i<count ; i++){
        total += courses[i].getCredits();
    }

    return total;
}

class graduatestudent : public student{
    private:
    string thiesisTitle;
    
    public:
    graduatestudent(int id, string n, string thiesis) : student(id , n){
        thiesisTitle = thiesis;
    }
    
    void displayinfo()const{
        cout<<"\nGraduate student information"<<endl;
        cout<<"Student id : "<<student_id<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Thiesis title : "<<thiesisTitle<<endl;
        cout<<"Total credit hours registered : "<<totalCredits();
    }

};