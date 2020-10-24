package utils;

public class KnapsackObject {
	public KnapsackObject(double weight, double utility, double profit, int id) {
		this.weight = weight;
		this.utility = utility;
		this.profit = profit;
		setId(id);
	}

	double weight;
	double utility;
	double profit;
	private int id;

	public int getId() {
		return id;
	}

	public void setId(int id) {
		if(id == 0 || id == 1)
			this.id = id;
	}
}
