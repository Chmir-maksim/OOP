from decimal import Decimal, ROUND_HALF_UP


class Money:
    def __init__(self, kopecks: int):
        self.kopecks = int(kopecks)

    @classmethod
    def from_float(cls, x: float) -> "Money":
        kop = int((Decimal(str(x)) * 100).quantize(Decimal("1"), rounding=ROUND_HALF_UP))
        return cls(kop)

    @classmethod
    def from_string(cls, amount_str: str) -> "Money":
        kop = int((Decimal(amount_str.strip()) * 100).quantize(Decimal("1"), rounding=ROUND_HALF_UP))
        return cls(kop)

    def to_float(self) -> float:
        return self.kopecks / 100

    def __str__(self) -> str:
        return f"{self.kopecks / 100:.2f} UAH"


# Приклад використання
m1 = Money(1250)
m2 = Money.from_float(12.5)
m3 = Money.from_string("12.50")
print(m1, m2.to_float(), str(m3))  # 12.50 UAH 12.5 12.50 UAH
