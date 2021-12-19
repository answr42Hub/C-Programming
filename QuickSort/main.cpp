#include <ctime>
#include <chrono>
#include <iostream>

#define DATA_COUNT 250000

using namespace std;
using namespace std::chrono;

int dataSimpleSort[DATA_COUNT];
int dataQuickSort[DATA_COUNT];

steady_clock::time_point start, stop;
duration<double> deltaTime;

void simpleSort() {
    for(int i =0; i < DATA_COUNT; i++) {
        for (int j = i+1; j < DATA_COUNT; j++) {
            if(dataSimpleSort[i] < dataSimpleSort[j])
            swap(dataSimpleSort[i], dataSimpleSort[j]);
        }
    }
}

void quickSort(int iMin, int iMax) {
    int gauche = iMin, pivot = iMin, droite = iMax;
    while(gauche != droite) {
        if(dataQuickSort[gauche] > dataQuickSort[droite]) {
            swap(dataQuickSort[gauche], dataQuickSort[droite]);
            pivot = gauche + droite - pivot;
        }
        (pivot == gauche) ? droite-- : gauche++;
    }
    
    if(iMax > pivot+1) quickSort(pivot+1, iMax);
    if(iMin < pivot-1) quickSort(iMin, pivot-1);
}

int main() {
    // Generation des nombres
    srand(time(NULL));
    start = steady_clock::now();
    for(int i = 0; i < DATA_COUNT; i++)
        dataQuickSort[i] = dataSimpleSort[i] = rand() % 1000;
    stop = steady_clock::now();
    deltaTime = duration_cast<duration<double>>(stop-start);
    cout << "Generation: " << deltaTime.count() << " secondes." << endl;

    // Tri Simple
    // start = steady_clock::now();
    // simpleSort();
    // stop = steady_clock::now();
    // deltaTime = duration_cast<duration<double>>(stop-start);
    // cout << "Tri Simple: " << deltaTime.count() << " secondes." << endl;

    // Tri Rapide
    start = steady_clock::now();
    quickSort(0, DATA_COUNT-1);
    stop = steady_clock::now();
    deltaTime = duration_cast<duration<double>>(stop-start);
    cout << "Tri Rapide: " << deltaTime.count() << " secondes." << endl;

    return 0;
}