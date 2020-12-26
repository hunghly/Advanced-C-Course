#include <stdio.h>

// creating a way to track a quantity of something
// it could be a count, a weight, or a volume
struct Tracker {
    short count;
    float weight;
    float volume;
} fruits; // this is not good because all these variables account for some type of tracking,-we only need one way to track

union BetterTracker {
    short count;
    float weight;
    float volume;
}; // this would allow all the data to utilize one of the data variables since we only need one quantity at a time

int main(void) {
    // a union is a derived type (similar to structure) with members that share the same storage space
    // used mainly in advanced programming applications where it is necessary to store different types of data in the same storage space
    // can be used to save space and for alternating data
    // a union does not waste storage on variables that are not being used
    // each element of a union is called a member and one member can contain a value at any given time so you can only access one at a given time
    // can be of any data type - in most cases they have multiple data types
    // reference data in a union with a variable of the wrong type is a logical error
    // ops that can be performed on a union are

    // 1. assigning a union to another union of the same type
    // 2. taking the address (&) of a union variable
    // 3. accessing union members

    // useful in embedded programming -- situations where direct access to hardware/memory is needed
    // -create an array of unions that store equal-sized units each of which can hold a variety of data types
    // -create a union that represents a file containing different record types

    // memory allocation for struct vs union
    // a struct allocates memory for all the members immediately
    // a union all the members have an offset of zero and one common storage space for all its members
    // a union there is enough space created for the largest field only - all the variables go to the same space of memory

    // unions are typically used in situations where space is premium but more importantly for exclusively alternating data
    // they ensure that mutually exclusive states remain mutually exclusive

    union BetterTracker tracker1;

    // count is wrong and volume is wrong since it overrides the memory space
    tracker1.count = 10;
    tracker1.volume = 14.5;
    tracker1.weight = 28.9;

    printf("Count: %d\n", tracker1.count); 
    printf("Volume: %f\n", tracker1.volume);
    printf("Weight: %f\n", tracker1.weight);

    // this will print out correctly since it's accessing one variable at a time and does not have memory conflicts
    tracker1.count = 10;
    printf("Count: %d\n", tracker1.count); 
    tracker1.volume = 14.5;
    printf("Volume: %f\n", tracker1.volume);
    tracker1.weight = 28.9;
    printf("Weight: %f\n", tracker1.weight);

}