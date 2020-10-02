""" Displaying contents of a file """
##f = open("t.txt")
##line = f.readline()
##while line:
##    line = line.strip() # remember to assign back to line!!
##    print(line)
##    line = f.readline()
##f.close()

""" Displaying contents of a file using read function """
##f = open("t.txt", "r")
##all = f.read()
##print(all)
##f.close()

"""Using file pointer to navigate through a file """
##f = open("butter.txt", "r")
##for line in f :
##    line = line.strip()
##    print(line)
##f.close()

""" Printing lines in a file without the \n charecter"""
##f = open("t.txt", "r")
##lines = f.readlines()
##f.close()
##
##for line in lines:
##    line = line.strip()
##    print(line)

""" Counting no. of times the word 'trouble' comes in a particular file"""
##f = open("t.txt", "r")
##lines = f.readlines()
##print(lines)
##f.close()
##total_count = 0
##for line in lines:
##    line = line.strip()
##    total_count += line.count('trouble')
##print("total trouble : ", total_count)

""" printing unique words in butter.txt """
##f = open("butter.txt", "r")
##all = f.read()
##f.close()
##print(all)
##
##wordset = set()
##for word in all.split():
##    wordset.add(word)
##
##print(wordset)

""" Pick all lines containing trouble and write to another file """
##fn = open("t.txt")
##fout = open("t_new.txt", "w")
##for line in fn:
##    if 'trouble' in line :
##        line = line.strip()
##        print(line, file = fout)
##fn.close()
##fout.close()
##
##f=open("t_new.txt","r")
##line=f.read()
##print(line)
##f.close()

""" Count no. of capital and small letters in a file and write O/P to another file """
##fin=open("butter.txt","r")
##fout=open("out.txt","w")
##text=fin.read()
##up=down=0
##for char in text:
##    if char.isupper():
##        up+=1
##    elif char.islower():
##        down+=1
##print(up,down,file=fout)
##fin.close()
##fout.close()
