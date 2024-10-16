import random
import time

def main():
    size = 99
    max_iterations = 9999

    # Bubble Sort
    mean_time = 0
    for _ in range(max_iterations):
        array = fill_random_num(size)
        start_time = time.time_ns()
        bubble_sort(array)
        end_time = time.time_ns()
        duration = end_time - start_time
        mean_time += duration
    mean_time //= max_iterations
    print(f"Bubble Sort: {mean_time}ns")

    # Insertion Sort
    mean_time = 0
    for _ in range(max_iterations):
        array = fill_random_num(size)
        start_time = time.time_ns()
        insertion_sort(array)
        end_time = time.time_ns()
        duration = end_time - start_time
        mean_time += duration
    mean_time //= max_iterations
    print(f"Insertion Sort: {mean_time}ns")

    # Selection Sort
    mean_time = 0
    for _ in range(max_iterations):
        array = fill_random_num(size)
        start_time = time.time_ns()
        selection_sort(array)
        end_time = time.time_ns()
        duration = end_time - start_time
        mean_time += duration
    mean_time //= max_iterations
    print(f"Selection Sort: {mean_time}ns")

    # Merge Sort
    mean_time = 0
    for _ in range(max_iterations):
        array = fill_random_num(size)
        start_time = time.time_ns()
        merge_sort(array)
        end_time = time.time_ns()
        duration = end_time - start_time
        mean_time += duration
    mean_time //= max_iterations
    print(f"Merge Sort: {mean_time}ns")

    # Quick Sort
    mean_time = 0
    for _ in range(max_iterations):
        array = fill_random_num(size)
        start_time = time.time_ns()
        quick_sort(array)
        end_time = time.time_ns()
        duration = end_time - start_time
        mean_time += duration
    mean_time //= max_iterations
    print(f"Quick Sort: {mean_time}ns")

    # Heap Sort
    mean_time = 0
    for _ in range(max_iterations):
        array = fill_random_num(size)
        start_time = time.time_ns()
        heap_sort(array)
        end_time = time.time_ns()
        duration = end_time - start_time
        mean_time += duration
    mean_time //= max_iterations
    print(f"Heap Sort: {mean_time}ns")

    # Radix Sort
    mean_time = 0
    for _ in range(max_iterations):
        array = fill_random_num(size)
        start_time = time.time_ns()
        radix_sort(array)
        end_time = time.time_ns()
        duration = end_time - start_time
        mean_time += duration
    mean_time //= max_iterations
    print(f"Radix Sort: {mean_time}ns")

    # Counting Sort
    mean_time = 0
    for _ in range(max_iterations):
        array = fill_random_num(size)
        start_time = time.time_ns()
        counting_sort(array)
        end_time = time.time_ns()
        duration = end_time - start_time
        mean_time += duration
    mean_time //= max_iterations
    print(f"Counting Sort: {mean_time}ns")

    # Bucket Sort
    mean_time = 0
    for _ in range(max_iterations):
        array = fill_random_num(size)
        start_time = time.time_ns()
        bucket_sort(array)
        end_time = time.time_ns()
        duration = end_time - start_time
        mean_time += duration
    mean_time //= max_iterations
    print(f"Bucket Sort: {mean_time}ns")

def fill_random_num(size):
    array = []
    for _ in range(size):
        array.append(random.randint(0, 99))
    return array


def bubble_sort(array):
    for i in range(len(array)):
        for j in range(1, len(array) - i):
            if array[j - 1] > array[j]:
                # swap elements
                array[j - 1], array[j] = array[j], array[j - 1]


def insertion_sort(array):
    for i in range(1, len(array)):
        j = i
        while j > 0 and array[j] < array[j - 1]:
            # swap elements
            array[j], array[j - 1] = array[j - 1], array[j]
            j -= 1


def selection_sort(array):
    for i in range(len(array) - 1):
        index = i
        for j in range(i + 1, len(array)):
            if array[j] < array[index]:
                index = j
        # swap elements
        array[i], array[index] = array[index], array[i]


def merge_sort(array):
    merge_sort_recursive(array, 0, len(array) - 1)


def merge_sort_recursive(array, left, right):
    if left < right:
        middle = (left + right) // 2
        merge_sort_recursive(array, left, middle)
        merge_sort_recursive(array, middle + 1, right)
        merge(array, left, middle, right)


def merge(array, left, middle, right):
    temp = array[left:right + 1]
    i = 0
    j = middle - left + 1
    k = left
    while i <= middle - left and j <= right - left:
        if temp[i] <= temp[j]:
            array[k] = temp[i]
            i += 1
        else:
            array[k] = temp[j]
            j += 1
        k += 1
    while i <= middle - left:
        array[k] = temp[i]
        k += 1
        i += 1


def quick_sort(array):
    quick_sort_recursive(array, 0, len(array) - 1)


def quick_sort_recursive(array, left, right):
    if left < right:
        pivot = partition(array, left, right)
        quick_sort_recursive(array, left, pivot - 1)
        quick_sort_recursive(array, pivot + 1, right)


def partition(array, left, right):
    pivot = array[right]
    i = left - 1
    for j in range(left, right):
        if array[j] <= pivot:
            i += 1
            # swap elements
            array[i], array[j] = array[j], array[i]
    # swap elements
    array[i + 1], array[right] = array[right], array[i + 1]
    return i + 1


def heap_sort(array):
    n = len(array)
    for i in range(n // 2 - 1, -1, -1):
        heapify(array, n, i)
    for i in range(n - 1, 0, -1):
        # swap elements
        array[0], array[i] = array[i], array[0]
        heapify(array, i, 0)


def heapify(array, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2
    if left < n and array[left] > array[largest]:
        largest = left
    if right < n and array[right] > array[largest]:
        largest = right
    if largest != i:
        # swap elements
        array[i], array[largest] = array[largest], array[i]
        heapify(array, n, largest)


def counting_sort(array):
    max_value = max(array)
    count = [0] * (max_value + 1)
    for num in array:
        count[num] += 1
    index = 0
    for i in range(len(count)):
        while count[i] > 0:
            array[index] = i
            index += 1
            count[i] -= 1


def radix_sort(array):
    max_value = max(array)
    place = 1
    while max_value // place > 0:
        counting_sort_by_place(array, place)
        place *= 10


def counting_sort_by_place(array, place):
    count = [0] * 10
    temp = [0] * len(array)
    for num in array:
        digit = (num // place) % 10
        count[digit] += 1
    for i in range(1, len(count)):
        count[i] += count[i - 1]
    for i in range(len(array) - 1, -1, -1):
        digit = (array[i] // place) % 10
        temp[count[digit] - 1] = array[i]
        count[digit] -= 1
    for i in range(len(array)):
        array[i] = temp[i]


def bucket_sort(array):
    max_value = max(array)
    bucket = [0] * (max_value + 1)
    for num in array:
        bucket[num] += 1
    index = 0
    for i in range(len(bucket)):
        while bucket[i] > 0:
            array[index] = i
            index += 1
            bucket[i] -= 1