/**
 * @file main.cpp
 * @brief Bank system application with login, sign-up, and account management functionality.
 */

#include <iostream>
#include "./login.h"
#include "./bank.h"
#include "./customer.h" // Include the Customer class
#include "./MilesAccount.h" // Include MilesAccount class
#include <map>
#include <functional>
#include <atomic>

/**
 * @brief Global atomic variable to track the number of memory allocations.
 */
static std::atomic<int> AllocationCount = 0;
static std::atomic<int> DeletedAllocationCount = 0;

/**
 * @brief Custom memory allocation operator that tracks the number of allocations.
 * 
 * @param size The size of the memory block to allocate.
 * @return A pointer to the allocated memory block.
 */
void* operator new(size_t size)
{
    AllocationCount++;
    return malloc(size);
}

/**
 * @brief Custom memory deallocation operator.
 * 
 * @param ptr Pointer to the memory block to free.
 */
void operator delete(void* ptr) noexcept
{
    DeletedAllocationCount++;
    free(ptr);
}

/**
 * @brief Displays the first page of the application, providing options for login, sign-up, password recovery, or exit.
 */
void firstPage()
{
    std::cout << "\n1- Login";
    std::cout << "\n2- Sign-Up";
    std::cout << "\n3- Forget Password or username";
    std::cout << "\n4- Exit";
    std::cout << "\nEnter Your choice: ";
}

/**
 * @brief Displays the account management menu for the customer. Allows creating savings or miles accounts, displaying customer info, and logging out.
 * 
 * @param customer Reference to a Customer object.
 */
void accountMenu(Customer& customer) {
    char choice;
    std::string name, id;
    bool running = true; // Flag to control the menu loop

    while (running) {
        std::cout << "\n1- Create Savings Account";
        std::cout << "\n2- Create Miles Account";
        std::cout << "\n3- Display Customer Info";
        std::cout << "\n4- Logout";
        std::cout << "\nEnter Your choice: ";

        std::cin >> choice;

        // Prompt for name and ID only if not logging out
        if (choice == '1' || choice == '2' || choice == '3')
        {
            std::cout << "\nEnter Your name: ";
            std::cin >> name;
            std::cout << "\nEnter Your National Id: ";
            std::cin >> id;
        }
        else
        {
            continue;
        }

        switch (choice)
        {
        case '1':
            customer.createAccount("Saving", name, id);
            break;
        case '2':
            customer.createAccount("Miles", name, id);
            break;
        case '3':
            customer.displayCustomerInfo();
            break;
        case '4':
            std::cout << "Logging out...\n";
            running = false; // Set flag to false to exit the loop
            break;
        default:
            std::cout << "Invalid Choice....!" << std::endl;
            break;
        }
    }
}

/**
 * @brief Main function of the bank system application.
 * 
 * Provides options for login, sign-up, and password recovery, then moves to account management.
 * Tracks memory allocations using custom new/delete operators.
 * 
 * @return int Exit code (0 for successful execution).
 */
int main() {
    Temp obj;
    bool loggedIn = false;  // Track if the user is logged in

    while (!loggedIn) {
        firstPage();
        char choice;
        std::cin >> choice;

        switch (choice) {
        case '1':
            if (obj.login()) {   // If login is successful, break out of the loop and go to accountMenu
                loggedIn = true;
            } else {
                std::cout << "Login failed, please try again.\n";
            }
            break;
        case '2':
            obj.signUp(); // Sign-up, then redirect to first page
            break;
        case '3':
            obj.forget(); // Forget password, then redirect to first page
            break;
        case '4':
            exit(0);      // Exit the application
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
    

    // Once logged in, proceed to account management
    Customer customer;
    accountMenu(customer);

    // Display number of allocations in the heap
    std::cout << "Allocations so far: " << AllocationCount.load() << std::endl;
    std::cout << "Deallocations so far: " << DeletedAllocationCount.load() << std::endl;
}