package Java;

public class Main {
    public static void main(String[] args) {
        int size = 99;
        int[] array;
        long startTime, endTime, duration;

        int maxIterations = 9999;

        //Bubble Sort
        long meanTime = 0;
        for(int i = 0; i < maxIterations; i++){
            array = fillRandomNum(size);
            startTime = System.nanoTime();
            bubbleSort(array);
            endTime = System.nanoTime();
            duration = (endTime - startTime);
            meanTime += duration;
        }
        meanTime /= maxIterations;
        System.out.println("Bubble Sort: " + meanTime + "ns");

        //Insertion Sort
        meanTime = 0;
        for(int i = 0; i < maxIterations; i++){
            array = fillRandomNum(size);
            startTime = System.nanoTime();
            insertionSort(array);
            endTime = System.nanoTime();
            duration = (endTime - startTime);
            meanTime += duration;
        }
        meanTime /= maxIterations;
        System.out.println("Insertion Sort: " + meanTime + "ns");

        //Selection Sort
        meanTime = 0;
        for(int i = 0; i < maxIterations; i++){
            array = fillRandomNum(size);
            startTime = System.nanoTime();
            selectionSort(array);
            endTime = System.nanoTime();
            duration = (endTime - startTime);
            meanTime += duration;
        }
        meanTime /= maxIterations;
        System.out.println("Selection Sort: " + meanTime + "ns");

        //Merge Sort
        meanTime = 0;
        for(int i = 0; i < maxIterations; i++){
            array = fillRandomNum(size);
            startTime = System.nanoTime();
            mergeSort(array);
            endTime = System.nanoTime();
            duration = (endTime - startTime);
            meanTime += duration;
        }
        meanTime /= maxIterations;
        System.out.println("Merge Sort: " + meanTime + "ns");

        //Quick Sort
        meanTime = 0;
        for(int i = 0; i < maxIterations; i++){
            array = fillRandomNum(size);
            startTime = System.nanoTime();
            quickSort(array);
            endTime = System.nanoTime();
            duration = (endTime - startTime);
            meanTime += duration;
        }
        meanTime /= maxIterations;
        System.out.println("Quick Sort: " + meanTime + "ns");

        //Heap Sort
        meanTime = 0;
        for(int i = 0; i < maxIterations; i++){
            array = fillRandomNum(size);
            startTime = System.nanoTime();
            heapSort(array);
            endTime = System.nanoTime();
            duration = (endTime - startTime);
            meanTime += duration;
        }
        meanTime /= maxIterations;
        System.out.println("Heap Sort: " + meanTime + "ns");

        //Radix Sort
        meanTime = 0;
        for(int i = 0; i < maxIterations; i++){
            array = fillRandomNum(size);
            startTime = System.nanoTime();
            radixSort(array);
            endTime = System.nanoTime();
            duration = (endTime - startTime);
            meanTime += duration;
        }
        meanTime /= maxIterations;
        System.out.println("Radix Sort: " + meanTime + "ns");

        //Counting Sort
        meanTime = 0;
        for(int i = 0; i < maxIterations; i++){
            array = fillRandomNum(size);
            startTime = System.nanoTime();
            countingSort(array);
            endTime = System.nanoTime();
            duration = (endTime - startTime);
            meanTime += duration;
        }
        meanTime /= maxIterations;
        System.out.println("Counting Sort: " + meanTime + "ns");

        //Bucket Sort
        meanTime = 0;
        for(int i = 0; i < maxIterations; i++){
            array = fillRandomNum(size);
            startTime = System.nanoTime();
            bucketSort(array);
            endTime = System.nanoTime();
            duration = (endTime - startTime);
            meanTime += duration;
        }
        meanTime /= maxIterations;
        System.out.println("Bucket Sort: " + meanTime + "ns");

    }

    public static int[] fillRandomNum(int size){
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = (int)(Math.random() * 100);
        }
        return array;
    }

    //Bubble Sort
    public static void bubbleSort(int[] array){
        int temp;
        for (int i = 0; i < array.length; i++) {
            for (int j = 1; j < (array.length - i); j++) {
                if(array[j-1] > array[j]){
                    //swap elements
                    temp = array[j-1];
                    array[j-1] = array[j];
                    array[j] = temp;
                }
            }
        }
    }

    //Insertion Sort
    public static void insertionSort(int[] array){
        int temp;
        for (int i = 1; i < array.length; i++) {
            for(int j = i ; j > 0 ; j--){
                if(array[j] < array[j-1]){
                    //swap elements
                    temp = array[j];
                    array[j] = array[j-1];
                    array[j-1] = temp;
                }
            }
        }
    }

    //Selection Sort
    public static void selectionSort(int[] array){
        int temp;
        for (int i = 0; i < array.length - 1; i++) {
            int index = i;
            for (int j = i + 1; j < array.length; j++){
                if (array[j] < array[index]){
                    index = j;
                }
            }
            //swap elements
            temp = array[index];
            array[index] = array[i];
            array[i] = temp;
        }
    }

    //Merge Sort
    public static void mergeSort(int[] array){
        mergeSort(array, 0, array.length - 1);
    }

    public static void mergeSort(int[] array, int left, int right){
        if(left < right){
            int middle = (left + right) / 2;
            mergeSort(array, left, middle);
            mergeSort(array, middle + 1, right);
            merge(array, left, middle, right);
        }
    }

    public static void merge(int[] array, int left, int middle, int right){
        int[] temp = new int[array.length];
        for (int i = left; i <= right; i++) {
            temp[i] = array[i];
        }
        int i = left;
        int j = middle + 1;
        int k = left;
        while(i <= middle && j <= right){
            if(temp[i] <= temp[j]){
                array[k] = temp[i];
                i++;
            }else{
                array[k] = temp[j];
                j++;
            }
            k++;
        }
        while(i <= middle){
            array[k] = temp[i];
            k++;
            i++;
        }
    }

    //Quick Sort
    public static void quickSort(int[] array){
        quickSort(array, 0, array.length - 1);
    }

    public static void quickSort(int[] array, int left, int right){
        if(left < right){
            int pivot = partition(array, left, right);
            quickSort(array, left, pivot - 1);
            quickSort(array, pivot + 1, right);
        }
    }

    public static int partition(int[] array, int left, int right){
        int pivot = array[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if(array[j] <= pivot){
                i++;
                //swap elements
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        //swap elements
        int temp = array[i + 1];
        array[i + 1] = array[right];
        array[right] = temp;
        return i + 1;
    }

    //Heap Sort
    public static void heapSort(int[] array){
        int n = array.length;
        for (int i = n / 2 - 1; i >= 0; i--){
            heapify(array, n, i);
        }
        for (int i = n - 1; i >= 0; i--){
            //swap elements
            int temp = array[0];
            array[0] = array[i];
            array[i] = temp;
            heapify(array, i, 0);
        }
    }

    public static void heapify(int[] array, int n, int i){
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if(left < n && array[left] > array[largest]){
            largest = left;
        }
        if(right < n && array[right] > array[largest]){
            largest = right;
        }
        if(largest != i){
            //swap elements
            int temp = array[i];
            array[i] = array[largest];
            array[largest] = temp;
            heapify(array, n, largest);
        }
    }

    //Counting Sort
    public static void countingSort(int[] array){
        int max = getMax(array);
        int[] count = new int[max + 1];
        for (int i = 0; i < array.length; i++) {
            count[array[i]]++;
        }
        int index = 0;
        for (int i = 0; i < count.length; i++) {
            while(count[i] > 0){
                array[index++] = i;
                count[i]--;
            }
        }
    }

    public static int getMax(int[] array){
        int max = array[0];
        for (int i = 1; i < array.length; i++) {
            if(array[i] > max){
                max = array[i];
            }
        }
        return max;
    }

    //Radix Sort
    public static void radixSort(int[] array){
        int max = getMax(array);
        for (int i = 1; max / i > 0; i *= 10) {
            countingSort(array, i);
        }
    }

    public static void countingSort(int[] array, int place){
        int[] count = new int[10];
        int[] temp = new int[array.length];
        for (int i = 0; i < array.length; i++) {
            count[(array[i] / place) % 10]++;
        }
        for (int i = 1; i < count.length; i++) {
            count[i] += count[i - 1];
        }
        for (int i = array.length - 1; i >= 0; i--) {
            temp[--count[(array[i] / place) % 10]] = array[i];
        }
        for (int i = 0; i < array.length; i++) {
            array[i] = temp[i];
        }
    }

    //Bucket Sort
    public static void bucketSort(int[] array){
        int max = getMax(array);
        int[] bucket = new int[max + 1];
        for (int i = 0; i < array.length; i++) {
            bucket[array[i]]++;
        }
        int index = 0;
        for (int i = 0; i < bucket.length; i++) {
            while(bucket[i] > 0){
                array[index++] = i;
                bucket[i]--;
            }
        }
    }

}