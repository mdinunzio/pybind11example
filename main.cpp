/*
https://www.youtube.com/watch?v=_5T70cAXDJ0
cmake .. ; cmake --build . --config Release ; python ..\test.py
*/
#include <vector>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>

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

	std::vector<std::vector<uint8_t>> make_image() {
		auto out = std::vector<std::vector<uint8_t>>();
		for (auto i = 0; i < 128; i++) {
			out.push_back(std::vector<uint8_t>(64));
		}
		for (auto i = 0; i < 30; i++) {
			for (auto j = 0; j < 30; j++){
				out[i][j] = 255;
			}
		}
		return out;
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
	.def_property_readonly("image", [](SomeClass &self){
						  py::array out = py::cast(self.make_image());
						  return out;
	})
	.def("multiply_two", [](SomeClass &self, float one, float two){
		return py::make_tuple(self.multiply(one), self.multiply(two));
	});
}
