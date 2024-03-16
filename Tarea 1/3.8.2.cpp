#include <iostream>
#include <cstdlib>

float Addition(float a, float b);
float Subtraction(float a, float b);
float Multiplication(float a, float b);
float Division(float a, float b);

int main() {

    typedef float (*lpfnOperation)(float, float);
    lpfnOperation vpf[4] = {&Addition, &Subtraction, &Multiplication, &Division};

    float a, b, c;
    int opt;

    std::cout << "Ingresar primer numero: ";
    std::cin >> a;

    std::cout << "Ingresar segundo numero: ";
    std::cin >> b;

    std::cout << "Elegir operacion (0: Suma, 1: Resta, 2: Multiplicacion, 3: Division): ";
    std::cin >> opt;

    if (opt < 0 || opt > 3) {
        std::cerr << "Opcion invalida!\n";
        return 1; 
    }

    c = (*vpf[opt])(a, b);

    switch (opt) {
        case 0:
            std::cout << a << " + " << b << " = " << c << std::endl;
            break;
        case 1:
            std::cout << a << " - " << b << " = " << c << std::endl;
            break;
        case 2:
            std::cout << a << " * " << b << " = " << c << std::endl;
            break;
        case 3:
            if (b == 0) {
                std::cerr << "Error: Division entre cero!\n";
                return 1;
            } else {
                std::cout << a << " / " << b << " = " << c << std::endl;
            }
            break;
    }

    return 0;
}


float Addition(float a, float b) {
    return a + b;
}

float Subtraction(float a, float b) {
    return a - b;
}

float Multiplication(float a, float b) {
    return a * b;
}

float Division(float a, float b) {
    if (b == 0) {
        return std::numeric_limits<float>::infinity(); 
    } else {
        return a / b;
    }
}
