from cs50 import SQL
import sys

# Check number of arguments
if len(sys.argv) != 2:
    print("Wrong number of arguments.")
    exit(1)

# Execute
db = SQL("sqlite:///students.db")
list_results = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last, first", sys.argv[1])

# Print the results
for i in range(len(list_results)):
    print(list_results[i]['first'], end=' ')
    if list_results[i]['middle'] != None:
        print(list_results[i]['middle'], end=' ')
    print(list_results[i]['last'], end=', ')
    print(f"born {list_results[i]['birth']}")