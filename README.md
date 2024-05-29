# joSH - A Simple Shell

**joSH** is a simple shell program written in C, allowing users to execute commands and navigate the system environment. It provides basic functionalities such as executing commands, changing directories, displaying command history, and clearing the screen.

## Features

- **Command Execution**: Execute system commands entered by the user.
- **Change Directory**: Navigate through directories using the `cd` command.
- **Command History**: View a history of previously executed commands.
- **Clear Screen**: Clear the terminal screen using the `clear` command.
- **Simple Interface**: Easy-to-use interface resembling a typical shell.

## How to Use

1. **Compilation**: Compile the program using a C compiler (e.g., gcc):
   ```
   gcc -o josh josh.c
   ```

2. **Execution**: Run the compiled executable:
   ```
   ./josh
   ```

3. **Usage**: Upon launching, you will see the joSH prompt (`joSH >`). Enter commands and press Enter to execute them. Use `exit` to quit the shell.

## Commands

- **Executing Commands**: Enter any system command (e.g., `ls`, `pwd`) to execute it.
- **Change Directory**: Use `cd <directory>` to navigate through directories.
- **Command History**: Enter `history` or `hst` to view the command history.
- **Clear Screen**: Type `clear` to clear the terminal screen.

## Contributing

Contributions are welcome! Feel free to submit issues, feature requests, or pull requests to enhance the functionality and usability of joSH.

## License

This project is licensed under the MIT License. See the [LICENSE.txt](LICENSE.txt) file for details.
