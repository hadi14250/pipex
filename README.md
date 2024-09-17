
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

Inspired by Unix shell pipelines, this project starts with basic process creation and redirection. We advance from handling simple input/output to managing complex inter-process communication using pipes. Utilizes fundamental system calls to mimic shell behavior and handle process execution.

<br>

## How to run

input_file command1 | command2 > output file

- Go to root directory and run `make`
- Run `./pipex file1 "ls -la" "grep pipex" file2`
- Usage: `./pipex input_file command1 command2 output file`
- Mimics the UNIX process: `< input_file command1 | command2 > output file`

<br>
