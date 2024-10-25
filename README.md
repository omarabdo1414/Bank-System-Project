# Bank System Project

A console-based bank management system written in C++ that allows users to sign up, log in, and manage different types of bank accounts. This system includes features such as secure login, account creation, customer info display, and tracks memory allocations dynamically.

## Features
- **User Authentication**: Sign-up, log in, and password recovery functionalities.
- **Account Management**: Create Savings and Miles accounts, and view customer information.
- **Memory Management Tracking**: Custom memory allocation and deallocation tracking with custom operators.

## File Structure
```bash
Project_Bank
├── Include
│   ├── bank.h            # Bank interface and class definitions
│   ├── creditCard.h      # Credit card management class
│   ├── customer.h        # Customer class for account management
│   ├── event.h           # Event handling class
│   ├── login.h           # Login and signup functionality
│   ├── MilesAccount.h    # MilesAccount subclass of Account
│   ├── savingAccount.h   # SavingAccount subclass of Account
│   └── subAccount.h      # SubAccount management
├── SRC
│   ├── creditCard.cpp    # Credit card source file
│   ├── customer.cpp      # Customer management source file
│   ├── login.cpp         # Login functionality source file
│   ├── MilesAccount.cpp  # MilesAccount source file
│   ├── savingAccount.cpp # SavingAccount source file
│   └── subAccount.cpp    # SubAccount source file
├── CMakeLists.txt        # CMake build configuration
└── main.cpp              # Main application entry point
```

## Setup and Installation
### Prerequisites
- **C++ compiler**: Ensure a C++ compiler like GCC or MSVC is installed.
- **CMake**: To build the project.

### Build Instructions
1. **Clone the Repository**:
   ```bash
   git clone git@github.com:omarabdo1414/Bank-System-Project.git
   cd Project_Bank
   ```

2. **Build the Project**:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. **Run the Application**:
   ```bash
   ./BankSystemApp  # Replace with executable name if different
   ```

## Usage
- **Main Menu**: Offers options for logging in, signing up, password recovery, and exiting.
- **Account Management**:
  - After login, create either a Savings or Miles account.
  - Display all customer information.
  - Logout option to return to the main menu.

## Memory Allocation Tracking
The application tracks memory allocations with custom `new` and `delete` operators to monitor:
- Total allocations made.
- Total deallocations performed.

## Code Example
```cpp
void* operator new(size_t size) {
    AllocationCount++;
    return malloc(size);
}

void operator delete(void* ptr) noexcept {
    DeletedAllocationCount++;
    free(ptr);
}
```

## Contributions
Feel free to fork this project, submit pull requests, and report issues.

--- 

This README covers the purpose, functionality, structure, and usage instructions for your project, making it clear and useful to potential users and collaborators.