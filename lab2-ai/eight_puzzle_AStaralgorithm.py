
'''
Lab Sheet 2

Name: Suraj Karki
CRN: 018-339

Question 4: Solve the 8 puzzle Problem-using A* algorithm.

'''

import heapq


def find_zero_pos(state):
    for i in range(3):
        for j in range(3):
            if state[i][j] == 0:
                return (i, j)


def possible_moves(state):
    x, y = find_zero_pos(state)
    moves = []
    if x > 0:
        moves.append((x-1, y))
    if x < 2:
        moves.append((x+1, y))
    if y > 0:
        moves.append((x, y-1))
    if y < 2:
        moves.append((x, y+1))
    return moves


def swap_positions(state, p1, p2):
    new_state = [list(row) for row in state]
    x1, y1 = p1
    x2, y2 = p2
    new_state[x1][y1], new_state[x2][y2] = new_state[x2][y2], new_state[x1][y1]
    return new_state


def manhattan_distance(state):
    distance = 0
    for i in range(3):
        for j in range(3):
            val = state[i][j]
            if val != 0:
                target_x, target_y = (val-1) // 3, (val-1) % 3
                distance += abs(i - target_x) + abs(j - target_y)
    return distance


def a_star(start_state, goal_state):
    visited = set()
    heap = [(manhattan_distance(start_state), start_state)]

    while heap:
        _, current_state = heapq.heappop(heap)

        for c in current_state:
            print(c)
        print("")

        if current_state == goal_state:
            return current_state
        visited.add(tuple(map(tuple, current_state)))
        for move in possible_moves(current_state):
            new_state = swap_positions(
                current_state, find_zero_pos(current_state), move)
            if tuple(map(tuple, new_state)) not in visited:
                heapq.heappush(
                    heap, (manhattan_distance(new_state), new_state))
    return None


start_state = [[1, 2, 3], [5, 0, 6], [4, 7, 8]]
goal_state = [[1, 2, 3], [4, 5, 6], [7, 8, 0]]
solution = a_star(start_state, goal_state)


print("")

if solution is None:
    print("No solution found")
else:
    print("Solution found:")
    for row in solution:
        print(row)
