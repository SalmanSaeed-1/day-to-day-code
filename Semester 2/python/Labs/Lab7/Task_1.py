class Calculator:  #base class
    def add (self , a , b , c = None):  #overloading 
        if c is not None:
            return a+b+c
        return a+b

class AdvancedCalculator(Calculator):    #inheritence 
    def add (self , a , b , c = None):
        if isinstance(a , str) and isinstance(b , str):
            return a+b
        return super().add(a , b , c)

calc = AdvancedCalculator()

print(calc.add(5 , 10))
print(calc.add(2.5 , 3.7))
print(calc.add(1 , 2 ,3))
print(calc.add("Hello " , "World"))