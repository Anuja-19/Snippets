package main

import (
	"strings"
)

func IsOperator(c uint8) bool {
	return strings.ContainsAny(string(c), "+ & - & * & /")
}

func IsOperand(c uint8) bool {
	return c >= '0' && c <= '9'
}

func GetOperatorWeight(op string) int {
	switch op {
	case "+", "-":
		return 1
	case "*", "/":
		return 2
	}
	return -1
}

func HasHigherPrecedence(op1 string, op2 string) bool {
	op1Weight := GetOperatorWeight(op1)
	op2Weight := GetOperatorWeight(op2)
	return op1Weight >= op2Weight
}

func ToPostfix(s string) string {

	var stack Stack

	postfix := ""

	length := len(s)

	for i := 0; i < length; i++ {

		char := string(s[i])
		// Skip whitespaces
		if char == " " {
			continue
		}

		if char == "(" {
			stack.Push(char)
		} else if char == ")" {
			for !stack.Empty() {
				str, _ := stack.Top().(string)
				if str == "(" {
					break
				}
				postfix += " " + str
				stack.Pop()
			}
			stack.Pop()
		} else if !IsOperator(s[i]) {
			// If character is not an operator
			// Keep in mind it's just an operand
			j := i
			number := ""
			for ; j < length && IsOperand(s[j]); j++ {
				number = number + string(s[j])
			}
			postfix += " " + number
			i = j - 1
		} else {
			// If character is operator, pop two elements from stack,
			// perform operation and push the result back.
			for !stack.Empty() {
				top, _ := stack.Top().(string)
				if top == "(" || !HasHigherPrecedence(top, char) {
					break
				}
				postfix += " " + top
				stack.Pop()
			}
			stack.Push(char)
		}
	}

	for !stack.Empty() {
		str, _ := stack.Pop().(string)
		postfix += " " + str
	}

	return strings.TrimSpace(postfix)
}
