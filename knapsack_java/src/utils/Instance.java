package utils;

import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Instance {
	// ###Singleton:
	private static Instance instance;

	public static synchronized Instance getInstance() {
		if (instance == null)
			instance = new Instance();
		//Initialize bes fo
		instance.s_star.setFo(-Double.MAX_VALUE);
		return instance;
	}

	private int n;// number of objects
	private double b;// knapsack capacity
	public Solution s = new Solution();// current solution
	public Solution s_star = new Solution();// best solution
	private ArrayList<Double> w = new ArrayList<Double>();// objects weight
	private ArrayList<Double> p = new ArrayList<Double>();// objects profit

	public boolean instanceIsNull() {
		if (n == 0) {
			Console.log("ERROR 404 - INSTANCE NOT FOUND");
			return true;
		}
		return false;
	}

	public void read() {
		Console.log("Type the path: ");
		String path = Console.readString();
		try {
			FileReader file = new FileReader(path);
			BufferedReader readFile = new BufferedReader(file);

			int line = 0;
			int c = 0;
			// Space = 32, \n = 13
			ArrayList<Character> current = new ArrayList<Character>();
			while (c != -1) {
				c = readFile.read();
				// Input 1
				if (c == 32) {
					if (line == 0) {
						n = arrayCharToInt(current);
					} else if (line > 0 && line < n + 1) {
						p.add(arrayCharToDouble(current));
					} else {
						s.add(arrayCharToInt(current));
					}
					current.clear();
					// Input 2
				} else if (c == 13) {
					if (line == 0) {
						b = arrayCharToInt(current);
					} else if (line > 0 && line < n + 1) {
						w.add(arrayCharToDouble(current));
					} else {
						s.add(arrayCharToInt(current));
					}
					current.clear();
					line++;
				} else if (c != 10) {
					current.add((char) c);
				}
			}
			Console.log("n: " + n);
			Console.log("b: " + b);
			Console.log("s: " + s);
			Console.log("w: " + w);
			Console.log("p: " + p);
			file.close();
		} catch (IOException e) {
			System.err.printf("Something went wrong: %s.\n", e.getMessage());
		}
	}

	private String arrayCharToString(ArrayList<Character> array) {
		char[] ch = new char[20];
		int count = 0;
		for (Character c : array) {
			ch[count] = c;
			count++;
		}
		String str = new String(ch);
		return str.trim();
	}

	private int arrayCharToInt(ArrayList<Character> array) {
		String s = arrayCharToString(array);
		return Integer.parseInt(s);
	}

	private double arrayCharToDouble(ArrayList<Character> array) {
		String s = arrayCharToString(array);
		return Double.parseDouble(s);
	}

	//Getters
	public int getN() {
		return n;
	}

	public double getB() {
		return b;
	}

	public ArrayList<Double> getW() {
		return w;
	}

	public ArrayList<Double> getP() {
		return p;
	}

}
