
extern "C" {

    __declspec(dllexport)
    double add(double a, double b) {
        return a + b;
    }

    __declspec(dllexport)
    double subtract(double a, double b) {
        return a - b;
    }

    __declspec(dllexport)
    double multiply(double a, double b) {
        return a * b;
    }

    __declspec(dllexport)
    double divide(double a, double b) {
        if (b == 0) {
            return 0; 
        }
        return a / b;
    }

}
