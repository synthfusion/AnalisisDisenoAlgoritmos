#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int weight;
    int benefit;
    double ratio;
};

bool compareItems(Item a, Item b) {
    return a.ratio > b.ratio;
}

double knapsackGreedy(int W, std::vector<Item>& items) {
    std::sort(items.begin(), items.end(), compareItems);

    int currentWeight = 0;
    double totalBenefit = 0.0;

    for (const auto& item : items) {
        if (currentWeight + item.weight <= W) {
            currentWeight += item.weight;
            totalBenefit += item.benefit;
        } else {
            int remainingWeight = W - currentWeight;
            totalBenefit += item.benefit * ((double)remainingWeight / item.weight);
            break;
        }
    }

    return totalBenefit;
}

int main() {
    int W = 50;
    std::vector<Item> items = {
        {10, 60, 0}, {20, 100, 0}, {30, 120, 0}
    };

    for (auto& item : items) {
        item.ratio = (double)item.benefit / item.weight;
    }

    double maxBenefit = knapsackGreedy(W, items);

    std::cout << "El beneficio maximo que se puede obtener es: " << maxBenefit << std::endl;

    return 0;
}
