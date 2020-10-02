# Function to check if palindrome or not
# returns boolean True or False
def isPalindrome(s):
    return s == s[::-1]

# code to test the isPalindrome function
s = "mom"
ans = isPalindrome(s)
print(ans)
if ans:
    print("Yes")
else:
    print("No")
