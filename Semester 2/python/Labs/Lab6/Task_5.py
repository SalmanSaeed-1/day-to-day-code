class LibraryMember:
    def __init__(self, member_name):
        self.member_name = member_name          # store member name
        self.__borrowed_books = {}              # private dictionary for borrowed books
        self.total_fine = 0                     # store total fine

    def borrow_book(self, title):
        # borrow book if not already borrowed
        if title in self.__borrowed_books:
            print(title, "is already borrowed")
        else:
            self.__borrowed_books[title] = 0
            print(title, "borrowed successfully")

    def return_book(self, title, days_late):
        # return book and calculate fine
        if title not in self.__borrowed_books:
            print(title, "was not borrowed")
        else:
            fine = 0

            if days_late >= 0 and days_late <= 3:
                fine = 0
            elif days_late >= 4 and days_late <= 7:
                fine = 5
            elif days_late > 7:
                fine = 10
            else:
                print("Invalid late days")
                return

            del self.__borrowed_books[title]
            self.total_fine += fine

            print(title, "returned successfully")
            print("Fine for this book:", fine)

    def show_details(self):
        # show member details
        print("Member Name:", self.member_name)
        print("Borrowed Books:", self.__borrowed_books)
        print("Total Fine:", self.total_fine)


m1 = LibraryMember("Ali")      # first member
m2 = LibraryMember("Ahmed")    # second member
m3 = LibraryMember("Sara")     # third member

while True:
    print("\n1 - Borrow Book")
    print("2 - Return Book")
    print("3 - Show Member Details")
    print("4 - Show Total Fine of All Members")
    print("5 - Exit")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        # borrow book for selected member
        member_no = int(input("Enter member number (1 Ali, 2 Ahmed, 3 Sara): "))
        title = input("Enter book title: ")

        if member_no == 1:
            m1.borrow_book(title)
        elif member_no == 2:
            m2.borrow_book(title)
        elif member_no == 3:
            m3.borrow_book(title)
        else:
            print("Invalid member number")

    elif choice == 2:
        # return book for selected member
        member_no = int(input("Enter member number (1 Ali, 2 Ahmed, 3 Sara): "))
        title = input("Enter book title: ")
        days_late = int(input("Enter late days: "))

        if member_no == 1:
            m1.return_book(title, days_late)
        elif member_no == 2:
            m2.return_book(title, days_late)
        elif member_no == 3:
            m3.return_book(title, days_late)
        else:
            print("Invalid member number")

    elif choice == 3:
        # show all member details
        print("\nMember 1 Details:")
        m1.show_details()
        print("\nMember 2 Details:")
        m2.show_details()
        print("\nMember 3 Details:")
        m3.show_details()

    elif choice == 4:
        # show total fine of each member
        print("\nTotal Fine Details:")
        print(m1.member_name, ":", m1.total_fine)
        print(m2.member_name, ":", m2.total_fine)
        print(m3.member_name, ":", m3.total_fine)

    elif choice == 5:
        # exit program
        print("Program ended")
        break

    else:
        # invalid option
        print("Invalid choice")