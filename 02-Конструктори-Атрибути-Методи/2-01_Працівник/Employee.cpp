class Employee:
    """Represents an employee."""
    count = 0

    def __init__(self, name="", salary=10000):
        """Initializes an employee."""
        self.name, self.salary = name, salary
        Employee.count += 1

    def raise_salary(self, percent):
        """Increases salary."""
        self.salary *= 1 + percent / 100


e1, e2, e3 = Employee("John"), Employee("Alice", 15000), Employee("Peter")
e1.raise_salary(10)

print(e1.salary)
print(e2.salary)
print(e3.salary)
print(Employee.count)

assert Employee().salary == 10000
assert e1.salary == 11000
assert Employee.count >= 3
