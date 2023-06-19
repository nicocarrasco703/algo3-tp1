import numpy as np
import os

np.random.seed(42)

def generate_test_case(n, m, k):
    # Generar puntos críticos s y t aleatorios
    s = np.random.randint(1, n+1)
    t = np.random.randint(1, n+1)
    while s == t:
        t = np.random.randint(1, n+1)

    # Generar calles unidireccionales
    streets = np.random.randint(1, n+1, size=(m, 2))
    street_lengths = np.random.randint(1, 1001, size=m)

    # Generar calles bidireccionales propuestas
    proposed_streets = np.random.randint(1, n+1, size=(k, 2))
    proposed_street_lengths = np.random.randint(1, 1001, size=k)

    return n, s, t, streets, street_lengths, proposed_streets, proposed_street_lengths

def save_test_case(filename, test_case):
    n, s, t, streets, street_lengths, proposed_streets, proposed_street_lengths = test_case
    with open(filename, 'w') as file:
        file.write(f"{n} {len(streets)} {len(proposed_streets)} {s} {t}\n")
        for i in range(len(streets)):
            file.write(f"{streets[i, 0]} {streets[i, 1]} {street_lengths[i]}\n")
        for i in range(len(proposed_streets)):
            file.write(f"{proposed_streets[i, 0]} {proposed_streets[i, 1]} {proposed_street_lengths[i]}\n")

# Crear carpeta "inputs" si no existe
os.makedirs("inputs", exist_ok=True)

# Generar casos de prueba y guardar en archivos de texto
num_cases = 10000
for i in range(num_cases):
    n = np.random.randint(1, 10001)
    m = np.random.randint(1, 100001)
    k = np.random.randint(1, 301)
    test_case = generate_test_case(n, m, k)
    filename = f"inputs/input_{n}_{m}_{i}.txt"
    save_test_case(filename, test_case)
