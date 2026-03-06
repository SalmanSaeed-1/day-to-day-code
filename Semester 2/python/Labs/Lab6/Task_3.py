class Product:
    def __init__(self, name, price):
        self.name = name          # store product name
        self.price = price        # store product price
        self.__stock = 0          # private stock value

    def add_stock(self, quantity):
        # add stock if quantity is valid
        if quantity <= 0:
            print("Invalid quantity")
        else:
            self.__stock += quantity
            print(quantity, "items added to", self.name)

    def sell(self, quantity):
        # sell items if enough stock is available
        if quantity <= 0:
            print("Invalid quantity")
        elif quantity > self.__stock:
            print("Not enough stock available")
        else:
            self.__stock -= quantity
            print(quantity, "items sold from", self.name)

    def stock_value(self):
        # return total stock value
        return self.price * self.__stock

    def show_details(self):
        # show product details
        print("Product Name:", self.name)
        print("Price:", self.price)
        print("Stock Value:", self.stock_value())


p1 = Product("Laptop", 50000)   # first product
p2 = Product("Phone", 30000)    # second product
p3 = Product("Tablet", 20000)   # third product

while True:
    print("\n1 - Add Stock")
    print("2 - Sell Product")
    print("3 - Show Product Details")
    print("4 - Show Product with Highest Stock Value")
    print("5 - Exit")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        # add stock to selected product
        product_no = int(input("Enter product number (1 Laptop, 2 Phone, 3 Tablet): "))
        quantity = int(input("Enter quantity to add: "))

        if product_no == 1:
            p1.add_stock(quantity)
        elif product_no == 2:
            p2.add_stock(quantity)
        elif product_no == 3:
            p3.add_stock(quantity)
        else:
            print("Invalid product number")

    elif choice == 2:
        # sell stock from selected product
        product_no = int(input("Enter product number (1 Laptop, 2 Phone, 3 Tablet): "))
        quantity = int(input("Enter quantity to sell: "))

        if product_no == 1:
            p1.sell(quantity)
        elif product_no == 2:
            p2.sell(quantity)
        elif product_no == 3:
            p3.sell(quantity)
        else:
            print("Invalid product number")

    elif choice == 3:
        # show all product details
        print("\nProduct 1 Details:")
        p1.show_details()
        print("\nProduct 2 Details:")
        p2.show_details()
        print("\nProduct 3 Details:")
        p3.show_details()

    elif choice == 4:
        # find product with highest stock value
        max_product = p1

        if p2.stock_value() > max_product.stock_value():
            max_product = p2
        if p3.stock_value() > max_product.stock_value():
            max_product = p3

        print("Product with highest stock value is:", max_product.name)
        print("Highest Stock Value:", max_product.stock_value())

    elif choice == 5:
        # exit program
        print("Program ended")
        break

    else:
        # invalid option
        print("Invalid choice")