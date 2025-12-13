#include <iostream>
#include <string>


template <typename T>
class FixedListTestCase {
    public:
        const FixedList<T> input;
        const FixedList<FixedList<T>> expected;

        FixedListTestCase(const FixedList<T>& input,
            const FixedList<FixedList<T>>& expected,
        ) : input(input), expected(expected) {}

        bool isSolution(FixedList<T> solution) {
            bool isSolution = false;
            do {
                if()
            } while();
        }
};

template <typename T>
class GenericFixedListProblem {
    public:
        const FixedList<FixedListTestCase<T>> testCaseList;

        GenericFixedListProblem(
            const FixedList<FixedListTestCase<T>> testCaseList
        ) : testCaseList(testCaseList) {}

        virtual void solve() const; 
};

class PairSumProblem : public GenericFixedListProblem<int> {
    public:
        const int target;

        PairSumProblem(
            const FixedList<FixedListTestCase<int>> testCaseList,
            const int target
        ) : GenericFixedListProblem(testCaseList), target(target) {}

        virtual void solve() const override {
            for(int i = 0; i < testCaseList.size; i++) {

            }
        }
};

int main() {
    return 0;
};