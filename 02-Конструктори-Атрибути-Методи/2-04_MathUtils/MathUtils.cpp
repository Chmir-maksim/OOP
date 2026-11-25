class MathUtils:
    @staticmethod
    def gcd(a: int, b: int) -> int:
        a, b = abs(a), abs(b)
        while b:
            a, b = b, a % b
        return a

    @staticmethod
    def is_prime(n: int) -> bool:
        if n < 2:
            return False
        if n in (2, 3):
            return True
        if n % 2 == 0 or n % 3 == 0:
            return False
        i = 5
        while i * i <= n:
            if n % i == 0 or n % (i + 2) == 0:
                return False
            i += 6
        return True

    @staticmethod
    def factorial(n: int) -> int:
        if n < 0:
            raise ValueError("Факторіал визначений лише для невід'ємних чисел")
        result = 1
        for i in range(2, n + 1):
            result *= i
        return result

    @staticmethod
    def fibonacci(n: int) -> int:
        if n < 0:
            raise ValueError("Індекс Фібоначчі не може бути від'ємним")
        a, b = 0, 1
        for _ in range(n):
            a, b = b, a + b
        return a


# Приклад використання
print(MathUtils.gcd(48, 18))       # 6
print(MathUtils.is_prime(29))      # True
print(MathUtils.factorial(5))      # 120
print(MathUtils.fibonacci(7))     # 13
