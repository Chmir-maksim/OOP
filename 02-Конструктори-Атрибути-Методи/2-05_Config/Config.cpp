class Config:
    defaults = {
        "theme": "light",
        "timeout": 30,
        "retries": 3,
    }

    def __init__(self, **overrides):
        # Копіюємо словник для кожного екземпляра окремо
        self._settings = dict(overrides)

    def set(self, key: str, value):
        self._settings[key] = value

    def get(self, key: str):
        if key in self._settings:
            return self._settings[key]
        return self.defaults.get(key)


# Перевірка незалежності об'єктів
c1 = Config(theme="dark")
c2 = Config()

c1.set("timeout", 120)
print("c1 theme:", c1.get("theme"), "| c1 timeout:", c1.get("timeout"))  # dark | 120
print("c2 theme:", c2.get("theme"), "| c2 timeout:", c2.get("timeout"))  # light | 30
