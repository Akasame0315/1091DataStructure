import java.util.Scanner;

public class binarySearch {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] num = new int[9];
		int temp, input;
		
		//random方法產生1-100的亂數
		for(int i = 0; i < num.length; i++)
			num[i] = (int)(Math.random()*100)+1;//亂數出來為float型別所以要轉成int
		
		//印出排序前
		System.out.print("original: ");
		for(int a : num) //加強型for迴圈讀取陣列元素
			System.out.print(a + " ");
		
		//bubbbleSort
		for(int i = num.length - 1; i >= 0; i--) 
			for(int j = 0; j < i; j++)
				if(num[j] > num[j + 1]) {
					temp = num[j];
					num[j] = num[j + 1];
					num[j + 1] = temp;
				}
		
		//印出排序後
		System.out.print("\nafter: ");
		for(int a : num) //加強型for迴圈讀取陣列元素
			System.out.print(a + " ");
		
		System.out.print("\nEnter the number: ");
		Scanner scn = new Scanner(System.in);
		input = scn.nextInt();
		
		int n = -1, low = 0, high = num.length - 1, midnum;
		//binarySearch
		do {
			midnum = (low + high) / 2;
			
			//輸入的值剛好是陣列中間元素
			if(input == num[midnum]) {
				n = midnum;
				low = high + 1; //跳出do-while迴圈
			}
			else if(input > num[midnum]) //往較大的元素開始找
				low = midnum + 1;
			else
				high = midnum - 1; //往較小的元素開始找
			
		}while(low <= high); //low <= high的話迴圈繼續
		
		if(n == -1) 
			System.out.print(input + " isn't in array.");
		else
			System.out.print(input + " is in array, it's at " + midnum);

	scn.close();
	}

}
