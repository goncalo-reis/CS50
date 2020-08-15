from cs50 import get_string

# get string from user
text = get_string("Text: ") 

# Get number of letters
letters = 0
for i in text:
    if i.isalpha():
        letters += 1

# Get number of words
tmp_list = text.split(" ")
words = len(tmp_list)

# Get number of sentences
sentences = 0
for i in text:
    if i == '.' or i == '?' or i == '!':
        sentences += 1

L = 100 * letters / words
S = 100 * sentences / words
index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {str(index)}")