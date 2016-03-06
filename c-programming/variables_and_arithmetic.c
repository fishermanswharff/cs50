#include <stdio.h>

/*
  Print Fahrenheit-celsius table
  ——————————————————————————————
  C = (5/9)(F-32)
  F = °C × 9/5 + 32
*/

#define LOWER 0
#define UPPER 300
#define STEP 1

void toTable() {
  // in C variable must be declared before they are used, usually at the beginning of the function before any executable statements.
  float fahr, celsius;
  /*
  the type int means that the variable listed are integers
  float: floating point, typically a 32-bit quantity
  the range of both int and float depends on the machine you are using:
  16-bit ints lie between -32768 & +32767
  32-bit ints usually in the magnitude of 10^-38 and 10^+38

  C provides several basic types:
  int     whole number
  float   floating point (number with a fractional part)
  char    character-a single byte
  short   short integer
  long    long integer
  double  double-precision floating point

  the sizes of all these objects are machine dependent
  */
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  printf("Fah   Cels\n");
  while (fahr <= upper) {
    celsius = (5.0/9.0) * (fahr-32);
    /*
    "%d" specifies a token fulfilled by an integer.
    the first argument is the string to be printed,
    with each % indicating where one of the other
    arguments is to be subbed
    Each % construction in the first argument is
    paired with the corresponding second, third, etc.
    they must match up properly by number and type.

    printf is not part of the c language.
    there is no input or output defined in C itself
    */
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}

void tableWithFor() {
  /*
    results are the same as toTable(),
    but we use the for loop, and
    eliminate most of the variables
  */

  int fahr;

  /*
    it's good practice to deal with magic numbers/constants by defining them and give them meaningful names
    A #define line defines a symbolic name or symbolic constant to be a particular string of characters:
    #define   name   replacement text
  */


  // reverse order: for(fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
  for(fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}

void toFahrenheit(float celsius) {
  float fahr;
  fahr = celsius * (9.0/5.0) + 32;
  printf("Celsius to Fahrenheit:\n%f => %f\n", celsius, fahr);
}

void toCelsius(float fahr) {
  float celsius;
  celsius = (5.0/9.0) * (fahr - 32);
  printf("Fahrenheit to Celsius:\n%f => %f\n", fahr, celsius);
}

int main(void) {

  tableWithFor();
  // toTable();

  // toFahrenheit(0);
  // toFahrenheit(1);
  // toFahrenheit(2);
  // toFahrenheit(3);
  // toFahrenheit(26);

  // toCelsius(78);
  // toCelsius(32);
  // toCelsius(33);
  // toCelsius(104);
}
