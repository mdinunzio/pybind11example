import sys
sys.path.append(r'C:\Users\mdinu\Desktop\bindings\build\Release')
import module_name


print(dir(module_name))
print(module_name.__doc__)
print(module_name.some_fn_python_name)
print(module_name.some_fn_python_name(1,2))
