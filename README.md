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