#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

std::vector<int> fillRandomNum(int size) {
    std::vector<int> array(size);
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
    return array;
}

void bubbleSort(std::vector<int>& array) {
    int temp;
    for (int i = 0; i < array.size(); i++) {
        for (int j = 1; j < (array.size() - i); j++) {
            if (array[j - 1] > array[j]) {
                // swap elements
                temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void insertionSort(std::vector<int>& array) {
    int temp;
    for (int i = 1; i < array.size(); i++) {
        for (int j = i; j > 0; j--) {
            if (array[j] < array[j - 1]) {
                // swap elements
                temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
        }
    }
}

void selectionSort(std::vector<int>& array) {
    int temp;
    for (int i = 0; i < array.size() - 1; i++) {
        int index = i;
        for (int j = i + 1; j < array.size(); j++) {
            if (array[j] < array[index]) {
                index = j;
            }
        }
        // swap elements
        temp = array[index];
        array[index] = array[i];
        array[i] = temp;
    }
}

void merge(std::vector<int>& array, int left, int middle, int right) {
    int size1 = middle - left + 1;
    int size2 = right - middle;

    std::vector<int> leftArray(size1);
    std::vector<int> rightArray(size2);

    for (int i = 0; i < size1; i++) {
        leftArray[i] = array[left + i];
    }
    for (int j = 0; j < size2; j++) {
        rightArray[j] = array[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < size1 && j < size2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        }
        else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < size2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& array, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}

int partition(std::vector<int>& array, int left, int right) {
    int pivot = array[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (array[j] <= pivot) {
            i++;
            // swap elements
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    // swap elements
    int temp = array[i + 1];
    array[i + 1] = array[right];
    array[right] = temp;
    return i + 1;
}

void quickSort(std::vector<int>& array, int left, int right) {
    if (left < right) {
        int pivot = partition(array, left, right);
        quickSort(array, left, pivot - 1);
        quickSort(array, pivot + 1, right);
    }
}

void heapify(std::vector<int>& array, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && array[left] > array[largest]) {
        largest = left;
    }
    if (right < n && array[right] > array[largest]) {
        largest = right;
    }
    if (largest != i) {
        // swap elements
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        heapify(array, n, largest);
    }
}

void heapSort(std::vector<int>& array) {
    int n = array.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(array, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        // swap elements
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        heapify(array, i, 0);
    }
}

void countingSort(std::vector<int>& array) {
    int max = *std::max_element(array.begin(), array.end());
    std::vector<int> count(max + 1, 0);
    for (int i = 0; i < array.size(); i++) {
        count[array[i]]++;
    }
    int index = 0;
    for (int i = 0; i < count.size(); i++) {
        while (count[i] > 0) {
            array[index++] = i;
            count[i]--;
        }
    }
}

void radixSort(std::vector<int>& array) {
    int max = *std::max_element(array.begin(), array.end());
    for (int place = 1; max / place > 0; place *= 10) {
        countingSort(array, place);
    }
}

void countingSort(std::vector<int>& array, int place) {
    std::vector<int> count(10, 0);
    std::vector<int> temp(array.size());

    for (int i = 0; i < array.size(); i++) {
        count[(array[i] / place) % 10]++;
    }

    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    for (int i = array.size() - 1; i >= 0; i--) {
        temp[--count[(array[i] / place) % 10]] = array[i];
    }

    for (int i = 0; i < array.size(); i++) {
        array[i] = temp[i];
    }
}

void bucketSort(std::vector<int>& array) {
    int max = *std::max_element(array.begin(), array.end());
    std::vector<int> bucket(max + 1, 0);
    for (int i = 0; i < array.size(); i++) {
        bucket[array[i]]++;
    }
    int index = 0;
    for (int i = 0; i < bucket.size(); i++) {
        while (bucket[i] > 0) {
            array[index++] = i;
            bucket[i]--;
        }
    }
}

int main() {
    int size = 99;
    std::vector<int> array;
    long startTime, endTime, duration;

    int maxIterations = 9999;

    // Bubble Sort
    long meanTime = 0;
    for (int i = 0; i < maxIterations; i++) {
        array = fillRandomNum(size);
        startTime = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        bubbleSort(array);
        endTime = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        duration = (endTime - startTime);
        meanTime += duration;
    }
    meanTime /= maxIterations;
    std::cout << "Bubble Sort: " << meanTime << "ns" << std::endl;

    // Insertion Sort
    meanTime = 0;
    for (int i = 0; i < maxIterations; i++) {
        array = fillRandomNum(size);
        startTime = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        insertionSort(array);
        endTime = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        duration = (endTime - startTime);
        meanTime += duration;
    }
    meanTime /= maxIterations;
    std::cout << "Insertion Sort: " << meanTime << "ns" << std::endl;

    // Selection Sort
    meanTime = 0;
    for (int i = 0; i < maxIterations; i++) {
        array = fillRandomNum(size);
        startTime = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        selectionSort(array);
        endTime = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        duration = (endTime - startTime);
        meanTime += duration;
    }
    meanTime /= maxIterations;
    std::cout << "Selection Sort: " << meanTime << "ns" << std::endl;

    // Merge Sort
    meanTime = 0;
    for (int i = 0; i < maxIterations; i++) {
        array = fillRandomNum(size);
        startTime = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        mergeSort(array);
        endTime = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        duration = (endTime - startTime);
        meanTime += duration;
    }
    meanTime /= maxIterations;
    std::cout << "Merge Sort: " << meanTime << "ns" << std::endl;

    // Quick Sort
    meanTime = 0;
    for (int i = 0; i < maxIterations; i++) {
        array = fillRandomNum(size);
        startTime = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        quickSort(array);
        endTime = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        duration = (endTime - startTime);
        meanTime += duration;
    }
    meanTime /= maxIterations;
    std::cout << "Quick Sort: " << meanTime << "ns" << std::endl;

    // Heap Sort
    meanTime = 0;
    for (int i = 0; i < maxIterations; i++) {
        array = fillRandomNum(size);
        startTime = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        heapSort(array);
        endTime = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        duration = (endTime - startTime);
        meanTime += duration;
    }
    meanTime /= maxIterations;
    std::cout << "Heap Sort: " << meanTime << "ns" << std::endl;

    // Counting Sort
    meanTime = 0;
    for (int i = 0; i < maxIterations; i++) {
        array = fillRandomNum(size);
        startTime = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        countingSort(array);
        endTime = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        duration = (endTime - startTime);
        meanTime += duration;
    }
    meanTime /= maxIterations;
    std::cout << "Counting Sort: " << meanTime << "ns" << std::endl;

    // Radix Sort
    meanTime = 0;
    for (int i = 0; i < maxIterations; i++) {
        array = fillRandomNum(size);
        startTime = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        radixSort(array);
        endTime = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        duration = (endTime - startTime);
        meanTime += duration;
    }
    meanTime /= maxIterations;
    std::cout << "Radix Sort: " << meanTime << "ns" << std::endl;

    // Bucket Sort
    meanTime = 0;
    for (int i = 0; i < maxIterations; i++) {
        array = fillRandomNum(size);
        startTime = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        bucketSort(array);
        endTime = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        duration = (endTime - startTime);
        meanTime += duration;
    }
    meanTime /= maxIterations;
    std::cout << "Bucket Sort: " << meanTime << "ns" << std::endl;

    return 0;
}
