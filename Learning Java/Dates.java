
class Dates 
{
	
	int mm, yy, dd;
	
	Dates()
	{
		dd=mm=yy=00;
	}
	
	Dates(int d)
	{
		this(d, 5);
	}
	Dates(int d, int m)
	{
		this(d,m,2011);
	}
	
	Dates(int dd, int mm, int yy)
	{
		this.dd=dd;
		this.mm=mm;
		this.yy=yy;
	}
	public void setDate(int dd, int mm, int yy)
	{
		this.dd=dd;
		this.mm=mm;
		this.yy=yy;
	}
	public String toString ()
	{
		return " "+dd+"/"+mm+"/"+yy;
	}
	
	
	
	
	
}
