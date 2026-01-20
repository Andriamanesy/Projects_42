This project has been created as part of the 42 curriculum by harramar, briandri.

# Minishell

## Description

**Minishell** is a simplified version of a shell (like **Bash**).  
The objective is to create a program capable of reading commands, parsing them, and executing them while managing processes and the system environment.

- **Why is this important?** This project is a deep dive into the inner workings of UNIX. It allows for the mastery of process creation (`fork`), inter-process communication (`pipe`), signal management, and file descriptor manipulation.

- **Overview** The program displays a prompt, waits for user input, parses the command line to identify executables, arguments, and redirections, and then launches execution while handling priorities and errors.

---

## Instructions

### Compilation
The project requires the `readline` library. Ensure it is installed on your system.

```bash
# Clone the repository
git clone git@vogsphere.42antananarivo.mg:vogsphere/intra-uuid-3c799e4a-6eed-4ff2-8185-b14f622948d5-7088686-harramar minishell
cd minishell

# Compile the project
make

```

### Execution

Once compiled, launch the shell with the following command:

```bash
./minishell

```

---

## Features

### Built-ins

The following internal commands are implemented:

* `echo` (with `-n` option)
* `cd`
* `pwd`
* `export`
* `unset`
* `env`
* `exit`

### Pipes

* Support for single and multiple pipes using `|`
* Correct connection of the standard output of one command to the input of the next
* Proper management of file descriptors

### Redirections

* Input redirection: `<`
* Output redirection: `>`
* Append mode redirection: `>>`
* Heredoc: `<<`

### Environment Variables

* Environment variable expansion: `$VAR`
* Last command exit code expansion: `$?`
* Management of exported and non-exported variables

### Signals

* `Ctrl-C` (SIGINT): Interrupts the current command
* `Ctrl-D` (EOF): Exits the shell
* `Ctrl-\` (SIGQUIT): Handled according to Bash behavior

---

## Project Architecture

### Lexer / Parser

Analyzes the command line, splits it into tokens, and handles quotes, environment variables, and redirections.

### Executor

Creates processes, configures pipes and redirections, and executes commands (either built-ins or binaries).

### Built-ins

Internal implementations respecting Bash behavior.

### Signals

Signal handling to ensure a stable interactive shell.

---

## Resources

### Documentation & References

* Man pages:
* `fork`
* `execve`
* `pipe`
* `dup2`
* `waitpid`
* `signal`


* *The Architecture of Open Source Applications* – Chapter on Shells
* Tutorials on UNIX parsing and lexing

---

## Use of AI

In accordance with 42 school rules, AI was used solely as a **pedagogical assistance tool**.

### Tasks Involved

* Theoretical understanding of multiple pipes
* Analysis of Bash behavior
* Logical debugging of complex redirections

### Project Parts

* Parsing of single and double quotes
* Signal management in interactive mode

### Tools Used

* ChatGPT
* Gemini
