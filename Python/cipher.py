s = input()      #reads input string
n= int(input())   #a number which is used to convert string to cipher
s1 = ""
for x in s:       #used to convert the string to a cipher
    if(x.isalnum()):
        ass = ord(x)
        if(ass>=65 and ass<=90):
            ass+=n
            if(ass>90):
                ass = 64+n-1
        if(ass>=97 and ass<=122):
            ass+=n
            if(ass>122):
                ass = 96+n
        if(ass>=48 and ass<=57):
            ass+=n
            if(ass>57):
                ass = 47+n
        s1+=chr(ass)
    else:
        s1+=x
print(s1)    #printing the converted coded string.
