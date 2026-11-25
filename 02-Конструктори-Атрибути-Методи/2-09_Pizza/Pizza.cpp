class Pizza:
    BASE_PRICES = {
        25: 120,
        30: 150,
        35: 190,
    }
    TOPPING_PRICE = 10

    def __init__(self, size: int = 30, toppings: list[str] | None = None):
        if size not in self.BASE_PRICES:
            raise ValueError("Доступні розміри піци: 25, 30, 35")
        self.size = size
        # Створюємо новий список для кожного об'єкта, щоб уникнути спільного стану
        self.toppings = list(toppings) if toppings is not None else []

    def add(self, topping: str) -> "Pizza":
        self.toppings.append(topping)
        return self

    def price(self) -> int:
        return self.BASE_PRICES[self.size] + len(self.toppings) * self.TOPPING_PRICE


# Перевірка, що начинки не спільні між об'єктами
p1 = Pizza(30).add("сир").add("гриби")
p2 = Pizza(30).add("пепероні")

print("p1:", p1.toppings, "ціна:", p1.price())  # ['сир', 'гриби'] ціна: 170
print("p2:", p2.toppings, "ціна:", p2.price())  # ['пепероні'] ціна: 160
print("Списки різні?", p1.toppings is not p2.toppings)  # True
