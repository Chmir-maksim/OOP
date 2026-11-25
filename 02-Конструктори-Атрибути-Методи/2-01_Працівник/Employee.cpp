class Employee:
    count = 0

    def __init__(self, name: str, salary: float = 10000):
        self.name = name
        self.salary = salary
        Employee.count += 1

    def raise_salary(self, percent: float) -> float:
        self.salary += self.salary * (percent / 100)
        return self.salary


# Приклад використання
e1 = Employee("Олена")
e2 = Employee("Максим", 15000)
e1.raise_salary(20)
print(e1.name, e1.salary)  # Олена 12000.0
print("Усього працівників:", Employee.count)  # 2
