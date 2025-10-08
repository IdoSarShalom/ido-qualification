#include <iostream>
#include <memory>
#include <numeric>
#include <limits>

size_t get_array_size() {
    long long input; // signed type to catch negatives
    while (true) {
        std::cout << "Enter the size of the array (positive integer): ";
        if (std::cin >> input && input > 0) {
            return static_cast<size_t>(input); // safe cast
        }
        std::cout << "Invalid size. Please try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void fill_array(std::unique_ptr<int[]> &arr, size_t size) {
    std::cout << "Enter " << size << " integer values:\n";
    for (size_t i = 0; i < size; ++i) {
        std::cout << "Enter value for element " << i << ": ";
        std::cin >> arr[i];
    }
}

int calculate_sum(const std::unique_ptr<int[]> &arr, size_t size) {
    return std::accumulate(arr.get(), arr.get() + size, 0);
}

void print_sum(const std::unique_ptr<int[]> &arr, size_t size) {
    std::cout << "The sum of all the values in the array is: "
              << calculate_sum(arr, size) << std::endl;
}

int main() {
    const size_t size = get_array_size();
    auto arr = std::make_unique<int[]>(size);
    fill_array(arr, size);
    print_sum(arr, size);
    return 0;
}
