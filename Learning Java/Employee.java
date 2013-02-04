
public class Employee 
{
	String Name, ID;
	Dates DoJ, DoB;
	Employee()
	{
		Name="Default";
		ID="20XXXXPS###G";
		DoJ = new Dates(31,2,2020);
		DoB = new Dates(31,2,2020);
	}
	Employee(String Name, String ID, Dates DoJ, Dates DoB)
	{
		this.Name=Name;
		this.ID=ID;
		this.DoJ = new Dates();
			this.DoJ = DoJ;
		this.DoB = new Dates();
			this.DoB = DoB;
		}
	public String toString()
	{
		return "Employee Name: "+Name+" ID No.:"+ID+" joined on: "+DoJ+" Date of Birth "+DoB;
	}
	public float CalSal()
	{
		return 0.0f;
	}


}
