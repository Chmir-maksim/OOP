class Date:
    def __init__(self, year: int, month: int, day: int):
        self.year = year
        self.month = month
        self.day = day

    @classmethod
    def from_string(cls, date_str: str) -> "Date":
        year, month, day = map(int, date_str.split("-"))
        return cls(year, month, day)

    @staticmethod
    def is_leap(year: int) -> bool:
        return (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)

    def days_in_month(self) -> int:
        if self.month in (1, 3, 5, 7, 8, 10, 12):
            return 31
        if self.month in (4, 6, 9, 11):
            return 30
        if self.month == 2:
            return 29 if self.is_leap(self.year) else 28
        raise ValueError("Некоректний місяць (очікується 1..12)")


# Приклад використання
d = Date.from_string("2024-02-15")
print(Date.is_leap(2024), d.days_in_month())  # True 29
