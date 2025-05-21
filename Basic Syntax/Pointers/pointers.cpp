#include <iostream>

using namespace std;

/*
    * -> indicates that a variable will hold a memory address
    & -> holds the memory address of a variable
    int a = 1;
    so, to acces the memory address you need to do: int* aPtr = &a;
    
    Syntax:
    type*(can be 1 or more asteriks) = &(variable);

    You display a value from a pointer like this:

    cout << *aPtr;
    It should print 1, because aPtr points to a

    For more than 1 asterik:

    int a = 1;
    int* aPtr = &a;
    int** aSecondPtr = &aPtr;

    So, now:

    a -> value
    aPtr -> pointer to a
    aSecondPtr -> pointer to aPtr

    This means that if we access *aSecondPointer, its going to return the address of aPtr

    To create a primitive array, you need to use two methods: malloc(s) | calloc(c, s)

    malloc -> gives a variable an entire block of memory of size s (in bytes)
    calloc -> does the same as malloc, but calloc also sets the size of each element inside the memory,
            also, calloc initialize all the memory that is going to be used to the equivalent of 0 in any data type

    You can free the memory of a pointer (and so, a variable) with the method free(var) or else, delete var

    Last but not least, void*

    void* are just pointers with not explicit type of variable, for example:

    int a = 1;
    void* aPtr = &a;
    
    This works the same as using int*, but here the compiler doesnt know what type of variable is pointing to, the compiler
    just knows that its pointing to a variable

    (This is quite strange imo, why the hell you use void as a data type? void literally means NOTHING)
*/
int main()
{
    int var = 5;
    int* varPtr = &var;
    cout << varPtr << " " << *varPtr << endl;
    
    int** secondVarPtr = &varPtr;
    cout << secondVarPtr << " " << *secondVarPtr << " " << **secondVarPtr << endl;
    cout << secondVarPtr << " " << *secondVarPtr << " " << &secondVarPtr << " " << **secondVarPtr << endl;

    void* voidPtr = &var;
    cout << voidPtr << " " << &voidPtr << endl;
    
    int *arr = (int *)malloc(5 * sizeof(int));
    for (int i = 0 ; i < 5 ; i++)
    {
        arr[i] = i + 1;
        std::cout << arr[i];
    }
    cout << endl;

    cout << arr << " " << *arr << " " << &arr << endl;

    return 0;
}
