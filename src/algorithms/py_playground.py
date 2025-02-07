from typing import Iterable, Any

import package.module2
from time import sleep
import os

# import antigravity
import datetime

# no import, o módulo é EXECUTADO apenas uma vez, e reaproveitado em outros imports (CACHE)
import my_module
import my_module as mm
from my_module import show as showwww
import sys

# from my_module import * ( imports everything )

courses = ["History", "Math", "Physics"]

print(courses.index("History"))
print(courses.index("Math"))
print("Physics" in courses)
print("Physics" not in courses)

for idx, item in enumerate(courses):
    print(f"idx: {idx } - Item: {item}", end="\n")

print()

print(courses[:2])
print(" - ".join(courses))
print(" - ".join(courses).split(" - "))

# immutable
# tuples
t = (1, 2, 3, 4, 5)
print(t)
print(t.count(2))
print(t.index(5))
print(t[0])

t = list(t)
t.insert(0, 10)
print(tuple(t))

# collection of unordered and unique elements
s = set([2, 2, 3, 3, 5, 5, 5, 10])
s2 = {2, 2, 3, 3, 5, 5, 5}

# this is a set
s3 = {2, 2, 3, 3, 5, 5, 5, 15, 20}

# this is a dictionary. Not a set
hashmap = {}
print(s)
print(s2)
print(2 in s2)
print(s.intersection(s2))
print(s.union(s2, s3))
print(s.difference())


def fn_kwargs(**kwargs):
    # dict
    print(kwargs)


def fn_args(*args):
    # tuple
    print(args)


def fn_args_kwargs(*args, **kwargs):
    print("kwargs: {}".format(kwargs), end=" - args: ")
    print(args)


def pack(*a: Iterable[Any]):
    print("packed into tuple: ", a)


fn_kwargs(a=20, b=15, c=-1)
fn_args(20, "hello", 20)
fn_args_kwargs(20, "hello", 20, a=20, b=15, c=-1)
pack(1, 2, 3, "hello")


def receive(a: int, b: int, c: int):
    print("a = ", a)
    print("b = ", b)
    print("c = ", c)


# unpack and pass each individual item as parameter
receive(*[1, 2, 3])

hashset = dict([("item 1", 1), ("item 2", 1), ("item 3", 3)])
print(hashset)
print(hashset["item 1"])
print(hashset.get("item 1"))
hashset["item 1"] = 15
print(hashset["item 1"])

# default value ( second parameter )
print(hashset.get("item 4", "Not found"))
hashset.update({"item 4": 29})
print(hashset)

del hashset["item 4"]
print(hashset)

# get the value and pops off
v = hashset.pop("item 3")
print("v: ", v, " - ", hashset)
print(len(hashset))
print(hashset.__len__())

keys = hashset.keys()
values = hashset.values()
print("keys: ", keys, " - ", "values: ", values)
print(hashset.items())

for k in hashset.keys():
    print(k, end=" ")

print()
for v in hashset.values():
    print(v, end=" ")

print()
print("-" * 10)
for k, v in hashset.items():
    print(f"key: {k} - value: {v}")

obj1 = {}
obj2 = obj1
obj3 = obj2
obj4 = obj1.copy()
print(f"obj1 id: {id(obj1)} - obj2 id: {id(obj2)}", obj1 is obj2)
print(f"obj3 id: {id(obj3)} - obj1 id: {id(obj1)}", obj3 is obj1)
print(f"obj4 id: {id(obj4)} - obj1 id: {id(obj1)}", obj4 is obj1)

# is - object equality
# == - value equality
# Falsy values: False or None or 0 or {} or [])

nums = [1, 2, 3, 4, 5]
for n in nums:
    print(n, end=" ")

print()

for n in nums:
    if n == 3:
        break
    print(n, end=" ")

print()
# from 0 to 9
for i in range(10):
    print("i: ", i)

print()
for i in range(0, 10):
    print("i: ", i)


def blank():
    pass


def student_info(*args, **kwargs) -> None:
    """
    This is a my student function info
    """

    print(args)
    print(kwargs)


courses = ["Math", "Art"]
info = {"name": "Guilherme", "age": 20}

# * unpack a iterable, passing each item as positional argument
# ** unpack a mapping, passing each item as a keyword argument
student_info(*courses, **info)
print(my_module.test_variable)
mm.show()
showwww()
# paths where python looks for modules on imports
# it is possible to modify it to include other module paths
print(sys.path)

# order of available modules
"""
1 - cwd
2 - pythonpath env variables
3 - std library directories
"""
print()

# prints the location of the module
print(os.__file__)
print(my_module.__file__)


# python's default argument are only initialized once the function is declared


# not at every call
def show_time(time=datetime.datetime.now()):
    print(time)


# this way, it has a updated value for each call
def show_update_time(time=None):
    if not time:
        time = datetime.datetime.now()
    print(time)


show_time()
show_time()
show_time()
print("-------------")
show_update_time()
# sleep(0.5)
show_update_time()
# sleep(0.5)
show_update_time()

lst1 = [1, 2, 3]
lst2 = ["churros", "shoyou", "gui"]

# creates a list of tuples, each one with corresponding elements from the iterables
zipped = zip(lst1, lst2)

# this way, it creates the iterator, and exhausts it, converting to a list
zipped2 = list(zip(lst1, lst2))
# here, the zip object, which is an ITERATOR, gets exhausted
# which means it can not be iterated again. Only once
list(zipped)

# then, this for loop would not iterave over the zipped object
for i in list(zipped):
    print(i)
# print(list(zipped))

for i in list(zipped2):
    print(i)

print("-------------")

for i in list(zipped2):
    print(i)


"""
Common mistakes

1) Indentation and Spaces 
2) Naming Conflicts
3) Mutable Default Args
4) Exhausting Iterators
5) Importing with *

"""
