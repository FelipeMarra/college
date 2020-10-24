package utils;

import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class Instance {
	// ###Singleton:
	private static Instance instance;

	public static synchronized Instance getInstance() {
		if (instance == null)
			instance = new Instance();

		return instance;
	}

	int n;// number of objects
	double b;// knapsack capacity
	ArrayList<Integer> s = new ArrayList<Integer>();// current solution
	ArrayList<Integer> s_star = new ArrayList<Integer>();// best solution
	ArrayList<Double> w = new ArrayList<Double>();// objects weight
	ArrayList<Double> p = new ArrayList<Double>();// objects profit
	double fo; // current fo
	double fo_star; // best fo

	public static void read() {
		Console.log("Type the path: ");
		String path = Console.readString();
		try {
			FileReader file = new FileReader(path);
			BufferedReader readFile = new BufferedReader(file);
			String linha = readFile.readLine(); // lê a primeira linha
			// a variável "linha" recebe o valor "null" quando o processo
			// de repetição atingir o final do arquivo texto
			while (linha != null) {
				System.out.printf("%s\n", linha);

				linha = readFile.readLine(); // lê da segunda até a última linha
			}

			file.close();
		} catch (IOException e) {
			System.err.printf("Something went wrong: %s.\n", e.getMessage());
		}
		Console.log(null);
	}

}
