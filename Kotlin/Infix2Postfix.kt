import java.util.*

/**
 *  Convert infix to postfix
 *  Support operators: + - * / ^
 */
fun infix2postfix(inFixString: String): String {

    var postFixString = ""
    var stack = ArrayDeque<Char>()
    for(i in inFixString.indices) {
        if(isOperand(inFixString[i])) {
            postFixString += inFixString[i]
        } else if(inFixString[i] == '(') {
            stack.push(inFixString[i])
        } else if(inFixString[i] == '^') {
            stack.push(inFixString[i])
        } else if(inFixString[i] == ')') {
            while(stack.isEmpty().not() && stack.peek() != '(') {
                postFixString += stack.pop();
            }
            // pop '(' from stack
            stack.pop();
        } else {
            if(stack.isEmpty() || priority(inFixString[i]) > priority(stack.peek())){
                stack.push(inFixString[i])
            } else {
                while(stack.isEmpty().not() && priority(inFixString[i]) <= priority(stack.peek())) {
                    postFixString += stack.pop()
                }
                stack.push(inFixString[i])
            }
        }
    }
    while (stack.isEmpty().not()) {
        postFixString += stack.pop()
    }
    return postFixString
}

/**
 * Get pecedence of operator
 */
fun priority(input: Char): Int {
    if(input == '+' || input == '-') {
        return 1
    } else if(input == '*' || input == '/') {
        return 2
    } else if(input == '^') {
        return 3
    } else {
        return 0
    }
}

/**
 * Consider character other than + - * / ^ ( ) to be an operand
 */
fun isOperand(input: Char): Boolean {
    var notOperandList = mutableSetOf<Char>('+','-','*','/','^','(',')')
    if(notOperandList.contains(input))
        return false
    else
        return true
}

fun main(args: Array<String>) {
    val infixString1 = "a^b*(2/c)+3";
    println(infixString1 + " -> " + infix2postfix(infixString1))
    val infixString2 = "a+b*c/(e-f)"
    println(infixString2 + " -> " + infix2postfix(infixString2))
    val infixString3 = "a+b*(c^d-e)^(f+g*h)-i"
    println(infixString3 + " -> " + infix2postfix(infixString3))
}