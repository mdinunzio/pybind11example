#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

float some_fn(float arg1, float arg2) {
	return arg1 + arg2;
}

class SomeClass {
	float multiplier;

public:
	SomeClass(float multiplier_) : multiplier(multiplier_) {};
	float multiply(float input) {
		return multiplier * input;
	}
	std::vector<float> multiply_list(std::vector<float> items) {
		for (auto i=0; i < items.size(); i++) {
			items[i] = multiply(items.at(i));
		}
		return items;
	}
	py::tuple multiply_two(float one, float two) {
		return py::make_tuple(multiply(one), multiply(two));
	}
};


PYBIND11_MODULE(module_name, handle) {
	handle.doc() = "This is the module docs. Teehee.";
	handle.def("some_fn_python_name", &some_fn);

	py::class_<SomeClass>(
						  handle, "PySomeClass"
						  )
	.def(py::init<float>())
	.def("multiply", &SomeClass::multiply)
	.def("multiply_list", &SomeClass::multiply_list)
	.def("multiply_two", &SomeClass::multiply_two);
}
