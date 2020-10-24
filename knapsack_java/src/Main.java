import grasp.Grasp;
import utils.Console;
import utils.Instance;

public class Main {
	public static void main(String[] args) {
		int choice = 0;
		//App controller
		Instance instance = Instance.getInstance();
	
		//Welcome
		Console.log("Welcome");
		Console.log("Before any algorithm you need to provide an instance");
		instance.read();
		instance.setIterMax();
		instance.setAlfa();
	
		//Main menu
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
			Grasp grasp = new Grasp();
			grasp.run();
			break;
		}
		}while(choice != 0);
	}
	
}
