import grasp.Grasp;
import utils.Console;
import utils.Instance;

public class Main {
	public static void main(String[] args) {
		int choice = 0;
		Instance instance = Instance.getInstance();
		//Main menu
		instance.read();
		do {
		Console.log("0 - close");
		Console.log("1 - new instance");
		Console.log("2 - grasp");
		Console.log("Make a choice: ");
		choice = Console.readInt();
		switch(choice) {
		case 0:
			System.exit(0);
			break;
		case 1:
			instance.read();
			break;
		case 2:
			Grasp.run();
			break;
		}
		}while(choice != 0);
	}
	
}
