import java.util.Arrays;
import java.util.Scanner;

public class search {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String[] name = {"Jerry", "Jack", "Winnie", "Max", "Amy", "Peter", "Tony"};
		String input;
		int n = -1;
		
		//印出排序前
		System.out.print("original: ");
		for(int i = 0; i < name.length; i++)
			System.out.print(name[i] + " ");

		//Arrays.sort直接呼叫
		Arrays.sort(name);
		
		//印出排序後
		System.out.print("\nafter: ");
		for(int i = 0; i < name.length; i++)
			System.out.print(name[i] + " ");
		System.out.println("");
		
		System.out.println("Enter the name: ");
		Scanner scn = new Scanner(System.in);
		input = scn.nextLine();
		
		//直接呼叫binarySearch方法
		//binarySearch找到值會回傳註標位置,否則會回傳負值
		
		if((n = Arrays.binarySearch(name, input)) > -1)
			System.out.print(input + " is in array, it's at" + n);
		else
			System.out.print(input + " isn't in array.");
		
		scn.close();
	}
}
