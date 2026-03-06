class Candidate:
    def __init__(self, name):
        self.name = name        # store candidate name
        self.__votes = 0        # private votes

    def add_vote(self):
        # add one vote
        self.__votes += 1

    def get_votes(self):
        # return total votes
        return self.__votes

    def show_details(self):
        # show candidate details
        print("Candidate Name:", self.name)
        print("Votes:", self.get_votes())


c1 = Candidate("Ali")      # first candidate
c2 = Candidate("Ahmed")    # second candidate
c3 = Candidate("Sara")     # third candidate

while True:
    print("\n1 - Add Vote")
    print("2 - Show Candidate Details")
    print("3 - Show Winner")
    print("4 - Exit")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        # add vote to selected candidate
        candidate_no = int(input("Enter candidate number (1 Ali, 2 Ahmed, 3 Sara): "))

        if candidate_no == 1:
            c1.add_vote()
            print("Vote added to", c1.name)
        elif candidate_no == 2:
            c2.add_vote()
            print("Vote added to", c2.name)
        elif candidate_no == 3:
            c3.add_vote()
            print("Vote added to", c3.name)
        else:
            print("Invalid candidate number")

    elif choice == 2:
        # show all candidate details
        print("\nCandidate 1 Details:")
        c1.show_details()
        print("\nCandidate 2 Details:")
        c2.show_details()
        print("\nCandidate 3 Details:")
        c3.show_details()

    elif choice == 3:
        # find candidate with highest votes
        winner = c1

        if c2.get_votes() > winner.get_votes():
            winner = c2
        if c3.get_votes() > winner.get_votes():
            winner = c3

        print("Winner of the election is:", winner.name)
        print("Total Votes:", winner.get_votes())

    elif choice == 4:
        # exit program
        print("Program ended")
        break

    else:
        # invalid option
        print("Invalid choice")