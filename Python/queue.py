# Python program for queue implementation
# Queue = FIFO = First In First Out
  
# Initializing a queue 
queue = [] 
  
# Adding elements to the queue 
queue.append('Queue Value 1') 
queue.append('Queue Value 2') 
queue.append('Queue Value 3') 
  
print("Initial queue") 
print(queue) 
  
# Removing elements from the queue 
print("\nElements removed from the queue") 
print(queue.pop(0)) 
print(queue.pop(0)) 
print(queue.pop(0)) 
  
print("\nQueue after removing the elements") 
print(queue) 
  
# Uncommenting print(queue.pop(0)) 
# will raise and IndexError 
# as the queue is now empty 