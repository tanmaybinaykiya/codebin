/**
 * 
 */

/**
 * @author tanmay
 *
 */
public class Main_Class {

	public static void main(String args[]) 
	{
		Employee Emp[]=new Employee[5];
		Emp[0]=new WagedEmployee();
		Emp[1]=new WagedEmployee();
		Emp[2]=new WagedEmployee();
		Emp[3]=new WagedEmployee();
		Emp[4]=new WagedEmployee();
		System.out.println("Hello World"+Emp[0]);
		System.out.println("Hello World"+Emp[1]);
		System.out.println("Hello World"+Emp[2]);
		System.out.println("Hello World"+Emp[3]);
		System.out.println("Hello World"+Emp[4]);
	}

}
