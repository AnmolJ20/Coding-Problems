// You run an e-commerce website and want to record the last N order ids
// in a log. Implement a data structure to accomplish this, with the 
// following API.
//	- record(order_id): adds the order_id to the log
//	- get_last(i): gets the ith last element from the log.
//				i is guaranteed to be smalled than or equal to N.
// You should be as efficient with time and space as possible.

#include <iostream>
#include <list>

class Store {
    std::list<int> order_IDS;
public:
    void record(int order_id);
    int getLast(int i);
};

int main() {
    Store TPStreet;
    TPStreet.record(168);
    TPStreet.record(254);
    TPStreet.record(753);
    TPStreet.record(918);
    TPStreet.record(1003);
    TPStreet.record(2652);

    std::cout << TPStreet.getLast(3) << std::endl;
    std::cout << TPStreet.getLast(3) << std::endl;
}

void Store::record(int order_id) {
    order_IDS.push_back(order_id);
}

int Store::getLast(int i) {
    auto it = order_IDS.rbegin();
    for (int j = 0; j < i-1; j++, it++);

    return *it;
}