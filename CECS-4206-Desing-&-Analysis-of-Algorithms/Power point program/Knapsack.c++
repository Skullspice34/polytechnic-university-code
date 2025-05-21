#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent each item with its value and weight
struct Item {
    int value;
    int weight;
};

// Function to compare items based on their value-to-weight ratio
bool compare(Item i1, Item i2) {
    double ratio1 = (double)i1.value / i1.weight; // Calculate ratio for item 1
    double ratio2 = (double)i2.value / i2.weight; // Calculate ratio for item 2
    return ratio1 > ratio2; // Sort in descending order of ratios
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare); // Sort items based on value-to-weight ratio

    double totalValue = 0.0; // Initialize total value of items in the knapsack
    int currentWeight = 0; // Initialize current weight in the knapsack

    // Iterate through each item
    for (int i = 0; i < items.size(); ++i) {
        // If adding the entire item does not exceed capacity, add it
        if (currentWeight + items[i].weight <= capacity) {
            totalValue += items[i].value; // Add value of the item
            currentWeight += items[i].weight; // Add weight of the item
        } else {
            // If adding the entire item exceeds capacity, add fraction of it
            int remainingCapacity = capacity - currentWeight; // Calculate remaining capacity
            totalValue += (double)items[i].value * remainingCapacity / items[i].weight; // Add fraction of value
            break; // Stop adding items as capacity is reached
        }
    }

    return totalValue; // Return total value of items in the knapsack
}

int main() {
    // Define items and capacity
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 50;

    // Find maximum value that can be obtained using fractional knapsack
    double maxValue = fractionalKnapsack(capacity, items);

    // Output the maximum value that can be obtained
    cout << "Maximum value that can be obtained: $" << maxValue << endl;

    return 0;
}
