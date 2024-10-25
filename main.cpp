#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

std::string generate_password(int length) {
    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::string password;
    
    // Generate random characters
    for (int i = 0; i < length; ++i) {
        password += characters[rand() % characters.size()];
    }
    
    return password;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
    const int password_length = 16;
    const int total_passwords = 20;


    // Open the file in append mode
    std::ofstream file("password.txt", std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    for (int i = 0; i < total_passwords; ++i) {
        std::string password = generate_password(password_length);
        file << password << std::endl; // Save the password
        std::cout << "Generated Password: " << password << std::endl; // Output to console
    }

    file.close();
    return 0;
}

