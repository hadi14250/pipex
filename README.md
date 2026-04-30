
<div align="center">
<a href="https://github.com/hadi14250">
    <img src="github_gifs/pipe.gif" alt="3d cube" width="150" height="150">
  </a>
  <h3 align="center">Pipex</h3>
  Pipes, forks, processes, and redirection.
  <br>
  <br>
</div>


<div align="center">
<a href="https://github.com/hadi14250">
    <img src="github_gifs/pipex_demo.gif" alt="gif gameplay"  width="600" height="400">
  </a>


</div>

<br>


# Pipex

Pipex is a C project that recreates the behavior of Unix shell pipelines from scratch. It builds up from raw process creation and file descriptor redirection to coordinating two programs that talk to each other through a pipe, just like the shell does when you type `cmd1 | cmd2`. Under the hood it leans on the core Unix system calls — `fork`, `pipe`, `dup2`, `execve`, `wait` — to spawn child processes, wire their standard input and output to files or to each other, resolve binaries against the `PATH` environment variable, and clean everything up once the commands finish.

<br>

## What it does

Given an input file, two shell commands, and an output file, pipex runs the first command with the input file as its stdin, pipes its stdout into the second command, and writes the second command's stdout to the output file. The end result is identical to what the shell would produce for `< infile cmd1 | cmd2 > outfile`.

<br>

## How to run

Usage: `./pipex input_file command1 command2 output_file`

- From the project root, run `make` to build the binary.
- Then run, for example: `./pipex file1 "ls -la" "grep pipex" file2`
- This mirrors the shell pipeline: `< file1 ls -la | grep pipex > file2`

<br>

## How it works

1. **Parse** the four arguments and prepare the input file, output file, and both command strings.
2. **Open** the input file for reading and the output file for writing (creating or truncating it as needed).
3. **Pipe** — create a pipe to connect the two child processes.
4. **Fork** twice, once per command. Each child uses `dup2` to redirect its stdin and stdout to the right end of the pipe or to the input/output file, then calls `execve` on the resolved binary.
5. **Wait** in the parent for both children to finish, close every file descriptor, and free all allocated memory.

<br>

## Key concepts practiced

- Process creation and lifecycle management with `fork` and `wait`.
- Inter-process communication through anonymous pipes.
- File descriptor manipulation and redirection with `dup2`.
- Resolving and executing external binaries via `PATH` and `execve`.
- Defensive error handling for missing files, invalid commands, and failed system calls.

<br>
