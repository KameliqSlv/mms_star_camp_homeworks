#include <limits.h>
#include <stdio.h>
#include <stdint.h>


void show_ieee754 (float f)
{
    union {
        double f;
        uint32_t u;
    } fu = { .f = f };
    int i = sizeof f * CHAR_BIT;

    printf ("  ");
    while (i--)
        printf ("%d ", (fu.u >> i) & 0x1);

    putchar ('\n');
    printf (" |- - - - - - - - - - - - - - - - - - - - - - "
            "- - - - - - - - - -|\n");
    printf (" |s|      exp      |                  mantissa"
            "                   |\n\n");
}

int main (void) {

    float f = -3.14159f;

    printf ("\nIEEE-754 Single-Precision representation of: %f\n\n", f);
    show_ieee754 (f);

    return 0;

}