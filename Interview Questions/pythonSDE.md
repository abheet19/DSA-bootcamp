# Python Interview Questions

This file contains a curated set of 100 Python interview questions covering fundamental concepts, advanced topics, Flask/web development, and pandas, along with code snippets and explanations.

## Table of Contents

- [Fundamentals](#fundamentals)
- [Advanced Concepts](#advanced-concepts)
- [Flask/Web Development](#flaskweb-development)
- [Pandas](#pandas)
- [Object-Oriented Programming](#object-oriented-programming)
- [Data Structures and Algorithms](#data-structures-and-algorithms)
- [Modules and Packages](#modules-and-packages)
- [File Handling](#file-handling)
- [Error Handling](#error-handling)
- [Testing](#testing)


## Fundamentals

**1. What are the key differences between lists and tuples in Python?**

* **Lists:** Mutable (can be modified after creation), defined using square brackets ``, generally used for collections that might change.
    ```python
    my_list = [1, 2, 3]
    my_list.append(4) 
    print(my_list)  # Output: [1, 2, 3, 4]
    ```

* **Tuples:** Immutable (cannot be modified after creation), defined using parentheses `()`, often used for fixed data or records.
    ```python
    my_tuple = (1, 2, 3)
    # my_tuple.append(4)  # This would raise an error
    ```

**2. Explain the concept of list comprehensions and provide an example.**

List comprehensions provide a concise way to create lists. They consist of an expression followed by a `for` clause, then zero or more `for` or `if` clauses.

```python
squares = [x**2 for x in range(1, 6)]
print(squares)  # Output: [1, 4, 9, 16, 25]

