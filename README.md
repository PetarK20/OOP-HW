# OOP-HW

---

## Компилация и Изпълнение

Отворете терминал в директорията (`OOP-HW/`) и изпълнете:

```bash
g++ -std=c++17 -Wall -Wextra -O2 -Iinclude main/Test.cpp src/*.cpp -o library_app
```
След това стартирайте програмата:

```bash
./library_app
```


## Примерен изход
```bash
Member with ID M001 already exists. Cannot add duplicate.

Library contains:
Books ->
Title: Pod igoto
Author: Ivan Vazov (Born: 1850)
Year: 1894
Price: 25.500000
ISBN: ISBN-001

Title: Nema zemya
Author: Ivan Vazov (Born: 1850)
Year: 1900
Price: 18.900000
ISBN: ISBN-002

Members ->
Name: Petar Kolev, ID: M001, Year Joined: 2025
Name: Yordan Vladov, ID: M002, Year Joined: 2025
Loans ->
No active loans.

## 1. Loan Test ##
Loan created.
Loan failed.

## 2. Availability Check ##
Available ISBN-001? false
Available ISBN-003? false
Available ISBN-002? true

Current Library State:
Library contains:
Books ->
Book unavailable: Pod igoto (ISBN: ISBN-001)
Title: Nema zemya
Author: Ivan Vazov (Born: 1850)
Year: 1900
Price: 18.900000
ISBN: ISBN-002

Members ->
Name: Petar Kolev, ID: M001, Year Joined: 2025
Name: Yordan Vladov, ID: M002, Year Joined: 2025
Loans ->
ISBN: ISBN-001
Member ID: M001
Start Date: 2025-12-03
Due Date: 2025-12-07
Returned: No


## 3. Return Book ##
Available ISBN-001? true

## 4. Find By Author ##
Found: Pod igoto
Found: Nema zemya

## 5. Books By Year (1900) ##
Found: Nema zemya

## 6. Final Library State ##
Library contains:
Books ->
Title: Pod igoto
Author: Ivan Vazov (Born: 1850)
Year: 1894
Price: 25.500000
ISBN: ISBN-001

Title: Nema zemya
Author: Ivan Vazov (Born: 1850)
Year: 1900
Price: 18.900000
ISBN: ISBN-002

Members ->
Name: Petar Kolev, ID: M001, Year Joined: 2025
Name: Yordan Vladov, ID: M002, Year Joined: 2025
Loans ->
ISBN: ISBN-001
Member ID: M001
Start Date: 2025-12-03
Due Date: 2025-12-07
Returned: Yes

```

## Част от екранна снимка

![Снимка на екрана](test.png "Снимка")

## Образователни цели

Проектът има за цел да демонстрира:

- разделение между интерфейс (.h) и имплементация (.cpp);
- използване на списъци за инициализация;
- валидация и обработка на изключения;
- работа със статични членове;
- прилагане на const-коректност.

## Автор

- Име: Петър Колев
- Номер: 22423
- Курс: Обектно-ориентирано програмиране (C++)
- Дата: 03.12.2025

