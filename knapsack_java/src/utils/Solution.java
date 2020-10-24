package utils;

import java.util.ArrayList;

public class Solution {
	private ArrayList<Integer> s = new ArrayList<Integer>();
	private double fo;
	
	//Controllers
	Instance instance = Instance.getInstance();
	
	//Methods
	public ArrayList<Integer> getS() {
		return s;
	}
	
	public void add(int i) {
		if(i == 1 || i == 0) {
			s.add(i);
		}
	}
	
	public void changeBit(int index) {
		int currentValue = s.get(index);
		int newValue = currentValue == 0 ? 1 : 0;
		s.set(index, newValue);
	}

	public double getFo() {
		return fo;
	}
	
	public void setFo(Double newFo) {
		fo = newFo;
	}

	public double calculateFo(){
		double foValue;
		double utility = 0, weight = 0, penality = 0;
		
		for(int i = 0; i < instance.getN(); i++) {
			if(s.get(i).equals(1)) {
				utility += instance.getP().get(i);
				weight += instance.getW().get(i);
			}
			penality += instance.getW().get(i);
		}


		foValue = utility - penality * Double.max(0, weight - instance.getB());

		return foValue;
	}
	
}
