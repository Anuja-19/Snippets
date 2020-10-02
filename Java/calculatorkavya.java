import java.util.Scanner;

public class calculatorkavya {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter two numbers: ");

        // nextDouble() reads the next double from the keyboard
        double first = sc.nextDouble();
        double second = sc.nextDouble();

        System.out.print("Enter an operator (+, -, *, /): ");
        char op = sc.next().charAt(0);

        double result;

        switch(op)
        {
            case '+':
                result = first + second;
                break;

            case '-':
                result = first - second;
                break;

            case '*':
                result = first * second;
                break;

            case '/':
                result = first / second;
                break;

        
            default:
                System.out.printf("Error");
                return;
        }

        System.out.printf("%.1f %c %.1f = %.1f", first, op, second, result);
    }
}