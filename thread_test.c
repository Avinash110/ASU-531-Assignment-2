// (c) Partha Dasgupta 2009
// permission to use and distribute granted.
#include <stdio.h>
#include <stdlib.h>
#include "threads.h"

int global = 0;

void function_1()
{
    int local = 0;

    while (1)
    {
        printf("Function 1 incrementing local and global\n");
        sleep(1);
        global++;
        local++;
        yield();
        printf("Function 1 printing .... global = %d  local = %d\n", global, local);
        yield();
        sleep(1);
    }
}

void function_2()
{
    int local = 0;

    while (1)
    {
        printf("Function 2 incrementing local and global\n");
        sleep(1);
        global++;
        local++;
        yield();
        printf("Function 2 printing .... global = %d  local = %d\n", global, local);
        yield();
        sleep(1);
    }
}

void function_3()
{
    int local = 0;

    while (1)
    {
        printf("Function 3 incrementing local and global\n");
        sleep(1);
        global++;
        local++;
        yield();
        printf("Function 3 printing .... global = %d  local = %d\n", global, local);
        yield();
        sleep(1);
    }
}

int main()
{
    init_ready();
    start_thread(&function_1);
    start_thread(&function_2);
    start_thread(&function_3);

    run();

    // while (1)
    //     sleep(1); // infinite loop

    return 0;
}