# Pipex
## Overview
Pipex is a project designed to familiarize you with UNIX mechanisms through practical implementation in your program. It simulates the behavior of a shell command involving file redirection and command execution through pipes.

## How it Works
Pipex takes four arguments: infile, command1, command2, and outfile. It executes command1 with infile as input and directs its output to command2, whose output is then redirected to outfile. Essentially, it mimics the behavior of < infile command1 | command2 > outfile shell command.

## Compilation
To compile the project, use the provided Makefile. Separate compilation targets are available for the main project and the bonus features.
Main Project: This is compiled using make. It includes the core functionality of Pipex.
```bash
make
```
Bonus Features: The bonus features are compiled using make bonus. This includes additional functionalities such as managing multiple pipes and accepting << and >> operators for input and output redirection.
```bash
make bonus
```
## Test Examples
Here are some test examples to demonstrate Pipex's functionality:
1. Redirecting noexiste grep hello output to wc:
```bash
./pipex noexiste "grep hello" "wc" /dev/stdout
```
2. Executing ls and redirecting its output to another ls command:
```bash
./pipex input "ls" "ls" /dev/stdout
```
3. Filtering input file with grep and then redirecting to wc:
```bash
./pipex input "grep hello" "wc" /dev/stdout
```
4. Using sleep command in one of the pipelines:
```bash
./pipex noexiste "grep hello" "sleep 3" output
```
5. Combining grep and sleep commands with input file:
```bash
./pipex input "grep hello" "sleep 3" /dev/stdout
```
## Further Tests
Several additional tests are provided in the test.txt file to cover various scenarios and edge cases. These tests showcase Pipex's ability to handle different input/output combinations and command executions.
