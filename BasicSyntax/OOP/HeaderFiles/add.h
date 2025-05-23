#ifndef ADD_H
#define ADD_H

/*
    This is a header file, here you only define functions signatures and declare variables
    Its not recomendable to declare functions body/initialize variables in this type of
    files

    You can make a unique access to this file with the keywords #define|#ifndef-#endif
    
    #define <- defines a value that can be replaced in all files that make reference to it before the entire program compiles
    #ifndef <- checks if a value have not been defined yet
    #ifdef <- checks if a value have been defined
    #endif <- ends statement of #ifndef|#ifdef
*/

int add(int x, int y);

#endif