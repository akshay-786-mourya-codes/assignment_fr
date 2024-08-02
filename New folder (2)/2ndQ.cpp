#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <cmath>
#include <limits>
#include <string>

using namespace std;

void distribute_apples() {
    vector<int> apple_weights;
    int weight;
    
    // Input weights of apples
    cout << "Enter apple weight in gram (-1 to stop): ";
    while (cin >> weight && weight != -1) {
        apple_weights.push_back(weight);
        cout << "Enter apple weight in gram (-1 to stop): ";
    }

    // Sort weights in descending order for greedy distribution
    sort(apple_weights.rbegin(), apple_weights.rend());

    // Amount paid by each person
    map<string, int> amounts_paid = {{"Ram", 50}, {"Sham", 30}, {"Rahim", 20}};
    int total_amount = 100;
    int total_weight = accumulate(apple_weights.begin(), apple_weights.end(), 0);

    // Target weights for each person based on amount paid
    map<string, double> target_weights;
    for (const auto& p : amounts_paid) {
        target_weights[p.first] = total_weight * (static_cast<double>(p.second) / total_amount);
    }

    // Store the distributed weights
    map<string, vector<int>> distributed_weights;
    map<string, int> current_weights = {{"Ram", 0}, {"Sham", 0}, {"Rahim", 0}};

    // Greedy distribution of apples
    for (const int& w : apple_weights) {
        string best_fit;
        double min_diff = numeric_limits<double>::max();

        for (const auto& p : amounts_paid) {
            string person = p.first;
            int potential_weight = current_weights[person] + w;
            double diff = abs(target_weights[person] - potential_weight);
            if (diff < min_diff) {
                min_diff = diff;
                best_fit = person;
            }
        }

        distributed_weights[best_fit].push_back(w);
        current_weights[best_fit] += w;
    }

    // Output the distribution result
    cout << "Distribution Result:" << endl;
    for (const auto& p : distributed_weights) {
        cout << p.first << " : ";
        for (size_t i = 0; i < p.second.size(); ++i) {
            cout << p.second[i];
            if (i != p.second.size() - 1) cout << ", ";
        }
        cout << endl;
    }
}

int main() {
    distribute_apples();
    return 0;
}
