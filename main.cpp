
#include <iostream>
#include <windows.h>

typedef double (*CalculatorFunction)(double, double);

int main() {

    HINSTANCE dll = LoadLibraryA("calculator.dll");

    if (!dll) {
        std::cout << "Unable to load DLL!" << std::endl;
        return 1;
    }

    CalculatorFunction add =
        (CalculatorFunction)GetProcAddress(dll, "add");

    CalculatorFunction subtract =
        (CalculatorFunction)GetProcAddress(dll, "subtract");

    CalculatorFunction multiply =
        (CalculatorFunction)GetProcAddress(dll, "multiply");

    CalculatorFunction divide =
        (CalculatorFunction)GetProcAddress(dll, "divide");

    double a, b;

    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;

    std::cout << "Addition: " << add(a, b) << std::endl;
    std::cout << "Subtraction: " << subtract(a, b) << std::endl;
    std::cout << "Multiplication: " << multiply(a, b) << std::endl;

    if (b != 0)
        std::cout << "Division: " << divide(a, b) << std::endl;
    else
        std::cout << "Division: Cannot divide by zero!" << std::endl;

    FreeLibrary(dll);

    return 0;
}
