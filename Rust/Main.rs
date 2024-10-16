use std::time::{SystemTime, Duration};
use rand::{Rng, thread_rng};

fn fill_random_num(size: usize) -> Vec<u32> {
    let mut rng = thread_rng();
    (0..size).map(|_| rng.gen_range(0..=100)).collect()
}

fn bubble_sort(array: &mut [u32]) {
    let n = array.len();
    for i in 0..n {
        for j in 0..n - i - 1 {
            if array[j] > array[j + 1] {
                array.swap(j, j + 1);
            }
        }
    }
}

fn insertion_sort(array: &mut [u32]) {
    let n = array.len();
    for i in 1..n {
        let key = array[i];
        let mut j = i;
        while j > 0 && array[j - 1] > key {
            array[j] = array[j - 1];
            j -= 1;
        }
        array[j] = key;
    }
}

fn selection_sort(array: &mut [u32]) {
    let n = array.len();
    for i in 0..n - 1 {
        let mut min_index = i;
        for j in i + 1..n {
            if array[j] < array[min_index] {
                min_index = j;
            }
        }
        array.swap(i, min_index);
    }
}

fn merge_sort(array: &mut [u32]) {
    if array.len() <= 1 {
        return;
    }
    let mid = array.len() / 2;
    merge_sort(&mut array[..mid]);
    merge_sort(&mut array[mid..]);
    let mut temp = Vec::with_capacity(array.len());
    let (mut i, mut j) = (0, mid);
    while i < mid && j < array.len() {
        if array[i] <= array[j] {
            temp.push(array[i]);
            i += 1;
        } else {
            temp.push(array[j]);
            j += 1;
        }
    }
    temp.extend_from_slice(&array[i..mid]);
    temp.extend_from_slice(&array[j..]);
    array.copy_from_slice(&temp);
}

fn quick_sort(array: &mut [u32]) {
    if array.len() <= 1 {
        return;
    }
    let pivot = array[array.len() - 1];
    let mut i = 0;
    for j in 0..array.len() - 1 {
        if array[j] <= pivot {
            array.swap(i, j);
            i += 1;
        }
    }
    array.swap(i, array.len() - 1);
    quick_sort(&mut array[..i]);
    quick_sort(&mut array[i + 1..]);
}

fn heapify(array: &mut [u32], n: usize, i: usize) {
    let mut largest = i;
    let left = 2 * i + 1;
    let right = 2 * i + 2;
    if left < n && array[left] > array[largest] {
        largest = left;
    }
    if right < n && array[right] > array[largest] {
        largest = right;
    }
    if largest != i {
        array.swap(i, largest);
        heapify(array, n, largest);
    }
}

fn heap_sort(array: &mut [u32]) {
    let n = array.len();
    for i in (0..n / 2).rev() {
        heapify(array, n, i);
    }
    for i in (1..n).rev() {
        array.swap(0, i);
        heapify(array, i, 0);
    }
}

fn counting_sort(array: &mut [u32]) {
    let max = *array.iter().max().unwrap_or(&0);
    let mut count = vec![0; (max + 1) as usize];
    for &num in array.iter() {
        count[num as usize] += 1;
    }
    let mut i = 0;
    for (num, &freq) in count.iter().enumerate() {
        for _ in 0..freq {
            array[i] = num as u32;
            i += 1;
        }
    }
}

fn radix_sort(array: &mut [u32]) {
    let mut max = *array.iter().max().unwrap_or(&0);
    let mut exp = 1;
    let n = array.len();
    let mut temp = vec![0; n];
    while max / exp > 0 {
        let mut count = vec![0; 10];
        for &num in array.iter() {
            count[(num / exp % 10) as usize] += 1;
        }
        for i in 1..10 {
            count[i] += count[i - 1];
        }
        for i in (0..n).rev() {
            let num = array[i];
            let index = (num / exp % 10) as usize;
            temp[count[index] as usize - 1] = num;
            count[index] -= 1;
        }
        array.copy_from_slice(&temp);
        exp *= 10;
    }
}

fn bucket_sort(array: &mut [u32]) {
    let max = *array.iter().max().unwrap_or(&0);
    let n = array.len();
    let mut buckets: Vec<Vec<u32>> = vec![vec![]; n];
    for &num in array.iter() {
        let index = (num * n as u32 / (max + 1)) as usize;
        buckets[index].push(num);
    }
    for bucket in buckets.iter_mut() {
        insertion_sort(bucket);
    }
    let mut i = 0;
    for bucket in buckets.iter() {
        for &num in bucket.iter() {
            array[i] = num;
            i += 1;
        }
    }
}

fn main() {
    const SIZE: usize = 1000;
    const MAX_ITERATIONS: usize = 100;

    let mut array: Vec<u32>;
    let mut start_time;
    let mut end_time;
    let mut duration;
    let mut mean_time;

    // Bubble Sort
    mean_time = Duration::new(0, 0);
    for _ in 0..MAX_ITERATIONS {
        array = fill_random_num(SIZE);
        start_time = SystemTime::now();
        bubble_sort(&mut array);
        end_time = SystemTime::now();
        duration = end_time.duration_since(start_time).unwrap();
        mean_time += duration;
    }
    mean_time /= MAX_ITERATIONS as u32;
    println!("Bubble Sort: {:?}ns", mean_time.as_nanos());

    // Insertion Sort
    mean_time = Duration::new(0, 0);
    for _ in 0..MAX_ITERATIONS {
        array = fill_random_num(SIZE);
        start_time = SystemTime::now();
        insertion_sort(&mut array);
        end_time = SystemTime::now();
        duration = end_time.duration_since(start_time).unwrap();
        mean_time += duration;
    }
    mean_time /= MAX_ITERATIONS as u32;
    println!("Insertion Sort: {:?}ns", mean_time.as_nanos());

    // Selection Sort
    mean_time = Duration::new(0, 0);
    for _ in 0..MAX_ITERATIONS {
        array = fill_random_num(SIZE);
        start_time = SystemTime::now();
        selection_sort(&mut array);
        end_time = SystemTime::now();
        duration = end_time.duration_since(start_time).unwrap();
        mean_time += duration;
    }
    mean_time /= MAX_ITERATIONS as u32;
    println!("Selection Sort: {:?}ns", mean_time.as_nanos());

    // Merge Sort
    mean_time = Duration::new(0, 0);
    for _ in 0..MAX_ITERATIONS {
        array = fill_random_num(SIZE);
        start_time = SystemTime::now();
        merge_sort(&mut array);
        end_time = SystemTime::now();
        duration = end_time.duration_since(start_time).unwrap();
        mean_time += duration;
    }
    mean_time /= MAX_ITERATIONS as u32;
    println!("Merge Sort: {:?}ns", mean_time.as_nanos());

    // Quick Sort
    mean_time = Duration::new(0, 0);
    for _ in 0..MAX_ITERATIONS {
        array = fill_random_num(SIZE);
        start_time = SystemTime::now();
        quick_sort(&mut array);
        end_time = SystemTime::now();
        duration = end_time.duration_since(start_time).unwrap();
        mean_time += duration;
    }
    mean_time /= MAX_ITERATIONS as u32;
    println!("Quick Sort: {:?}ns", mean_time.as_nanos());

    // Heap Sort
    mean_time = Duration::new(0, 0);
    for _ in 0..MAX_ITERATIONS {
        array = fill_random_num(SIZE);
        start_time = SystemTime::now();
        heap_sort(&mut array);
        end_time = SystemTime::now();
        duration = end_time.duration_since(start_time).unwrap();
        mean_time += duration;
    }
    mean_time /= MAX_ITERATIONS as u32;
    println!("Heap Sort: {:?}ns", mean_time.as_nanos());

    // Counting Sort
    mean_time = Duration::new(0, 0);
    for _ in 0..MAX_ITERATIONS {
        array = fill_random_num(SIZE);
        start_time = SystemTime::now();
        counting_sort(&mut array);
        end_time = SystemTime::now();
        duration = end_time.duration_since(start_time).unwrap();
        mean_time += duration;
    }
    mean_time /= MAX_ITERATIONS as u32;
    println!("Counting Sort: {:?}ns", mean_time.as_nanos());

    // Radix Sort
    mean_time = Duration::new(0, 0);
    for _ in 0..MAX_ITERATIONS {
        array = fill_random_num(SIZE);
        start_time = SystemTime::now();
        radix_sort(&mut array);
        end_time = SystemTime::now();
        duration = end_time.duration_since(start_time).unwrap();
        mean_time += duration;
    }
    mean_time /= MAX_ITERATIONS as u32;
    println!("Radix Sort: {:?}ns", mean_time.as_nanos());

    // Bucket Sort
    mean_time = Duration::new(0, 0);
    for _ in 0..MAX_ITERATIONS {
        array = fill_random_num(SIZE);
        start_time = SystemTime::now();
        bucket_sort(&mut array);
        end_time = SystemTime::now();
        duration = end_time.duration_since(start_time).unwrap();
        mean_time += duration;
    }
    mean_time /= MAX_ITERATIONS as u32;
    println!("Bucket Sort: {:?}ns", mean_time.as_nanos());
}
