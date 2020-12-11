/*

Encrypted arithmetic puzzle
- Assign letter to digit (S = 4, E = 7, ...) so math
  SEND
+ MORE
 MONEY

Exhaustive Strategy
- Find unassigned letter, assign digit
- Recur from there and see if solution works out
- If not, unmake assignment and try again
- Actually just doing permutation match of digits to characters

bool DumbSolver(puzzleT puzzle, string LettersToAssign) {
    if (lettersToAssign == "")
        return PuzzleSolved(puzzle);

    for (int digit = 0; digit <= 9; digit++) {
        if (AssignLetter(lettersToAssign[0], digit)) {
            if (DumbSolve(puzzle, lettersToAssign.substr(1))) return true;
            UnassignLetter(lettersToAssign[0], digit);
        }
        return false;  // nothing worked, need to backtrack
    }
}


Smarter Solver
- Start with lastmost column (least significant digit)
- If failed, stop recur onwards, backtrack

*/