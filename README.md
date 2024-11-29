# Get Next Line - 42 Network Project

Get Next Line is a function that reads a line from a file descriptor, designed to efficiently handle large lines and multiple file descriptors, while ensuring proper memory management without relying on external libraries.
It helps in handling file input in C and is a key part of the 42 Network curriculum.

---

## 🚀 Features

- **Reads a line** from a file descriptor, handling multiple reads if the line is too large for a buffer.
- **Memory management**: Ensures dynamic memory allocation for each line.
- **Efficient handling** of multiple file descriptors, allowing you to read from different sources.

---

## 🛠️ Getting Started

### Prerequisites

To get started, ensure you have the following installed:
- A C compiler like `gcc` or `clang`
- `make` for building the project
- A UNIX-like operating system (Linux/macOS/WSL)

### 1. Clone the Repository
```bash
git clone https://github.com/mdbentaleb/get_next_line_42.git
cd get_next_line_42
