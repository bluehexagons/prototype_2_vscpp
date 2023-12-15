#include <iostream>
#include <string>
#include <format>
#include <vector>

using std::endl;
using std::string;
using std::vector;

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

void sieveOfEratosthenes(Number n) {
    vector<bool> flags(n);

    for (Number i = 2; i < n; i++) {
        if (flags[i]) continue;

        std::cout << std::format("{} ", i);

        for (Number j = i + i; j < n; j += i) {
            flags[j] = true;
        }
    }
}

int main() {
    while (true) {
        std::cout << std::format("Enter a number up to {}:", std::numeric_limits<long long>::max()) << endl;
        Number val = 0;

        prompt_string(val);

        if (val == 0) {
            std::cout << "Exiting";
            return 0;
        }

        std::cout << std::format("Factors of {}:\n", val);
        findFactors(val);
        std::cout << endl << endl;

        if (val < 1000000) {
            std::cout << std::format("Finding prime numbers up to {}.\n  ", val);
            sieveOfEratosthenes(val);
            std::cout << endl << endl;
        }
    }
}

