package utils;

import java.util.ArrayList;

public class Solution {
	public Solution(){};
	
	public Solution(int solutionSize){
		initSolution(solutionSize);
	}
	
	private ArrayList<Integer> s = new ArrayList<Integer>();
	private double fo;
	
	//Controllers
	Instance instance = Instance.getInstance();
	
	//Methods
	private void initSolution(int size) {
		for(int i = 0; i < size; i++)
			s.add(0);
	}

	public Integer getIndex(int index) {
		return s.get(index);
	}
	
	public Integer setIndex(int index, int value) {
		return s.set(index, value);
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
