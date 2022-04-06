#include <iostream>
#include <string>
#ifndef ILLEGAL
#define ILLEGAL
class illegalParameterValue {
   private:
    std::string message;

   public:
    illegalParameterValue()
        : message("Illegal parameter value") {}
    illegalParameterValue(char* theMassage) {
        message = std::string(theMassage);
    }
    void outputMessage() { std::cout << message << "\n"; }
    ~illegalParameterValue() = default;
};

#endif  // ILLEGAL

int abc(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0)
        throw illegalParameterValue("All parameters should be>0");
    return a + b * c;
}

int main() {
    try {
        std::cout << abc(2, 1, 4) << "\n";
    } catch (illegalParameterValue e) {
        std::cout << "The parameters to abc were 2,0 and 4"
                  << "\n";
        std::cout << "illegalParameterValue exception thrown"
                  << "\n";
        e.outputMessage();
        return 1;
    }
    return 0;
}