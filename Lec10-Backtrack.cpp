/*

Backtracking pseducode

bool Solve(configuration conf) {
    if (no more choice)  // base case
        return (conf is goal state);

    for (all available choices) {
        try one choice c;
        //solve from here , if works out, you're done
        if (Solve(conf with choice c made)) return true;
        unmake choice c;
    }

    return false; // tried all choices, no solution found
}

*/

