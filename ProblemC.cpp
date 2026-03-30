#include <iostream>
#include <vector>
#include <algorithm>

int longest_increasing_subsequence(const std::vector<int>& sequence) {
    std::vector<int> tails;

    for (int num : sequence) {
        auto it = std::lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end()) {
            tails.push_back(num);
        }
        else {
            *it = num;
        }
    }

    return tails.size();
}

int main() {
    int Z; // Liczba zestawów danych
    std::cin >> Z;

    while (Z--) {
        int N; // Długość ciągu
        std::cin >> N;

        std::vector<int> sequence(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> sequence[i];
        }

        std::cout << longest_increasing_subsequence(sequence) << std::endl;
    }

    return 0;
}


