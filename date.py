def toDays(date: str):
    y, m, d = [int(x) for x in date.split(" ")]
    # days = y * 365 + y // 4 + 
    return (1461 * (y + 4800 + (m - 14) // 12)) // 4 +(367 * (m - 2 - 12 * ((m - 14) // 12))) // 12 - (3 * ((y + 4900 + (m - 14) // 12) // 100)) // 4 + d - 32075

d1 = "2022 9 18"
d2 = "1825 10 4"

print(toDays(d1) - toDays(d2))