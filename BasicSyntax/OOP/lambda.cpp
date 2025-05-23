#include <iostream>
#include <functional>

/*
    There also are lambda functions in C++, its usually declared as "auto", because
    lambdas are callables and may be very complex to validate sometimes, so, its syntax looks like this:

    auto lambda = [](...) {...}

    The "[]" represents a capturing group the expression will take from its scope, 
    there are many types of expressions that you can put inside, like:

    [] <- empty, dont access any variable or reference
    [&] <- reference, captures variables references from the current scope
    [=] <- value, captures variables values from the current scope
    [v, ...] <- specific values, captures variables values listed inside the capturing group
    [&v, ...] <- specific references, captures varables references listed inside the capturing group
    [=, &v] <- all values except, captures all variables values except the one with the reference v
    [&, v] <- all references except, captures all varaibles references except the one with the value v
    [value=expression] <- initialize value, initializes a value inside the scope of the lambda

    Theres also a standar library that allows you to use methods as parameters:

    std::function<returntype()> c <- callable function

    You just need to pass as argument the lambda expression:

    some_function(lambda); <- lambda its a callable

    And then, in some_function you call lambda like this:

    lambda(); <- calls the callable
    */

void someFunction(std::function<void()> callable)
{
    std::cout << "Calling function" << std::endl;
    callable();
}

int main()
{
    auto sum = [](int a, int b) { return a + b; };
    std::cout << sum(1, 2) << std::endl;

    auto hello = []() { std::cout << "Hello World" << std::endl; };
    someFunction(hello);

    for (int i = 0 ; i < 10 ; i++)
    {
        auto show = [i]() { std::cout << i << " "; };
        show();
    }

    return 0;
}