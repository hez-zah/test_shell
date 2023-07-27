![image](https://gunmagwarehouse.com/blog/wp-content/uploads/2022/04/12-gauge-minishell-brands-1536x1152.jpeg)

<h1 align="center" text_color="red">Minishell Project</h1>

### This project aims to create a mini version of bash, Creating almost the same behavior

---

- Search and launch the right executable (based on the PATH variable or using arelative or an absolute path).
- Handle ’ (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence.
- Handle " (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for $ (dollar sign).
- Implement redirections:
    - `<` should redirect input.
    - `>` should redirect output.
    - `<<` should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn’t have to update the history.
    - `>>` should redirect output in append mode.
-  Implement pipes (| character). The output of each command in the pipeline is connected to the input of the next command via a pipe.
-  Handle environment variables ($ followed by a sequence of characters) which should expand to their values.
-  Handle $? which should expand to the exit status of the most recently executed foreground pipeline.
-  Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash.
-  In interactive mode:
    - `ctrl-C` displays a new prompt on a new line.
    - `ctrl-D` exits the shell.
    - `ctrl-\` does nothing.
- Your shell must implement the following builtins:
    - echo with option -n
    - cd with only a relative or absolute path
    - pwd with no options
    - export with no options
    - unset with no options
    - env with no options or arguments
    - exit with no options

---

In Your program you can use the multiple functions, `readline()` is one of them.
