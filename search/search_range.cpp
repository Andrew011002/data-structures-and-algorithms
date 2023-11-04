#include<iostream>
#include <vector>
#include <cassert>
using namespace std;

struct Goal {
private:
    int goal_num;

public: 
    Goal(int num) {
        goal_num = num;
    }

    int is_close(int num) {
        if (num > goal_num) {
            return 1;
        } else if (num < goal_num) {
            return -1;
        } return 0;
    }

    void change_num(int num) {
        goal_num = num;
    }
};

int search_range(pair<int,int> range, Goal &goal) {
    int low = range.first;
    int high = range.second;
    int mid;
    // basic check
    assert(low <= high);

    // search while pointers don't overcross
    while (low <= high) {
        mid = (low + high) / 2;
        if (goal.is_close(mid) == -1) { // too small, move low higher
            low = mid + 1;
        } else if (goal.is_close(mid) == 1) { // too big, move high lower
            high = mid - 1;
        } else if (goal.is_close(mid) == 0) {
            return mid; // value found
        }
    }
    return -1;
}

int main() {
    Goal goal = Goal(5);
    pair<int,int> range(-10, 10);
    assert(search_range(range, goal) == 5);

    goal.change_num(10);
    assert(search_range(range, goal) == 10);

    goal.change_num(-10);
    assert(search_range(range, goal) == -10);

    range.first = 1;
    range.second = 1;
    goal.change_num(1);
    assert(search_range(range, goal) == 1);

    goal.change_num(2);
    assert(search_range(range, goal) == -1);

    range.first = -100000;
    range.second = 100000;
    goal.change_num(6969);
    assert(search_range(range, goal) == 6969);
}
