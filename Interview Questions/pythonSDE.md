
# Python Interview Questions

This file contains a curated set of Python interview questions covering fundamental concepts, advanced topics, Flask/web development, and pandas, along with code snippets and explanations.

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

### 1. What are the key differences between lists and tuples in Python?

Lists are mutable and defined using square brackets [], while tuples are immutable and defined using parentheses ().

```python
my_list = [1, 2, 3]
my_list.append(4)
print(my_list)  # Output: [1, 2, 3, 4]

my_tuple = (1, 2, 3)
# my_tuple.append(4)  # This would raise an error
```

### 2. Explain the concept of list comprehensions and provide an example.

List comprehensions provide a concise way to create lists. They consist of an expression followed by a for clause, then zero or more for or if clauses.

```python
squares = [x**2 for x in range(1, 6)]
print(squares)  # Output: [1, 4, 9, 16, 25]
```

### 3. How does Python handle memory management for objects?

Python uses automatic memory management through its garbage collector. It automatically frees memory occupied by objects that are no longer needed.

### 4. What is the difference between == and is operators in Python?

== compares the values of two objects, while is checks if both variables refer to the same object in memory.

### 5. Explain the concept of duck typing in Python.

Duck typing is a philosophy in which the type or class of an object is less important than the methods it defines. If an object looks like a duck and quacks like a duck, it's a duck.

## Advanced Concepts

### 6. How does Python handle asynchronous programming?

Python supports asynchronous programming through libraries like asyncio and async/await syntax.

```python
import asyncio

async def main():
    print("Hello")
    await asyncio.sleep(1)
    print("World")

asyncio.run(main())
```

### 7. Explain the concept of generators in Python.

Generators are functions that return an iterator object. They allow you to generate a sequence of values on-the-fly without storing them all in memory at once.

```python
def infinite_sequence():
    num = 0
    while True:
        yield num
        num += 1

gen = infinite_sequence()
print(next(gen))  # 0
print(next(gen))  # 1
```

### 8. How does Python handle exceptions?

Python uses try-except blocks to catch and handle exceptions. You can also define custom exception classes.

```python
try:
    x = 5 / 0
except ZeroDivisionError:
    print("Cannot divide by zero!")
```

## Flask/Web Development

### 9. What is Flask? How does it differ from Django?

Flask is a lightweight web framework for Python. It's minimalist compared to Django, which is a full-fledged web framework.

```python
from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route('/api', methods=['POST'])
def api():
    data = request.json
    return jsonify({'message': 'Received data'}), 200

if __name__ == '__main__':
    app.run(debug=True)
```

### 10. Explain the concept of middleware in Flask.

Middleware functions run before or after each request to perform common tasks such as logging, authentication, etc.

```python
from flask import Flask, request, Response

app = Flask(__name__)

@app.before_request
def log_request_info():
    app.logger.info(f'Request: {request.method} {request.url}')

@app.after_request
def log_response_time(response):
    app.logger.info(f'Response time: {response.response.time}')
    return response
```

## Pandas

### 11. How do you create a DataFrame in pandas?

DataFrames are two-dimensional labeled data structures with columns of potentially different types.

```python
import pandas as pd

data = {'Name': ['Alice', 'Bob', 'Charlie'], 
        'Age': [25, 30, 35]}
df = pd.DataFrame(data)
print(df)
```

### 12. Explain the difference between merge() and join() in pandas.

merge() performs database-style joins, while join() aligns indexes.

```python
left = pd.DataFrame({'key': ['A', 'B'], 'value': [1, 2]})
right = pd.DataFrame({'key': ['B', 'C'], 'value': [3, 4]})

result_merge = pd.merge(left, right, on='key')
result_join = left.join(right.set_index('key'), lsuffix='_left')

print(result_merge)
print(result_join)
```

### 13. How do you handle missing values in pandas?

You can use dropna(), fillna(), or replace() methods to handle missing values.

```python
import pandas as pd

df = pd.DataFrame({'A': [1, None, 3], 'B': [None, 5, 6]})
print(df)

# Drop rows with NaN
df_dropped = df.dropna()
print("\nDropped:")
print(df_dropped)

# Fill NaN with mean
df_filled = df.fillna(df.mean())
print("\nFilled:")
print(df_filled)
```

## Object-Oriented Programming

### 14. Explain the concept of inheritance in Python.

Inheritance allows one class to inherit properties and methods from another class.

```python
class Animal:
    def speak(self):
        pass

class Dog(Animal):
    def speak(self):
        return "Woof!"

class Cat(Animal):
    def speak(self):
        return "Meow!"

dog = Dog()
cat = Cat()

print(dog.speak())  # Output: Woof!
print(cat.speak())  # Output: Meow!
```

### 15. How does polymorphism work in Python?

Polymorphism allows objects of different classes to be treated as objects of a common superclass.

```python
class Shape:
    def area(self):
        pass

class Circle(Shape):
    def area(self):
        return 3.14

class Rectangle(Shape):
    def area(self):
        return 20

shapes = [Circle(), Rectangle()]
for shape in shapes:
    print(shape.area())
```

## Data Structures and Algorithms

### 16. Implement a binary search algorithm in Python.

Binary search finds an element in a sorted array by repeatedly dividing in half.

```python
def binary_search(arr, target):
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return -1

arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
index = binary_search(arr, 5)
print(index)  # Output: 4
```

### 17. Explain the concept of dynamic programming.

Dynamic programming breaks down a problem into smaller subproblems and solves them only once.

```python
def fibonacci(n):
    fib = [0] * (n + 1)
    fib[1] = 1
    for i in range(2, n + 1):
        fib[i] = fib[i-1] + fib[i-2]
    return fib[n]

print(fibonacci(10))  # Output: 55
```

### 18. How does the quicksort algorithm work?

Quicksort partitions the array around a pivot element and recursively sorts the subarrays.

```python
def quicksort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quicksort(left) + middle + quicksort(right)

print(quicksort([3,6,8,10,1,2,1]))
```

## Modules and Packages

### 19. How do you create and install a Python package?

Use setuptools to create a package and pip to install it.

```bash
pip install setuptools
python setup.py sdist bdist_wheel
pip install .
```

### 20. Explain the concept of virtual environments in Python.

Virtual environments allow you to create isolated Python environments for different projects.

```bash
python -m venv myenv
source myenv/bin/activate
```

## File Handling

### 21. How do you read and write files in Python?

Use open() function with 'r' (read) or 'w' (write) mode.

```python
with open('file.txt', 'w') as f:
    f.write("Hello, World!")

with open('file.txt', 'r') as f:
    content = f.read()
print(content)
```

### 22. Explain the difference between read(), readline(), and readlines() methods in file handling.

read() reads the entire file into a string, readline() reads one line at a time, while readlines() returns all lines in a list.

```python
with open('file.txt', 'r') as f:
    print(f.read())  # Reads whole file
    print(f.readline())  # Reads first line
    print(f.readlines())  # Reads all lines into a list
```

### 23. How do you handle exceptions in file operations?

Use try-except blocks to catch specific exceptions like FileNotFoundError.

```python
try:
    with open('non_existent_file.txt', 'r') as f:
        content = f.read()
except FileNotFoundError as e:
    print(f"File not found: {e}")
```

## Error Handling

### 24. What is the difference between raise and assert statements in Python?

raise raises an exception, while assert checks assumptions made by the program.

```python
def divide(a, b):
    if b == 0:
        raise ValueError("Cannot divide by zero!")
    return a / b

# Using raise
try:
    result = divide(10, 0)
except ValueError as e:
    print(e)

# Using assert
assert b != 0, "Cannot divide by zero!"
result = a / b
```

### 25. Explain how to create custom exceptions in Python.

Custom exceptions inherit from the Exception class.

```python
class InsufficientFunds(Exception):
    pass

def withdraw(amount):
    if amount > account_balance:
        raise InsufficientFunds("Insufficient funds")
    # Withdraw money...

try:
    withdraw(10000)
except InsufficientFunds as e:
    print(e)
```

## Testing

### 26. What is the unittest module in Python? How does it work?

unittest provides a rich set of tools for constructing and running tests.

```python
import unittest

def add(x, y):
    return x + y

class TestAddFunction(unittest.TestCase):
    def test_add_positive_numbers(self):
        self.assertEqual(add(1, 2), 3)

if __name__ == '__main__':
    unittest.main()
```

### 27. Explain the concept of mocking in Python testing.

Mocking is used to isolate units of code during testing by replacing complex dependencies with simpler ones.

```python
import unittest.mock as mock

def fetch_data():
    # Simulating an API call
    return "Data from API"

class DataManager:
    def process_data(self):
        data = fetch_data()
        return f"Processed: {data}"

# Mocking the function
mock_fetch_data = mock.patch('fetch_data', return_value="Mocked Data")

with mock_fetch_data:
    manager = DataManager()
    result = manager.process_data()

print(result)
```

### 28. How do you write unit tests for asynchronous functions?

Use pytest-asyncio library to test async functions.

```python
import asyncio
from pytest_asyncio import async_test

@async_test
async def test_async_function():
    result = await async_sum(1, 2)
    assert result == 3

async def async_sum(a, b):
    return a + b
```

### 29. What is the difference between pytest and unittest?

pytest is generally faster and more feature-rich compared to Python's built-in unittest module.

```python
# Using unittest
def test_addition():
    assert 1 + 1 == 2

# Using pytest
def test_subtraction():
    assert 5 - 3 == 2
```

### 30. How do you handle database migrations in Flask applications?

Use SQLAlchemy's migration tools to manage database schema changes.

```python
from flask_sqlalchemy import SQLAlchemy

db = SQLAlchemy(app)

class User(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(80), unique=True, nullable=False)

def create_initial_migration():
    db.create_all()

def migrate_database():
    db.session.execute("ALTER TABLE users ADD COLUMN email VARCHAR(120)")
    db.session.commit()

create_initial_migration()
migrate_database()
```

### 31. Explain how to implement rate limiting in Flask applications.

Use Flask-Limiter extension to limit request rates.

```python
from flask import Flask
from flask_limiter import Limiter
from flask_limiter.util import get_remote_address

app = Flask(__name__)
limiter = Limiter(
    app,
    key_func=get_remote_address,
    default_limits=["200 per day", "50 per hour"]
)

@app.route("/")
@limiter.limit("10 per minute")
def hello():
    return "Hello World!"
```

### 32. How do you handle authentication and authorization in Flask applications?

Use Flask-HTTPAuth extension for basic authentication and Flask-Security for more advanced features.

```python
from flask_httpauth import HTTPBasicAuth
from flask_security import SQLAlchemyUserDatastore, UserMixin, RoleMixin, Security

auth = HTTPBasicAuth()

@auth.verify_password
def verify_password(username, password):
    user = User.query.filter_by(username=username).first()
    return user is not None and user.check_password(password)

db = SQLAlchemy(app)

roles_users = db.Table('roles_users',
    db.Column('user_id', db.Integer(), db.ForeignKey('user.id')),
    db.Column('role_id', db.Integer(), db.ForeignKey('role.id'))
)

class Role(db.Model, RoleMixin):
    id = db.Column(db.Integer(), primary_key=True)
    name = db.Column(db.String(80), unique=True)
    description = db.Column(db.String(255))

class User(db.Model, UserMixin):
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(80), unique=True, nullable=False)
    email = db.Column(db.String(120), unique=True, nullable=False)
    password = db.Column(db.String(255), nullable=False)
    roles = db.relationship('Role', 
                            secondary=roles_users, 
                            back_populates='users')

security = Security(app, SQLAlchemyUserDatastore(db, User, Role))

@app.route('/login')
@auth.login_required
def login():
    return f"Logged in as {auth.current_user().username}"
```

### 33. Explain how to implement caching in Flask applications.

Use Flask-Caching extension to add caching capabilities to your Flask application.

```python
from flask import Flask
from flask_caching import Cache

app = Flask(__name__)
cache = Cache(app, config={'CACHE_TYPE': 'simple'})

@app.route('/')
@cache.cached(timeout=300)
def hello():
    return "Hello World!"
```

### 34. How do you handle asynchronous tasks in Flask applications?

Use Celery for background task processing.

```python
from flask import Flask
from celery import Celery

app = Flask(__name__)
celery = Celery(app.name, broker='redis://localhost:6379/0')

@celery.task
def add(x, y):
    return x + y

@app.route('/task')
def task():
    result = add.delay(4, 4)
    return f"Task submitted: {result.id}"
```

### 35. Explain how to implement API versioning in Flask applications.

Use Flask-RESTX extension for API versioning and Swagger documentation.

```python
from flask import Flask
from flask_restx import Api, Resource, fields

app = Flask(__name__)
api = Api(app, version='1.0', title="API Documentation", description="Sample API")

ns = api.namespace('sample', path='/sample')

parser = api.parser()
parser.add_argument('key', type=str, required=True, help='API key')

@ns.route('/')
class Sample(Resource):
    @api.expect(parser)
    def get(self):
        args = parser.parse_args()
        return {'message': f'Welcome, {args.key}'}, 200
```

### 36. How do you handle CORS (Cross-Origin Resource Sharing) in Flask applications?

Use Flask-CORS extension to handle CORS requests.

```python
from flask import Flask
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

@app.route('/')
def hello():
    return "Hello World!"
```
