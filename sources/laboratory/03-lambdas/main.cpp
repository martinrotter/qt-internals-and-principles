#include <iostream>
#include <functional>
#include <list>


// In-place map function.
// Executes func for each member of input_list
void map(const std::function<void(double&)> &func, std::list<double> &input_list) {

    // Range-based for-loop.
    for (double &value : input_list) {
	func(value);
    }
}

int main() {
    // Create simple list using list initializer.
    std::list<double> my_list = {1.7, 2.8, 4.9, 5.9, 0.0};

    // Instantiate lambda expression (anonymous function).
    auto func_twice = [&] (double &input) {
	input *= 2;
    };

    // Use lambda expression as function parameter.
    map(func_twice, my_list);

    for (double value : my_list) {
	std::cout << value << " ";
    }

    return 0;
}

