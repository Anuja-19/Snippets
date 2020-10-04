package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func ReadFromInput() (string, error) {

	reader := bufio.NewReader(os.Stdin)
	s, err := reader.ReadString('\n')

	return strings.TrimSpace(s), err
}

func main() {

	fmt.Print("Enter infix expression: ")
	infixString, err := ReadFromInput()

	if err != nil {
		fmt.Println("Error when scanning input:", err.Error())
		return
	}

	fmt.Println("Ya you postfix notation:", ToPostfix(infixString))
	return
}
