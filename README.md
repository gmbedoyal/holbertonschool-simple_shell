# Holberton School - Simple Shell Project README


This git contains a simple shell created for C. This shell has the following characteristics:

-   It dsplay a prompt and wait for the user to type a command. A command line always ends with a new line.
-   The prompt is displayed again each time a command has been executed.
-   The command lines are simple, it doesn't support semicolons, nor pipes, nor redirections or any other advanced features.
-   It handles command lines with arguments passed to programs.
-   If an executable cannot be found, it prints an error message and display the prompt again.
-   Handle errors.
-   It handles the “end of file” condition (`Ctrl+D`)

## Flowchart

<img src= "https://i.imgur.com/WX9vuk9.jpeg">

## Installation

To use this shell you need to fork this github into your terminal and compile.


## Usage

```c
$ ls

# returns list of files
README.md         addpath.c          execution.c        hsh      path.c
simple_shell.h    str_functions.c    tokenizer.c a.out  env_cpy.c
free_array.c       main.c            strcmp_functions.c

$ echo "hola"

# returns "hola"
"hola"
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## Creators

https://github.com/gmbedoyal - Miguel Bedoya

https://github.com/jegomezV - Juan Eduardo Gomez
