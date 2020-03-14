class Taxi:

    def __init__(self, model, capacity, variant):
        self.__model = model      # __model is private to Taxi class
        self.__capacity = capacity
        self.__variant = variant

    def getModel(self):          # getmodel() is accessible outside the class
        return self.__model

    def getCapacity(self):         # getCapacity() function is accessible to class Vehicle
        return self.__capacity

    def setCapacity(self, capacity):  # setCapacity() is accessible outside the class
        self.__capacity = capacity

    def getVariant(self):         # getVariant() function is accessible to class Vehicle
        return self.__variant

    def setVariant(self, variant):  # setVariant() is accessible outside the class
        self.__variant = variant

class Vehicle(Taxi):

    def __init__(self, model, capacity, variant, color):
        # call parent constructor to set model and color  
        super().__init__(model, capacity, variant)
        self.__color = color

    def vehicleInfo(self):
        return self.getModel() + " " + self.getVariant() + " in " + self.__color + " with " + self.getCapacity() + " seats"

# In method getInfo we can call getmodel(), getCapacity() as they are 
# accessible in the child class through inheritance

v1 = Vehicle("i20 Active", "4", "SX", "Bronze")
print(v1.vehicleInfo())
print(v1.getModel()) # Vehicle has no method getModel() but it is accessible via Vehicle class

v2 = Vehicle("Fortuner", "7", "MT2755", "White")
print(v2.vehicleInfo())
print(v2.getModel()) # Vehicle has no method getModel() but it is accessible via Vehicle class
