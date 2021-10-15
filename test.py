import numpy as np
from build.Release.module_name import *
from concurrent.futures import ThreadPoolExecutor
import time

print(some_fn_python_name(3, 5))
my_class = PySomeClass(5.0)

print('multiplier is', my_class.multiplier)
my_class.multiplier = 10
print('multiplier is', my_class.multiplier)

print(my_class.multiply(8))
print(my_class.multiply_list([1,2,3,4,5]))
print(my_class.multiply_two(10, 20))
print(my_class.image)

start_time = time.time()

with ThreadPoolExecutor(4) as ex:
	ex.map(lambda x: my_class.function_that_takes_a_while(), [None]*4)

print(f"Threaded fun took {time.time() - start_time} seconds")