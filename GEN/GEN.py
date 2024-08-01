import random
import string

def generate_email_address():
    recipient_name = ''.join(random.choices(string.ascii_letters + string.digits, k=random.randint(1, 20))).lower()
    server_name = ''.join(random.choices(string.ascii_letters + string.digits, k=random.randint(1, 20))).lower()
    zone_name = ''.join(random.choices(string.ascii_lowercase, k=random.randint(1, 5)))
    return f"{recipient_name}@{server_name}.{zone_name}"

def generate_random_string():
    return ''.join(random.choices(string.ascii_letters + string.digits, k=random.randint(1, 20)))

def generate_random_or_email_string():
    if random.random() < 0.5:
        return generate_email_address()
    else:
        return generate_random_string()

def main(num_lines):
    with open('output.txt', 'w') as file:
        for _ in range(num_lines):
            if random.random() < 0.3:
                file.write(f"mailto:{generate_email_address()}\n")
            else:
                file.write(f"mailto:{','.join([generate_random_or_email_string() for _ in range(random.randint(1, 3))])}\n")

# Выбор количества генерируемых строк
num_lines_choice = input("Выберите количество генерируемых строк (100/1000/10000/100000/1000000/10000000): ")
num_lines_map = {
    "100": 100,
    "1000": 1000,
    "10000": 10000,
    "100000": 100000,
    "1000000": 1000000,
    "10000000": 10000000
}
if num_lines_choice in num_lines_map:
    num_lines = num_lines_map[num_lines_choice]
else:
    num_lines = 100  # По умолчанию

main(num_lines)