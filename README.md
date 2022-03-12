# ft_printf
A repository to store and share my implementation of `printf` function. Written for a 42 project.

<p align="center">
	<img src="readme_ressources/grade.png" alt="Libft Grade" width="280" height="300"/>
</p>

<p align="center">
	<img src="https://img.shields.io/github/languages/top/Spidfail/ft_printf" alt="Most used language"/>
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/Spidfail/ft_printf">
	<img alt="Repo size" src="https://img.shields.io/github/repo-size/Spidfail/ft_printf ">
	<img src="https://img.shields.io/github/license/Spidfail/ft_printf" alt="Licence"/>
</p>

<p align="center">
	<img src="https://img.shields.io/github/last-commit/Spidfail/ft_printf" alt="Last commit"/>
	<img src="https://img.shields.io/github/issues-pr/Spidfail/ft_printf" alt="Pull requests"/>
	<img src="https://img.shields.io/github/issues/Spidfail/ft_printf" alt="Issues"/>
	<img src="https://img.shields.io/github/contributors/Spidfail/ft_printf" alt="Contributors"/>
</p>

<p align="center">
	<img src="https://img.shields.io/github/followers/Spidfail?style=social" alt="User followers"/>
	<!-- <img src="https://img.shields.io/github/stars/Spidfail?style=social" alt="User followers"/> -->
	<!-- <img src="https://img.shields.io/github/watchers/Spidfail/ft_printf?style=social" alt="User followers"/> -->
</p>

## Original purpose

The `ft_printf` project aims to learn the basics of C programming language by recoding a popular function among programmers : `printf`. As a training exercise, it's not perfect but it works.

Some constrains were added to make us use our brain, here is a summary :
- As many file as we want.
- A header should list all non-static functions.
- The keyword `static` must be used prior to auxiliary functions in the same file.
- It should follow the norm imposed by the school (syntax mostly, 5 functions max per file, 25l maximum per function...)
- We cannot use unauthorized functions.
- Authorized functions : `write()` `malloc()` `free()` `va_arg()` `va_start()` `va_copy()` `va_end()`
- Imposed Makefile rules like `$(NAME)` or `clean`
- Imposed compilation flags : `-Wall -Wextra -Werror`
- The program must not create memory leaks.

42's subject asked us to implement :
- conversions (`%c %d %i %s %p %u %x %X %%`)
- flags (`-` `0` `.`)
- bonus flags (`[space]` `+`)

## How to install the project

Just clone it in your directory.

## How to use ft_printf 

Include the header in yours : `#include "ft_printf/inc/ft_printf.h"`

Prototype : `int	ft_printf(const char *, ...);`

About implementation, don't forget the prefix "ft_" to distinguish these functions from the strandard ones.

## Compilation

The Makefile will produce a binary called `libftprintf.a` by using `ar` command. Compile/link your project with the binary to be able to use `ft_printf()`.

You can use these commands :
- `make`
- `make cf` : compile then link the project with optionnal `main.c`
- `make cnf` : same as `cf` without `-Werror` flag.
- `make cf-san` : same as `cf` with `-fsanitize=address` flag.
- `make cnf-san` : same as `cnf` with `-fsanitize=address` flag.
- `clean`, `fclean`, `sclean`, `sfclean` : clean directory or libft directory.
- `re` : force clean then recompile the project.

This project has it's own `libft` implementation, slightly different from mine (see [here](https://github.com/Spidfail/libft_extended)). The Makefile compile it automatically.

If you want to run this Makefile from yours, check [recursion in Makefile](https://www.gnu.org/software/make/manual/html_node/Recursion.html) to learn more.
