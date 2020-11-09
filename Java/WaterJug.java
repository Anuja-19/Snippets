import java.util.*;

public class WaterJug_3306 {
	/*Waterjug Program*/

	void waterjug(int j1, int j2, int[] soln) {
		int st = 1;
		int x = j1, y = 0;
		int flag1=0, flag2=0;
		System.out.println("Step " + st + ":" + x + " " + y);
		while (st < 30) {
			if (x <= j1 && y < j2) {
				st++;
				if (x - (j2 - y) > 0) {
					x = x - (j2 - y);
					y = j2;
				} else {
					y = y + x;
					x = 0;
				}
				System.out.println("Step " + st + ":" + x + " " + y);
				if (x == soln[0] && y == soln[1]) {
					System.out.println("Got Solution");
					flag1++;
					break;
				}
			}
			if (x == 0) {
				x = j1;
				st++;
				System.out.println("Step " + st + ":" + x + " " + y);
				if (x == soln[0] && y == soln[1]) {
					System.out.println("Got Solution");
					flag1++;
					break;
				}
			}
			if (y == j2) {
				y = 0;
				st++;
				System.out.println("Step " + st + ":" + x + " " + y);
				if (x == soln[0] && y == soln[1]) {
					System.out.println("Got Solution");
					flag1++;
					break;
				}
			}
		}

		int st1 = 1;
		x = 0;
		y = j2;
		System.out.println("\n\n\n Step " + st1 + ":" + x + " " + y);
		while (st1 < 30) {
			if (y <= j2 && x < j1) {
				st1++;
				if ((j1 - x) < y) {
					y = y - (j1 - x);
					x = j1;
				} else {
					x = y + x;
					y = 0;
				}
				System.out.println("Step " + st1 + ":" + x + " " + y);
				if (x == soln[0] && y == soln[1]) {
					System.out.println("Got Solution");
					flag2++;
					break;
				}
			}
			if (y == 0) {
				y = j2;
				st1++;
				System.out.println("Step " + st1 + ":" + x + " " + y);
				if (x == soln[0] && y == soln[1]) {
					System.out.println("Got Solution");
					flag2++;
					break;
				}
			}
			if (x == j1) {
				x = 0;
				st1++;
				System.out.println("Step " + st1 + ":" + x + " " + y);
				if (x == soln[0] && y == soln[1]) {
					System.out.println("Got Solution");
					flag2++;
					break;
				}
			}
		}
		if (flag1!=0 && flag2!=0)
		{
			if(st<st1)
			{
				System.out.println("if jug " + j1
						+ " is filled first.. We get soln in less steps");
			}
			else
			{
				System.out.println("if jug " + j2
						+ " is filled first.. We get soln in less steps");				
			}
		}
		else if(flag1!=0)
		{
			System.out.println("We get soln if jug "+j1 +"is filled 1st");
		}
		else if(flag2!=0)
		{
			System.out.println("We get soln if jug "+j2 +"is filled 1st");			
		}
		else
		{
			System.out.println("No Solution Got!!!!");
		}

	}

	public static void main(String[] args) {

		WaterJug_3306 wj = new WaterJug_3306();
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter Size of 1st jug:");
		int j1 = sc.nextInt();
		System.out.println("Enter Size of 2nd jug:");
		int j2 = sc.nextInt();
		int soln[] = new int[2];
		System.out.println("Enter Required Solution:");
		soln[0] = sc.nextInt();
		soln[1] = sc.nextInt();
		wj.waterjug(j1, j2, soln);
	}

}
