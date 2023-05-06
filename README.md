<h1 align="center">
	🔍📖 get_next_line
</h1>

<p align="center">
	<b><i>get_next_line from a file (line ends with \n or EOF)</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/jblackiex/42_get_next_line?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/jblackiex/42_get_next_line?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/jblackiex/42_get_next_line?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/jblackiex/42_get_next_line?color=black" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/jblackiex/42_get_next_line?color=green" />
</p>

<h3 align="center">
	<a href="#-VERSIONS">⚙️VERSIONS</a>
	<span> · </span>
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

---

## 💡 About the project

> _The aim of this project is to make you code a function that returns a line, read from a file descriptor._

	You will understand how files are opened, read and closed in an OS,
	and how they are interpreted by a programming language for further analysis.
	This task is crucial to understand for a future programmer since much of the time is based
	on manipulating files for data management and persistence.
	This project consists of coding a function that returns one line at a time from a text file.

For more detailed information, look at the [**subject of this project**](https://github.com/jblackiex/42_get_next_line/blob/main/get_next_line_subject.pdf).


## 🛠️ Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Using it in your code**

To use the function in your code, simply include its header:

```C
#include "get_next_line.h"
```

and, when compiling your code, add the source files and the required flag:

```shell
get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```
## 📚 VERSIONS

--- > BUFFER_SIZE version: [**read_BUFFER_SIZE_bytes**](https://github.com/jblackiex/42_get_next_line/tree/main/read_BUFFER_SIZE_bytes).

--- > Instead of BUFFER_SIZE try [**read_1_byte**](https://github.com/jblackiex/42_get_next_line/tree/main/read_1_byte) version.


## 📋 Testing

Manual testing:
  ---> add main function inside get_next_line.c and open test.txt file with OPEN function
```shell
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils.c && ./a.out
```

Tested with:

* [Tripouille/gnlTester](https://github.com/Tripouille/gnlTester)
