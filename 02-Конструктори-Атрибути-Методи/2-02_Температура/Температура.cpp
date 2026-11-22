
class Temperature:
    """Represents Celsius temperature."""

    def __init__(self, celsius=0):
        """Initializes temperature."""
        self.celsius = celsius

    @classmethod
    def from_fahrenheit(cls, f):
        """Converts Fahrenheit to Celsius."""
        return cls((f - 32) * 5 / 9)

    @classmethod
    def from_kelvin(cls, k):
        """Converts Kelvin to Celsius."""
        if k < 0:
            raise ValueError("Invalid Kelvin")
        return cls(k - 273.15)

    def to_fahrenheit(self):
        """Converts Celsius to Fahrenheit."""
        return self.celsius * 9 / 5 + 32

    @staticmethod
    def is_valid(c):
        """Checks valid Celsius temperature."""
        return c >= -273.15

t1, t2, t3 = Temperature(), Temperature.from_fahrenheit(32), Temperature.from_kelvin(300)
print(t1.celsius)
print(t2.celsius)
print(t3.celsius)

assert t1.celsius == 0
assert t2.to_fahrenheit() == 32
assert not Temperature.is_valid(-300)
