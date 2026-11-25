class Person:
    def __init__(self, first_name: str, last_name: str):
        self.first_name = first_name
        self.last_name = last_name

    @classmethod
    def from_full_name(cls, full_name: str) -> "Person":
        parts = full_name.strip().split()
        if len(parts) < 2:
            raise ValueError("Потрібно вказати ім'я та прізвище")
        return cls(parts[0], parts[-1])

    def full_name(self) -> str:
        return f"{self.first_name} {self.last_name}"

    def initials(self) -> str:
        return f"{self.first_name[0].upper()}.{self.last_name[0].upper()}."


# Приклад використання
p = Person.from_full_name("Ivan Koval")
print(p.full_name())  # Ivan Koval
print(p.initials())   # I.K.
