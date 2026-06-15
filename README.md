# Pipex

## About

Pipex is a system programming project from the 42 School curriculum that recreates the behavior of Unix pipes and command redirections. The objective is to understand how processes communicate through pipes, how file descriptors work, and how commands are executed using system calls such as `fork()`, `pipe()`, `dup2()`, and `execve()`.

This project provides a deeper understanding of process creation, inter-process communication, and the Unix execution environment.

## The Challenge

The program must reproduce the behavior of the following shell command:

```bash
< file1 cmd1 | cmd2 > file2
```

Which is equivalent to:

```bash
./pipex file1 "cmd1" "cmd2" file2
```

The output of the first command is redirected through a pipe and used as the input of the second command, while the final result is written to the output file.

## Features

- Multiple process creation using `fork()`.
- Inter-process communication through pipes.
- Input and output file redirection.
- Command execution with `execve()`.
- Environment path resolution.
- Error handling and resource cleanup.
- Support for the mandatory and bonus parts.

## Usage

### Mandatory Part

```bash
./pipex infile "cmd1" "cmd2" outfile
```

Example:

```bash
./pipex infile "grep hello" "wc -l" outfile
```

Equivalent shell command:

```bash
< infile grep hello | wc -l > outfile
```

## Bonus Part

The bonus version supports multiple commands and here documents.

### Multiple Pipes

```bash
./pipex infile "cmd1" "cmd2" "cmd3" ... "cmdn" outfile
```

Equivalent shell command:

```bash
< infile cmd1 | cmd2 | cmd3 | ... | cmdn > outfile
```

### Here Document

```bash
./pipex here_doc LIMITER "cmd1" "cmd2" outfile
```

Equivalent shell command:

```bash
cmd1 << LIMITER | cmd2 >> outfile
```

## Example

```bash
./pipex infile "cat" "grep error" outfile
```

Output flow:

```text
infile
   │
   ▼
  cat
   │
   ▼
grep error
   │
   ▼
outfile
```

## Project Structure

```text
pipex/
├── includes/
│   └── pipex.h
├── src/
│   ├── parsing/
│   ├── execution/
│   ├── pipes/
│   ├── heredoc/
│   └── utils/
├── Makefile
└── README.md
```

## Compilation

Compile the project:

```bash
make
```

Available Makefile rules:

```bash
make
make bonus
make clean
make fclean
make re
```

The compilation generates:

```bash
./pipex
```

## System Calls Used

The project relies on several Unix system calls:

```c
open()
close()
read()
write()
fork()
pipe()
dup()
dup2()
execve()
access()
wait()
waitpid()
```

These functions are essential for process management, file handling, and inter-process communication.

## Implementation Details

### Process Creation

Each command is executed in a separate child process created using `fork()`.

### Pipes

Pipes are used to redirect the output of one process to the input of another.

### Redirections

Input and output files are managed through file descriptors and duplicated using `dup2()`.

### Command Execution

Commands are located using the `PATH` environment variable and executed with `execve()`.

### Error Management

The program handles:

- Invalid files.
- Missing permissions.
- Nonexistent commands.
- System call failures.
- Memory allocation errors.

All allocated resources and file descriptors are properly released before termination.

## Learning Objectives

Through this project, I gained experience with:

- Unix process management.
- File descriptors.
- Pipes and inter-process communication.
- Process synchronization.
- Environment variables.
- Command execution with `execve()`.
- Error handling in system-level applications.
- Resource management and memory safety.

## Technologies

- C
- Unix/Linux System Calls
- Process Management
- Pipes
- File Descriptors
- Makefile

Developed as part of the 42 School curriculum.
