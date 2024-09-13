def counting_sort(originalList: list) -> list:
    listLength = len(originalList)
    greater: int = max(originalList)
    sortedList: list = [0 for _ in range(listLength)]
    countingList: list = [0 for _ in range(greater + 1)]

    for i in range(0, listLength):
        countingList[originalList[i]] += 1

    for j in range(1, greater + 1):
        countingList[j] += countingList[j - 1]

    for k in range(listLength - 1, 0, -1):
        sortedList[countingList[originalList[k]] - 1] = originalList[k]
        countingList[originalList[k]] -= 1

    return sortedList
