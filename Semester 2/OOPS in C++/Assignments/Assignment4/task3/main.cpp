#include <iostream>
#include <string>
using namespace std;

class Manager {
private:
    string name;

public:
    Manager(string n = "") : name(n) {}

    string getManager() const {
        return name;
    }
};

class Project {
private:
    string title;
    Manager* manager; // a project may or may not have a manager

public:
    Project(string t = "") : title(t), manager(nullptr) {}

    string getTitle() const {
        return title;
    }

    void setTitle(string t) {
        title = t;
    }

    Manager* getManager() const {
        return manager;
    }

    void setManager(Manager* m) {
        manager = m;
    }
};

class Employee {
private:
    string name;
    Project project; // composition: employee owns current project record

public:
    Employee(string n = "", string projectTitle = "") : name(n), project(projectTitle) {}

    void setName(string n) {
        name = n;
    }

    void setProject(string projectTitle) {
        project.setTitle(projectTitle);
    }

    void allocateManager(Manager* manager) {
        project.setManager(manager);
    }

    void print() const {
        cout << "Employee Name: " << name << endl;

        if (project.getTitle() == "")
            cout << "Project Title: No project assigned" << endl;
        else
            cout << "Project Title: " << project.getTitle() << endl;

        if (project.getManager() != nullptr)
            cout << "Manager Name: " << project.getManager()->getManager() << endl;

        cout << "-----------------------------" << endl;
    }
};

int main() {
    Manager managers[4] = {
        Manager("Michael"),
        Manager("Dwight"),
        Manager("Jim"),
        Manager("Andy")
    };

    const int MAX_EMPLOYEES = 15;
    Employee employees[MAX_EMPLOYEES];

    // Populate the array with employee names and project titles.
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        employees[i].setName("Employee " + to_string(i + 1));

        if (i == 9 || i == 10 || i == 11) {
            employees[i].setProject(""); // these employees are currently unsupervised
        } else {
            employees[i].setProject("Project " + to_string(i + 1));
        }
    }

    // First manager supervises first and second employee.
    employees[0].allocateManager(&managers[0]);
    employees[1].allocateManager(&managers[0]);

    // Second manager supervises third and seventh employee.
    employees[2].allocateManager(&managers[1]);
    employees[6].allocateManager(&managers[1]);

    // Third manager supervises employees four through nine except seven.
    for (int i = 3; i <= 8; i++) {
        if (i != 6)
            employees[i].allocateManager(&managers[2]);
    }

    // Fourth manager supervises projects fourteen and fifteen.
    employees[13].allocateManager(&managers[3]);
    employees[14].allocateManager(&managers[3]);

    cout << "Maintenance Management System\n";
    cout << "=============================\n\n";

    for (int i = 0; i < MAX_EMPLOYEES; i++)
        employees[i].print();

    return 0;
}
