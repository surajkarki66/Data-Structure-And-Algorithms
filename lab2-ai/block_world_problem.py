'''
Lab Sheet 2

Name: Suraj Karki
CRN: 018-339

Question 2: WAP to calculate the heuristic value of the states for Blocks World Problem

'''


def heuristic_value(current, goal):
    h_value = 0
    for i in range(4):
        if (current[i] == goal[i]):
            h_value = h_value + i
        else:
            h_value = h_value - i

    return h_value


def main():
    current = ['A', 'D', 'B', 'C']
    goal = ['A', 'B', 'C', 'D']

    print("The current state is: ", end=" ")

    for i in current:
        print(i, end=" ")

    print("")
    h_value = heuristic_value(current, goal)
    print("The heuristic value of current state is: " +
          str(h_value))


if __name__ == '__main__':
    main()
