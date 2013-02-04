
public class WagedEmployee extends Employee 
{
	float Rate;
	int hrs;
	public WagedEmployee()
	{
		Rate=hrs=0;
	}
	public WagedEmployee(int hrs, float Rate)
	{
		this.Rate=Rate;
		this.hrs=hrs;
	}
	public String toString()
	{
		
		return super.toString()+"The Employee's Wage rate is "+Rate+" No of Hours:  "+hrs;
	}
	public float CalSal()
	{
		return (Rate*hrs);
	}
	

}
