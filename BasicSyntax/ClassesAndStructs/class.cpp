#include <iostream>

/*
    class Class <- defines the class name
    Class() <- the constructor
    ~Class() <- the destructor (called when an instance is deleted)

    You can declare variables and methods inside a class
    By default, a class will be private, so, if you want something to be public/protected, you need to do this:

    class Class 
    {
        public/protected/private: ...
    }

    When you create an instance of a class, you only need to do this:

    Class class; <- it instantiates automaticaly

    But, if you want to manage everything in the class (deletion included) you need to do it like this:

    Class* class = new Class();

    Keep in mind that you NEED to call method free() (if the reference is created with malloc/calloc/realloc methods) 
    or also keyword delete {reference} to delete the reference of the class,
    because youre making a reference to a new instance Class, so, the instance its still alive even if you get out of the actual scope

    That means, a normal class (Class class;) deletes itself automaticaly when it reaches the end of its scope,
    but a Class referenced, need to be deleted from memory

    Also, a class can declare static fields, they need to be accesed like this: 

    Class::field;
*/

class Class 
{
    public:
        int id;

        Class() { std::cout << "Initializing Class " << id << std::endl; }
        ~Class() { std::cout << "Deleting Class " << id << std::endl; }

        void helloWorld() { std::cout << "Hello World from Class " << id << std::endl; }
        static void staticHelloWorld() { std::cout << "Hellow World from the static field" << std::endl; }
};

int main() {
    Class class1;
    class1.id = 1;
    class1.helloWorld();

    Class* myOwnClass = new Class();
    myOwnClass->id = 2;
    myOwnClass->helloWorld();

    delete myOwnClass;

    Class::staticHelloWorld();

    return 0;
}
