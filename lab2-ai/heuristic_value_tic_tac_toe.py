'''
Lab Sheet 2

Name: Suraj Karki
CRN: 018-339

Question 3: WAP to calculate the heuristic value of the states for Tic-Tac-Toe

'''


def heuristic(board, player, opponent):
    possible_wins = [
        [0, 1, 2],
        [3, 4, 5],
        [6, 7, 8],
        [0, 3, 6],
        [1, 4, 7],
        [2, 5, 8],
        [0, 4, 8],
        [2, 4, 6],
    ]

    h_value, flag = 0, 0
    player_values = {
        'X': 0,
        'O': 0

    }

    for i in range(8):
        flag = 0
        for j in range(3):
            if (board[possible_wins[i][j]] == '' or

                    board[possible_wins[i][j]] == player):

                flag = 1
            else:
                flag = 0
                break
        if flag == 1:
            player_values[player] = player_values[player] + 1

    for i in range(8):
        flag = 0
        for j in range(3):
            if (board[possible_wins[i][j]] == ''):
                flag = 1
            else:
                flag = 0
                break

        if flag == 1:
            player_values[opponent] = player_values[opponent] + 1

    print(player_values)
    h_value = player_values[player] - player_values[opponent]
    return h_value


def main():
    current_state = ['', '', 'X', '', '', '', '', '', '']
    current_player = 'X'
    opponent_player = '-'
    if current_player == 'X':
        opponent_player = 'O'
    else:
        opponent_player = 'X'
    h_value = heuristic(current_state, current_player,
                        opponent_player)
    print("The heuristic value of current state is: "+str(h_value))


if __name__ == '__main__':
    main()
