from cs50 import get_string


text = get_string("enter the phrase to verify your grade : ")

let = sent = wor = 0

for char in text:
    if char.isspace():
        wor += 1
    if char.isalpha():
        let += 1
    if char in ['!', '?', '.']:
        sent += 1
wor += 1

L = (let * 100) / wor
S = (sent * 100) / wor
res = int((0.0588 * L - 0.296 * S - 15.8) + 0.5)
if res < 1:
    print("Before Grade 1")
elif res >= 16:
    print("Grade 16+")
else:
    print(f"Grade: {res}")