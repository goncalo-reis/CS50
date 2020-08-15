# Import necessary modules
import sys, csv, re

# Check number of arguments
if len(sys.argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)



# Populate list of names
with open(sys.argv[1], "r") as csv_file:
    csv_reader = csv.reader(csv_file)
    list_names = []
    for row in csv_reader:
        if row[0] != 'name':
            list_names.append(row[0])


# Populate list of STR's
with open(sys.argv[1], "r") as csv_file:
    csv_reader = csv.reader(csv_file)
    list_STR = []
    for row in csv_reader:
        columns = len(row)
        for i in range(1, columns):
            list_STR.append(row[i])
        break

# Populate CSV Dictionary
csv_dict = {}

for name in list_names:
    with open(sys.argv[1], "r") as csv_file:
        csv_dict_reader = csv.DictReader(csv_file)
        for row in csv_dict_reader:
            if row['name'] == name:
                csv_dict[name] = {}
                for STR in list_STR:
                    csv_dict[name].update({STR: row[STR]})
                break



# Populate list of STR values
with open(sys.argv[2], "r") as file:
    dna = file.read()
    list_STR_values = []
    for STR in list_STR:
        matches = re.findall(f'(?:{STR})+', dna)
        if len(matches) == 0:
            list_STR_values.append('0')
            continue
        bigger_match = max(matches, key=len)
        list_STR_values.append(str(bigger_match.count(STR)))

# Populate File Dictionary
file_dict = {}
i = 0
for STR in list_STR:
    file_dict[STR] = list_STR_values[i]
    i += 1



# Compare both Dictionaries and print the name of the match
miss_pairings = 0
for key, value in csv_dict.items():
    if file_dict == csv_dict[key]:
        print(key)
        break
    else:
        miss_pairings += 1

# If no match, print "No match"
if miss_pairings == len(list_names):
    print("No match")




