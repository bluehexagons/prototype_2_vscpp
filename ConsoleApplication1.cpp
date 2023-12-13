#include <iostream>
#include <string>
#include <format>
using std::endl, std::string;

using Number = long long;

template <typename T>
bool from_string(const std::string& str, T& value) {
    auto [_p, ec] = std::from_chars(str.data(), str.data() + str.size(), value);

    return ec == std::errc();
}

template <typename T>
bool prompt_string(T& value) {
    string userInput;

    std::getline(std::cin, userInput);

    return from_string(userInput, value);
}

void findFactors(Number n) {
    // Use trial division to find factors
    Number upper = n + 1;

    for (Number i = 1; i < upper; i++) {
        if (n % i == 0) {
            std::cout << std::format("{} {} ", i, n / i);
            upper = n / i;
        }
    }
}

int main() {
    while (true) {
        std::cout << "Enter a number to check for factors:" << endl;
        Number val = 0;

        prompt_string(val);

        if (val == 0) {
            std::cout << "Exiting";
            return 0;
        }

        std::cout << std::format("Let's find factors! {}\n", val);

        findFactors(val);
        std::cout << endl;
    }
}

