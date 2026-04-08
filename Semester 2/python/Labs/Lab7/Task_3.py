class BankAccount:
    def __init__(self, accountNo, balance):
        self.accountNo = accountNo
        self.balance = balance

    # Simulated overloading using default argument
    def deposit(self, amount, bonus=0):
        total = amount + bonus
        self.balance += total
        print(f"Deposited: {amount}, Bonus: {bonus}, Total Added: {total}")

    def displayAccountInfo(self):
        print("Account No:", self.accountNo)
        print("Balance:", self.balance)


class SavingAccount(BankAccount):
    def __init__(self, accountNo, balance, interestRate):
        super().__init__(accountNo, balance)
        self.interestRate = interestRate

    # Overriding
    def displayAccountInfo(self):
        print("Saving Account Details:")
        print("Account No:", self.accountNo)
        print("Balance:", self.balance)
        print("Interest Rate:", self.interestRate)


# Base class reference (polymorphism)
account = SavingAccount("12345", 1000, 5.5)

# Deposit without bonus
account.deposit(500)

# Deposit with bonus (overloading behavior)
account.deposit(300, 50)

# Display info (overridden method)
account.displayAccountInfo()

# Final balance
print("Final Balance:", account.balance)