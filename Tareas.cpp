#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    int benefit;
    int deadline;
};

bool compareTasks(Task a, Task b) {
    return a.benefit > b.benefit;
}

int findSlot(std::vector<int>& slots, int deadline) {
    for (int i = deadline; i >= 1; --i) {
        if (slots[i] == 0) {
            return i;
        }
    }
    return -1;
}

int maxBenefitScheduling(std::vector<Task>& tasks) {
    std::sort(tasks.begin(), tasks.end(), compareTasks);

    int maxDeadline = 0;
    for (const auto& task : tasks) {
        maxDeadline = std::max(maxDeadline, task.deadline);
    }

    std::vector<int> slots(maxDeadline + 1, 0);
    int totalBenefit = 0;

    for (const auto& task : tasks) {
        int slot = findSlot(slots, task.deadline);
        if (slot != -1) {
            slots[slot] = 1;
            totalBenefit += task.benefit;
        }
    }

    return totalBenefit;
}

int main() {
    std::vector<Task> tasks = {
        {100, 2}, {19, 1}, {27, 2}, {25, 1}, {15, 3}
    };

    int maxBenefit = maxBenefitScheduling(tasks);

    std::cout << "El beneficio maximo que se puede obtener es: " << maxBenefit << std::endl;

    return 0;
}
