#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Estructura para representar una tarea
struct Task {
    int start, end, benefit;
    Task(int s, int e, int b) : start(s), end(e), benefit(b) {}
};

// Función auxiliar para ordenar las tareas por tiempo de finalización
bool sortByEndTime(const Task &a, const Task &b) {
    return a.end < b.end;
}

// Función recursiva de backtracking para encontrar la máxima ganancia
void backtrack(vector<Task>& tasks, vector<int>& currentSolution, int& maxBenefit, int index) {
    // Calcular el beneficio total actual
    int currentBenefit = 0;
    for (int i = 0; i < currentSolution.size(); ++i) {
        if (currentSolution[i] == 1) {
            currentBenefit += tasks[i].benefit;
        }
    }
    
    // Actualizar el máximo beneficio encontrado
    maxBenefit = max(maxBenefit, currentBenefit);
    
    // Recorrer las tareas siguientes
    for (int i = index; i < tasks.size(); ++i) {
        // Verificar si la tarea puede ser incluida sin solaparse
        bool canInclude = true;
        for (int j = 0; j < i; ++j) {
            if (currentSolution[j] == 1 && tasks[j].end > tasks[i].start) {
                canInclude = false;
                break;
            }
        }
        
        // Si puede incluirse, hacemos la recursión
        if (canInclude) {
            currentSolution[i] = 1;
            backtrack(tasks, currentSolution, maxBenefit, i + 1);
            currentSolution[i] = 0;
        }
    }
}

// Función principal para resolver el problema del planificador de tareas
int maxBenefitScheduler(vector<Task>& tasks) {
    int n = tasks.size();
    if (n == 0) return 0;
    
    // Ordenar las tareas por tiempo de finalización
    sort(tasks.begin(), tasks.end(), sortByEndTime);
    
    // Inicializar la solución actual y el máximo beneficio encontrado
    vector<int> currentSolution(n, 0);
    int maxBenefit = 0;
    
    // Llamar a la función de backtracking
    backtrack(tasks, currentSolution, maxBenefit, 0);
    
    return maxBenefit;
}

int main() {
    // Ejemplo de uso
    vector<Task> tasks = {
        {1, 4, 5},  // Tarea 1: inicio = 1, fin = 4, beneficio = 5
        {3, 5, 6},  // Tarea 2: inicio = 3, fin = 5, beneficio = 6
        {0, 6, 8},  // Tarea 3: inicio = 0, fin = 6, beneficio = 8
        {4, 7, 2}   // Tarea 4: inicio = 4, fin = 7, beneficio = 2
    };

    int maxBenefit = maxBenefitScheduler(tasks);
    cout << "El beneficio máximo es: " << maxBenefit << endl;

    return 0;
}
