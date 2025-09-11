class Item:
    def __init__(self, id: int, weight: int, value: int):
        self.id = id
        self.weight = weight
        self.value = value


items = [
    Item(1, 10, 15),
    Item(2, 40, 90),
    Item(3, 26, 50),
    Item(4, 32, 60),
    Item(5, 8, 12),
]

capacity = 80


def glutton(itemsList: list[Item], capacity: int):
    sortedList = sorted(itemsList, key=lambda item: item.value, reverse=True)
    backpack = []
    weight = 0

    for item in sortedList:
        if weight + item.weight <= capacity:
            backpack.append(item)
            weight += item.weight

    return backpack


backpack = glutton(items, capacity)

print("__GLUTTON_BACKPACK__")
print(
    f"items: {[b.id for b in backpack]}",
)
print(f"weight: {sum([b.weight for b in backpack])}")
print(f"value: {sum([b.value for b in backpack])}")
