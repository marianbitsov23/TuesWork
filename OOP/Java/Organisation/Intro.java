class Intro{
	public static void main(final String[] args) {
		System.out.println("Hello!");
	}

	public void hello(){
		System.out.println("Test!");

		int a = 10;
		long b = 10;
		float c = 1.3f;
		double d = 4.5;
		char e = 'e';
		boolean f = false;
		String g = "asdf";

		final Integer a2 = (Integer) a;
		final String g2 = a2.toString();

		System.out.println(g2);

		for (int i = 0; i < 10; i++) {
			System.out.println(i);
		}

		int[] arr = new int[20];
		for(int i = 0; i < arr.length; i++){
			System.out.println(arr[i]);
		}
	}
}
