# ft_printf

## Project Description
ft_printf is a custom implementation of the printf function in C. It provides a flexible way to format and print data to the standard output, supporting various conversion specifiers and adhering to C++98 compliance.

## Features
- Supports basic conversion specifiers: %c, %s, %d, %i, %u, %x, %X, %p, %%
- Handles formatting for characters, strings, integers, unsigned integers, and pointers
- Compliant with C++98 standards

## Project Structure
- **include/**: Contains the header file `ft_printf.h` defining the public API.
- **srcs/**: Contains the source files:
  - `ft_printf.c`: Main implementation of the printf function.
  - `convert.c`: Handles conversion specifiers.
  - `h_numbers.c`, `h_string.c`, `h_utils.c`: Helper functions for number and string handling.
- **Makefile**: Build script to compile the project.

## How to Build
To build the project, run the following command in the project directory:
```bash
make
```
This will create a static library named `libftprintf.a`.

## Usage
To use ft_printf in your project, include the header file and link against the library:
```c
#include "ft_printf.h"

int main() {
    ft_printf("Hello, %s!\n", "World");
    return 0;
}
```

## How the Problem Was Solved
The project was implemented with a focus on modularity and clarity. The main function, `ft_printf`, parses the format string and delegates conversion handling to specific functions. This approach ensures that the code is maintainable and adheres to C++98 compliance.

## Testing
You can run tests using the provided Makefile target:
```bash
make test
```

## Credits
Created by [Your Name] 