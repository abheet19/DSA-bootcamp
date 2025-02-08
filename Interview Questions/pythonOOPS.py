class Car:
    
    total_car=0
    
    def __init__(self,brand,model):
        self.__brand= brand
        self.model= model
        Car.total_car +=1
    
    def get_brand(self):
        return self.__brand
    
    def fullName(self):
        return f"{self.__brand} {self.model}"
    
    def fuel_type(self):
        return "Petrol or Diesel"
        
        
class ElectricCar(Car):
    def __init__(self,brand,model,battery_size):
        super().__init__(brand,model)
        self.battery_size=battery_size
        
    def fuel_type(self):
        return "Electricity"
    
my_car= Car("Toyota","Corolla")
#print(my_car.brand)
print(my_car.model)   

my_new_car= Car("Honda","Civic")
print(my_new_car.get_brand())
print(my_new_car.model)

print(my_car.fullName())
print(my_new_car.fullName())

my_tesla = ElectricCar("Tesla","Model S","85kWh")
print(my_tesla.get_brand())
print(my_tesla.model)
print(my_tesla.fullName())      
print(my_tesla.battery_size)

print(my_car.fuel_type())
print(my_tesla.fuel_type())

print(Car.total_car)






