import random


# -----------------------------
# Definição do problema
# -----------------------------
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

CAPACITY = 80
MAX_ITERATIONS = 100
TABU_LIST_SIZE = 5
MAX_NO_IMPROVE = 10


def fitness(solution):
    total_value = sum(items[i].value for i in range(len(items)) if solution[i] == 1)
    total_weight = sum(items[i].weight for i in range(len(items)) if solution[i] == 1)

    if total_weight > CAPACITY:
        return 0
    return total_value


def get_neighbors(solution):
    neighbors = []
    for idx, _ in enumerate(solution):
        neighbor = solution.copy()
        neighbor[idx] = 1 - neighbor[idx]
        neighbors.append((neighbor, idx))
    return neighbors


# -----------------------------
# Busca Tabu
# -----------------------------
def tabu_search(items):
    initial_solution = [random.randint(0, 1) for _ in range(len(items))]

    local_solution = initial_solution.copy()
    global_solution = local_solution.copy()
    global_value = fitness(global_solution)

    tabu_list = []

    iteration_counter = 0
    no_improve_counter = 0

    while iteration_counter < MAX_ITERATIONS and no_improve_counter < MAX_NO_IMPROVE:
        neighbors = get_neighbors(local_solution)

        local_best_solution = None
        local_best_value = -1
        local_best_move_idx = -1

        for candidate_solution, candidate_move_idx in neighbors:
            candidate_value = fitness(candidate_solution)

            if candidate_move_idx in tabu_list:
                if candidate_value <= global_value:
                    continue

            if candidate_value > local_best_value:
                local_best_solution = candidate_solution
                local_best_value = candidate_value
                local_best_move_idx = candidate_move_idx

        if local_best_solution is None:
            print(
                f"Execução parada: não há vizinhos melhores na iteração {iteration_counter + 1}"
            )
            break

        local_solution = local_best_solution
        tabu_list.append(local_best_move_idx)

        if len(tabu_list) > TABU_LIST_SIZE:
            tabu_list.pop(0)

        if local_best_value > global_value:
            global_solution = local_best_solution
            global_value = local_best_value
            no_improve_counter = 0
        else:
            no_improve_counter += 1

        print(
            f"Iteração {iteration_counter + 1}: "
            f"valor_global = {global_value}, "
            f"solução_global = {global_solution}"
        )

        iteration_counter += 1

    # -----------------------------
    # Motivo da parada
    # -----------------------------
    if iteration_counter >= MAX_ITERATIONS:
        print(
            f"Execução parada: máximo de iterações {iteration_counter}/{MAX_ITERATIONS}"
        )
    if no_improve_counter == MAX_NO_IMPROVE:
        print(
            f"Execução parada: máximo de iterações sem melhora {no_improve_counter}/{MAX_NO_IMPROVE}"
        )

    return global_solution, global_value


# -----------------------------
# Executando
# -----------------------------
best_solution, best_value = tabu_search(items)
print("\nMelhor solução encontrada:", best_solution)
print("Valor total:", best_value)
