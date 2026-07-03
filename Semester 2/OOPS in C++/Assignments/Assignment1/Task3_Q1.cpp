#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
 
/* -------------------- Data structures -------------------- */
struct Snake {
    int head, tail;
};

struct Ladder {
    int bottom, top;
};

/* -------------------- Small helper functions -------------------- */
void waitForEnter() {
    cout << "Press ENTER to roll...";
    cin.get();
}

// Check if a value already exists in any endpoint array pair
bool usedInPairs(int a[], int b[], int count, int x) {
    for (int i = 0; i < count; i++) {
        if (a[i] == x || b[i] == x) return true;
    }
    return false;
}

// Make sure snake/ladder points do not overlap with each other
bool usedEverywhere(
    int sHead[], int sTail[], int sCount,
    int lFoot[], int lTop[], int lCount,
    int x
) {
    return usedInPairs(sHead, sTail, sCount, x) ||
           usedInPairs(lFoot, lTop, lCount, x);
}

/* -------------------- Board mapping (zig-zag numbering) -------------------- */
// Converts row/column (bottom-based) to cell number
int cellFromRowColBottomBased(int r, int c, int N) {
    if (r % 2 == 0) return r * N + c + 1;      // left to right
    else return r * N + (N - c);               // right to left
}

/* -------------------- Generate snakes and ladders -------------------- */
void generateSnakes(int count, int total, int sHead[], int sTail[], int lFoot[], int lTop[], int lCount) {
    int i = 0;
    while (i < count) {
        int head = rand() % (total - 2) + 2;     // [2 .. total-1]
        int tail = rand() % (head - 1) + 1;      // [1 .. head-1]

        if (head <= tail || head == total) continue;
        if (usedEverywhere(sHead, sTail, i, lFoot, lTop, lCount, head)) continue;
        if (usedEverywhere(sHead, sTail, i, lFoot, lTop, lCount, tail)) continue;

        sHead[i] = head;
        sTail[i] = tail;
        i++;
    }
}

void generateLadders(int count, int total, int sHead[], int sTail[], int sCount, int lFoot[], int lTop[]) {
    int i = 0;
    while (i < count) {
        int foot = rand() % (total - 2) + 1;             // [1 .. total-2]
        int top  = rand() % (total - foot - 1) + foot + 1; // [foot+1 .. total-1]

        if (top <= foot) continue;
        if (usedEverywhere(sHead, sTail, sCount, lFoot, lTop, i, foot)) continue;
        if (usedEverywhere(sHead, sTail, sCount, lFoot, lTop, i, top)) continue;

        lFoot[i] = foot;
        lTop[i] = top;
        i++;
    }
}

/* -------------------- Snake/Ladder lookup -------------------- */
int snakeAt(int pos, int sHead[], int sTail[], int sCount) {
    for (int i = 0; i < sCount; i++) {
        if (sHead[i] == pos) return sTail[i];
    }
    return -1;
}

int ladderAt(int pos, int lFoot[], int lTop[], int lCount) {
    for (int i = 0; i < lCount; i++) {
        if (lFoot[i] == pos) return lTop[i];
    }
    return -1;
}

/* -------------------- Display board -------------------- */
void displayBoard(int M, int N, int p1Pos, int p2Pos) {
    cout << "\n================ BOARD ================\n";

    // Print top row to bottom row so board looks natural
    for (int topR = M - 1; topR >= 0; topR--) {
        for (int c = 0; c < N; c++) {
            int cell = cellFromRowColBottomBased(topR, c, N);

            if (cell == p1Pos && cell == p2Pos) cout << "[" << cell << ":P1,P2]\t";
            else if (cell == p1Pos)             cout << "[" << cell << ":P1]\t";
            else if (cell == p2Pos)             cout << "[" << cell << ":P2]\t";
            else                                cout << "[" << cell << "]\t";
        }
        cout << "\n";
    }
    cout << "=======================================\n";
}

/* -------------------- Apply one player turn -------------------- */
void applyTurn(
    int playerNo, int dice, int total,
    int &pos, bool &started,
    int sHead[], int sTail[], int sCount,
    int lFoot[], int lTop[], int lCount
) {
    cout << "Player " << playerNo << " rolled: " << dice << "\n";

    // Player must roll 6 to enter
    if (!started) {
        if (dice == 6) {
            started = true;
            pos = 1;
            cout << "Player " << playerNo << " entered board at cell 1.\n";
        } else {
            cout << "Player " << playerNo << " needs 6 to start.\n";
        }
        return;
    }

    int next = pos + dice;

    // If move goes beyond last cell, skip this move
    if (next <= total) pos = next;
    else {
        cout << "Player " << playerNo << " move skipped (beyond " << total << ").\n";
        return;
    }

    // Check snake first
    int t = snakeAt(pos, sHead, sTail, sCount);
    if (t != -1) {
        cout << "Player " << playerNo << ": Oops! Snake (" << pos << " -> " << t << ")\n";
        pos = t;
        return;
    }

    // Then check ladder
    int top = ladderAt(pos, lFoot, lTop, lCount);
    if (top != -1) {
        cout << "Player " << playerNo << ": Lucky! Ladder (" << pos << " -> " << top << ")\n";
        pos = top;
    }
}

/* -------------------- Main game controller -------------------- */
void startSnakeGame() {
    int M, N;
    cout << "Enter board rows (M) and columns (N): ";
    cin >> M >> N;
    cin.ignore();

    if (M < 2 || N < 2) {
        cout << "Invalid board size.\n";
        return;
    }

    int total = M * N;
    int count = N - 1;  // As required in your assignment logic

    // Dynamic arrays for endpoints
    int *snakeHead = new int[count];
    int *snakeTail = new int[count];
    int *ladderFoot = new int[count];
    int *ladderTop = new int[count];

    srand((unsigned)time(0)); // seed once

    generateSnakes(count, total, snakeHead, snakeTail, ladderFoot, ladderTop, 0);
    generateLadders(count, total, snakeHead, snakeTail, count, ladderFoot, ladderTop);

    int p1Pos = 0, p2Pos = 0;
    bool p1Started = false, p2Started = false;
    int currentPlayer = 1;

    cout << "\n=== 2-Player Snake & Ladder Started ===\n";
    cout << "Rule: each player needs 6 to start.\n";

    while (true) {
        displayBoard(M, N, p1Pos, p2Pos);

        waitForEnter();
        int dice = rand() % 6 + 1;

        if (currentPlayer == 1) {
            applyTurn(1, dice, total, p1Pos, p1Started, snakeHead, snakeTail, count, ladderFoot, ladderTop, count);
            currentPlayer = 2;
        } else {
            applyTurn(2, dice, total, p2Pos, p2Started, snakeHead, snakeTail, count, ladderFoot, ladderTop, count);
            currentPlayer = 1;
        }

        // Show positions after every turn
        cout << "Position: P1=" << p1Pos << " , P2=" << p2Pos << "\n";

        if (p1Pos == total) {
            cout << "\nPlayer 1 wins!\n";
            break;
        }
        if (p2Pos == total) {
            cout << "\nPlayer 2 wins!\n";
            break;
        }
    }

    // Clean up dynamic memory
    delete[] snakeHead;
    delete[] snakeTail;
    delete[] ladderFoot;
    delete[] ladderTop;
}

int main() {
    startSnakeGame();   // main only calls one function
    return 0;
}
