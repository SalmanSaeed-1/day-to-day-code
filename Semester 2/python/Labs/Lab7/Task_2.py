class Animal:  #base class 
    def sound(self):
        print("Animal makes a sound")

class Dog(Animal):   #derived class
    def sound(self):
        print("Dog barks")

class cat(Animal):     #derived class 
    def sound(self):
        print("Cat meows")

def make_sound(animal):
    animal.sound()

animal = Animal()
d = Dog()
c = cat()
make_sound(animal)
make_sound(d)
make_sound(c)