# Get Next Line - Efficient Line Reader

## Introduction

Welcome to my `Get Next Line project!` 🚀 Get Next Line (GNL) is a C function that reads a line from a file descriptor, making it easier to handle input from files or standard input one line at a time. This project demonstrates proficiency in file handling, dynamic memory management, and string manipulation, all essential skills for C programming.

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)

- [Contributing](#contributing)
- [Contact](#contact)

## Features
- Efficiently reads lines from files or standard input.
- Manages dynamic memory allocation and cleanup.
- Adheres to the 42 School standards for project submissions.
### Core Functionality

- `*get_next_line`:Reads the next line from the file descriptor and returns it as a string.
- `ft_read`: Reads data from the file descriptor into a buffer and appends it to the existing saved string until a newline is found or the end of the file is reached.
- `cut_a_line`: Extracts a line from the saved string up to and including the newline character.
- `cut_the_line`: Adjusts the saved string to remove the line that was just read, preparing it for the next call to `get_next_line`.  
### Helper Functions

To support the core functionality, several helper functions are implemented:

- `ft_strlen`: Calculates the length of a string.
- `check_for_newline`: Check if the string contains a string.
- `ft_strjoin`: Concatenates two strings into a new string.

## Getting Started
### Installation
To install Get Next Line, follow these steps:

Clone the repository:

```bash
git clone https://github.com/Abdalrhman-Olimat/get_next_line.git
```
Compile the code:
```c
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c
```
## Usage

Once you've linked the library to your project, you can use `get_next_line` to read and parse text files line by line. Here's an example of how to use `get_next_line`:

```c
#include "get_next_line.h"

int	main(void)
{
        int             fd;
        char    *line;
        fd = open("example.txt", O_RDWR);
        if (fd < 0)
        {
                perror("Error opening file");
                return (1);
        }
		
        while ((line = get_next_line(fd)) != NULL)
        {
                printf("%s", line);
                free(line);
        }
        close(fd);
        return (0);
 }
}
```

This will read the file `example.txt` line by line and print each line to the console.
## Contributing
Contributions are welcome! If you have suggestions for improvements or new features, feel free to open an issue or submit a pull request.
## Contact
If you have any questions or suggestions, please reach out to me via <a href="mailto:abdalrhmanolimat911@gmail.com" target="_blank"><img alt='gmail' src='https://img.shields.io/badge/Gmail-D14836?style=flat-square&logo=gmail&logoColor=white'/> </a>  or  <a href='https://https://www.linkedin.com/in/abdalrhman-olimat-ba2357215/' target="_blank"><img alt='Linkedin' src='https://img.shields.io/badge/LinkedIn-100000?style=flat-square&logo=Linkedin&logoColor=white&labelColor=0A66C2&color=0A66C2'/></a>
