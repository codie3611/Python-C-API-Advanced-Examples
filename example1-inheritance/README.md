
# Example1 - Inheritance

This is the inheritance example. The important parts are commented in the source code. The main differences can be achieved by letting the inheritance-class struct inherit the base-class struct. The base-class type must also be to the inheritance-class type block (there is an argument).

# Example

```python
from my_module import BaseClass
bc = BaseClass()
inh = InheritanceClass()

## Use a base class function. It just returns the arguments.
bc.some_base_function("some_string")
# >>> "some_string"
bc.some_base_function("some_string","some_string2")
# >>> "some_string2"

## Test the inheritance class for the base class function too
inh.some_base_function("some_string")
# >>> "some_string"
inh.some_base_function("some_string","some_string2")
# >>> "some_string2"
```