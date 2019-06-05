#include <cassert>
#include <iostream>
#include <vector>
#include "../my_code/pointers.h"

using namespace std;

const int NUM_THINGS = 40;


int main() {
    // first we test the various methods of passing args:
    int n = 0;
    inc_by_value(n);
    cout << "After value, n = " << n << endl;
    assert(n == 0);
    inc_with_pointer(&n);
    cout << "After ptr, n = " << n << endl;
    assert(n == 1);
    inc_with_reference(n);
    cout << "After ref, n = " << n << endl;
    assert(n == 2);

    // now assign TAs to students
    vector<Student*> students;
    Student* mary = new Student("mary");
    Student* gordon = new Student("gordon");
    assignTA(mary, gordon);
    students.push_back(mary);
    students.push_back(gordon);
    printTAs(students);
    assert(mary->ta == gordon);
    assert(gordon->ta == nullptr);

    // now let's make, print, change, and delete some "things":
    Thing** things = create_array_of_things(NUM_THINGS);
    assert(things != nullptr);

    print_all_things(things, NUM_THINGS);

    double_all_things(things, NUM_THINGS);
    for (int i = 0; i < NUM_THINGS; i++)
        assert(things[i]->val == (i * 2));

    print_all_things(things, NUM_THINGS);

    delete_all_things(things, NUM_THINGS);
    return 0;
}
