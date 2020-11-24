#include <stdio.h>
#include <stdbool.h>
// write a program that contains the following bit fields in a structure(onscreen box)
// box can be opaque or transparent
// a fill cover is selected from the following palette of colors:
    // black, red, green, yellow, blue, magenta, cyan,or white
// a border can be shown or hidden
// a border color is selected from the same palette used for the fill color
// a border can use one of three line stypes, solid, dotted, or dashed
// you need only a single bit to indicate whether the box is opaque or transparent

#define SOLID 0
#define DOTTED 1
#define DASHED 2

#define BLUE 4
#define GREEN 2
#define RED 1

#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

const char * colors[8] = {"black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"};

struct onscreen_box {
    unsigned int opaque:1; // 1 bit for opaque or transparent
    unsigned int fill_color:3; // 3 bits for fill colors i.e. 2^3 = 8
    unsigned int :4; // pad the bitmask 4 bits since 
    unsigned int show_border:1; //1 bit for shown or hidden
    unsigned int border_color:3; // 3 bits for border colors
    unsigned int line_style:2; // 2 bits for line style i.e. 2^2 for 4 total options
    unsigned int :2; // 2 padding to even out the bits
    // a total of 10 bits are needed to store all this data
};

void print_details(struct onscreen_box *box);

int main(void) {

    struct onscreen_box box1 = {0, 0, 0, 0, 0}; // initialize default values
    struct onscreen_box *boxPtr = &box1;
    printf("size of box is %ld\n", sizeof(box1));
    print_details(boxPtr);
    boxPtr->opaque = 1;
    boxPtr->fill_color = GREEN;
    boxPtr->show_border = 1;
    boxPtr->border_color = CYAN;
    boxPtr->line_style = 2;
    printf("\n----------\n");
    print_details(boxPtr);
}

void print_details(struct onscreen_box *box) {

    printf("Box is: %s\n", box->opaque == true ? "opaque" : "transparent");
    printf("Fill color: %s\n", colors[box->fill_color]);
    printf("Show Border: %s\n", box->show_border == true ? "shown" : "hidden");
    printf("Border Color: %s\n", colors[box->border_color]);
    printf("Line Style: %d\n", box->line_style);

}