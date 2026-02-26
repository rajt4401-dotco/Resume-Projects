expenses = []
categories = []

print("===== Simple Expense Tracker =====")

n = int(input("How many expenses do you want to enter? "))

for i in range(n):
    amount = float(input("Enter expense amount: "))
    category = input("Enter category (Food/Travel/Other): ")

    expenses.append(amount)
    categories.append(category)

total = sum(expenses)
average = total / n

print("\n----- Expense Summary -----")
print("Total Expenses:", total)
print("Average Expense:", round(average, 2))

food_total = 0
travel_total = 0
other_total = 0

for i in range(len(categories)):
    if categories[i].lower() == "food":
        food_total += expenses[i]
    elif categories[i].lower() == "travel":
        travel_total += expenses[i]
    else:
        other_total += expenses[i]

print("\nCategory-wise Spending:")
print("Food:", food_total)
print("Travel:", travel_total)
print("Other:", other_total)

print("\nThank you for using Expense Tracker!")