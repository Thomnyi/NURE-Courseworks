#include <iostream>

long long recursiveSeq(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    long long prev1 = recursiveSeq(n - 1);
    long long prev2 = recursiveSeq(n - 2);
    return (prev1 * prev1 * prev1) + (prev2 * prev2 * prev2);
}

int main()
{
    int n;
    long long* arr = new long long[1000];
    arr[0] = 1;
    std::cout << "Please enter number of elements in the sequence: ";
    std::cin >> n;
    if (n < 1) {
        std::cout << "The number cannot be less than 1";
        delete []arr;
        return 0;
    }
    for(int i = 0; i != n; i++) {
        arr[i] = recursiveSeq(i);
        std::cout << arr[i] << " ";
    }
    delete[]arr;
    return 0;
}

