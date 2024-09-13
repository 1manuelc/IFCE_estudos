def partition(lst: list, left, right) -> int:
    partition_index = left

    for j in range(left + 1, right):
        if lst[j] < lst[left]:
            partition_index += 1
            lst[partition_index], lst[j] = lst[j], lst[partition_index]

    lst[left], lst[partition_index] = lst[partition_index], lst[left]
    return partition_index


def quick_sort(lst: list, left: int = 0, right: int = None) -> list:
    if right is None:
        right = len(lst)

    if right > left:
        partition_index = partition(lst, left, right)
        quick_sort(lst, left, partition_index - 1)
        quick_sort(lst, partition_index + 1, right)
        
    return lst
