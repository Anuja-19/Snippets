class Node
  attr_accessor :node, :next
  
  def initialize(node)
    @node = node
  end
end

####
# add - inserts the specified element at the specified position, returns true on success
# addLast - inserts the specified element at the end of the list
# remove - removes specified element, returns true on success
# removeAt - removes element at specified index
# clear - remove all elements
# print - print elements in list
# reverse - reverses the linkedlist
####
class LinkedList
  attr_accessor :head
  
  def initialize(val)
    @head = Node.new(val)
  end

  def add(val)
    current = @head

    while current.next != nil
      current = current.next
    end
    current.next = Node.new(val)
  end

  def add_at(val, pos)
    current = @head
    previous = nil
    if pos == 0
      new_head = Node.new(val)
      new_head.next = @head
      @head = new_head
    else
      (0...pos).each do |i|
        return false if current.nil?
        previous = current
        current = current.next
      end
      next_node = Node.new(val)
      previous.next = next_node
      next_node.next = current
    end
    return true
  end

  def remove(val)
    current = @head
    temp = nil
    previous = nil
    while current != nil
      if current.node == val
        temp = current.next
        previous.next = temp
        return true
      else
        previous = current
        current = current.next
      end
    end

    return false
  end

  def remove_at(pos)
    current = @head
    previous = nil
    if pos == 0
      temp = @head.next
      @head = temp
    else
      (0...pos).each do
        return false if current.nil?
        previous = current
        current = current.next
      end
      previous.next = current.next
    end

    return true
  end

  def clear
    @head.node = nil
    @head.next = nil
  end

  def print
    msg = ''
    temp = nil
    current = @head
    while current != nil
      msg << "#{current.node} -> "
      current = current.next
    end

    return msg[0..-4]
  end

  def reverse
    previous = nil
    current = @head

    while current != nil
      next_node = current.next
      current.next = previous
      previous = current
      current = next_node
    end

    @head = previous
  end
end
