from cs50 import SQL
import csv
import sys

# Check number of arguments
if len(sys.argv) != 2:
    print("Wrong number of arguments.")
    exit(1)

# Read CSV file into tmp lists
names_list = []
houses_list = []
births_list = []
with open(sys.argv[1], "r") as csv_file:
    csv_dict_reader = csv.DictReader(csv_file)
    for row in csv_dict_reader:
        names_list.append(row['name'])
        houses_list.append(row['house'])
        births_list.append(row['birth'])

# Parse names in names_list into specific lists
first_list = []
middle_list = []
last_list = []
for name in names_list:
    tmp_list = name.split(" ")
    if len(tmp_list) == 3:
        first_list.append(tmp_list[0])
        middle_list.append(tmp_list[1])
        last_list.append(tmp_list[2])
    else:
        first_list.append(tmp_list[0])
        middle_list.append(None)
        last_list.append(tmp_list[1])

# Pass data from lists into students.db
db = SQL("sqlite:///students.db")
for i in range(len(names_list)):
    db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
                first_list[i], middle_list[i], last_list[i], houses_list[i], births_list[i])