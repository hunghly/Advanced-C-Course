// a flexibile array member is a feature introduced in the C99 standard of the C programming language
// when using a structure, we can declare an array without a dimension and whose size is flexible in nature
// a flexibile array member's size is variable (can be changed at runtime)

#include <stdio.h>

struct s
{
    int arraySize;
    int array[]; // must be the last member of a struct
}; // end struct

int main()
{

    int desiredSize = 5; // declare size
    struct s *ptr;

    ptr = malloc(sizeof (struct s) + (desiredSize * sizeof(int))); // the sizeof(struct s) is all the members of the struct
    // the desiredSize * sizeof(int) is the flexible array inside struct
    
    // a flexible array member can only be declared as the last member of a struct
    // each struct can contain at most one flexible array member
    // a flexible array cannot be the only member of a struct
    // the struct must also have one or more fixed members

    // any struct containing a flexible array member cannot be a member of another struct
    // a struct with a flexible array member cannot be statically initialized, 
    // 1. it must be allocated dynamically 2. you cannot fix the size of the flexible array member at compile time

    // it is debatable on whether it is good practice to use flexible array members
}