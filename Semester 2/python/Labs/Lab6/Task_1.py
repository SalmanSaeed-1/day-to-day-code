class Wallet:
    def __init__(self, balance):
        self.__balance = balance   # private balance

    def add_money(self, money):
        # add money if amount is valid
        if money <= 0:
            print("Invalid amount of money")
        else:
            self.__balance += money
            print("Money added successfully")

    def spend_money(self, money):
        # spend money if enough balance exists
        if money <= 0:
            print("Invalid amount of money")
        elif money > self.__balance:
            print("You do not have enough balance to spend!")
        else:
            self.__balance -= money
            print("Money spent successfully")

    def transfer(self, other, amount):
        # transfer money to another wallet
        if amount <= 0:
            print("Invalid amount of money")
        elif amount > self.__balance:
            print("You do not have enough balance to transfer!")
        else:
            self.__balance -= amount
            other.__balance += amount
            print("Money transferred successfully")

    def show_balance(self):
        # show current balance
        print("Available balance:", self.__balance)


w1 = Wallet(0)   # first wallet
w2 = Wallet(0)   # second wallet

while True:
    print("\n1 - Add Money")
    print("2 - Spend Money")
    print("3 - Transfer Money")
    print("4 - Show Balance")
    print("5 - Exit")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        # add money in selected wallet
        wallet_no = int(input("Enter wallet number (1 or 2): "))
        amount = int(input("Enter amount to add: "))

        if wallet_no == 1:
            w1.add_money(amount)
        elif wallet_no == 2:
            w2.add_money(amount)
        else:
            print("Invalid wallet number")

    elif choice == 2:
        # spend money from selected wallet
        wallet_no = int(input("Enter wallet number (1 or 2): "))
        amount = int(input("Enter amount to spend: "))

        if wallet_no == 1:
            w1.spend_money(amount)
        elif wallet_no == 2:
            w2.spend_money(amount)
        else:
            print("Invalid wallet number")

    elif choice == 3:
        # transfer money between wallets
        sender = int(input("Transfer from wallet (1 or 2): "))
        receiver = int(input("Transfer to wallet (1 or 2): "))
        amount = int(input("Enter amount to transfer: "))

        if sender == 1 and receiver == 2:
            w1.transfer(w2, amount)
        elif sender == 2 and receiver == 1:
            w2.transfer(w1, amount)
        else:
            print("Invalid wallet numbers")

    elif choice == 4:
        # show both wallet balances
        print("Wallet 1:")
        w1.show_balance()
        print("Wallet 2:")
        w2.show_balance()

    elif choice == 5:
        # exit program
        print("Program ended")
        break

    else:
        # invalid option
        print("Invalid choice")