
public class bubbleSort {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] num = {32, 24, 11, 48, 15};
		int temp;
		
		//印出排序前
		System.out.print("original: ");
		for(int i = 0; i < 5; i++)
			System.out.print(num[i] + " ");
		
		//bubbbleSort
		for(int i = num.length - 1; i >= 0; i--) {
			for(int j = 0; j < i; j++)
				if(num[j] > num[j + 1]) {
					temp = num[j];
					num[j] = num[j + 1];
					num[j + 1] = temp;
				}
			//排序一次就輸出一次看狀態
			System.out.println();
			System.out.print("after " + (5-i) + " times: ");
			for(int k = 0; k < 5; k++)
				System.out.print(num[k] + " ");
		}
		
	}

}
