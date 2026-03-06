class Course:
    def __init__(self, course_name, max_students):
        self.course_name = course_name      # store course name
        self.max_students = max_students    # store maximum seats
        self.__students = []                # private list of students

    def enroll(self, student_name):
        # add student if seats are available
        if len(self.__students) < self.max_students:
            self.__students.append(student_name)
            print(student_name, "enrolled in", self.course_name)
            return True
        else:
            print(self.course_name, "is full")
            return False

    def remove(self, student_name):
        # remove student if found
        if student_name in self.__students:
            self.__students.remove(student_name)
            print(student_name, "removed from", self.course_name)
        else:
            print(student_name, "not found in", self.course_name)

    def available_seats(self):
        # return remaining seats
        return self.max_students - len(self.__students)

    def show_students(self):
        # show course details
        print("Course Name:", self.course_name)
        print("Students:", self.__students)
        print("Available Seats:", self.available_seats())


c1 = Course("Python", 3)   # first course
c2 = Course("C++", 2)      # second course

first_full = None   # store first full course

while True:
    print("\n1 - Enroll Student")
    print("2 - Remove Student")
    print("3 - Show Course Details")
    print("4 - Show First Full Course")
    print("5 - Exit")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        # take course number and student name
        course_no = int(input("Enter course number (1 for Python, 2 for C++): "))
        student_name = input("Enter student name: ")

        if course_no == 1:
            c1.enroll(student_name)
            if c1.available_seats() == 0 and first_full is None:
                first_full = c1.course_name
        elif course_no == 2:
            c2.enroll(student_name)
            if c2.available_seats() == 0 and first_full is None:
                first_full = c2.course_name
        else:
            print("Invalid course number")

    elif choice == 2:
        # remove student from selected course
        course_no = int(input("Enter course number (1 for Python, 2 for C++): "))
        student_name = input("Enter student name to remove: ")

        if course_no == 1:
            c1.remove(student_name)
        elif course_no == 2:
            c2.remove(student_name)
        else:
            print("Invalid course number")

    elif choice == 3:
        # display both courses
        print("\nCourse 1 Details:")
        c1.show_students()
        print("\nCourse 2 Details:")
        c2.show_students()

    elif choice == 4:
        # print first course which became full
        if first_full is not None:
            print("First course to become full:", first_full)
        else:
            print("No course is full yet")

    elif choice == 5:
        # exit program
        print("Program ended")
        break

    else:
        # invalid menu option
        print("Invalid choice")