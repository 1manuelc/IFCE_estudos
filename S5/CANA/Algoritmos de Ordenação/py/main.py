from dataclasses import dataclass
import matplotlib.pyplot as plt
import random
import timeit


# define um objeto-base para metodos de ordenacao
@dataclass
class OrderingMethod:
    name: str
    import_name: str
    function_name: str
    plot_color: str
    timestamps: list


# define os metodos com base na dataclass
bubbleSort = OrderingMethod(
    "Bubble Sort", "bruteforce_methods", "bubble_sort", "royalblue", []
)
insertionSort = OrderingMethod(
    "Insertion Sort", "bruteforce_methods", "insertion_sort", "red", []
)
selectionSort = OrderingMethod(
    "Selection Sort", "bruteforce_methods", "selection_sort", "green", []
)

mergeSort = OrderingMethod(
    "Merge Sort", "divide_and_conquer_methods", "merge_sort", "slategray", []
)
quickSort = OrderingMethod(
    "Quick Sort", "divide_and_conquer_methods", "quick_sort", "deeppink", []
)

countingSort = OrderingMethod(
    "Counting Sort", "linear_time_methods", "counting_sort", "darkorange", []
)
radixSort = OrderingMethod(
    "Radix Sort", "linear_time_methods", "radix_sort", "gold", []
)
bucketSort = OrderingMethod(
    "Bucket Sort", "linear_time_methods", "bucket_sort", "darkturquoise", []
)

shellSort = OrderingMethod("Shell Sort", "shell_sort", "shell_sort", "navy", [])
heapSort = OrderingMethod("Heap Sort", "heap_sort", "heap_sort", "lime", [])

orderingMethods = [
    bubbleSort,
    insertionSort,
    selectionSort,
    mergeSort,
    quickSort,
    countingSort,
    radixSort,
    bucketSort,
    shellSort,
    heapSort,
]

testSizes = [
    1000,
    3000,
    6000,
    9000,
    12000,
    15000,
    18000,
    21000,
    24000,
]


def getRandomList(listSize: int) -> list:
    return random.sample(range(0, listSize), listSize)


# testa um metodo e retorna seu tempo cronometrado de execucao
def testMethod(method: OrderingMethod, listToSort: list) -> float:
    test_list = listToSort

    return timeit.timeit(
        stmt=f"{method.function_name}({test_list})",
        setup=f"from {method.import_name} import {method.function_name}",
        number=1,
    )


# coordena a cronometragem dos metodos e exibe seus tempos
def evaluateMethods() -> None:
    for i in range(len(testSizes)):
        originalList = getRandomList(testSizes[i])

        print(f"List of size {testSizes[i]} ordered in:")
        for method in orderingMethods:
            method.timestamps.append(testMethod(method, originalList))
            print(f"\t{method.name}:\t{method.timestamps[i]:.4f} seconds")
        print()


def plotAnalysis() -> None:
    fig, ax = plt.subplots()

    for method in orderingMethods:
        ax.plot(
            testSizes,
            method.timestamps,
            marker="o",
            linestyle="-",
            color=method.plot_color,
            label=method.name,
        )

    ax.set_xlabel("List size (elements)")
    ax.set_ylabel("Time (seconds)")
    ax.set_title("Ordering Algorythims Timing Analysis")
    ax.legend()
    plt.grid(True)
    plt.show()


# faz a media temporal dos metodos, para calcular o metodo mais rapido e mais devagar
def summarizeResults() -> None:
    timeAveragePerMethod = []

    for i in range(0, len(orderingMethods)):
        timeAveragePerMethod.append(
            [
                orderingMethods[i].name,
                sum(orderingMethods[i].timestamps) / len(testSizes),
            ]
        )

    fastestMethod = timeAveragePerMethod[0]
    for i in range(0, len(timeAveragePerMethod)):
        if timeAveragePerMethod[i][1] < fastestMethod[1]:
            fastestMethod = timeAveragePerMethod[i]

    slowestMethod = timeAveragePerMethod[0]
    for i in range(0, len(timeAveragePerMethod)):
        if timeAveragePerMethod[i][1] > slowestMethod[1]:
            slowestMethod = timeAveragePerMethod[i]

    print(
        f"fastest ordering method\t(average): {fastestMethod[0]}:\t{fastestMethod[1]:.4f} seconds"
    )
    print(
        f"slowest ordering method\t(average): {slowestMethod[0]}:\t{slowestMethod[1]:.4f} seconds"
    )


def main() -> None:
    evaluateMethods()
    plotAnalysis()
    summarizeResults()


if __name__ == "__main__":
    main()
