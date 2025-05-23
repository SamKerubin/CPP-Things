#include <iostream>
#include <string>

/*
    To inherit another class, you need to use ":" and then the class name
    You can also especify the access modifier of the class, to adjust the properties you want to access:

    class Class : public Class2 <- access public attributes of Class2

    Inherited classes can override methods from the base class, but keep in mind this only applies
    if the function have a body and also if its a virtual function:

    virtual void some_function() {} <- this can be overrided

    Also, a class can define a class method to be defined later in another class or even other file:

    void class_method(); <- doesnt especify functions body

    Then:

    void Class::class_method() {} <- now you especify the body with whatever you need

    Also, to use inherited attributes, you need to do this:

    Class(...) : Class2(...) {...} <- its like the syntax of the inheritance (Class : Class2)

    Also, when creating an object with unique attributes, you need to implement one of these ways:

    Class class{...}
    Class class(...)
    
    Or if the object is an object reference:

    Class* class = new Class(...)
*/

class Vehicle
{
public:
    Vehicle(std::string brand) { brand_ = brand; }

    virtual void move() { std::cout << "The vehicle is moving" << std::endl; }
    std::string getBrand() { return brand_; }

private:
    std::string brand_{ " " };
};

class Car : public Vehicle
{
public:
    Car(std::string brand, int wheels, double max_speed)
        : Vehicle(brand)
    {
        wheels_ = wheels;
        max_speed_ = max_speed;
    }

    int getWheels() { return wheels_; }
    int getMaxSpeed() { return max_speed_; }
    void move() override { std::cout << "The car " << getBrand() << " is moving" << std::endl; }
    void honk();

private:
    int wheels_{ 0 };
    double max_speed_{ 0.0 };
};

void Car::honk() { std::cout << "Honk honk" << std::endl; }

int main()
{
    Car ford{ "Ford", 4, 100 };
    ford.move();

    std::cout << "Brand: " << ford.getBrand() << std::endl;
    std::cout << "Wheels: " << ford.getWheels() << std::endl;
    std::cout << "Max speed: " << ford.getMaxSpeed() << std::endl;

    ford.honk();

    return 0;
}