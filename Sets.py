# add
fruits = {'apple','banana','cherry'}
fruits.add('orange')
print(fruits)

# pop - Remove a random item from the set
fruits = {"apple", "banana", "cherry"}
fruits.pop()
print(fruits)

# Union - Return a set that contains all items from both sets, duplicates are excluded
x = {"apple", "banana", "cherry"}
y = {"google", "microsoft", "apple"}
z = x.union(y)
print(z)

# Intersection - Return a set that contains the items that exist in both set x, and set y
x = {"apple", "banana", "cherry"}
y = {"google", "microsoft", "apple"}
z = x.intersection(y)
print(z)

# Difference - Return a set that contains the items that only exist in set x, and not in set y
x = {"apple", "banana", "cherry"}
y = {"google", "microsoft", "apple"}
z = x.difference(y)
print(z)

# Symmertic Difference - Return a set that contains all items from both sets, except items that are present in both sets
x = {"apple", "banana", "cherry"}
y = {"google", "microsoft", "apple"}
z = x.symmetric_difference(y)
print(z)
