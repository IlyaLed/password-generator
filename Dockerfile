# Используем официальный образ с GCC
FROM gcc:12.2.0

# Устанавливаем зависимости
RUN apt-get update && apt-get install -y \
    cmake \
    && rm -rf /var/lib/apt/lists/*

# Копируем исходный код
WORKDIR /app
COPY password.cpp .

# Компилируем программу
RUN g++ -std=c++20 -o password_generator password.cpp

# Устанавливаем точку входа
ENTRYPOINT ["./password_generator"]