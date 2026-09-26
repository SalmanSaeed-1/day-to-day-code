from collections import deque
import time


# 1. INITIAL BOARD
def initial_state():
    return tuple(tuple('.' for _ in range(3)) for _ in range(3))


# 2. GENERATE NEXT MOVES
def get_next_moves(board, current_player):
    moves = []
    for r in range(3):
        for c in range(3):
            if board[r][c] == '.':
                new_board = [list(row) for row in board]               # copy of the 2D board
                new_board[r][c] = current_player
                moves.append(tuple(tuple(row) for row in new_board))   # tuple so it fits in a set
    return moves


# 3. CHECK WINNER
def check_winner(board):
    for i in range(3):
        if board[i][0] == board[i][1] == board[i][2] != '.':           # row
            return board[i][0]
        if board[0][i] == board[1][i] == board[2][i] != '.':           # column
            return board[0][i]
    if board[0][0] == board[1][1] == board[2][2] != '.':               # main diagonal
        return board[0][0]
    if board[0][2] == board[1][1] == board[2][0] != '.':               # other diagonal
        return board[0][2]
    if all(board[r][c] != '.' for r in range(3) for c in range(3)):
        return 'Draw'
    return None                                                        # game still running


# 4. CHECK WHETHER BOARD IS VALID
def is_valid_board(board, player=None):
    # Board must be 3x3 and hold only 'X', 'O' or '.'
    if len(board) != 3 or any(len(row) != 3 for row in board):
        return False
    if any(cell not in ('X', 'O', '.') for row in board for cell in row):
        return False

    # X always plays first
    x_count = sum(row.count('X') for row in board)
    o_count = sum(row.count('O') for row in board)
    if x_count < o_count or x_count > o_count + 1:
        return False

    # Check whether X or O has won
    x_wins = o_wins = False
    for i in range(3):
        if board[i][0] == board[i][1] == board[i][2] != '.':           # row
            if board[i][0] == 'X':
                x_wins = True
            else:
                o_wins = True
        if board[0][i] == board[1][i] == board[2][i] != '.':           # column
            if board[0][i] == 'X':
                x_wins = True
            else:
                o_wins = True
    if board[0][0] == board[1][1] == board[2][2] != '.':               # main diagonal
        if board[0][0] == 'X':
            x_wins = True
        else:
            o_wins = True
    if board[0][2] == board[1][1] == board[2][0] != '.':               # other diagonal
        if board[0][2] == 'X':
            x_wins = True
        else:
            o_wins = True

    if x_wins and o_wins:                          # both players cannot win
        return False
    if x_wins and x_count != o_count + 1:          # X won, so X made the last move
        return False
    if o_wins and x_count != o_count:              # O won, so both made equal moves
        return False

    # If the game is still going, it must be the right player's turn
    # (X moves when both have the same number of marks, otherwise O)
    if player is not None and check_winner(board) is None:
        if player != ('X' if x_count == o_count else 'O'):
            return False
    return True


# 5. CHANGE PLAYER
def toggle_player(player):
    return 'O' if player == 'X' else 'X'


# 6. BFS SEARCH
def bfs_search(start_board, start_player, target_winner):
    if not is_valid_board(start_board, start_player):
        return None, 0
    winner = check_winner(start_board)
    if winner == target_winner:                    # already the target winner
        return [start_board], 0
    if winner is not None:                         # game is already over
        return None, 0

    queue = deque([(start_board, start_player, [])])
    visited = set([start_board])
    states_explored = 0
    while queue:
        current_board, player, path = queue.popleft()
        states_explored += 1
        winner = check_winner(current_board)
        if winner == target_winner:
            return path + [current_board], states_explored
        if winner is not None:
            continue
        for next_board in get_next_moves(current_board, player):
            if next_board not in visited:
                visited.add(next_board)
                queue.append((next_board, toggle_player(player), path + [current_board]))
    return None, states_explored


# 7. DFS SEARCH
def dfs_search(start_board, start_player, target_winner):
    if not is_valid_board(start_board, start_player):
        return None, 0
    winner = check_winner(start_board)
    if winner == target_winner:
        return [start_board], 0
    if winner is not None:
        return None, 0

    stack = [(start_board, start_player, [])]
    visited = set([start_board])
    states_explored = 0
    while stack:
        current_board, player, path = stack.pop()
        states_explored += 1
        winner = check_winner(current_board)
        if winner == target_winner:
            return path + [current_board], states_explored
        if winner is not None:
            continue
        for next_board in get_next_moves(current_board, player):
            if next_board not in visited:
                visited.add(next_board)
                stack.append((next_board, toggle_player(player), path + [current_board]))
    return None, states_explored


# 8. DEPTH-LIMITED SEARCH
def dls_search(board, player, target_winner, depth, path, visited):
    winner = check_winner(board)
    if winner == target_winner:                    # target found
        return path + [board], 1
    if winner is not None or depth == 0:           # game ended or depth limit reached
        return None, 1

    states_explored = 1
    for next_board in get_next_moves(board, player):
        if next_board not in visited:
            visited.add(next_board)
            result_path, explored = dls_search(next_board, toggle_player(player), target_winner,
                                               depth - 1, path + [board], visited)
            states_explored += explored
            if result_path:
                return result_path, states_explored
            visited.remove(next_board)             # so another branch can explore it
    return None, states_explored


# 9. ITERATIVE DEEPENING DFS
def iddfs_search(start_board, start_player, target_winner, max_depth=9):
    if not is_valid_board(start_board, start_player):
        return None, 0
    winner = check_winner(start_board)
    if winner == target_winner:
        return [start_board], 0
    if winner is not None:
        return None, 0

    total_explored = 0
    for depth in range(max_depth + 1):             # search with increasing depth
        visited = set([start_board])
        path, explored = dls_search(start_board, start_player, target_winner, depth, [], visited)
        total_explored += explored
        if path:
            return path, total_explored
    return None, total_explored


# 10. MINIMAX FOR OPTIMAL STRATEGY
def minimax(board, player):
    winner = check_winner(board)
    if winner == 'X':
        return 1
    if winner == 'O':
        return -1
    if winner == 'Draw':
        return 0

    if player == 'X':                              # X tries to maximize the score
        best_score = -float('inf')
        for next_board in get_next_moves(board, 'X'):
            score = minimax(next_board, 'O')
            best_score = max(best_score, score)
        return best_score
    else:                                          # O tries to minimize the score
        best_score = float('inf')
        for next_board in get_next_moves(board, 'O'):
            score = minimax(next_board, 'X')
            best_score = min(best_score, score)
        return best_score


# 11. FIND BEST MOVE USING MINIMAX
def find_best_move(board, player):
    if not is_valid_board(board, player):
        return None
    if check_winner(board) is not None:
        return None

    best_move = None
    if player == 'X':
        best_score = -float('inf')
        for next_board in get_next_moves(board, 'X'):
            score = minimax(next_board, 'O')
            if score > best_score:
                best_score = score
                best_move = next_board
    else:
        best_score = float('inf')
        for next_board in get_next_moves(board, 'O'):
            score = minimax(next_board, 'X')
            if score < best_score:
                best_score = score
                best_move = next_board
    return best_move


# 12. DISPLAY BOARD
def print_board(board):
    for row in board:
        print(" | ".join(row))
    print()


# 13. PERFORMANCE TEST
def run_performance_test(board_name, board, start_player, target_winner):
    print(f"\n--- Testing Configuration: {board_name} ---")
    if not is_valid_board(board, start_player):
        print("Invalid board configuration!")
        return

    start_time = time.time()
    bfs_path, bfs_explored = bfs_search(board, start_player, target_winner)
    bfs_time = time.time() - start_time
    bfs_len = len(bfs_path) if bfs_path else 0

    start_time = time.time()
    dfs_path, dfs_explored = dfs_search(board, start_player, target_winner)
    dfs_time = time.time() - start_time
    dfs_len = len(dfs_path) if dfs_path else 0

    start_time = time.time()
    iddfs_path, iddfs_explored = iddfs_search(board, start_player, target_winner)
    iddfs_time = time.time() - start_time
    iddfs_len = len(iddfs_path) if iddfs_path else 0

    print(f"BFS:   Explored {bfs_explored:<5} states in {bfs_time:.6f}s | Path Length: {bfs_len}")
    print(f"DFS:   Explored {dfs_explored:<5} states in {dfs_time:.6f}s | Path Length: {dfs_len}")
    print(f"IDDFS: Explored {iddfs_explored:<5} states in {iddfs_time:.6f}s "
          f"| Path Length: {iddfs_len}")


# 14. MAIN PROGRAM
if __name__ == "__main__":
    empty_board = initial_state()
    partial_board = (('X', '.', '.'),              # partially filled
                     ('.', 'O', '.'),
                     ('.', '.', 'X'))
    winning_board = (('X', 'X', '.'),              # X is one move away from winning
                     ('O', 'O', '.'),
                     ('.', '.', '.'))
    edge_case_draw = (('X', 'O', 'X'),             # already drawn
                      ('X', 'O', 'O'),
                      ('O', 'X', 'X'))
    edge_case_won = (('X', 'X', 'X'),              # already won by X
                     ('O', 'O', '.'),
                     ('.', '.', '.'))
    invalid_board = (('X', 'X', 'X'),              # both players have three in a row
                     ('O', 'O', 'O'),
                     ('.', '.', '.'))
    unknown_symbol_board = (('X', 'Z', '.'),       # unknown symbol on the board
                            ('.', 'O', '.'),
                            ('.', '.', '.'))
    wrong_size_board = (('X', 'O', '.'),           # wrong board size (only 2 rows)
                        ('.', '.', '.'))

    # PERFORMANCE TESTS
    run_performance_test("Empty Board", empty_board, 'X', 'X')
    run_performance_test("Partially Filled Board", partial_board, 'O', 'O')
    run_performance_test("Winning Position (1 move away)", winning_board, 'X', 'X')
    run_performance_test("Edge Case: Already Drawn", edge_case_draw, 'X', 'X')
    run_performance_test("Edge Case: Already Won by X", edge_case_won, 'O', 'O')
    run_performance_test("Edge Case: Invalid Board", invalid_board, 'X', 'X')
    run_performance_test("Edge Case: Wrong Player to Move (O first)", empty_board, 'O', 'O')
    run_performance_test("Edge Case: Unknown Symbol", unknown_symbol_board, 'X', 'X')
    run_performance_test("Edge Case: Wrong Board Size", wrong_size_board, 'X', 'X')

    # MINIMAX / OPTIMAL STRATEGY TEST
    print("\n" + "-" * 70)
    print("MINIMAX OPTIMAL STRATEGY TEST")
    print("-" * 70)
    print("\nInitial Empty Board:")
    print_board(empty_board)

    best_move = find_best_move(empty_board, 'X')
    print("One optimal first move for X:")
    print_board(best_move)

    best_reply = find_best_move(best_move, 'O')
    print("One optimal reply for O:")
    print_board(best_reply)

    result = {1: "X wins", 0: "Draw", -1: "O wins"}[minimax(best_reply, 'X')]
    print("If both players keep playing optimally, the game ends in:", result)
    print("Minimax evaluates X as the maximizing player and O as the minimizing player.")

    # COMPLEXITY / ANALYSIS INFORMATION
    print("\n" + "-" * 70)
    print("SEARCH COMPLEXITY INFORMATION")
    print("-" * 70)
    print("Theoretical Tic-Tac-Toe board state space: 3^9 = 19,683")
    print("Search-tree upper bound on move orderings: 9!")
    print("Actual reachable states are much smaller because games")
    print("terminate when a player wins or the board becomes full.")
    print("BFS uses a queue and finds the shallowest target path.")
    print("DFS uses a stack and may find a deeper path first.")
    print("IDDFS repeatedly performs depth-limited DFS.")
    print("BFS:   time O(b^d), space O(b^d)")
    print("DFS:   time O(b^m), space O(b*m)")
    print("IDDFS: time O(b^d), space O(b*d)")
    print("b = branching factor (empty squares, at most 9),")
    print("d = depth of the shallowest win, m = maximum depth (9 moves).")
    print("Minimax considers both players and selects an optimal move")
    print("assuming both players play optimally.")

    # AI INTERACTION TABLE
    row = "{:<12} | {:<35} | {:<30} | {}"
    print("\n" + "-" * 115)
    print(row.format("Interaction", "What I asked AI", "AI's suggestion",
                     "What I changed/verified"))
    print("-" * 115)
    print(row.format("1", "Implement BFS for Tic-Tac-Toe", "Use a queue for BFS",
                     "Changed list queue to collections.deque for O(1) pops"))
    print(row.format("2", "Debug DFS visited-state handling", "Use a visited set",
                     "Used tuple of tuples so boards can be stored in a set"))
    print(row.format("3", "Check complexity of the search", "State space is 3^9",
                     "Verified 3^9 = 19,683 and distinguished it from 9! move orderings"))
    print("-" * 115)

    # AI GENERATED CODE MODIFICATION
    print("\nAI Code Modification: "
          "AI initially suggested shallow copy `new_board = board.copy()`.")
    print("Modified it to use `[list(row) for row in board]` to correctly copy the nested rows "
          "and avoid modifying original board states across different branches.")