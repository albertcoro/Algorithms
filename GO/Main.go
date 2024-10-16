package main

import (
	"fmt"
	"math/rand"
	"time"
)

const (
	Size          = 10000
	MaxIterations = 10
)

func main() {
	// Seed the random number generator
	rand.Seed(time.Now().UnixNano())

	// Initialize the array
	array := make([]int, Size)

	// Bubble Sort
	fmt.Println("Bubble Sort:")
	meanTime := time.Duration(0)
	for i := 0; i < MaxIterations; i++ {
		fillRandomNum(array)
		startTime := time.Now()
		bubbleSort(array)
		endTime := time.Now()
		duration := endTime.Sub(startTime)
		meanTime += duration
	}
	meanTime /= time.Duration(MaxIterations)
	fmt.Printf("Mean Time: %dns\n", meanTime.Nanoseconds())

	// Insertion Sort
	fmt.Println("Insertion Sort:")
	meanTime = time.Duration(0)
	for i := 0; i < MaxIterations; i++ {
		fillRandomNum(array)
		startTime := time.Now()
		insertionSort(array)
		endTime := time.Now()
		duration := endTime.Sub(startTime)
		meanTime += duration
	}
	meanTime /= time.Duration(MaxIterations)
	fmt.Printf("Mean Time: %dns\n", meanTime.Nanoseconds())

	// Selection Sort
	fmt.Println("Selection Sort:")
	meanTime = time.Duration(0)
	for i := 0; i < MaxIterations; i++ {
		fillRandomNum(array)
		startTime := time.Now()
		selectionSort(array)
		endTime := time.Now()
		duration := endTime.Sub(startTime)
		meanTime += duration
	}
	meanTime /= time.Duration(MaxIterations)
	fmt.Printf("Mean Time: %dns\n", meanTime.Nanoseconds())

	// Merge Sort
	fmt.Println("Merge Sort:")
	meanTime = time.Duration(0)
	for i := 0; i < MaxIterations; i++ {
		fillRandomNum(array)
		startTime := time.Now()
		mergeSort(array)
		endTime := time.Now()
		duration := endTime.Sub(startTime)
		meanTime += duration
	}
	meanTime /= time.Duration(MaxIterations)
	fmt.Printf("Mean Time: %dns\n", meanTime.Nanoseconds())

	// Quick Sort
	fmt.Println("Quick Sort:")
	meanTime = time.Duration(0)
	for i := 0; i < MaxIterations; i++ {
		fillRandomNum(array)
		startTime := time.Now()
		quickSort(array)
		endTime := time.Now()
		duration := endTime.Sub(startTime)
		meanTime += duration
	}
	meanTime /= time.Duration(MaxIterations)
	fmt.Printf("Mean Time: %dns\n", meanTime.Nanoseconds())

	// Heap Sort
	fmt.Println("Heap Sort:")
	meanTime = time.Duration(0)
	for i := 0; i < MaxIterations; i++ {
		fillRandomNum(array)
		startTime := time.Now()
		heapSort(array)
		endTime := time.Now()
		duration := endTime.Sub(startTime)
		meanTime += duration
	}
	meanTime /= time.Duration(MaxIterations)
	fmt.Printf("Mean Time: %dns\n", meanTime.Nanoseconds())

	// Counting Sort
	fmt.Println("Counting Sort:")
	meanTime = time.Duration(0)
	for i := 0; i < MaxIterations; i++ {
		fillRandomNum(array)
		startTime := time.Now()
		countingSort(array)
		endTime := time.Now()
		duration := endTime.Sub(startTime)
		meanTime += duration
	}
	meanTime /= time.Duration(MaxIterations)
	fmt.Printf("Mean Time: %dns\n", meanTime.Nanoseconds())

	// Bucket Sort
	fmt.Println("Bucket Sort:")
	meanTime = time.Duration(0)
	for i := 0; i < MaxIterations; i++ {
		fillRandomNum(array)
		startTime := time.Now()
		bucketSort(array)
		endTime := time.Now()
		duration := endTime.Sub(startTime)
		meanTime += duration
	}
	meanTime /= time.Duration(MaxIterations)
	fmt.Printf("Mean Time: %dns\n", meanTime.Nanoseconds())
}

func fillRandomNum(array []int) {
	for i := range array {
		array[i] = rand.Intn(Size)
	}
}

func bubbleSort(array []int) {
	size := len(array)
	for i := 0; i < size-1; i++ {
		for j := 0; j < size-i-1; j++ {
			if array[j] > array[j+1] {
				array[j], array[j+1] = array[j+1], array[j]
			}
		}
	}
}

func insertionSort(array []int) {
	size := len(array)
	for i := 1; i < size; i++ {
		key := array[i]
		j := i - 1
		for j >= 0 && array[j] > key {
			array[j+1] = array[j]
			j--
		}
		array[j+1] = key
	}
}

func selectionSort(array []int) {
	size := len(array)
	for i := 0; i < size-1; i++ {
		minIndex := i
		for j := i + 1; j < size; j++ {
			if array[j] < array[minIndex] {
				minIndex = j
			}
		}
		array[i], array[minIndex] = array[minIndex], array[i]
	}
}

func mergeSort(array []int) {
	if len(array) > 1 {
		mid := len(array) / 2
		left := array[:mid]
		right := array[mid:]

		mergeSort(left)
		mergeSort(right)

		merge(array, left, right)
	}
}

func merge(array []int, left []int, right []int) {
	i, j, k := 0, 0, 0
	sizeL, sizeR := len(left), len(right)

	for i < sizeL && j < sizeR {
		if left[i] <= right[j] {
			array[k] = left[i]
			i++
		} else {
			array[k] = right[j]
			j++
		}
		k++
	}

	for i < sizeL {
		array[k] = left[i]
		i++
		k++
	}

	for j < sizeR {
		array[k] = right[j]
		j++
		k++
	}
}

func quickSort(array []int) {
	quickSortHelper(array, 0, len(array)-1)
}

func quickSortHelper(array []int, low int, high int) {
	if low < high {
		pivot := partition(array, low, high)
		quickSortHelper(array, low, pivot-1)
		quickSortHelper(array, pivot+1, high)
	}
}

func partition(array []int, low int, high int) int {
	pivot := array[high]
	i := low - 1

	for j := low; j < high; j++ {
		if array[j] < pivot {
			i++
			array[i], array[j] = array[j], array[i]
		}
	}

	array[i+1], array[high] = array[high], array[i+1]
	return i + 1
}

func heapSort(array []int) {
	size := len(array)

	for i := size/2 - 1; i >= 0; i-- {
		heapify(array, size, i)
	}

	for i := size - 1; i >= 0; i-- {
		array[0], array[i] = array[i], array[0]
		heapify(array, i, 0)
	}
}

func heapify(array []int, size int, root int) {
	largest := root
	left := 2*root + 1
	right := 2*root + 2

	if left < size && array[left] > array[largest] {
		largest = left
	}

	if right < size && array[right] > array[largest] {
		largest = right
	}

	if largest != root {
		array[root], array[largest] = array[largest], array[root]
		heapify(array, size, largest)
	}
}

func countingSort(array []int) {
	size := len(array)

	if size == 0 {
		return
	}

	maxValue := array[0]
	for i := 1; i < size; i++ {
		if array[i] > maxValue {
			maxValue = array[i]
		}
	}

	counts := make([]int, maxValue+1)

	for i := 0; i < size; i++ {
		counts[array[i]]++
	}

	index := 0
	for i := 0; i <= maxValue; i++ {
		for counts[i] > 0 {
			array[index] = i
			index++
			counts[i]--
		}
	}
}

func bucketSort(array []int) {
	size := len(array)

	if size == 0 {
		return
	}

	minValue, maxValue := array[0], array[0]
	for i := 1; i < size; i++ {
		if array[i] < minValue {
			minValue = array[i]
		} else if array[i] > maxValue {
			maxValue = array[i]
		}
	}

	bucketCount := (maxValue-minValue)/size + 1
	buckets := make([][]int, bucketCount)
	for i := 0; i < bucketCount; i++ {
		buckets[i] = make([]int, 0)
	}

	for i := 0; i < size; i++ {
		bucketIndex := (array[i] - minValue) / size
		buckets[bucketIndex] = append(buckets[bucketIndex], array[i])
	}

	index := 0
	for i := 0; i < bucketCount; i++ {
		bucketSize := len(buckets[i])
		if bucketSize > 0 {
			insertionSort(buckets[i])
			copy(array[index:], buckets[i])
			index += bucketSize
		}
	}
}
