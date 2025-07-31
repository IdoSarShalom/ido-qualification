#include <iostream>
#include <memory>
#include <numeric>
#include <iterator>

int get_array_size() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    return size;
}

void fill_array(std::unique_ptr<int[]> &arr, const int size) {
    std::cout << "Enter " << size << " integer values:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Enter value for element " << i << ": ";
        std::cin >> arr[i];
    }
}

int calculate_sum(const std::unique_ptr<int[]> &arr, const int size) {
    return std::accumulate(arr.get(), arr.get() + size, 0);
}

void print_sum(const std::unique_ptr<int[]> &arr, int size) {
    const int sum = calculate_sum(arr, size);
    std::cout << "The sum of all the values in the array is: " << sum << std::endl;
}

int main() {
    const int size = get_array_size();
    auto arr = std::make_unique<int[]>(size);
    fill_array(arr, size);
    print_sum(arr, size);

    return 0;
}
