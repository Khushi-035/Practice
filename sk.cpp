def is_prime(x: int) -> bool:
    if x < 2:
        return False
    if x % 2 == 0:
        return x == 2
    i = 3
    while i * i <= x:
        if x % i == 0:
            return False
        i += 2
    return True

def prime_factors_sum(n: int) -> int:
    s = 0
    while n % 2 == 0:
        s += 2
        n //= 2
    f = 3
    while f * f <= n:
        while n % f == 0:
            s += f
            n //= f
        f += 2
    if n > 1:
        s += n
    return s

def smallest_prime_value(n: int) -> int:
    while not is_prime(n):
        n = prime_factors_sum(n)
    return n

# --------------------------
if __name__ == "__main__":
    n = int(input())
    print(smallest_prime_value(n))
