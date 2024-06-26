# Pipex
## 1. Overview
Pipex is a project from the 42 School Common Core Rank 02. It simulates the behavior of pipes in a shell, including file redirection and command execution through pipes.

## 2. How it Works
To compile the project, use the provided Makefile. There are separate compilation targets for the main project and the bonus features.

### 2.1 Main Project
Compile the main project using:
```bash
make
```
This includes the core functionality of Pipex. Pipex takes four arguments, executes command1 with infile as input, and directs its output to command2, whose output is then redirected to outfile.
Usage:
```bash
./pipex infile command1 command2 outfile
```
This mimics the behavior of the shell command:
```bash
< infile command1 | command2 > outfile shell command.
```

### 2.2 Bonus Features
Compile the bonus features using:
```bash
make bonus
```
The bonus version includes additional functionalities such as managing multiple pipes and accepting << and >> operators for input and output redirection.
```bash
./pipex_bonus infile command1 command2 ... commandN outfile
./pipex_bonus here_doc DEL command1 command2 commandN outfile
```
Usage:
```bash
< infile command1 | command2 | ... | commandN > outfile
<< DEL command1 | command2 | ... | commandN >> outfile
```

## 3. Test Examples
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

### Further Tests
Several additional tests are provided in the test.txt file to cover various scenarios and edge cases. These tests showcase Pipex's ability to handle different input/output combinations and command executions.
