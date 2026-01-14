# 🛠️ Libft Tester

![Last Commit](https://img.shields.io/github/last-commit/Sfabi28/libft_tester?style=for-the-badge&color=red)

A comprehensive and strict tester for the 42 **Libft** project.

This tester includes **Smart Memory Leak Detection** via Valgrind. To ensure maximum speed without sacrificing safety, Valgrind is only active for functions that require memory allocation (e.g., `ft_split`, `ft_calloc`). 

Standard checks (Segfaults and Timeouts) are performed on **all** functions.

## ✨ Features

* **Smart Valgrind Integration:** Runs slow memory checks only where necessary.
* **Detailed Logging:** Generates a `tests_log.log` file with specific failure details.
* **Crash & Timeout Protection:** Detects segfaults and infinite loops.
* **Norminette Check:** Includes a quick Norminette pass.
* **Forbidden Functions Check:** Verifies that no forbidden functions are used in your binary.

---

## 📁 1. Installation

Ensure that the folder of this tester (`libft_tester`) is located **INSIDE** the root of your `libft` project.

**Correct Directory Structure:**

```text
/libft_root
    ├── Makefile
    ├── libft.h
    ├── *.c (your source files)
    └── libft_tester/       <--- YOU ARE HERE
          ├── .launch.sh
          ├── Makefile
          ├── CHANGELOG.md
          ├── README.md
          └── tests_log.log (generated after run)

**Important:** To avoid accidentally committing the tester to your repository, add `libft_tester/` to your `.gitignore` file:
```

```bash
echo "libft_tester/" >> .gitignore
```


Ensure that the path is right and set a proper timeout time **INSIDE** the `launch.sh` file

```text
   TIMEOUT_TIME=5
```

## ⚙️ 2. Usage Commands
-----------------
The tester supports different modes and optional integration with Valgrind.

```text
Command,Description
make   launches tests on all libft
make "function name"  launches tests only on the function 
```

**⚠️ THE FUNCTION NAME MUST NOT INCLUDE ft_ ⚠️**


## 📊 3. Results Legend
-----------------
```text
[OK]      : The printed output and the return value are identical to the original.
[KO]      : There is a discrepancy. Check the log file for details.
[LEAK]    : There are memory leaks in your function.
[CRASH]   : Your function segfaulted (Segmentation Fault).
[TIMEOUT] : Your function caused an infinite loop (adjust TIMEOUT_TIME in .sh if needed).

```

## 📝 4. Use of AI
-----------
```text
   Many of the tests were made by AI.

   I personally checked them all before publishing this tester.
   If you have any doubt on the results please contact me on my email (you can find it on my GitHub main page)
```
Happy debugging!🖥️



## 🛠️ More 42 Tools

Explore my full suite of testers:

[![ft_printf](https://img.shields.io/badge/42-ft__printf-blue?style=for-the-badge&logo=c)](https://github.com/Sfabi28/printf_tester)
[![get_next_line](https://img.shields.io/badge/42-Get_Next_Line-green?style=for-the-badge&logo=c)](https://github.com/Sfabi28/gnl_tester)
[![push_swap](https://img.shields.io/badge/42-push__swap-orange?style=for-the-badge&logo=c)](https://github.com/Sfabi28/push_swap_tester)
