class Ticket:
    _last_id = 0

    def __init__(self, event: str):
        Ticket._last_id += 1
        self.id = Ticket._last_id
        self.event = event

    @classmethod
    def created(cls) -> int:
        return cls._last_id


# Приклад використання
t1 = Ticket("Концерт")
t2 = Ticket("Кіно")
t3 = Ticket("Виставка")
print(t1.id, t2.id, t3.id)       # 1 2 3
print("Створено:", Ticket.created())  # 3
