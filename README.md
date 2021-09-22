# Monty

## Description
The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

### Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:
```
push 0
push 1
push 2
  push 3
                   pall
push 4
    push 5
      push    6
pall
```
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account.
```
julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$
```
## Usage
`./monty file` where `file` is the path to the file containing Monty byte code.

The monty program runs the bytecodes line by line and stops if either:
 - It executed properly every line of the file
 - It finds an error in the file
 - An error occured

## Installation
First, clone this repository onto your local machine using:
```
git clone https://github.com/ethanpasta/monty.git
```
After `cd`ing into the directory, compile all files with:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```
You should now have a `monty` executable file.
## Commands
| Command |                                                                                        Description                                                                                       |                                  File                                  |
|:-------:|:----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|:-:|
|   push  |                                                                              Pushes an element to the stack                                                                              | [push.c](https://github.com/youssefboussaid/monty/blob/master/push.c)  |
|   pall  |                                                                            Prints all the values on the stack                                                                            |   |
|   pint  |                                                                         Prints the value at the top of the stack                                                                         |   |
|   pop   |                                                                           Removes the top element of the stack                                                                           |   |
|   swap  |                                                                          Swaps the top two elements of the stack                                                                         |   |
|   add   |                                                                          Adds the top two elements of the stack                                                                          |   |
|   nop   |                                                                                    Doesn’t do anything                                                                                   |   |
|   sub   |              Subtracts the top element of the stack from the second top element. The result is stored in the second top element of the stack, and the top element is removed             |   |
|   div   |                Divides the second top element of the stack by the top element. The result is stored in the second top element of the stack, and the top element is removed               |   |
|   mul   |             Multiplies the second top element of the stack with the top element. The result is stored in the second top element of the stack, and the top element is removed             |   |
|   mod   | Computes the rest of the division of the second top element of the stack by the top element. The result is stored in the second top element of the stack, and the top element is removed |   |
|  pchar  |                     Prints the char at the top of the stack. The integer stored at the top of the stack is treated as the ascii value of the character to be printed                     |   |
|   pstr  | Prints the string starting at the top of the stack, followed by a new line. The integer stored in each element of the stack is treated as the ascii value of the character to be printed |   |
|   rotl  |                                                                               Rotates the stack to the top                                                                               |   |
|   rotr  |                                                                              Rotates the stack to the bottom                                                                             |   |
|  stack  |                                                Sets the format of the data to a stack (LIFO). This is the default behavior of the program                                                |   |
|  queue  |                                                                       Sets the format of the data to a queue (FIFO)                                                                      |   |


## Examples
### 1. push, sub, pall
#### byte.m
```
push 1
push 2
push 10
push 3
sub
pall
```
#### Output
```
7
2
1
```

### 2. push, pstr
#### byte.m
```
push 1
push 2
push 3
push 4
push 0
push 110
push 0
push 110
push 111
push 116
push 114
push 101
push 98
push 108
push 111
push 72
pstr
```
#### Output
```
Holberton
```

## Author
**boussaid youssef** - [youssef github](https://github.com/youssefboussaid)
/
**ben ali jassem** - [jassem github](https://github.com/jassemb)
