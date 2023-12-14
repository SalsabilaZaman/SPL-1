#include <iostream>
#include <complex>

int main() {
    // Get input from the user
    double input;
    std::cout << "Enter a negative number: ";
    std::cin >> input;

    // Check if the input is negative
    if (input >= 0) {
        std::cerr << "Error: Input must be a negative number." << std::endl;
        return 1;
    }

    // Calculate the square root of the negative number using std::sqrt and std::complex
    std::complex<double> result = std::sqrt(input);

    // Print the result
    std::cout << "The imaginary square root of " << input << " is: " << result << std::endl;

    return 0;
}

