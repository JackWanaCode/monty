# monty
---
## Description
* Monty 0.98 is a scripting language that is first compiled into Monty byte codes
* It relies on a unique stack, with specific instructions to manipulate it
* The project creates an interpreter for Monty ByteCodes files
* Files containing Monty byte codes usually have the .m extension
* The instructions are referred to as Opcode
* There is not more than one instruction per line
* Spaces are ignored when getting the Opcode from the Monty ByteCodes files
* Monty byte code files can contain blank lines and are ignored
* Usage: ./monty file.m
* Where file is the path to the file containing Monty byte code
* If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE
* If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE
* If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
* The monty program runs the bytecodes line by line and stops if either:
  It executed properly every line of the file
  It finds an error in the file
  An error occured
* If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE
* Demonstrates working with git submodules
* Demonstrates the proper way to use global variables
* Demonstrates the most common use cases of stacks and queues
* Demonstrates the common implementations of stacks and queues
## Files
---
File|Task
---|---
.gitignore | Ignore unwanted files when using git add all
exec_func.c | Executes opcode functions
monty.c | Main function
monty.h | Header file containing all function prototypes, global variables and structs
test_func.c | 5 helper functions - push, pall, pint, pop, swap
test_func2.c | 5 helper functions - add, nop
---|---
monty | Main directory for monty files
holbertonschool-low_level_programming/0x18-stacks_queues_lifo_fifo/monty | submodule
## Author
Damon Nyhan && Cuong "Jack" Tran