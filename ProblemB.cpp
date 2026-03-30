#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

bool canCut(const vector<double>& lengths, double length, int K) {
    int count = 0;
    for (double l : lengths) {
        count += static_cast<int>(l / length);
        if (count >= K) return true;
    }
    return false;
}

double maxCableLength(int N, int K, const vector<double>& lengths) {
    double low = 0.01, high = *max_element(lengths.begin(), lengths.end());
    double precision = 0.0001;

    while (high - low > precision) {
        double mid = (low + high) / 2;
        if (canCut(lengths, mid, K)) {
            low = mid;
        }
        else {
            high = mid;
        }
    }

    // Używamy low jako wyniku, ponieważ low będzie ostatnią długością, która spełnia warunek canCut
    return floor(low * 100 + 0.5) / 100;
}

int main() {
    int D;
    cin >> D;
    vector<string> results;

    for (int i = 0; i < D; ++i) {
        int N, K;
        cin >> N >> K;
        vector<double> lengths(N);
        double total_length = 0.0;

        for (int j = 0; j < N; ++j) {
            cin >> lengths[j];
            total_length += lengths[j];
        }

        if (total_length < K * 0.01) {
            results.push_back("0.00");
        }
        else {
            double max_length = maxCableLength(N, K, lengths);
            ostringstream out;
            out << fixed << setprecision(2) << max_length;
            results.push_back(out.str());
        }
    }

    // Wyświetlanie wyników po wprowadzeniu wszystkich danych
    for (const string& result : results) {
        cout << "Wynik: " << result << endl;
    }

    return 0;
}




