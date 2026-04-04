#include <bits/stdc++.h>
using namespace std;


void print_move(int start, int end)
{
    cout << start << " -> " << end << endl;
}

// Classic tower of Hanoi solution using recursion
void solve_tower_hanoi(int num_discs, int start_rod, int end_rod)
{
    if (num_discs == 1)
    {
        print_move(start_rod, end_rod);
        return;
    }
    // The auxilliary rod is the one that is not the starting or the ending rod
    int auxilliary_rod = 6 - (start_rod + end_rod);

    // All discs except the last are moved from the start rod to the auxilliary rod
    solve_tower_hanoi(num_discs - 1, start_rod, auxilliary_rod);

    // The last disc is moved from the start rod to the end rod
    print_move(start_rod, end_rod);

    // All discs from the auxilliary rod are moved to the end rod
    solve_tower_hanoi(num_discs - 1, auxilliary_rod, end_rod);
}

int main()
{
    int num_discs;
    cin >> num_discs;
    solve_tower_hanoi(num_discs, 1, 3);
    return 0;
}
