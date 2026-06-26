# Build Log - 2026-06-26 (Session 1)
## <div style="display:flex; justify-content:space-between;"> <span style="color:forestgreen;">Duration - 9:30am to 1:00 pm</span><span>git commit -m <span style="color:forestgreen;font-size:17px;"> "implemented basic redis-lite" </span> </span> </div>



# Objective

The objective for today's session was to build the first working version of **Redis-Lite** using the custom **HashMap** implementation developed as part of the STL Library project. The goal was to create a lightweight in-memory key-value database capable of processing Redis-like commands through a command-line interface without relying on STL associative containers.

---

# Work Completed

## Redis-Lite CLI Implementation

Implemented the core architecture of Redis-Lite and integrated it with the custom `HashMap`.

Successfully developed an interactive command-line application capable of continuously accepting user commands and performing database operations in real time.

---

## Command Processing

Implemented a command parser using:

* `getline()`
* `stringstream`

Each command is parsed into individual components before execution.

Example:

```text
SET name Nilesh
```

is parsed as:

```text
Method : set
Key    : name
Value  : Nilesh
```

---

## Supported Commands

The current implementation supports the following Redis-like commands:

* `SET`
* `GET`
* `EXISTS`
* `DEL`
* `CLEAR`
* `SIZE`

All commands directly interact with the custom HashMap implementation.

---

## Case-Insensitive Commands

Implemented a custom `To_lower()` utility to normalize user input before processing.

This allows commands to be executed irrespective of letter casing.

Example:

```text
SET
set
SeT
sEt
```

All are interpreted as the same command.

---

## HashMap Integration

Integrated Redis-Lite with the previously implemented custom HashMap.

The command-to-function mapping is as follows:

| Redis Command | HashMap Function |
| ------------- | ---------------- |
| SET           | insert()         |
| GET           | get()            |
| EXISTS        | exists()         |
| DEL           | remove()         |
| CLEAR         | clear()          |
| SIZE          | size()           |

This marks the first practical application built using the custom STL library.

---

# Problems Faced

## 1. Syntax Errors

Encountered several compilation issues caused by small syntax mistakes, including:

* Missing semicolons
* Typographical errors
* Missing return statements

These resulted in multiple cascading template compilation errors.

---

## 2. Using `switch` with `std::string`

Initially attempted to process Redis commands using a `switch` statement.

Compiler error:

```text
switch quantity not an integer
```

### Resolution

Replaced the command dispatcher with an `if-else` chain since C++ does not allow `std::string` in `switch` statements.

---

## 3. Variable Scope Inside `switch`

While experimenting with `switch`, encountered errors such as:

* Variable redeclaration
* Jump to case label
* Crosses initialization

### Learning

Variables declared inside one `case` remain within the switch scope unless enclosed inside braces.

---

## 4. Missing Semicolon

Forgot a semicolon after:

```cpp
ss >> key
```

which generated several unrelated compiler errors.

---

## 5. Namespace Issues

Encountered errors related to:

* `cout`
* `cin`
* `string`
* `endl`

These were caused by namespace visibility and missing `std::` qualification.

---

## 6. Template Definition Issues

Faced declaration mismatches between template declarations and definitions while implementing member functions inside the `.tpp` file.

---

## 7. Incorrect Compilation of Template Implementation

Attempted to compile the `.tpp` file directly.

This resulted in linker errors because template implementation files should only be included through the corresponding header and are not standalone compilation units.

---

## 8. Function Return Errors

The `size()` function initially returned `size_t` without returning an actual value.

This was corrected by returning the current HashMap size.

---

# Concepts Learned

* Building a CLI-based command interpreter.
* Parsing commands using `getline()` and `stringstream`.
* Case-insensitive command processing.
* Integrating a custom HashMap into a real-world application.
* Limitations of `switch` statements with non-integral types.
* Variable scope rules inside `switch` statements.
* Template implementation using `.tpp` files.
* Difference between compilation errors and linker errors.
* Proper organization of template-based projects.

---

# Current Status

The **basic version of Redis-Lite is now complete and fully functional**.

The application can now execute Redis-like commands directly from the terminal using the custom HashMap as its storage engine.

Current features include:

* Interactive CLI
* Command parsing
* In-memory key-value storage
* Case-insensitive commands
* HashMap integration
* Basic Redis operations

The project has successfully reached a stage where it is usable as a standalone command-line database.

---

# Next Steps

The next phase of development is to convert the current CLI-based application into a **client-server architecture**.
