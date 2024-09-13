from dataclasses import dataclass
import matplotlib.pyplot as plt
import random
import timeit


@dataclass
class OrderingMethod:
    name: str
    function_name: str
    import_name: str
    plot_color: str
    timestamps: list


# Colors wiki: https://matplotlib.org/stable/gallery/color/named_colors.html
bubbleSort = OrderingMethod(
    "Bubble Sort", "bubble_sort", "bubble_sort", "royalblue", []
)
insertionSort = OrderingMethod(
    "Insertion Sort", "insertion_sort", "insertion_sort", "red", []
)
selectionSort = OrderingMethod(
    "Selection Sort", "selection_sort", "selection_sort", "green", []
)
mergeSort = OrderingMethod("Merge Sort", "merge_sort", "merge_sort", "slategray", [])
quickSort = OrderingMethod("Quick Sort", "quick_sort", "quick_sort", "deeppink", [])
countingSort = OrderingMethod(
    "Counting Sort", "counting_sort", "counting_sort", "darkorange", []
)
radixSort = OrderingMethod("Radix Sort", "radix_sort", "radix_sort", "gold", [])
bucketSort = OrderingMethod(
    "Bucket Sort", "bucket_sort", "bucket_sort", "darkturquoise", []
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
    # 9000,
    # 12000,
    # 15000,
    # 18000,
    # 21000,
    # 24000,
]


def getRandomList(listSize: int) -> list:
    return random.sample(range(0, listSize * 2), listSize)


def testMethod(sortFunctionName: str, listToSort: list) -> float:
    test_list = listToSort

    return timeit.timeit(
        stmt=f"{sortFunctionName}({test_list})",
        setup=f"from {sortFunctionName} import {sortFunctionName}",
        number=1,
    )


def evaluateMethods() -> None:
    for i in range(len(testSizes)):
        originalList = getRandomList(testSizes[i])

        print(f"List of size {testSizes[i]} ordered in:")
        for method in orderingMethods:
            method.timestamps.append(testMethod(method.function_name, originalList))
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
