# get_next_line

## Project Description
get_next_line is a custom implementation of a function that reads a line from a file descriptor. It provides a flexible way to read data line by line, supporting various file descriptors and adhering to C++98 compliance.

## Features
- Reads a line from a file descriptor.
- Supports multiple file descriptors.
- Compliant with C++98 standards.

## Project Structure
- **get_next_line.c**: Main implementation of the get_next_line function.
- **get_next_line.h**: Header file defining the public API.
- **get_next_line_utils.c**: Helper functions for string manipulation.
- **get_next_line_bonus.c**: Bonus implementation for handling multiple file descriptors.
- **get_next_line_bonus.h**: Header file for the bonus implementation.

## How to Build
To build the project, run the following command in the project directory:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o get_next_line
```

## Usage
To use get_next_line in your project, include the header file and call the function:
```c
#include "get_next_line.h"

int main() {
    int fd = open("file.txt", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

## How the Problem Was Solved
The project was implemented with a focus on modularity and clarity. The main function, `get_next_line`, reads from a file descriptor and processes the data line by line. This approach ensures that the code is maintainable and adheres to C++98 compliance.

## Testing
You can test the function by reading from a file and printing each line.

## Credits
Created by [Your Name] 