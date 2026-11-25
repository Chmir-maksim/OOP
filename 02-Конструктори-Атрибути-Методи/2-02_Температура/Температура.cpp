
class Temperature:
    ABSOLUTE_ZERO_C = -273.15

    def __init__(self, celsius: float):
        if not self.is_valid(celsius):
            raise ValueError("Температура нижча за абсолютний нуль (-273.15°C)")
        self.celsius = celsius

    @classmethod
    def from_fahrenheit(cls, f: float) -> "Temperature":
        c = (f - 32) * 5 / 9
        return cls(c)

    @classmethod
    def from_kelvin(cls, k: float) -> "Temperature":
        c = k - 273.15
        return cls(c)

    def to_fahrenheit(self) -> float:
        return self.celsius * 9 / 5 + 32

    @staticmethod
    def is_valid(c: float) -> bool:
        return c >= Temperature.ABSOLUTE_ZERO_C


# Приклад використання
t1 = Temperature(25)
t2 = Temperature.from_fahrenheit(77)
t3 = Temperature.from_kelvin(300)
print(round(t1.to_fahrenheit(), 2), round(t2.celsius, 2), round(t3.celsius, 2))
print(Temperature.is_valid(-300))  # False
