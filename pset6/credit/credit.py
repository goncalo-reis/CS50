from cs50 import get_string

number = get_string("Number: ")
card = "INVALID\n"
if len(number) == 15 and (number[0:2] == '34' or number[0:2] == '37'):
    card = "AMEX\n"

if len(number) == 16:
    for n in range(51, 56):
        if number[0:2] == str(n):
            card = "MASTERCARD\n"

if (len(number) == 13 or len(number) == 16) and number[0] == '4':
    card = "VISA\n"

sum_total = 0
for n in range(2, len(number), 2):
    mult = str(int(number[-n]) * 2)
    
    if len(mult) == 2:
        sum_total += int(mult[0]) + int(mult[1])
    else:
        sum_total += int(mult)

if len(number) % 2 == 0:
    mult = str(int(number[0]) * 2)
    
    if len(mult) == 2:
        sum_total += int(mult[0]) + int(mult[1])
    else:
        sum_total += int(mult)
    

for n in range(1, len(number), 2):
    sum_total += int(number[-n])

if len(number) % 2 != 0:    
    sum_total += int(number[0])

if str(sum_total)[-1] == '0':
    print(card)
else:
    print("INVALID\n")

