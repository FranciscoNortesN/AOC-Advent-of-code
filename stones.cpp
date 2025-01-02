#include <iostream>
#include <vector>
#include <unordered_map>

// Function to count the number of digits in a number
int countDigits(long long num) {
    int count = 0;
    if (num == 0) return 1;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

// Function to transform a value based on the given rules
std::vector<long long> transformValue(long long value, std::unordered_map<long long, std::vector<long long>>& memo) {
    // Check if the value is already memoized
    if (memo.find(value) != memo.end()) {
        return memo[value];
    }

    std::vector<long long> result;
    if (value == 0) {
        result.push_back(1);
    } else if (countDigits(value) % 2 == 0) {
        int halfDigits = countDigits(value) / 2;
        long long divisor = 1;
        for (int j = 0; j < halfDigits; j++) {
            divisor *= 10;
        }
        long long firstPart = value / divisor;
        long long secondPart = value % divisor;
        result.push_back(firstPart);
        result.push_back(secondPart);
    } else {
        result.push_back(value * 2024);
    }

    // Memoize the result
    memo[value] = result;
    return result;
}

// Function to apply transformations using dynamic programming
std::vector<long long> applyTransformations(const std::vector<long long>& stones, int iterations) {
    std::unordered_map<long long, std::vector<long long>> memo;
    std::vector<long long> currentStones = stones;
    for (int i = 0; i < iterations; i++) {
        std::vector<long long> newStones;
        for (long long value : currentStones) {
            std::vector<long long> transformedValues = transformValue(value, memo);
            newStones.insert(newStones.end(), transformedValues.begin(), transformedValues.end());
        }
        currentStones = newStones;
    }
    return currentStones;
}

int main() {
    // Original dynamic array
    std::vector<long long> stones = {773, 79858, 0, 71, 213357, 2937, 1, 3998391};

    // Apply transformations 25 times
    std::vector<long long> finalStones = applyTransformations(stones, 75);


    // Print the number of values in the final array
    std::cout << "El numero de piedras es: " << finalStones.size() << std::endl;

    return 0;
}