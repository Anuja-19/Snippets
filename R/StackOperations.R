Stack<-R6::R6Class("Stack",list(
        stack = NULL,
        push = function(x) {
                self$stack <- append(self$stack,x)
        },
        pop = function() {
                if(length(self$stack)>0) {
                        top <- self$stack[1]
                        self$stack <- self$stack[-1]
                        return(top)
                }
                else
                        cat("Empty Stack")
        },
        display = function() {
                print(self$stack)
        },
        size = function() {
                cat("Number Of elements in stack are: ",length(self$stack))
        }
))

# Some Basic Operations
t<-Stack$new()
t$push(1)
t$push(2)
t$push("Element")
t$display()
t$size()
t$pop()
t$display()
t$size()
t$pop()
t$display()
t$size()
t$pop()
t$display()
t$size()
t$pop()
